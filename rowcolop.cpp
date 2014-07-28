#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

inline int fastread()
{
        int noRead=0;
        char p=getchar_unlocked();
        for(; p<33;) {
                p=getchar_unlocked();
        };
        while(p>32) {
                noRead = (noRead << 3) + (noRead << 1) + (p - '0');
                p=getchar_unlocked();
        }
        return noRead;
};


main()
{
    int n,q,x,i;
    n=fastread();
    q=fastread();
   // scanf("%d %d",&n,&q);
     char ch[8];
     int r[n];
     int c[n];
     memset(r,0,sizeof(int)*(n));
     memset(c,0,sizeof(int)*(n));
    //vector<int> r(n, 0), c(n, 0);
    while(q--)
    {
            scanf("%s",ch);
             i=fastread();
             x=fastread(); //increase by x
            if(strcmp(ch,"RowAdd")==0)
            {
                r[i-1]+=x;
            }
            else
            {
                c[i-1]+=x;
            }
    } // we created d matrix
    int maxc=0;
    int maxr=0;
    //find the max of the row and cols
    for(i=0;i<n;i++)
    {
        if(r[i]>=maxr);
         maxr=r[i];

        if(c[i]>=maxc)
            maxc=c[i];
    }

     //int maxr = *max_element(r.begin(), r.end());
     //int maxc = *max_element(c.begin(), c.end());
     cout<<(maxr+maxc)<<endl;


return 0;
}
