def partition(arr, s, e):
    pivot = arr[s]
    iCnt = 0
    for i in range (s+1,e+1):
        if(arr[i]<pivot):
            iCnt = iCnt + 1

    p_index = s + iCnt
    arr[s],arr[p_index] = arr[p_index],arr[s]

    i = s
    j = e
    while(i<p_index and j>p_index):
        while(arr[i] < pivot):
            i = i+1
        while(arr[j]>pivot):
            j = j-1
        if(i<p_index and j>p_index):
            arr[i], arr[j] = arr[j], arr[i]
            i = i+1
            j = j-1

    return p_index

def Quick(arr, s, e):
    if(s>=e):
        return
    
    p = partition(arr,s,e)

    Quick(arr, s, p-1)
    Quick(arr, p+1, e)

def main():
    lis = [6,8,3,2,1,4,9,2,3]
    Quick(lis, 0, len(lis)-1)

    for i in lis:
        print(i,end=" ")

main()
