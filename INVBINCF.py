import math
def comb(n,k):
    f=math.factorial
    com=f(n)/(f(k)*f(n-k))
    return int(com)
test_cases=int(input())
for k in range(0,test_cases):
    x=input()
    n,R=x.split()
    n=int(n)
    R=int(R)
    p=1
    div=pow(2,n)
    up=div-1
    for k in range(0,up+1):
        c=comb(up,k)
        if((c%div)==R):
                p=0
                ans=k
                break
    if(p==0):
        print(ans)
    else:
        print(-1)
