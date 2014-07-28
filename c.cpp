#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#define p1 pair<int, int>

using namespace std;

int main()
{



    pair<long, long> temp;
     map<long, long> m;
    pair<long, p1> p[100005];
    long i,j,c,s,f,n,k,idx,t,x;
    scanf("%ld",&t);
    while(t--)
    {

        scanf("%ld %ld",&n,&k);
        for(i=1;i<=n;i++)
        {
            scanf("%ld %ld %ld",&s,&f,&idx);
            temp=make_pair(s,idx);
            p[i]=make_pair(f,temp);
        }
        sort(p+1,p+n+1);
        c=0;
        for(i=1;i<=n;i++)
        {
            x=p[i].second.second;
            if(m.find(x)==m.end())
            {
                c++;
                m[x]=p[i].first;
            }
            else
            {
                if(p[i].second.first>=m[x])
                {
                    c++;
                    m[x]=p[i].first;
                }
            }
        }
        printf("%ld\n",c);
        m.clear();
    }
return 0;
}
