#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
using namespace std;
main()
{
    int n,i,m;
    LL l;
    LL y;
    S(n);
    S(m);
    int x=n*m-1;
    int a[x+1][2];
    for(i=0;i<x;i++)
    {
        S(a[i][0]);
        S(a[i][1]);
    }
     int flag=0;
    if(n%2==1){
        swap(n,m);
        flag=1;
    }
   // cout<<"n="<<n<<"\t m= "<<m<<endl;

    int p;
    LL total_steps= (n*m-1)*n*m;
    cout<<total_steps<<endl;
    while(x--) // each apple eaten one by one
    {
        //for(int l=1;l<=n;l++)
        int ran=n/2;
        while(ran--)
        {


            for(i=2;i<=m;i++)
              {
                  if(flag==0)
                    printf("3 ");
                  else
                    printf("1 ");
              }
           if(flag==0)
                printf("1 ");
            else
                printf("3 ");

            for(i=1;i<m;i++)
            {
              if(flag==0)
                printf("2 ");
              else
                printf("0 ");

            }

          //  vec.pb(1);
          if(flag==0)
            printf("1 ");
          else
            printf("3 ");

        }
          // printf("1 ");
    }

return 0;
}
