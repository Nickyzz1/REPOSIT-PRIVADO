from machine import Pin, ADC
import time

light_sensor = Pin(34, Pin.IN)

if light_sensor.value() == 1:
    print("there are light")
else:
    print("just darkness")


