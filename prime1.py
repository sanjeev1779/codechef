import math

test_cases=int(input())
for t in range(0,test_cases):
        m,num=input().split()
        m=int(m)
        num=int(num)
        c=0
        a=[]
        p=[]
        for i in range(0,num+1):
            a.append(1)
        a[0]=a[1]=0

        sqrt_num=int(math.sqrt(num))    
        for i in range(0,sqrt_num+1):
            if(a[i]==1):
                k=1
                j=i*i
                while(j<=num):
                    a[j]=0
                    j=i*i+k*i
                    k=k+1
        for i in range(m,num+1):
            if(a[i]==1):
                c=c+1
                p.append(i)
        lp=len(p)
        for i in range(0,lp):
            print(p[i])
        print()    
                    
