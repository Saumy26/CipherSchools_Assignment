def largestSubArraySum(arr, n):
    max_so_far =arr[0]
    curr_max = arr[0]
    for x in range(1, n):
        curr_max = max(arr[x], curr_max + arr[x])
        max_so_far = max(max_so_far,curr_max)
    return max_so_far

arr = [-2, -3, 4, -1, -2, 1, 5, -3]
print(largestSubArraySum(arr,len(arr)))
