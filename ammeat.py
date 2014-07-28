def sep(s):
    a=[]
    b=''
    for i in list(s):
        if(i==' '):
            a.append(int(b))
            b=''
        b=b+i
    if(b!=' '):
        a.append(int(b))    
    return(a)

t=int(input())
for k in range(t):
    n,m=input().split()
    n=int(n)
    m=int(m)
    x=input()
    p=sep(x)
    p.sort()
    p.reverse()
    i=0
    su=0
    flag=1
    l=len(p)
    for i in range(l):
        su=su+p[i]
        if(su>=m):
            flag=0
            break
        else:
            i=i+1
    if(flag==0):
        print(i+1)
    else:
        print(-1)
