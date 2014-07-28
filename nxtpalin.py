def ispalindrome(num):
        x=str(num)
        l=len(x)
        p=1
        for i in range(0,int(l/2)):
            if(x[i]!=x[l-1-i]):
                p=0
                break
        if(p==1):
            return 1
t=int(input())
for k in range(t):
    num=int(input())
    while(1):
        if(ispalindrome(num)==1):
            print (num)
            break
        num=num+1
