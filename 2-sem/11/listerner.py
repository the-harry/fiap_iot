import datetime
import logging
import paho.mqtt.client as mqtt
from influxdb import InfluxDBClient

def persists(msg):
    json_body = [
        {
            "measurement": "metrics",
            "tags": {},
            "time": datetime.datetime.utcnow().isoformat(),
            "fields": {
                "value": int(msg.payload)
            }
        }
    ]
    logging.info(json_body)
    influx_client.write_points(json_body)

logging.basicConfig(level=logging.DEBUG) #INFO)

influx_client = InfluxDBClient('influx', 8086, database='metrics')
client = mqtt.Client()

client.on_connect = lambda self, mosq, obj, rc: self.subscribe("/metrics")
client.on_message = lambda client, userdata, msg: persists(msg)

client.connect("mosquitto", 1883, 60)
client.loop_forever()
