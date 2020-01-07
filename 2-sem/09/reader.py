import json
import requests
import serial
import time
from datetime import datetime

class Reader:

    def __init__(self, port='/dev/ttyACM0'):
        self.port = port
        self.data = ''
        self.sensor = self.connect()

    def connect(self):
        global BAUD
        try:
            self.sensor = serial.Serial(self.port, BAUD)
            print('Conectado com sucesso.\n')
            return self.sensor
        except:
            print('Sem conexão na porta ' + str(self.port) + '.\n')
            return 0

    def getData(self):
        self.connect()
        if(self.sensor != 0):
            self.data = str(self.sensor.readline().decode("utf-8").rstrip())
            self.saveData()
        else:
            time.sleep(10)
            self.getData()

    def saveData(self):
        global URI
        try:
            payload = self.buildPayload()
            res = requests.post(url = URI, data = payload, auth=('admin', 'ADMIN'))
            print(res.text)
            print(self.data)
        except Exception as e:
            raise e
            pass

    def buildPayload(self):
        payload = {}
        payload['sensor'] = 'pet_01'
        payload['presence'] = present?
        data = json.dumps(payload)
        return data

    def present?(self):
        True if self.data == 'open' else False
