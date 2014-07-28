import math
test_cases=int(input())
for k in range(0,test_cases):
    l=[]
    for i in range(3,100):
        angle=(i-2)*180/i
        check_for_int=math.floor(angle)-math.ceil(angle)
        angle=int(angle)
        if(check_for_int==0):
            l.append(angle)
            
            
    a=int(input())
    ln=len(l)
    p=1
    for i in range(0,ln):
        if(l[i]==a):
            p=0
            break
    if(p==0):
        print('YES')
    else:
        print('NO')
