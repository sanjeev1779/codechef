def ispalindrome(num):
        if(reverse(num)==num):
            return 1

def reverse(num):
    rev=0
    while(num>0):
        rem=num%10
        num=int(num/10)
        rev=10*rev+rem
    return rev    
        
num=int(input())
coun=0
if(ispalindrome(num)==1):
    print (num)
else:
    while(1):
        x=0
        coun=coun+1
        if(coun>100):
            print('NONE')
            break
        x=num+reverse(num)
       # print(x)
        if(ispalindrome(x)):
            print(x)
            break
        else:
            num=x   
