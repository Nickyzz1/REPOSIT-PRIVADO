from machine import Pin
import machine
import time
import dht
import random
import urequests
import ujson
import network

# Configura o pino onde o DHT11 está conectado
dht_sensor = dht.DHT11(Pin(21))
buttonLed = machine.Pin(22, machine.Pin.IN)
buttonTv = machine.Pin(23, machine.Pin.IN)
led = machine.Pin(18, machine.Pin.OUT)
tv = machine.Pin(19, machine.Pin.OUT)

led.value(0)
tv.value(0)

countLed = 0
countTv = 0

#Credenciais do WIFI
nome = "Celofone da Sasá"
senha = "sasa12345"

buttonStateTv = 0
buttonStateLed = 0

tvState = 0
ledState = 0

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

def onTv():
    global countTv, buttonStateTv
    countTv += 1
    if countTv % 2 == 1:
        buttonStateTv = 1
        tv.value(1)
        return buttonStateTv
    else:
        buttonStateTv = 0
        tv.value(0)
        return buttonStateTv

def onLed():
    global countLed, buttonStateLed
    countLed += 1
    if countLed % 2 == 1:
        buttonStateLed = 1
        led.value(1)
        return buttonStateLed
    else:
        buttonStateLed = 0
        led.value(0)
        return buttonStateLed

# Função principal para ler o sensor DHT11
def read_dht11():
    while True:
        try:
            if buttonLed.value() == 1:
                global ledState
                ledState = onLed()
                print(f"led state: {ledState}")
            if buttonTv.value() == 1:
                global tvState
                tvState = onTv()
                print(f"tv state: {tvState}")
            #dht_sensor.measure()
            #temp = dht_sensor.temperature()
            #hum = dht_sensor.humidity()
            temp = "30c"
            hum = "95 %"
            informacao = {
                "LivingRoom": {
                "temperature": temp,
                "humidity": hum,
                "light": ledState,
                "tv": tvState
                },
                "Office": {
                "temperature": temp,
                "humidity": hum,
                "light": ledState,
                "tv": tvState
                },
                "PrincipalRoom": {
                "temperature": temp,
                "humidity": hum,
                "light": ledState,
                "tv": tvState
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
