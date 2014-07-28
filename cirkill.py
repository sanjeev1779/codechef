import math
import sys
def solve():
        t= int(input())
                for ll in range(t):
                    cor=[]
                    a=[]
                    n= int(input())
                    c=0
                    for i in range(0,n):
                        l2=[]
                        for j in range(0,n):
                            l2.append(0)
                        a.append(l2)    
                    for i in range(n):
                        x= input().split()
                        l2=[]
                        l2.append( (int) (x[0]) )
                        l2.append((int) (x[1]))
                        cor.append(l2)
                        
                    for i in range(0,n):
                        for j in range(i+1,n):
                            x=  math.sqrt( (cor[j][0]-cor[i][0])*(cor[j][0]-cor[i][0])+ (cor[j][1]-cor[i][1])*(cor[j][1]-cor[i][1]) )
                            a[j][i]= a[i][j]=x
                    cnt=0
                    for i in range(0,n):
                        for j in range(i+1,n):
                            for k in range(j+1,n):
                                cnt=cnt+1
                                if(a[i][j]!=0 and  a[i][k]!=0 and a[j][k]!=0):
                                    if( (a[i][j]+ a[j][k]> a[i][k]) and ( a[i][k] + a[k][j] >a[i][j]) and ( a[i][k] + a[i][j] >a[j][k]) ):
                                        x= ( (cor[i][0]*cor[i][0]+ cor[i][1]*cor[i][1])* ( cor[j][1]- cor[k][1]) + ( cor[j][0]*cor[j][0] + cor[j][1]*cor[j][1])*( cor[k][1]-cor[i][1]) + (cor[k][0]* cor[k][0] + cor[k][1]*cor[k][1] )*(cor[i][1]- cor[j][1]) )
                                        y=  ( (cor[i][0]*cor[i][0]+ cor[i][1]*cor[i][1])* ( cor[k][0]- cor[j][0]) + ( cor[j][0]*cor[j][0] + cor[j][1]*cor[j][1])*( cor[i][0]-cor[k][0]) + (cor[k][0]* cor[k][0] + cor[k][1]*cor[k][1] )*(cor[j][0]- cor[i][0]) )
                                        z= 2*( cor[i][0]*( cor[j][1]- cor[k][1]) + cor[j][0]*( cor[k][1]- cor[i][1]) + cor[k][0]*( cor[i][1]- cor[j][1]) )
                                        R= math.sqrt( (cor[i][0]- x/z)*(cor[i][0]- x/z) + (cor[i][1]- y/z)*(cor[i][1]- y/z) )
                                        for m in range(n):
                                            dis_centre_ash = math.sqrt( (cor[m][0]-x/z)*(cor[m][0]-x/z) + (cor[m][1]-y/z)*(cor[m][1]-y/z) )
                                            if( dis_centre_ash<=R):
                                                c=c+1
                                        c=c-3
                    ans= c/(cnt*(n-3))
                    print (ans)
def main():
    solve()
    return 0
