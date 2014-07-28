t=int(input())
for k in range(t):
    l=[]
    key=input()
    ln=len(key)
    n=int(input())
    for i in range(n):
        rec=input()
        l.append(rec)
    l.sort()
    #print (l)
    flag=1
    for i in range(n):
        li=len(l[i])
        if(li>=ln):
            substr=l[i][0:ln]
            if(substr==key):
                flag=0
                print (l[i])
                break
    
    if(flag==1):
        print (key)
