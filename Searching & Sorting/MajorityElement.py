def majorityElement(A, n):
    Count = 0
    x = -1 
    for i in range(n):
        c = 0
        for j in range(n):
            if(A[i] == A[j]):
                c += 1
        if(c > Count):
            Count = c
            x = i

    if (Count > n//2):
        print(A[x])

    else:
        print("No Majority Element")

if __name__ == "__main__":
    A = [3, 3, 4, 2, 4, 4, 2, 4, 4]
    n = len(A)

    majorityElement(A, n)
