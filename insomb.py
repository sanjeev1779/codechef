import math
num=int(input())
x=int(math.sqrt(num)+2)
p=1
for i in range(2,x):
    if(num%i==0):
        p=0
        break
if(p==1):
    print('PRIME')
else:
    print('COMPOSITE')
