import math
def comb(n,k):
    f=math.factorial
    com=f(n)/(f(k)*f(n-k))
    return com


t=int(input())
for l in range(0,t):
    x=input()
    S,N,M,K=x.split()
    S=int(S)
    N=int(N)
    M=int(M)
    K=int(K)
    if(N<K+1):
        print('0.000000')
    elif(N==S):
        print('1.000000')
    else:
        ans=0
        #ran_up_lt=min(N-1,M-1)+1
        ran_up_lt=min(N,M)
        for x in range(K,ran_up_lt):
            each= comb(S-M,N-1-x)*comb(M-1,x)/comb(S-1,N-1)
            x=x+1
            ans=ans+ each   
        print ('{:.6f}'.format(ans))
