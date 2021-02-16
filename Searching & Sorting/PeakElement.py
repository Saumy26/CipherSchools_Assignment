def peakElement(arr, n) :
    if (n == 1) :
        return arr[0]
    if (arr[0] >= arr[1]) :
        return 0
    if (arr[n - 1] >= arr[n - 2]) :
        return n - 1

    for i in range(1, n - 1) :
        if (arr[i] >= arr[i - 1] and arr[i] >= arr[i + 1]) :
            return i

arr = [ 10, 20, 15, 16, 23, 2 ]
n = len(arr)
print(arr[peakElement(arr, n)])
