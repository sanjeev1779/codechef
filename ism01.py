import math
t= math.factorial
l=[]

def su(x):
    s=0
    x= str(x)
    for i in range(len(x)):
        s= s+ (int) (x[i])
    return (s)    
        
    
for i in range(1001):
    l.append(0)

for i in range(1,1001):
    x= t(i)
    l[i]= su(x)
print(l)    
    
