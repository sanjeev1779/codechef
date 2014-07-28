t= int(input())

for k in range(0,t):
    x=input()
    A,B=x.split()
    p=1
    for j in range(0,5):
        if(A[0+j:5+j]==B):
            p=0
            break
    if(p==0):
        print(1)
    else:
        print(0)
    
        
