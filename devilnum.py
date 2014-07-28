t=int(input())
for k in range(t):
    n=int(input())
    n=str(n)
    first_num= (int) (n[0:1])
    if(first_num>3):
        first_num=3
    l=len(n)
    num= (str) (first_num)
    for i in range(0,l-1):
        num=num+'3'
    num=(int)(num) 
    print (num)    
