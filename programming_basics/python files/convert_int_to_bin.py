

def convert_int_to_bin(n):
    num = n
    if n == 0:
        return 0
    
    binary = ''
    while n > 0:

        binary = str(n%2) + binary
        n = n // 2
    
    print(f"binary of n: {num} is {binary}")

    print(f"binary to integer")

    integer = 0
    binary = binary[::-1] #reverse the binary
    for i, digit in enumerate(binary):
        print(i, digit)
        if digit == str(1):
            integer = integer + ( 2 ** i)
    
    print("Integer: ", integer)





if __name__ == '__main__':
    convert_int_to_bin(1)