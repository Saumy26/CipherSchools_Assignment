def firstOccurrence(arr, x, n):
    low = 0
    high = n - 1
    ans = -1
    while (low <= high):
        mid = (low + high)//2

        if arr[mid] > x:
            high = mid - 1
        elif arr[mid] < x:
            low = mid + 1
        else:
            ans = mid
            high = mid - 1
    return ans

def lastOccurrence(arr, x, n):
    low = 0
    high = n - 1
    ans = -1
    while(low <= high):
        mid = (low + high)//2

        if arr[mid] > x:
            high = mid - 1
        elif arr[mid] < x:
            low = mid + 1 
        else:
            ans = mid
            low = mid + 1
    return ans

arr = [ 1, 3, 5, 5, 5, 5, 67, 123, 125 ]
n = len(arr)
x = 5
print("First Occurrence =", firstOccurrence(arr, x, n))
print("Last Occurrence =", lastOccurrence(arr, x, n))
