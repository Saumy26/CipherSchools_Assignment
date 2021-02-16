def maxWater(arr, n):
    res = 0
    lmax = 0
    rmax = 0
    low = 0
    high = n-1

    while(low<=high): 
        if(arr[low] < arr[high]):
            if(arr[low] > lmax):
                lmax = arr[low]
            else:
                res = res + lmax - arr[low]
                low = low + 1
        else:
            if(arr[high] > rmax):
                rmax = arr[high]
            else:
                res = res + rmax - arr[high]
            high = high - 1
            
    return res

arr = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
n = len(arr)

print("Max Rain Water that can be Stored : ", maxWater(arr, n))
