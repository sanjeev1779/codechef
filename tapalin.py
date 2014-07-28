import math
t=int(input())
for i in range(t):
    num=int(input())
    ans=0
    for k in range(1,num+1):
          k=math.ceil(k/2)
          ran=(int)(k/100)
          rem=k%100
          prod=1
          mult=449141237
          for j in range(0,ran):
              prod=prod*449141237
              prod=prod%1000000007
          rem_prod=26**rem
          print("prd=", prod)
          print("rem_prod=",rem_prod)
          prod= prod*rem_prod
          prod=prod%1000000007
          print("final prod= ",prod)
          ans=ans+prod
          ans=ans%10000007
    print (ans%1000000007)
