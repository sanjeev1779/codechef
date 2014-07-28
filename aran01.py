t=int(input())
for i in range(0,t):
    w=input()
    l=len(w)
    s=0
    for j in range(0,l):
        s=s+ord(w[j])
    p=int(s/l)    
    print(chr(p))
        
