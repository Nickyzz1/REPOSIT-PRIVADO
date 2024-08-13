from machine import Pin
import machine
import time
import dht
import random
import urequests
import ujson
import network

global recivedData

# living room
buttonLedLR = machine.Pin(2, machine.Pin.IN)
buttonTvLR = machine.Pin(4, machine.Pin.IN)
ledLR = machine.Pin(26, machine.Pin.OUT)
tvLR = machine.Pin(25, machine.Pin.OUT)

ledLR.value(0)
tvLR.value(0)

tvStateLR = 0
ledStateLR = 0
onTvLR = False
onLedLR = False
buttonStateTvLR = 0
buttonStateLedLR = 0

# office
buttonLedOF = machine.Pin(5, machine.Pin.IN)
buttonTvOF = machine.Pin(18, machine.Pin.IN)
ledOF = machine.Pin(33, machine.Pin.OUT)
tvOF = machine.Pin(32, machine.Pin.OUT)

ledOF.value(0)
tvOF.value(0)

tvStateOF = 0
ledStateOF = 0
onTvOF = False
onLedOF = False
buttonStateTvOF = 0
buttonStateLedOF = 0

# principalRoom
buttonLedPR = machine.Pin(19, machine.Pin.IN)
buttonTvPR = machine.Pin(21, machine.Pin.IN)
ledPR = machine.Pin(12, machine.Pin.OUT)
tvPR = machine.Pin(14, machine.Pin.OUT)

ledPR.value(0)
tvPR.value(0)

tvStatePR = 0
ledStatePR = 0
onTvPR = False
onLedPR = False
buttonStateTvPR = 0
buttonStateLedPR = 0

# Credenciais do WIFI
nome = "Wifi Amilton"
senha = "87654321"

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
    
def reciveFire():
    headers = {
        "Content-Type": "application/json",
        "Authorization": "Bearer " + SECRET_KEY
    }
    url = FIREBASE_URL + "/Nicolle.json" 
    print(url)

    response = urequests.get(url, headers=headers)
    dataResponse = ujson.loads(response.text)
    response.close()
    return dataResponse

# living room
# ligar tv
def onTvLR(onTvLr):
    global buttonStateTvLR
    if onTvLR == True or recivedData["LivingRoom"]["tv"] == 1:
        buttonStateTvLR = 1
        tvLR.value(1)
        onTvLR == False
        return buttonStateTvLR
    else:
        buttonStateTvLR = 0
        tvLR.value(0)
        return buttonStateTvLR

# ligar luz
def onLedLR():
    global countLedLR, buttonStateLedLR
    countLedLR += 1
    if countLedLR % 2 == 1 or recivedData["LivingRoom"]["light"] == 1:
        buttonStateLedLR = 1
        ledLR.value(1)
        return buttonStateLedLR
    else:
        buttonStateLedLR = 0
        ledLR.value(0)
        return buttonStateLedLR
    
# office
# ligar luz
def onLedOF():
    global onLedOF, buttonStateLedOF
    onLedOF += 1
    if onLedOF % 2 == 1 or recivedData["Office"]["light"] == 1 :
        buttonStateLedOF = 1
        ledOF.value(1)
        return buttonStateLedOF
    else: 
        buttonStateLedOF = 0
        ledOF.value(0)
        return buttonStateLedOF
    
# ligar tv
def onTvOF():
    global onTvOF, buttonStateTvOF
    onTvOF += 1
    if onTvOF % 2 == 1 or recivedData["Office"]["tv"] == 1:
        buttonStateTvOF = 1
        tvOF.value(1)
        return buttonStateTvOF
    else:
        buttonStateTvOF = 0
        tvOF.value(0)
        return buttonStateTvOF

# principal room   
# ligar tv
def onTvPR():
    global onTvPR, buttonStateTvPR
    onTvPR += 1
    if onTvPR % 2 == 1 or recivedData["PrincipalRoom"]["light"] == 1:
        buttonStateTvPR = 1
        tvPR.value(1)
        return buttonStateTvPR
    else:
        buttonStateTvPR = 0
        tvPR.value(0)
        return buttonStateTvPR

# ligar luz
def onLedPR():
    global onLedPR, buttonStateLedPR
    onLedPR += 1
    if onLedPR % 2 == 1 or recivedData["PrinciRoom"]["light"] == 1:
        buttonStateLedPR = 1
        ledPR.value(1)
        return buttonStateLedPR
    else:
        buttonStateLedPR = 0
        ledPR.value(0)
        return buttonStateLedPR

# Função principal para ler o sensor DHT11
def read_dht11():
    while True:
        try:
            # Recebe dados do Firebase
            recivedData = reciveFire()

            # living room
            if buttonLedLR.value() == 1:
                onLedLR = not onLedLR
            if buttonLedOF.value() == 1:
                onLedOF = not onLedOF
            if buttonLedPR.value() == 1:
                onLedPR = not onLedPR
            # dht_sensor.measure()
            # temp = dht_sensor.temperature()
            # hum = dht_sensor.humidity()
            
            temp = "30c"
            hum = "95 %"
            informacao = {
                "LivingRoom": {
                    "temperature": temp,
                    "humidity": hum,
                    "light": ledStateLR,
                    "tv": tvStateLR
                },
                "Office": {
                    "temperature": temp,
                    "humidity": hum,
                    "light": ledStateOF,
                    "tv": tvStateOF
                },
                "PrincipalRoom": {
                    "temperature": temp,
                    "humidity": hum,
                    "light": ledStatePR,
                    "tv": tvStatePR
                }
            }
            conectarWifi()
            enviarFire(informacao)

            print("Temperatura: {}°C  Umidade: {}%".format(temp, hum))
        except OSError as e:
            print(e)

        # Aguarda dois segundos antes de ler novamente
        time.sleep(2)

# Chama a função principal
read_dht11()

