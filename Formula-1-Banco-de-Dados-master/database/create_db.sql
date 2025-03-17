CREATE DATABASE IF NOT EXISTS F1;
USE F1;

DROP TABLE IF EXISTS Contrata;
DROP TABLE IF EXISTS Participa;
DROP TABLE IF EXISTS Ocorre_em;
DROP TABLE IF EXISTS Corrida;
DROP TABLE IF EXISTS Circuito;
DROP TABLE IF EXISTS Piloto;
DROP TABLE IF EXISTS Construtor;

CREATE TABLE Construtor (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Nome VARCHAR(255) NOT NULL,
    Nacionalidade VARCHAR(255) NOT NULL
);

CREATE TABLE Piloto (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Primeiro_Nome VARCHAR(255) NOT NULL,
    Sobrenome VARCHAR(255) NOT NULL,
    Data_de_Nascimento DATE NOT NULL
);

CREATE TABLE Circuito (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Nome VARCHAR(255) NOT NULL,
    Localizacao VARCHAR(255) NOT NULL
);

CREATE TABLE Corrida (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Num_Rodada INT NOT NULL,
    Id_Circuito INT NOT NULL,
    FOREIGN KEY (Id_Circuito) REFERENCES Circuito(Id)
);

CREATE TABLE Participa (
    fk_Corrida_Id INT NOT NULL,
    fk_Piloto_Id INT NOT NULL,
    Resultado INT NOT NULL,
    FOREIGN KEY (fk_Corrida_Id) REFERENCES Corrida(Id),
    FOREIGN KEY (fk_Piloto_Id) REFERENCES Piloto(Id),
    PRIMARY KEY (fk_Corrida_Id, fk_Piloto_Id)
);

CREATE TABLE Ocorre_em (
    fk_Circuito_Id INT NOT NULL,
    fk_Corrida_Id INT NOT NULL,
    Ano INT NOT NULL,
    FOREIGN KEY (fk_Circuito_Id) REFERENCES Circuito(Id),
    FOREIGN KEY (fk_Corrida_Id) REFERENCES Corrida(Id),
    PRIMARY KEY (fk_Circuito_Id, fk_Corrida_Id, Ano)
);

CREATE TABLE Contrata (
    fk_Construtor_Id INT NOT NULL,
    fk_Piloto_Id INT NOT NULL,
    FOREIGN KEY (fk_Construtor_Id) REFERENCES Construtor(Id),
    FOREIGN KEY (fk_Piloto_Id) REFERENCES Piloto(Id),
    PRIMARY KEY (fk_Construtor_Id, fk_Piloto_Id)
);
