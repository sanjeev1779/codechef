import math
f=math.factorial

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


def combo(n,k):
    comb=f(n)/(f(k)*f(n-k))
    return comb

test_cases=int(input())
for k in range(test_cases):
    s=input()
    k=int(input())
    a=sep(s)
    a.sort()
    a.reverse()
    x=1
    if(k==11):
        print(1)
    else:    
        for i in range(0,10):
            if(a[i]==a[i+1]):
                x=x+1    
            else:
                k=k-x
                if(k<0):
                    print(int(combo(x,x+k)))
                    break
                x=1   
            
