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
#define mp make_pair
using namespace std;
main()
{
    int test_cases;
    S(test_cases);
    LL num;
    int rem,cnt;
    string ch[11]={"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
    while(test_cases--)
    {
        cnt=0;
        scanf("%lld",&num);
        string str="";
        while(num>0)
        {
            rem=num%10;
            num/=10;
            str= ch[rem]+str;
        }
        cout<<str<<endl;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='.')
                cnt++;
        }
        cout<<cnt<<endl;
    }

return 0;
}
