import math

num = int(input("enter a value: "))

pot = num * num
inv = 1 / num
fat = 0

for i in range(1, num):
    temp = num * num - 1 #  3 * 2
    fat = temp * num - i # fat = 3 * 2
    num = num - 1 #num = 2

print(fat)
# 3
# 1*2*3