#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string.h>
#define LL long long
#define maxm 10000000
using namespace std;


int det(int a1,int a2,int a3,int a4, int a5, int a6, int a7, int a8, int a9)
{
    int det_val= a1*(a5*a9 - a8*a6) - a2*(a4*a9-a6*a7)+ a3*(a4*a8-a5*a7);
    return det_val;
}
main()
{
    int c,n,i,j,k,m,fourth,first,second,third,val;
    double ans=0.0;
    int cor[30][2];
    int test_cases;
    scanf("%d",&test_cases);
    while(test_cases--)
    {
        c=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&cor[i][0],&cor[i][1]);
        }


        int cnt=0;
        for(i=0;i<n-2;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    cnt++;
                   int area= abs(cor[i][0]*(cor[j][1]-cor[k][1]) + cor[j][0]*(cor[k][1]-cor[i][1]) + cor[k][0]*(cor[i][1]-cor[j][1]));

                        if( area!=0 )// forms a circle
                        {

                                for(m=0;m<n;m++)
                                {
                                    if(m==i || m==j || m==k) continue;
                                    else
                                    {
                                        first = (cor[m][0]*cor[m][0]+ cor[m][1]*cor[m][1])* det(cor[i][0],cor[i][1],1,cor[j][0],cor[j][1],1,cor[k][0],cor[k][1],1);
                                        second= cor[m][0]* det((cor[i][0]*cor[i][0]+ cor[i][1]*cor[i][1]), cor[i][1],1, (cor[j][0]*cor[j][0]+ cor[j][1]*cor[j][1]), cor[j][1],1, (cor[k][0]*cor[k][0]+ cor[k][1]*cor[k][1]), cor[k][1],1);
                                        third= cor[m][1]*det((cor[i][0]*cor[i][0]+ cor[i][1]*cor[i][1]), cor[i][0],1, (cor[j][0]*cor[j][0]+ cor[j][1]*cor[j][1]), cor[j][0],1, (cor[k][0]*cor[k][0]+ cor[k][1]*cor[k][1]), cor[k][0],1);
                                        fourth= det((cor[i][0]*cor[i][0]+ cor[i][1]*cor[i][1]), cor[i][0],cor[i][1], (cor[j][0]*cor[j][0]+ cor[j][1]*cor[j][1]),cor[j][0], cor[j][1], (cor[k][0]*cor[k][0]+ cor[k][1]*cor[k][1]), cor[k][0],cor[k][1]);

                                        val= first- second+third-fourth;
                                        if(val<=0)
                                            c++;
                                    }
                                }


                    }
                }
            }
        }

printf("total number killed places=%d  and total place = %d\n",cnt*(n-3),c);
        ans=  (double)c/ (double)(cnt*(n-3));
        printf("%.6lf\n",ans);

    }
return 0;
}
