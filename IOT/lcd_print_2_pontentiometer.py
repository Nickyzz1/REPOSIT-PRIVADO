from machine import Pin, ADC
import time

# Configuração do ADC
adc = ADC(Pin(34))
adc.width(ADC.WIDTH_12BIT)
adc.atten(ADC.ATTN_11DB)

# Configuração dos pinos do LCD
rs = Pin(14, Pin.OUT)
e = Pin(12, Pin.OUT)
d4 = Pin(27, Pin.OUT)
d5 = Pin(26, Pin.OUT)
d6 = Pin(25, Pin.OUT)
d7 = Pin(33, Pin.OUT)

def pulse_enable():
    e.on()
    time.sleep_us(1)
    e.off()
    time.sleep_us(50)

def send_nibble(data):
    d4.value((data >> 0) & 1)
    d5.value((data >> 1) & 1)
    d6.value((data >> 2) & 1)
    d7.value((data >> 3) & 1)
    pulse_enable()

def send_byte(data, rs_value):
    rs.value(rs_value)
    send_nibble(data >> 4)  # Envia o nibble superior
    send_nibble(data & 0x0F)  # Envia o nibble inferior

def lcd_command(cmd):
    send_byte(cmd, 0)

def lcd_data(data):
    send_byte(data, 1)

def lcd_init():
    time.sleep(0.05)
    rs.off()
    e.off()
    send_nibble(0x03)
    time.sleep_ms(5)
    send_nibble(0x03)
    time.sleep_us(150)
    send_nibble(0x03)
    send_nibble(0x02)
    lcd_command(0x28)  # Função set: 4 bits, 2 linhas, 5x8 pontos
    lcd_command(0x0C)  # Display on, cursor off, blink off
    lcd_command(0x06)  # Entry mode set: incrementa e sem shift
    lcd_command(0x01)  # Limpa o display
    time.sleep_ms(2)

def lcd_clear():
    lcd_command(0x01)  # Limpa o display
    time.sleep_ms(5)

def lcd_puts(text):
    for char in text:
        lcd_data(ord(char))

# Inicializa o LCD
lcd_init()

while True:
    lcd_clear()
    pot_value = round(adc.read() * 15 / 4095)
    if pot_value == round(15):
        print(pot_value)
        time.sleep(1)
        lcd_puts("N")
        time.sleep(1)
    elif pot_value == 0:
        time.sleep(1)
        lcd_puts("I")
        time.sleep(1)
    elif pot_value == round(1):
        time.sleep(1)
        lcd_puts("C")
        time.sleep(1)
    elif pot_value == round(2):
        time.sleep(1)
        lcd_puts("O")
        time.sleep(1)
    elif pot_value == round(3):
        time.sleep(1)
        lcd_puts("L")
        time.sleep(1)
    elif  pot_value == round(4):
        time.sleep(1)
        lcd_puts("L")
        time.sleep(1)
    elif  pot_value == round(5):
        time.sleep(1)
        lcd_puts("E")
        time.sleep(1)
    elif  pot_value == round(6):
        time.sleep(1)
        lcd_puts("A")
        time.sleep(1)
    elif pot_value == round(7):
        time.sleep(1)
        lcd_puts("B")
        time.sleep(1)
    elif pot_value == round(8):
        time.sleep(1)
        lcd_puts("C")
        time.sleep(1)
    elif pot_value == round(9):
        time.sleep(1)
        lcd_puts("D")
        time.sleep(1)
    elif pot_value == round(10):
        time.sleep(1)
        lcd_puts("E")
        time.sleep(1)
    elif pot_value == round(11):
        time.sleep(1)
        lcd_puts("F")
        time.sleep(1)
    elif pot_value == round(12):
        time.sleep(1)
        lcd_puts("G")
        time.sleep(1)
    elif pot_value == round(13):
        time.sleep(1)
        lcd_puts("H")
        time.sleep(1)
    elif pot_value == round(14):
        time.sleep(1)
        lcd_puts("I")
        time.sleep(1)
    else:
        lcd_clear()
        print(pot_value)
        time.sleep(1)
    lcd_clear()

