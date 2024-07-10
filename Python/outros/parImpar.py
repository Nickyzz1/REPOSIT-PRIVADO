import random

user = int(input("1 - par\n2 - ímpar\n---"))
num = int(input("Emter a number behid 1 and 10:\n---"))
randomNum = random.randint(1,10)

try:
 
    if user == 1 or user == 2:
        if num < 11 and num > 0:
            while True:
                    if (num + randomNum) % 2 == 0 and user == 1:
                        print(f"User ganhou! O número da máuina foi {randomNum}")
                        break
                    elif (num + randomNum) % 2 == 1 and user == 2:
                        print(f"User ganhou! O número da máuina foi {randomNum}")
                        break
                    else:
                        print(f"User perdeu! O número da máuina foi {randomNum}")
                        break
        else:
            raise Exception
    else:
        raise Exception
except Exception as e:
    print(f"enter as valid number {e}")


