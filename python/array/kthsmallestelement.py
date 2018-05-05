def partition(arr, start, end):
    pivot = start
    while True:
        while arr[start] < arr[pivot]:
            start+=1
        while arr[end] > arr[pivot]:
            end-=1
        if start < end:
            arr[start], arr[end] = arr[end], arr[start]
        else:
            arr[pivot], arr[end] = arr[end], arr[pivot]
            j = end
            break
    return j

def kth_smallest_integer(arr, k):
    if k >= len(arr):
        #print("k is larger than array size")
        return None
    start = 0
    end = len(arr)-1
    while start < end:
        # a[j] is the jth smallest element
        j = partition(arr, start, end)
        if j == k:
            return arr[j]
        elif j<k:
            start = j+1
        else:
            end = j-1
    #not found
    return -1

if __name__ == "__main__":
    arr = [4, 21, 36, 27, 0, 9, 1, 67]
    print(kth_smallest_integer(arr, 6))
