n= int(input())
times=[]
for i in range(100001):
        times.append(0)
l= map(int,raw_input().split())
for i in range(l):
        times[l[i]]= times[l[i]]+1
        
right=[]
left=[]
while(len(l)>n-490):
        l_len= len(l)
        key=l[l_len-1]
        flag=1
        for i in range(l_len-2,-1,-1):
            #print("key=",key,"and ","li=",l[i])
            if(l[i]==key):
                diff=i
                flag=0
                left.append(i+1)
                right.append(l_len-1-i)
               # print("dual=",i+1,l_len-i-1)
                x=l.pop(l_len-1)
                y=l.pop(i)
                #print("popped= ",x,y)
                break
        if(flag==1):
            left.append(l_len)
            right.append(1)
            x=l.pop(l_len-1)
            #print("popped= ",x)
            #print(l_len,1)
            
            
n= len(right)
x=  len(l)
print(n+x)
for i in range(n):
    y=str(left[i])+" "+str(right[i])
    print(y)
for i in range(x,0,-1):
        y=str(i)+" 1"
        print(y)
                
                
            
