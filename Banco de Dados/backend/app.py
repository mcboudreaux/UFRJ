from flask import Flask, jsonify
from flask_cors import CORS
import mysql.connector
from mysql.connector import Error

# Configuração do Flask
app = Flask(__name__)
CORS(app)

# Configuração do Banco de Dados
DB_CONFIG = {
    "host": "localhost",          # Endereço do servidor MySQL
    "user": "root",        # Usuário do MySQL
    "password": "joao3v16",      # Senha do MySQL
    "database": "F1"       # Nome do banco de dados
}

# Função para executar consultas
def execute_query(query):
    try:
        connection = mysql.connector.connect(**DB_CONFIG)
        cursor = connection.cursor(dictionary=True)
        cursor.execute(query)
        results = cursor.fetchall()
        return results
    except Error as e:
        return {"error": str(e)}
    finally:
        if connection.is_connected():
            cursor.close()
            connection.close()

# Rotas para as consultas
@app.route("/consulta1")
def consulta1():
    query = """
    SELECT 
        Piloto.Primeiro_Nome, 
        Piloto.Sobrenome, 
        Construtor.Nome AS Nome_Equipe
    FROM 
        Piloto
    INNER JOIN 
        Contrata ON Piloto.Id = Contrata.fk_Piloto_Id
    INNER JOIN 
        Construtor ON Contrata.fk_Construtor_Id = Construtor.Id
    LIMIT 10;
    """
    return jsonify(execute_query(query))

@app.route("/consulta2")
def consulta2():
    query = """
    SELECT 
        Corrida.Id AS Corrida_Id, 
        Corrida.Num_Rodada, 
        Circuito.Nome AS Nome_Circuito, 
        Circuito.Localizacao
    FROM 
        Circuito
    LEFT JOIN 
        Corrida ON Circuito.Id = Corrida.Id_Circuito
    LIMIT 10;
    """
    return jsonify(execute_query(query))

@app.route("/consulta3")
def consulta3():
    query = """
    SELECT 
        Construtor.Nome AS Nome_Equipe, 
        COUNT(Contrata.fk_Piloto_Id) AS Total_Pilotos
    FROM 
        Construtor
    LEFT JOIN 
        Contrata ON Construtor.Id = Contrata.fk_Construtor_Id
    GROUP BY 
        Construtor.Nome
    LIMIT 10;
    """
    return jsonify(execute_query(query))

@app.route("/consulta4")
def consulta4():
    query = """
    SELECT 
        Piloto.Primeiro_Nome, 
        Piloto.Sobrenome, 
        Participa.Resultado, 
        Corrida.Num_Rodada
    FROM 
        Piloto
    INNER JOIN 
        Participa ON Piloto.Id = Participa.fk_Piloto_Id
    INNER JOIN 
        Corrida ON Participa.fk_Corrida_Id = Corrida.Id
    WHERE 
        Corrida.Num_Rodada BETWEEN 6 AND 10
    LIMIT 10;
    """
    return jsonify(execute_query(query))

@app.route("/consulta5")
def consulta5():
    query = """
    SELECT 
        Nome, 
        Localizacao, 
        Media_Rodada
    FROM (
        SELECT 
            Circuito.Nome, 
            Circuito.Localizacao, 
            AVG(Corrida.Num_Rodada) AS Media_Rodada
        FROM 
            Circuito
        INNER JOIN 
            Corrida ON Circuito.Id = Corrida.Id_Circuito
        GROUP BY 
            Circuito.Id
    ) AS Subconsulta
    WHERE 
        Media_Rodada > 5
    LIMIT 10;
    """
    return jsonify(execute_query(query))

# Rota inicial para testar a API
@app.route("/")
def home():
    return jsonify({"message": "API funcionando!"})

# Inicialização do servidor
if __name__ == "__main__":
    app.run(debug=True)
