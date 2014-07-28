#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string.h>
#define LL long long
using namespace std;


main()
{
    double a[30][30];
    double add= 0.000006;
    int c,n,i,j,k,m;
    int
    double x,y,z,R,s,dis_centre_ash,ans=0;
    double cor[30][2];
    int test_cases;
    scanf("%d",&test_cases);
    while(test_cases--)
    {
        c=0;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf",&cor[i][0],&cor[i][1]);
        }

        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                a[i][j]=  sqrt( (cor[j][0]-cor[i][0])*(cor[j][0]-cor[i][0])+ (cor[j][1]-cor[i][1])*(cor[j][1]-cor[i][1]) );
                a[j][i]= a[i][j];
            }
        }
        int cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    cnt++;
                    if(a[i][j]!=0 && a[i][k]!=0 && a[j][k]!=0)
                    {
                        if( (a[i][j]+ a[j][k]> a[i][k]) && ( a[i][k] + a[k][j] >a[i][j]) && ( a[i][k] + a[i][j] >a[j][k]) )// forms a circle
                        {
                                //find the circumradius of the given circle to check the enemy lies within it or not
                               //s= (a[i][j]+a[j][k]+a[k][i])/2;
                              // R= (a[i][j]* a[j][k]* a[k][j]) / (sqrt( (s)* (a[i][j]+a[j][k]- s)* ( a[k][j] + a[i][k] - s )*( a[i][k]+ a[i][j]-s)));

                                x= ( (cor[i][0]*cor[i][0]+ cor[i][1]*cor[i][1])* ( cor[j][1]- cor[k][1]) + ( cor[j][0]*cor[j][0] + cor[j][1]*cor[j][1])*( cor[k][1]-cor[i][1]) + (cor[k][0]* cor[k][0] + cor[k][1]*cor[k][1] )*(cor[i][1]- cor[j][1]) );
                                y=  ( (cor[i][0]*cor[i][0]+ cor[i][1]*cor[i][1])* ( cor[k][0]- cor[j][0]) + ( cor[j][0]*cor[j][0] + cor[j][1]*cor[j][1])*( cor[i][0]-cor[k][0]) + (cor[k][0]* cor[k][0] + cor[k][1]*cor[k][1] )*(cor[j][0]- cor[i][0]) );
                                z= 2*( cor[i][0]*( cor[j][1]- cor[k][1]) + cor[j][0]*( cor[k][1]- cor[i][1]) + cor[k][0]*( cor[i][1]- cor[j][1]) );
                              //  cout<<"x and y corrd="<<x<<"="<<y<<endl;
                                x=  x/z ;
                                y= y/z;
                              //  cout<<x<<"=x\n";
                                //cout<<y<<"=y\n";
                                R= sqrt( (cor[i][0]- x)*(cor[i][0]- x) + (cor[i][1]- y)*(cor[i][1]- y) );
                                //cout<<"radius of the circumcircle= "<<R<<endl;


                                for(m=0;m<n;m++)
                                {
                                    if(m==i || m==j || m==k) continue;
                                    else{
                                    dis_centre_ash = sqrt( (cor[m][0]-x)*(cor[m][0]-x) + (cor[m][1]-y)*(cor[m][1]-y) );
                                  //  cout<<"distance between = "<<dis_centre_ash<<endl;
                                    if( sqrt( (cor[m][0]-x)*(cor[m][0]-x) + (cor[m][1]-y)*(cor[m][1]-y) )<=  sqrt( (cor[i][0]- x)*(cor[i][0]- x) + (cor[i][1]- y)*(cor[i][1]- y) ) + 6*pow(10,-7)|| sqrt( (cor[m][0]-x)*(cor[m][0]-x) + (cor[m][1]-y)*(cor[m][1]-y) )<=  sqrt( (cor[i][0]- x)*(cor[i][0]- x) + (cor[i][1]- y)*(cor[i][1]- y) ) - 6*pow(10,-7)  )
                                       {
                                            c++;
                                          //  cout<<"ans= "<<cor[m][0]<<" and " <<cor[m][1]<<endl;
                                       }
                                    }


                                }
                                   // cout<<"c="<<c<<"\n";
                        }
                    }
                  //  cout<<"next\n";
                }
            }
        }

       // printf("total number killed places=%d  and total place = %d\n",cnt*(n-3),c);
        ans=  (double)c/ (double)(ways[n-1]*(n-3));
        printf("%.6lf\n",ans);

    }
return 0;
}
