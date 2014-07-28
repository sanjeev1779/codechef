#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define pb push_back
using namespace std;
vector<int>a;

main()
{
    vector<int>left,right;
    int N,i,j,flag,l,key,q,cd;
    scanf("%d",&N);
    a.pb(0);
    int x;
    int times[100001];
    memset(times,0,sizeof(times));
    for(i=1;i<=N;i++)
    {
        scanf("%d",&x);
        a.pb(x);
        times[x]++;
    }
    flag=1;
    for(i=a.size()-1;i>0 ;i--)
    {
        //cout<<"single element\n";
        if(times[ a[i]]==1)
        {
           // cout<<"singleton\n";
            times[a[i]]--;
            left.pb(i);
            right.pb(a.size()-1);
            a.erase(a.begin()+i);
        }
    }
    l = a.size();
   // cout<<" list size after single elements del ="<<l<<"\n";
    while(a.size()>1)
    {
        if(times[a[i]]==1)
        {
            times[a[i]]--;
            left.pb(i);
            right.pb(a.size()-1);
            a.erase(a.begin()+i);
        }
        else
        {
            key=a[a.size()-1];
            for(j=a.size()-2;j>0;j--)
            {
                if(a[j]==key)
                    break;
            }
            cd= a.size()-1-j;
            times[key]--;
            a.erase(a.begin()+(a.size()-1 ));

            while(j>0 && a[j]==key)
            {
                times[key]--;
                a.erase(a.begin()+j);
                j=j-cd;
            }
            j=j+cd; // one time cd extra added in the above while loop

            left.pb(j);
            right.pb(cd);
        }
    }

    q= left.size();
    cout<<q<<endl;
    for(i=0;i<q;i++)
    {
        printf("%d %d\n",left[i],right[i]);
    }



return 0;
}
