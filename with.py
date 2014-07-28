def gcd(a,b):
    temp = a%b;
    if(temp==0):
        return(b);
    else:
       return(gcd(b, temp))

t=int(input())
for k in range(t):
    n=int(input())
    maxim=0.5
    for i in range(2,n+1):
        phi=0
        j=i
        for p in range(1,j+1):
            if(gcd(j,p)==1):
                phi=phi+1
        #print("phi=", phi,i)
        check=(float)(phi/i)
        #print(check)
       # print('{.3f}'.format(check))
        if(check>=maxim):
            maxim=check
            ans=i
            
    print (ans)
