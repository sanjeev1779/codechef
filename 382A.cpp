// codeforces
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
#define SL(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;
main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        string str,str2,le="",re="";
        cin>>str;
        int l= str.length(),idx=0,j;
        int flag=0,i,left=0,right=0;
        for(i=0;i<l;i++)
        {
            if(str[i]=='|')
            {
                flag=1;
                idx=i;
                continue;
            }
            if(flag==0)
              {
                  le+= str[i];left++;
              }
            else {
                re+=str[i]; right++;
            }
        }
        cin>>str2;
        int l2 =str2.size();
        int tot= left+right+l2;
        int avg= tot/2;
        int x,y;
        if(tot%2==1)
        {

            printf("Impossible\n");
            return 0;
        }

        else
        {
            //cout<<left<<" "<<right<<endl;
                if(left<=avg && right<=avg)
                {
                    x= avg-left;
                    y= avg-right;
                    string ans= le;
                    for(j=0;j<str2.size();j++)
                    {
                        if(avg>left)
                        {
                            ans+= str2[j];
                            left++;
                        }
                      else break;
                    }
                    ans+='|'+re;

                    for(;j<str2.size();j++)
                    {
                         ans+= str2[j];
                    }
                    cout<<ans<<endl;
                }
                else  printf("Impossible\n");
        }
return 0;
}
