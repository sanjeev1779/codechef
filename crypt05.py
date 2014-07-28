while(1):
    n= int(input())
    if(n!=0):
        x=1
        y=1
        if(n==1 or n==2):
            z=1
        for i in range(2,n):
            z=x+y
            x,y=y,z#swap
        print (z)
    else:
        break
