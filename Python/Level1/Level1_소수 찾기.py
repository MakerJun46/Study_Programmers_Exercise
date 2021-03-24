import math

def solution(n):
    isPrime = [False, False] + [True] * (n-1)

    maxNum = int(math.sqrt(n))

    
    for i in range(2, maxNum + 1) :
        if isPrime[i] :
            for j in range(i+i, n + 1, i) :
                isPrime[j] = False
    
    return isPrime.count(True)


#best Answer
"""
def solution(n):
    num=set(range(2,n+1))

    for i in range(2,n+1):
        if i in num:
            num-=set(range(2*i,n+1,i))
    return len(num)
"""
