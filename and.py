n =int(input())
a= map(int,raw_input().split())
ans=0
for i in range(0,n):
    for j in range(i+1,n):
        ans=ans+ (a[i]&a[j])
print(ans)
