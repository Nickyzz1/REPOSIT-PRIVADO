import machine
import time
import random
    
buttonRed = machine.Pin(13, machine.Pin.IN)
buttonYellow = machine.Pin(12, machine.Pin.IN)
buttonGreen = machine.Pin(14, machine.Pin.IN)
buttonBlue = machine.Pin(27, machine.Pin.IN)

ledRed = machine.Pin(26, machine.Pin.OUT)
ledYellow = machine.Pin(25, machine.Pin.OUT)
ledGreen = machine.Pin(33, machine.Pin.OUT)
ledBlue = machine.Pin(32, machine.Pin.OUT)

ledRed.value(0)
#print(" Red: desligado")
ledYellow.value(0)
#print(" Yellow : desligado")
ledGreen.value(0)
#print(" Green : desligado")
ledBlue.value(0)
#print(" Blue : desligado")


sequency = []
userSequency = []
count = 0
score = 0;

for i in range(4):
    num = random.randint(1,4)
    sequency.append(num)
       
for i in sequency:
    if i == 1:
        ledRed.value(1)
        time.sleep(2)
        ledRed.value(0)
    elif i == 2:
        ledYellow.value(1)
        time.sleep(2)
        ledYellow.value(0)
    elif i == 3:
        ledGreen.value(1)
        time.sleep(2)
        ledGreen.value(0)
    elif i == 4:
        ledBlue.value(1)
        time.sleep(2)
        ledBlue.value(0)

ledRed.value(0)
#print(" Red: desligado")
ledYellow.value(0)
#print(" Yellow : desligado")
ledGreen.value(0)
#print(" Green : desligado")
ledBlue.value(0)

while True:
    #ligue os leds em padrões aleatórios
    #a ssequencooia preciaa ser a mesma
    if count == 4:
        break
    else:
        if buttonRed.value() == 1:
            #print(buttonRed.value())
            ledRed.value(1)
            print(f" Red: {ledRed.value()}")
            print(f" buttton state Red: {buttonRed.value()}")
            userSequency.append(1)
            count += 1
            
        elif buttonYellow.value() == 1:
            
            #print(buttonYellow.value())
            ledYellow.value(1)
            print(f" Yellow: {ledYellow.value()}")
            print(f" buttton state Yellow: {buttonYellow.value()}")
            userSequency.append(2)
            count += 1
            
        elif buttonGreen.value() == 1:
            
            #print(buttonGreen.value())
            ledGreen.value(1)
            print(f" Green: {ledGreen.value()}")
            print(f"buttton state Green: {buttonGreen.value()}")
            userSequency.append(3)
            count += 1
            
        elif buttonBlue.value() == 1:
            
            #print(buttonBlue.value())
            ledBlue.value(1)
            print(f" Blue: {ledBlue.value()}")
            print(f" button state Blue: {buttonBlue.value()}")
            userSequency.append(4)
            count += 1
            
        else:
            ledRed.value(0)
            #print(" Red: desligado")
            ledYellow.value(0)
            #print(" Yellow : desligado")
            ledGreen.value(0)
            #print(" Green : desligado")
            ledBlue.value(0)
            #print(" Blue : desligado")
        print(f"count: {count}")
        time.sleep(0.5)
i = 0    
while i < 4:
    print(f"i é : {i}")
    if userSequency[i] != sequency[i]:
        print("User errou o padrão")
        break
    else:
        score += 1
        if score == 4:
            print("user acertou o padrão")
    i += 1
    



