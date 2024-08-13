from machine import Pin, PWM
import time


# maior pino na saída da esp
# mnenor poino no negativo

buzzer = PWM(Pin(15, Pin.OUT))

def playTone(freq, duration_ms):
    buzzer.freq(freq)
    buzzer.duty(50)
    time.sleep_ms(duration_ms)
    buzzer.duty(0)
    
playTone(600, 1000)
