import fractions

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


t= int(input())
for k in range(0,t):
    n=int(input())
    s=input()
    l=sep(s)
    gcd= fractions.gcd(l[0],l[1])
    for i in range(2,n):
        gcd= fractions.gcd(gcd,l[i])
        
    print(gcd)    
        
        
