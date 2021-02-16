def searchElement(arr, low, high, key): 
    if low > high: 
        return -1

    mid = (low + high)//2
    if arr[mid] == key: 
        return mid 

    if arr[low] <= arr[mid]: 
        if key >= arr[low] and key <= arr[mid]: 
            return searchElement(arr, low, mid-1, key) 
        return searchElement(arr, mid + 1, high, key) 

    if key >= arr[mid] and key <= arr[high]: 
        return searchElement(arr, mid + 1, high, key) 
    return searchElement(arr, low, mid-1, key) 

arr = [5, 6, 7, 8, 9, 10, 1, 2, 3] 
key = 3
i = searchElement(arr, 0, len(arr)-1, key) 
if i != -1: 
    print("Found at Index: % d" %i) 
else: 
    print("Not found") 
