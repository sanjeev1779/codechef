import math
t=int(input())
for k in range(t):
    n=int(input())

    if(n%2==0):
        n=n-1
    ans=math.factorial(n) % 1000000007
    ans= ans/2+ 1
    print (int (ans))
