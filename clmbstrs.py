def fibo(num):
    if(num<2):
        return 1
    else:
        return fibo(num-1)+fibo(num-2)
l=[]
for i in range(1,100000):
    x=fibo(i)
    print (x)
    l.append(x)  
