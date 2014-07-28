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
/*
4
3
-1 0
0 1
3 5
1
0 1
3
-2 -1
-2 -1
-2 0
4
4 6
3 5
-1 1
1 2*/
main()
{
      //freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    string str;
    int n,fre,test;
    int i;
    S(test);
    int arr1[1010];
    int arr2[1010];
    while(test--)
    {
        S(n);
        memset(arr1,0,sizeof(arr1));
        memset(arr2,0,sizeof(arr2));
        for(i=0;i<n;i++)
        {
           S(arr1[i]);S(arr2[i]);
        }
        str="";// set it to null
        fre=0;
        for(i=0;i<=n-2;i++){
            while(arr1[i]!=arr1[i+1]||arr2[i]!=arr2[i+1])
            {
                if(arr1[i+1]>arr1[i]&&(arr1[i]+1)!=arr2[i])
                {
                	fre++;
                     str+="L+";
                     arr1[i]++;
                }
                else if( arr1[i+1]<arr1[i] && (arr1[i]-1)!=arr2[i])
                {
                    str+="L-";
                     arr1[i]--;
                    fre++;
                }
                else if(arr2[i+1]>arr2[i]&&(arr2[i]+1)!=arr1[i])
                {
                    arr2[i]++;
                    str+="R+";
                      fre++;
                }
                else if(arr2[i+1]<arr2[i]&&(arr2[i]-1)!=arr1[i]){
                    arr2[i]--;str+="R-";
                    fre++;
                }
                /*else if(arr2[i+1]<arr2[i]&&(arr2[i]-1)!=arr1[i]){
                    arr2[i]--;str+="R-";
                    fre++;
                }*/
            }
        }
        printf("%d\n",fre);
        cout<<str<<endl;
    }
return 0;
}
