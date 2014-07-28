// codeforces
#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long int
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
        //freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int n,idx,cnt_d1,maxm=0, cnt_maxm,minm,i,cnt_d2;
        cin>>n;
        vector<LL>ans;
        LL a[n+2],d1,d2;
        for(i=0;i<n;i++)
            cin>>a[i];
        if(n==1)
        {
            cout<<"-1\n";
            return 0;
        }
        sort(a,a+n);
        int flag=0,ch=0;
         d1= a[1]-a[0];
         int check=0;
         i=0;
         while(i<n-1&&a[i+1]-a[i]==d1)
         {
             i++;
         }
         //cout<<i<<" "<<a[i+1]<<" "<<a[i]<<endl;
         d2= a[i+1]-a[i];
        for(;i<n-1;i++)
        {
            int d3= a[i+1]-a[i];
            if(d3!=d1 && d3!=d2)
            {
                flag++;
            }
            if(flag>1)
            {
                break;
                ch=1;
            }
            if(flag==1 && check==0)
            {
                check=1;
                idx= i;
            }

        }
        //cout<<d1<<" "<<d2;
        if(ch==1)
        {
            printf("0\n");
            return 0;
        }
       cnt_d1=0,cnt_d2=0;
        for(i=0;i<n-1;i++)
        {
            if(a[i+1]-a[i]==d1)
                cnt_d1++;
        }
          cnt_d2= n-1-cnt_d1;
         //cout<<cnt_d1<<" "<< cnt_d2<<endl;
         if(cnt_d1==n-1)
        {
            if(d1==0) {cout<<"1\n"; cout<<a[0]<<endl;return 0;}
            else
            {
                if(n==2)
                {
                    if(d1%2==0)
                    {
                        cout<<"3\n";
                        cout<<a[0]-d1<<" "<<(a[0]+a[1])/2<<" "<<a[1]+d1<<endl;return 0;
                    }
                    else
                    {
                        cout<<"2\n";
                        cout<<a[0]-d1<<" "<<a[1]+d1<<endl;return 0;
                    }
                }
                else
                {
                         cout<<"2\n";
                        cout<<a[0]-d1<<" "<<a[n-1]+d1<<endl;
                        return 0;
                }
            }

        }

        if( cnt_d1!=1 && cnt_d1!=n-2 )
        {
            printf("0\n");
            return 0;
        }
        else
        {

            if(d1>d2)
            {
                maxm=d1;
                cnt_maxm= cnt_d1;

                minm=d2;
            }
            else {maxm=d2; minm=d1; cnt_maxm= cnt_d2;}

            if(maxm!=2*minm)
            {
                printf("0\n");
                //
                return 0;
            }
            if(cnt_maxm!=1){
                 printf("0\n");
                return 0;
            }
             cout<<"1\n";
            for(i=0;i<n-1;i++)
            {
                if(a[i+1]-a[i]== maxm)
                {
                    cout<<(a[i+1]+a[i])/2<<endl; break;
                }
            }
        }
return 0;
}
