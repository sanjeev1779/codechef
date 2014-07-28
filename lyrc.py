W= int(input())
wl= []
for i in range(W):
    word= input()
    wl.append(word)
N= int(input())
S=[]
for i in range(N):
    lyric = input()
    S.append(lyric)
for i in range(W):
    ans=0
    for j in range(N):
        ans=ans+S[j].count(wl[i])     
    print(ans)        
