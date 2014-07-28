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
    int m,i,k,x,ans;
    char ch[11];
    cin>>ch;
    cin>>m;
    int left=0;
    int right=0;
    int j=0;
    int a[10];
    int p=1;
    for(i=0;i<10;i++)
    {
        if(ch[i]=='1')
        {
            a[j]=i+1;
            j++;
        }
    }


    left=a[0];
    ans=1;
    k=1;
    x=1;
    vector<int>vect;
    vect.pb(a[0]);
   // cout<<vect[0]<<"first";
    while(vect.size()<m)
    {

         if(vect.size()%2==1)
         {

             if(right+a[k]>left)
               {

                right+=a[k];
                vect.pb(a[k]);

                k++;
                if(k==j)
                    k=0;

               }
               else
                p=0;

         }
         if(p==1)
            break;

         else
         {

             if(left+a[k]>right)
             {

                 left+=a[k];
                vect.pb(a[k]);

                k++;
                if(k==j)
                    k=0;


             }
             else
               {
                   p=0;
               }
               if(p==1)
                break;
         }
    }
    //cout<<"\nans"<<endl;
    if(p==1)
    {
        for(i=0;i<vect.size();i++)
            cout<<vect[i]<<" ";
        cout<<endl;

    }
    else
        cout<<"NO\n";
return 0;
}
