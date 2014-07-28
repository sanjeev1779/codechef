#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int test;
        S(test);
        int a[1010],b[1015];
        while(test--)
        {
            string str="";
            cin>>N;
            for(i=0;i<N;i++)
            {
                S(a[i]);S(b[i]);
            }
            for(i=0;i<N-1;i++)
            {
                    x= a[i+1]-a[i];
                    y=b[i+1]-b[i];
                    if(x>0 && y>0)
                    {
                            while(1)
                            {

                                if(a[i]<b[i] && a[i]<=a[i+1])
                                    {
                                        str+="L+";
                                        a[i]+=1;
                                    }
                                else break;

                            }
                           while(1)
                           {
                               if(b[i]<a[i+1] && b[i]<=b[i+1])
                               {
                                   str+="R+";
                                   b[i]++;
                               }
                               else break;
                           }


                                while(a[i]<=a[i+1])
                                    {
                                        str+="L+";
                                        a[i]+=1;
                                    }


                                while(b[i]<=b[i+1])
                                    {
                                        str+="R+";
                                        b[i]+=1;
                                    }

                    }
                    else if(x>0 && y<0)
                    {

                    }
            }


        }

return 0;
}
