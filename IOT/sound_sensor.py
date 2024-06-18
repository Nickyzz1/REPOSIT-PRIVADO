from machine import Pin
import time

pir_sensor = Pin(13, Pin.IN)
pir_sensor_volum = Pin(27, Pin.OUT)

def read_pir_sensor():
    while True:
        if pir_sensor.value() == 0:
            print("that -wasn't detected any moviment")
            pir_sensor_volum.off() 
        else:
            print("Moviment was detected")
            pir_sensor_volum.on()
        time.sleep(0.5)                                    

read_pir_sensor()