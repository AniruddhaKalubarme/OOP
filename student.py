def avg(lis):
    iSum = 0
    for i in lis:
        if(i == -1):
            continue
        iSum += i
    return iSum/len(lis)

def sort(marks):
    for i in range (0,len(marks)):
        for j in range (i,len(marks)):
            if(marks[i]>marks[j]):
                marks[i], marks[j] = marks[j], marks[i]

def LowScore(marks):
    sort(marks)
    for i in marks:
        if(i==-1):
            continue
        return i

def HighScore(marks):
    sort(marks)
    return marks[len(marks)-1]

def CountAbsent(marks):
    iCnt = 0
    for i in marks:
        if(i == -1):
            iCnt = iCnt + 1
    return iCnt


def MaxFreq(marks):
    iMax = 0
    iCnt = 1
    value = -1
    for i in range(0, len(marks)-1):
        if(marks[i] == marks[i+1] & marks[i] != -1):
            iCnt = iCnt+1
            if(iMax < iCnt):
                iMax = iCnt
                value = marks[i]
        else:
            iCnt = 0
    return value

def main():
    marks = [10,10,10,60,-1,100,30,30, 40,-1,20,80,90]
    print("The average of students are",avg(marks))
    print("The Highest marks are: ",HighScore(marks))
    print("The Lowest marks are: ",LowScore(marks))
    print("The Count of Absent are: ",CountAbsent(marks))
    print("Max freq is: ",MaxFreq(marks))


main()