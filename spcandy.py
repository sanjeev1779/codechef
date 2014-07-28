t = int(input())
for i in range(t):
    x= input()
    n,k= x.split();
    n= int(n)
    k= int(k)
    if(k!=0 and n!=0):
        ans= n/k
        rem= n%k
        print (int(ans), rem)
    else:
        if(k==0):
            print (0,n)
        else:
            print(0,0)
