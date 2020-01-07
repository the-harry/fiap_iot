import serial
import time

class Sender:
    def __init__(self, port='/dev/ttyACM0'):
        self.port = port
        self.baud = 9600

    def connect(self):
        try:
            device = serial.Serial(self.port, self.baud)
            print('Conectado com sucesso.\n')
            return device
        except:
            print('Sem conexão na porta ' + str(self.port) + '.\n')
            return 0

    def alimentar!(self):
        device = self.connect()
        if(device != 0):
            self.data.append(str(device.readline()))
        else:
            time.sleep(30)
            self.alimentar!
