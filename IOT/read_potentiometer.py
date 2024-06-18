from machine import ADC, Pin
import time

adc = ADC(Pin(34))
adc.width(ADC.WIDTH_12BIT)
adc.atten(ADC.ATTN_11DB)

def read_potentiometer():
    while True:
        #lê o valor de adc potenciometro
        pot_value = adc.read()*15/4095
        if pot_value == 15:
            print("N")
            print("value of potentiometer ", pot_value)
        elif pot_value == 8:
            print("i")
            print("value of potentiometer ", pot_value)
        else:
            print("value of potentiometer ", pot_value)
            
        #aguarda 1 segundo
        time.sleep(1)
#chama a função principal
read_potentiometer()


