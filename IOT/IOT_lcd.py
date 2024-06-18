from machine import Pin
import time

# Configuração dos pinos do LCD
rs = Pin(14, Pin.OUT)
e = Pin(13,
        Pin.OUT)
d4 = Pin(12, Pin.OUT)
d5 = Pin(27, Pin.OUT)
d6 = Pin(26, Pin.OUT)
d7 = Pin(25, Pin.OUT)

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

def lcd_puts(text):
    for char in text:
        lcd_data(ord(char))

# Inicializa o LCD
lcd_init()


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
    send_nibble(data >> 4)  # Send upper nibble
    send_nibble(data & 0x0F)  # Send lower nibble

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
    lcd_command(0x28)  # Function set: 4 bits, 2 lines, 5x8 dots
    lcd_command(0x0C)  # Display on, cursor off, blink off
    lcd_command(0x06)  # Entry mode set: increment & no shift
    lcd_command(0x01)  # Clear display
    time.sleep_ms(2)

def lcd_puts(text):
    for char in text:
        lcd_data(ord(char))

def lcd_goto(linha, coluna):
    if (linha < 0 or linha > 1) or (coluna < 0):
        print("Invalid line or column. Ignoring goto command.")
        return
    if linha == 0:
        max_coluna = 14  # 15 characters on line 0
    else:
        max_coluna = 15  # 16 characters on line 1


    if coluna > max_coluna:
        coluna = max_coluna


    address = (linha * 0x40) + coluna  
    lcd_command(0x80 | address)  

# Escreve no display
lcd_goto(0, 0)
lcd_puts("welcome!")