def SelectionSort(list):
    for i in range (0,len(list)-1):
        iMin = list[i]
        index = i
        for j in range(i+1,len(list)):
            if(iMin > list[j]):
                iMin = list[j]
                index = j
        list[i], list[index] = list[index], list[i]        

def BubbleSort(list):
    for i in range(0, len(list)-1):
        for j in range(0,len(list)-i-1):
            if(list[j] > list[j+1]):
                list[j], list[j+1] = list[j+1], list[j]

def main():
    marks = [2.3,3.6,3.8,2.1,33.3,6.9,65.1,86.5]
    # SelectionSort(marks)
    BubbleSort(marks)
    for i in marks:
        print(i,end=' -> ')

main()