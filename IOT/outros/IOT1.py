import machine
import time

led = machine.Pin(32 , machine.Pin.OUT)
button  = machine.Pin(34 , machine.Pin.IN)
led2 = machine.Pin(18 , machine.Pin.OUT)
button2  = machine.Pin(33, machine.Pin.IN)

while True:
    
    if button.value() == 1:
        
        led.on()
        time.sleep(0.5)
        led.off()
        time.sleep(0.5)
        
        button_state = button.value()
        print("estado do botão 1 :", button_state)
        
    elif button2.value() == 1:
        
        led2.on()
        time.sleep(0.5)
        led2.off()
        time.sleep(0.5)
        
        button2_state = button2.value()
        print("estado do botão 2 :", button2_state)
        
    elif button.value() == 1 and button2.value() == 1:
        
        button_state = button.value()
        button2_state = button2.value()
        print("estado do botão 1 :", button_state)
        print("estado do botão 2 :", button2_state)
        
   
#while True:
#    led.value(not led.value())
#    time.sleep(1)  0-