import time

def counter(start, end, step):
    # print(start)
    # print(end)
    # print(step)
    if start > end:
        for i in range(start, end - 1, -step):
            print(i)
            time.sleep(0.5)
    else:
        for i in range(start, end + 1, step):
            print(i)
            time.sleep(0.5)

def main():
    start = int(input("enter a start:\n--"))
    end = int(input("enter a end:\n--"))
    step = int(input("enter a step:\n--"))
    counter(start, end, step)

main()

