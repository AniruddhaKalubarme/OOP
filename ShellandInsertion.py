def InsertionSort(arr):
    for i in range(1,len(arr)):
        num = arr[i]
        j = i-1
        while(j>=0 and arr[j]>num):
            arr[j+1] = arr[j]
            j = j - 1
        arr[j+1] = num

def ShellSort(arr):
    n = len(arr)
    gap = (len(arr)+1)//2
    while(gap>=1):
        j = gap
        while(j<n):
            i = j-gap
            while(i>=0):
                if(arr[i+gap]<arr[i]):
                    arr[i+gap],arr[i] = arr[i], arr[i+gap]
                i = i - gap
            j += 1
        if(gap == 1):
            gap = 0
        else:
            gap = (gap+1)//2
        

def main():
    list = [8,6,3,2,4,63,1]
    ShellSort(list)
    for i in list:
        print(i,end=" ")

main()