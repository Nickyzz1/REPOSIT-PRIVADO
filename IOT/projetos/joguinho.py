import machine
from machine import Pin
import time

# Configuração dos pinos do LCD
rs = Pin(14, Pin.OUT)
e = Pin(13, Pin.OUT)
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

def lcd_goto(linha, coluna):
    if (linha < 0 or linha > 1) or (coluna < 0 or coluna > 15):
        print("Invalid line or column. Ignoring goto command.")
        return
    address = coluna + 0x40 * linha
    lcd_command(0x80 | address)

# Inicializa o LCD
lcd_init()

# Função que limpa apenas uma linha específica do display
def clear_line(linha):
    lcd_goto(linha, 0)
    lcd_puts(" " * 16)  # Supondo um display de 16 colunas

# Posições iniciais do ";"
current_col = 15  # Última coluna do display

# Escreve "N" na posição inicial
lcd_goto(1, 0)
lcd_puts("N")

# Configuração do botão
button = machine.Pin(34, machine.Pin.IN)

# Função move() que coloca o caractere ";" na próxima posição
def move():
    global current_col
    # Limpa a coluna atual onde ";" está
    lcd_goto(1, current_col)
    lcd_puts(" ")

    # Move para a próxima coluna
    if current_col > 0:
        current_col -= 1
    else:
        current_col = 15  # Volta para a última coluna

    # Atualiza a posição de ";"
    lcd_goto(1, current_col)
    lcd_puts(";")

def jump():
    # Limpa a posição atual do "N"
    lcd_goto(1, 0)
    lcd_puts(" ")

    # Move "N" para a linha superior na mesma coluna
    lcd_goto(0, 0)
    lcd_puts("N")

    # Espera um tempo e retorna "N" para a linha inferior
    time.sleep(0.5)
    lcd_goto(0, 0)
    lcd_puts(" ")
    lcd_goto(1, 0)
    lcd_puts("N")

# Loop principal
while True:
    if button.value() == 1:
        jump()
        time.sleep(0.5)  # Debounce do botão
    move()  # Move o caractere ";" para a posição correta
    time.sleep(0.5)  # Pequena pausa para evitar loop rápido demais
