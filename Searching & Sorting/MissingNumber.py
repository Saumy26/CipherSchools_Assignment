def missingNo(n):
    x = len(n)
    total = (x + 1)*(x + 2)/2
    sum_of_x = sum(n)
    return int(total - sum_of_x)
 
x = [1, 2, 4, 6, 3, 7, 8]
m = missingNo(x)
print(m)
