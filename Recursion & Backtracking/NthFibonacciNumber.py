class Solution:
    def nthFibonacci (ob, n):
	    fib = [0, 1] 
	    for i in range(2, n+1):
		    fib.append((fib[i-1] + fib[i-2])%1000000007)
	    return fib[n]
	

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n = int(input())
        
        ob = Solution()
        print(ob.nthFibonacci(n))
