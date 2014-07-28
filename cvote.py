n,m= input().split()
n= int(n)
m= int(m)
country=[]
name=[]
vote_name=[]      
for i in range(n):
    x= input()
    name,desh= x.split()
    country.append(desh)
for i in range(m):
    x= input()
    vote_name.append(x)
l_len= len(country)
maxm=0
country.sort()
ans=""
for i in range(0,l_len):
        num=1
        flag=1
        j=i
        for j in range(i,l_len-1):
            if(country[j]==country[j+1]):
                num=num+1
            else:
                break
        i=j+1    
        if(num>maxm):
            ans=country[i-1]
            maxm=num
print( ans)
l_len= len(vote_name)
maxm=0
vote_name.sort()
flag=0
ans=""
for i in range(0,l_len-1):
        num=1
        flag=1
        j=i
        for j in range(i,l_len-1):
            if(vote_name[j]==vote_name[j+1]):
                num=num+1
            else:
                break
        i=j+1    
        if(num>maxm):
            ans=vote_name[i-1]
            maxm=num
print(ans)
