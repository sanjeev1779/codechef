def sep(s):
    a=[]
    b=''
    for i in list(s):
        if(i==' ' or i=='\n'):
            a.append(int(b))
            b=''
        b=b+i
    return(a)

t=int(input())
for k in range(t):
    L=int(input())
    x=input()
    n=sep(x)
    maxm=n[0]
    for i in range(1,L):
        if(n[i]>maxm):
            p=0
            ans=i+1
    if(p==0):
        print(ans)
    else:
        print(1)
