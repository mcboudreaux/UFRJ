import json
import pandas as pd
import mysql.connector

# Carregar o arquivo de configuração
with open('config.json') as f:
    config = json.load(f)

HOST = config['MYSQL_HOST']
USER = config['MYSQL_USER']
PASSWORD = config['MYSQL_PASSWORD']
DATABASE = config['MYSQL_DATABASE']


class f1:
    def __init__(self):
        self.constructors = pd.read_csv('database/csvs/constructors.csv')
        self.drivers = pd.read_csv('database/csvs/drivers.csv')
        self.circuits = pd.read_csv('database/csvs/circuits.csv')
        self.races = pd.read_csv('database/csvs/races.csv')
        self.results = pd.read_csv('database/csvs/results.csv')
        self.db = mysql.connector.connect(host=HOST, user=USER, password=PASSWORD, database=DATABASE)
        self.sql = self.db.cursor()

    def insert_constructor(self, name, nationality):
        query = "INSERT INTO `Construtor` (`Nome`, `Nacionalidade`) VALUES (%s, %s)"
        return self.sql.execute(query, (name, nationality))

    def populate_constructors(self):
        for _, constructor in self.constructors.iterrows():
            self.insert_constructor(constructor['name'], constructor['nationality'])

    def insert_driver(self, first_name, last_name, date_of_birth):
        query = "INSERT INTO `Piloto` (`Primeiro_Nome`, `Sobrenome`, `Data_de_Nascimento`) VALUES (%s, %s, %s)"
        return self.sql.execute(query, (first_name, last_name, date_of_birth))

    def populate_drivers(self):
        for _, driver in self.drivers.iterrows():
            self.insert_driver(driver['forename'], driver['surname'], driver['dob'])

    def insert_circuit(self, name, location):
        query = "INSERT INTO `Circuito` (`Nome`, `Localizacao`) VALUES (%s, %s)"
        self.sql.execute(query, (name, location))

    def populate_circuits(self):
        for _, circuit in self.circuits.iterrows():
            self.insert_circuit(circuit['name'], circuit['location'])

    def insert_race(self, round, circuit_id):
        query = "INSERT INTO `Corrida` (`Num_Rodada`, `Id_Circuito`) VALUES (%s, %s)"
        self.sql.execute(query, (int(round), int(circuit_id)))


    def insert_contract(self, constructor_id, driver_id):
        query = "INSERT INTO `Contrata` (`fk_Construtor_Id`, `fk_Piloto_Id`) VALUES (%s, %s)"
        self.sql.execute(query, (int(constructor_id), int(driver_id)))

    def populate_contracts(self):
        races_from_last_year = self.races[self.races['year'] == 2024]
        results_races_from_last_year = pd.merge(self.results, races_from_last_year, on='raceId', how='inner')
        # Drop duplicates
        df = results_races_from_last_year.drop_duplicates(subset=['driverId', 'constructorId'])
        for _, contract in df.iterrows():
            self.insert_contract(contract['constructorId'], contract['driverId'])

    def insert_participation(self, race_id, driver_id, result):
        query = "INSERT INTO `Participa` (`fk_Corrida_Id`, `fk_Piloto_Id`, `Resultado`) VALUES (%s, %s, %s)"
        self.sql.execute(query, (int(race_id), int(driver_id), int(result)))

    def insert_event(self, circuit_id, race_id, year):
        query = "INSERT INTO `Ocorre_em` (`fk_Circuito_Id`, `fk_Corrida_Id`, `Ano`) VALUES (%s, %s, %s)"
        self.sql.execute(query, (int(circuit_id), int(race_id), int(year)))

    def populate_races(self):
        for _, race in self.races.iterrows():
            self.insert_race(race['round'], race['circuitId'])

    def populate_events(self):
        for _, race in self.races.iterrows():
            self.insert_event(race['circuitId'], race['raceId'], race['year'])

    def populate_participation(self):
        for _, result in self.results.iterrows():
            try:
                self.insert_participation(result['raceId'], result['driverId'], result['position'])
            except:
                # Ignore duplicatas de raceId e driverId
                continue
    
def main():
    try:
        c = f1()

        c.sql.execute("SET FOREIGN_KEY_CHECKS=0")
        c.populate_drivers()
        c.populate_constructors()
        c.populate_circuits()
        c.populate_races()
        c.populate_contracts()
        c.populate_events()
        c.populate_participation()
        c.sql.execute("SET FOREIGN_KEY_CHECKS=1")
        c.db.commit()
        c.db.close()
        print("Import completed")
    except Exception as ex:
        print(f"error: {ex}")
        c.db.close()

if __name__ == '__main__':
    main()