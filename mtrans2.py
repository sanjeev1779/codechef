x=int(input())
l=[]
for i in range(x):
    y=input()
    r,c=y.split()
    r=int(r)
    c=int(c)
    x=input()
    l.append(x)
    print (zip(*l))
        
