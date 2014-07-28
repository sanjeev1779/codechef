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
    int test_cases,i,j,R,C,left[503][503],right[503][503],top,bottom,minm,minm1,minm2,x,y,k;
    int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509};
    S(test_cases);
    string str;
    int a[503][503];
    while(test_cases--)
    {
        S(R);
        S(C);
        vector<int>vech[R+1];
        vector<int>vecv[C+1];
        memset(a,0,sizeof(a));
        int k=0;

        for(j=1;j<=C;j++)
            vecv[j].pb(0);
        for(i=1;i<=R;i++)
        {
            cin>>str;
            vech[i].pb(0);

            for(j=1;j<=C;j++)
            {

                if(str[j-1]=='^')
                   {
                       a[i][j]=1;

                   }
                else
                   {
                        a[i][j]=0;

                        vech[i].pb(j); //horizontal entry
                        vecv[j].pb(i); //vertical entry
                   }
            }
            vech[i].pb(C+1);
        }
          for(j=1;j<=C;j++)
            vecv[j].pb(R+1);

        int ans=0;
        int x=0;
        int y=0;
    /*    for(i=1;i<=R;i++)
        {
            for(j=1;j<=C;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
        cout<<"\n B matrix\n";
        for(i=1;i<=C;i++)
        {
            for(j=1;j<=R;j++)
                cout<<b[i][j]<<" ";
            cout<<endl;
        }

        cout<<"\n  hor\n";
        for(i=1;i<=R;i++)
        {
            for(j=0;j<vech[i].size();j++)
                cout<<vech[i][j]<<" ";
            cout<<endl;
        }
        cout<<"\n ver mar\n";
        for(i=1;i<=C;i++)
        {
            for(j=0;j<vecv[i].size();j++)
                cout<<vecv[i][j]<<" ";
            cout<<endl;
        }*/
        for(i=1;i<=R;i++)
        {
            x=0;
            y=0;
            for(j=1;j<=C;j++)
            {
                    if(a[i][j]==1)
                    {

                        left[i][j]= j-vech[i][x]-1;
                        right[i][j]= vech[i][x+1]-j-1;


                    }
                    else
                    {
                            x++;
                    }


            }
        }

        for(i=1;i<=C;i++)
        {
            x=0;
            for(j=1;j<=R;j++)
            {
                if(a[j][i]==1)
                {

                    top= j-vecv[i][x]-1;
                    bottom= vecv[i][x+1]-j-1;
                    minm=min(left[j][i],min(right[j][i],min(top,bottom)));
                       // cout<<"for i and j= "<<i<<" and "<<j<<"left= "<<left[j][i]<<"right="<<right[j][i]<<"top="<<top<<"bottom="<<bottom<<endl;

                        for(k=0;primes[k]<=minm;k++)
                        {
                            ans++;
                        }
                }
                else
                    x++;
            }
        }
        cout<<ans<<endl;
    }

return 0;
}
