from machine import Pin
import machine
import time
import dht
import random
import urequests
import ujson
import network

# living room
buttonLedLR = machine.Pin(2, machine.Pin.IN)
buttonTvLR = machine.Pin(4, machine.Pin.IN)
ledLR = machine.Pin(26, machine.Pin.OUT)
tvLR = machine.Pin(25, machine.Pin.OUT)

ledLR.value(0)
tvLR.value(0)

tvStateLR = 0
ledStateLR = 0
countTvLR = 0
buttonStateTvLR = 0
countLedLR = 0
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
countTvOF = 0
buttonStateTvOF = 0
countLedOF = 0
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
countTvPR = 0
buttonStateTvPR = 0
countLedPR = 0
buttonStateLedPR = 0

# Credenciais do WIFI
nome = "Celofone da Sasá"
senha = "sasa12345"

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

# living room
# ligar tv
def onTvLR():
    global countTvLR, buttonStateTvLR
    countTvLR += 1
    if countTvLR % 2 == 1:
        buttonStateTvLR = 1
        tvLR.value(1)
        return buttonStateTvLR
    else:
        buttonStateTvLR = 0
        tvLR.value(0)
        return buttonStateTvLR

# ligar luz
def onLedLR():
    global countLedLR, buttonStateLedLR
    countLedLR += 1
    if countLedLR % 2 == 1:
        buttonStateLedLR = 1
        ledLR.value(1)
        return buttonStateLedLR
    else:
        buttonStateLedLR = 0
        ledLR.value(0)
        return buttonStateLedLR
    
#office
# ligar luz
def onLedOF():
    global countLedOF, buttonStateLedOF
    countLedOF += 1
    if countLedOF % 2 == 1:
        buttonStateLedOF = 1
        ledOF.value(1)
        return buttonStateLedOF
    else: 
        buttonStateLedOF = 0
        ledOF.value(0)
        return buttonStateLedOF
    
# ligar tv
def onTvOF():
    global countTvOF, buttonStateTvOF
    countTvOF += 1
    if countTvOF % 2 == 1:
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
    global countTvPR, buttonStateTvPR
    countTvPR += 1
    if countTvPR % 2 == 1:
        buttonStateTvPR = 1
        tvPR.value(1)
        return buttonStateTvPR
    else:
        buttonStateTvPR = 0
        tvPR.value(0)
        return buttonStateTvPR

# ligar luz
def onLedPR():
    global countLedPR, buttonStateLedPR
    countLedPR += 1
    if countLedPR % 2 == 1:
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
            # living room
            if buttonLedLR.value() == 1:
                global ledStateLR
                ledStateLR = onLedLR()
                print(f"led state: {ledStateLR}")
            if buttonTvLR.value() == 1:
                global tvStateLR
                tvStateLR = onTvLR()
                print(f"tv state: {tvStateLR}")
                
            # office
            if buttonLedOF.value() == 1:
                global ledStateOF
                ledStateOF = onLedOF()
                print(f"led state: {ledStateOF}")
            if buttonTvOF.value() == 1:
                global tvStateOF
                tvStateOF = onTvOF()
                print(f"tv state: {tvStateOF}")
                
            # principal room
            if buttonLedPR.value() == 1:
                global ledStatePR
                ledStatePR = onLedPR()
                print(f"led state: {ledStatePR}")
            if buttonTvPR.value() == 1:
                global tvStatePR
                tvStatePR = onTvPR()
                print(f"tv state: {tvStatePR}")
                
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
            print("Falha na leitura do sensor:", e)

        # Aguarda dois segundos antes de ler novamente
        time.sleep(1)

# Chama a função principal
read_dht11()
