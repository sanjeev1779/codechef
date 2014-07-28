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
    int test_cases,i,j,R,C,left,right,top,bottom,minm,minm1,minm2,x,y,k;
   // int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509};
    S(test_cases);
    string str;
    int a[53][53];
    while(test_cases--)
    {
        S(R);
        S(C);
        memset(a,0,sizeof(a));
        for(i=0;i<R;i++)
        {
            cin>>str;
            for(j=0;j<C;j++)
            {
                if(str[j]=='^')
                    a[i][j]=1;
                else
                    a[i][j]=0;
            }
        }
        int ans=0;
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                right=0;
                left=0;
                top=0;
                bottom=0;
                    if(a[i][j]==1)
                    {
                        for(y=j+1;y<C;y++)//right
                        {
                            if(a[i][y]==0)
                                break;
                            right++;
                        }
                        for(y=j-1;y>=0;y--)//left
                        {
                            if(a[i][y]==0)
                                break;
                            left++;
                        }

                        for(x=i-1;x>=0;x--)//top
                        {
                            if(a[x][j]==0)
                                break;
                            top++;
                        }

                        for(x=i+1;x<R;x++)//bottom
                        {
                            if(a[x][j]==0)
                                break;
                            bottom++;
                        }

                        minm1=min(top,bottom);
                        minm2=min(left,right);
                        minm= min(minm1,minm2);

                        if(minm>=2)
                            ans++;
                    }

            }
        }
        cout<<ans<<endl;
    }

return 0;
}
