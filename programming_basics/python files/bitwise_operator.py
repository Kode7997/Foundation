
def playBitwise(num: int, idx: int):

    print(num, idx)
    temp = num 

    num2 = num & (1 << idx)
    print("and: ",num2)

    num = temp
    num2 = num << idx
    print("left: ",num2)

    num = temp
    num2 = num | (1 << idx)
    print("left or: ",num2)

    num = temp
    num2 = num >> idx
    print("right: ",num2)

    a = 5
    b = 5
    #check if two number are equal using bitwise XOR operator
    print("if equal: ", True if not (a ^ b) else False)
    
    

if __name__ == "__main__":
    playBitwise(5,2)