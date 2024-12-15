#1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9

def TakeInput(lis):
    for i in range (3):
        for j in range (3):
            lis[i][j] = int(input("enter the number: "))

def addition(lis1, lis2):
    for i in range (3):
        for j in range (3):
            print(lis1[i][j] + lis2[i][j], end="\t")
        print()

def subtraction(lis1, lis2):
    for i in range (3):
        for j in range (3):
            print(lis1[i][j] - lis2[i][j], end="\t")
        print()

def Transpose(lis):
    for i in range(3):
        for j in range(3):
            print(lis[j][i],end="\t")
        print()

def Multiplication(lis1, lis2):
    for i in range (3):
        for j in range (3):
            iSum = 0
            for k in range (3):
                iSum += lis1[i][k] * lis2[k][j]
            print(iSum,end="\t")
        print()

def main():
    lis1 = [[0,0,0],[0,0,0],[0,0,0]]
    lis2 = [[0,0,0],[0,0,0],[0,0,0]]
    TakeInput(lis1)
    TakeInput(lis2)

    addition(lis1, lis2)
    print()
    subtraction(lis1, lis2)
    print()
    Multiplication(lis1, lis2)
    print()
    Transpose(lis1)

main()
