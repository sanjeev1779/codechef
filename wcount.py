import math
t=math.factorial
mod=1000000007
t=int(input())
for k in range(t):
    a=[]
    x=input()
    l= len(x)
    div=1
    for i in range(125):
        a.append(0)
    for i in x:
        a[ord(i)]=a[ord(i)]+1
    for j in range(65,123):
        div=(div*math.factorial(a[j])) % mod
    ans= (math.factorial(l)%mod )/div
    print (int (ans%mod) )    
    
        
