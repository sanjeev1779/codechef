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
    int a[10000];
    a[2]='A';   a[22]='B'; a[222]='C'; a[3]='D'; a[33]='E'; a[333]='F';  a[4]='G'; a[44]='H';
    a[444]='I', a[5]='J',  a[55]='K', a[555]='L', a[6]='M', a[66]='N', a[666]='O';
    a[7]='P', a[77]='Q', a[777]='R', a[7777]='S', a[8]='T', a[88]='U', a[888]='V';
    a[9]='W', a[99]='X', a[999]='Y', a[9999]='Z'; a[0]=32;
    int t,flag,num,l,i,x;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        l=str.size();
        for(i=0;i<l;)
        {
            flag=0;
            if(i<=l-4){
            if(str[i]==str[i+1] && str[i]==str[i+2] && str[i]==str[i+3])
            {
               // cout<<"four\n";
                x=str[i]-48;
                //cout<<"x: i= "<<str[i]<<" : "<<i<<endl;
                num= 1000*x+ 100*x+10*x+x;
               // cout<<num<<endl;
                printf("%c",a[num]); flag=1;
                i=i+3;
            }}

            if(i<=l-3 && flag==0)
            {
                if(str[i]==str[i+1] && str[i]==str[i+2])
                    {
                      //  cout<<"thre\n";
                        x=str[i]-48; flag=1;
                   //     cout<<"x: i= "<<str[i]<<" : "<<i<<endl;
                        num=100*x+10*x+x;
                     //   cout<<num<<endl;
                        printf("%c",a[num]);i+=2;
                    }
            }

            if(i<=l-2 && flag==0){
                    if(str[i]==str[i+1])
            {
            //    cout<<"two\n";
                x=str[i]-48; num=10*x+x; flag=1;
                //cout<<"x: i= "<<str[i]<<" : "<<i<<endl;
                //cout<<num<<endl;
                printf("%c",a[num]);i=i+1;
            }}
             if(str[i]!='#' && flag==0)
            {
              //  cout<<"one\n";
                x=str[i]-48; num= x;flag=1;
               // cout<<"x: i= "<<str[i]<<" : "<<i<<endl;
                //cout<<"num= "<<num<<endl;
                printf("%c",a[num]);
            }
            i++;
        }
        cout<<endl;
    }
return 0;
}
