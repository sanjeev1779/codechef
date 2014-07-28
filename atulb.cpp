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
LL sum[11];
LL numb(int dig)
{
    LL num=0;
    while(dig>0)
    {
        num=10*num+9;
        dig--;
    }
    return num;
}
LL start(int dig)
{
    LL num=1;
    while(dig>=2)
    {
        num=10*num;
        dig--;
    }
    return num;
}
void precompute()
{
    sum[0]=0;
    LL x,y;
    for(int i=1;i<=9;i++)
    {
        x= (numb(i)*(numb(i)+1))/2;
        y= (numb(i-1)*(numb(i-1)+1))/2;
        sum[i]= sum[i-1]+(x-y)*i;
    }
}
int nod(LL num)
{
    int cnt=0;
    while(num>0)
    {
        cnt++;
        num/=10;
    }
    return cnt;
}
main()
{
         // freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
      // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int test,i;
    S(test);
    precompute();
    LL K;
    for(i=0;i<10;i++)
        cout<<sum[i]<<endl;
    while(test--)
    {
        cin>>K;
        if(K==0)
        {
            printf("0\n");continue;
        }
         i=0;
        while(sum[i]<K)
        {
            i++;
        }
        i--;
        cout<<"i = "<<i<<endl;
        LL left=K-sum[i];
    cout<<left<<endl;
    i++;
        LL nu= start(i);
      //  cout<<"numb= "<<numb(i)<<endl;
         cout<<"but numb= "<<nu<<endl;
        while(left>0)
        {
            cout<<"left= "<<left<<endl;
            left-= ((nu)*i);
            nu++;
        }
        nu--;
        cout<<nu<<endl;
    }
return 0;
}
