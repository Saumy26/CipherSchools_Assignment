def inversion(arr, n):
    count = 0
    for i in range(n):
        for j in range(i+1, n):
            if (arr[i] > arr[j]):
                count = count+1
    return count

arr = [8, 4, 2, 1]
n = len(arr)
print(inversion(arr, n))
