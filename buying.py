def sep(s):
    a=[]
    b=''
    su=0
    for i in list(s):
        if(i==' '):
            su=su+int(b)
            a.append(int(b))
            b=''
        b=b+i
    if(b!=' '):
        a.append(int(b))
        su=su+int(b)
    return(a),su


t=int(input())
for k in range(t):
    N,X=input().split()
    N=int(N)
    X=int(X)
    #for i in range(0,N):
    a=input()
    l,su=sep(a)
    ans=int(su/X)
    rem=su%X
    p=1
    for i in l:
        if(rem>=i):
            p=0
            break
    if(p==1):
        print(ans)
    else:
        print('-1')
    
