t=int(input())
for k in range(0,t):
    a,b=input().split()
    x=a.find(b)
    if(x==-1):
        print('0')
    else:
        print('1')
