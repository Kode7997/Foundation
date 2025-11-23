
def matrx_operation(matrx1, matrx2):

    for i in range(len(matrx1)):
        for j in range(len(matrx1[0])):
            print(matrx1[i][j])


if __name__ == '__main__':
    matrx1 = [[10,20,30],[40,50,60]]
    matrx2 = [[1,2,3],[4,5,6]]

    matrx_operation(matrx1, matrx2)