import machine
import time
import random
import urequests
import ujson
import network


#Credenciais do WIFI
nome = "Vivo-Internet-BF17"
senha = "78814222"

# Endereço do firebase
FIREBASE_URL = "https://iiot-7276b-default-rtdb.firebaseio.com/"
SECRET_KEY = ""

def conectarWifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    if not wlan.isconnected():
        print("Conectando no WiFi...")
        wlan.connect(nome, senha)
        while not wlan.isconnected():
            pass
    print("Wifi conectado... IP: {}".format(wlan.ifconfig()[0]))

def enviarFire(data):
    headers = {
        "Content-Type": "application/json",
        "Authorization": "Bearer " + SECRET_KEY
    }
    url = FIREBASE_URL + "/Nicolle.json"  # Coloque o seu nome
    print(url)

    response = urequests.put(url, data=ujson.dumps(data), headers=headers)
    print("Firebase Response:", response.text)
    response.close()
    
time.sleep(0.1)
conectarWifi()
    
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
hit = 0;
score = 0
rounds = 1;
Continue = False
end = 4

player = input("Digite seu nome: ")

def generateRandomSequency():
    for i in range(4):
        num = random.randint(1, end)
        sequency.append(num)

generateRandomSequency()

def flashSequency():
    time.sleep(1)
    for i in sequency:
        #print(f"i agora é {i}")
        if i == 1:
            ledRed.value(1)
            time.sleep(1)
            ledRed.value(0)
        elif i == 2:
            ledYellow.value(1)
            time.sleep(1)
            ledYellow.value(0)
        elif i == 3:
            ledGreen.value(1)
            time.sleep(1)
            ledGreen.value(0)
        elif i == 4:
            ledBlue.value(1)
            time.sleep(1)
            ledBlue.value(0)
              
        ledRed.value(0)
        #print(" Red: desligado")
        ledYellow.value(0)
        #print(" Yellow : desligado")
        ledGreen.value(0)
        #print(" Green : desligado")
        ledBlue.value(0)
        time.sleep(0.5) 
            
flashSequency()

ledRed.value(0)
#print(" Red: desligado")
ledYellow.value(0)
#print(" Yellow : desligado")
ledGreen.value(0)
#print(" Green : desligado")
ledBlue.value(0)

i = 0
while True:
    if buttonRed.value() == 1:
        #print(buttonRed.value())
        time.sleep(0.1)
        ledRed.value(1)
        #print(f" Red: {ledRed.value()}")
        #print(f" buttton state Red: {buttonRed.value()}")
        userSequency.append(1)
        count += 1
        
    elif buttonYellow.value() == 1:
        
        #print(buttonYellow.value())
        time.sleep(0.1)
        ledYellow.value(1)
        #print(f" Yellow: {ledYellow.value()}")
        #print(f" buttton state Yellow: {buttonYellow.value()}")
        userSequency.append(2)
        count += 1
        
    elif buttonGreen.value() == 1:
        
        #print(buttonGreen.value())
        time.sleep(0.1)
        ledGreen.value(1)
        #print(f" Green: {ledGreen.value()}")
        #print(f"buttton state Green: {buttonGreen.value()}")
        userSequency.append(3)
        count += 1
        
    elif buttonBlue.value() == 1:
        
        #print(buttonBlue.value())
        time.sleep(0.1)
        ledBlue.value(1)
        #print(f" Blue: {ledBlue.value()}")
        #print(f" button state Blue: {buttonBlue.value()}")
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
   
    time.sleep(0.5)
    if count == len(sequency):
        if userSequency[i] != sequency[i]:
            print(f"{player} errou o padrão")
            print(f"seu score foi: {score}")
            count = 0
            informacao = {
                "Player": player,
                "Score": score
            }
            enviarFire(informacao)
            break
        else:
            i += 1
            if i == len(sequency) - 1:
                #count = 0
                Continue = True
                score += 1
                print(f"{player} acertou o padrão")
                print(f"Score : {score}")
                if Continue == True:
                    rounds += 1
                    newNum = random.randint(1, end)
                    sequency.append(newNum)
                    flashSequency()
                    count = 0


