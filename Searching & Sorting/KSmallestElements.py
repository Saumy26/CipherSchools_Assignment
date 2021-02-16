def smallestElements(arr, n, k): 
    for i in range(k, n): 
        maxval = arr[k-1] 
        x = k-1
        for j in range(k-2, -1, -1): 
            if (arr[j] > maxval): 
                maxval = arr[j] 
                x = j 

        if (maxval > arr[i]): 
            j = x 
            while (j < k-1): 
                arr[j] = arr[j+1] 
                j = j+1

            arr[k-1] = arr[i] 

    for i in range(0, k): 
        print(arr[i], end = " ") 

arr = [4, 2, 6, 1, 5]
k = 3
n = len(arr) 
smallestElements(arr, n, k) 

