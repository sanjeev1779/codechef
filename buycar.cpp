#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<sstream>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
LL convertString(string s){LL num;stringstream sstr(s);sstr>>num;return num;}

main()
{
    int t,N,i,j,tax;
    S(t);
    LL base,car_base,tot_cost,maxm;
    string car,car_buy, base_str, tax_str;
    while(t--)
    {
        S(N);
        maxm=-1;
        for(i=0;i<N;i++)
        {
            cin>>car>>base_str>>tax_str;
             //string base_str_new="";
            // string taxs="";
            int lb= base_str.size();
            base=0; tax=0;
            for(j=1;j<lb;j++)
            {
                base= base*10+(base_str[j]-'0');
            }
            int lt= tax_str.size();
            for(j=0;j<lt-1;j++)
            {
                tax= tax*10+(tax_str[j]-'0');
            }
           // base= convertString(base_str_new);
            //tax= convertString(taxs);
            tot_cost= base*(1+ 0.01*tax);
           // cout<<"total cost= "<<tot_cost<<endl;
            if(tot_cost>maxm)
            {
                maxm= tot_cost;
                car_buy= car;
                car_base= base;
            }
            else if(tot_cost==maxm)
            {
                if(car_base<=base)
                {
                    car_base=base;
                    car_buy=car;
                    maxm=tot_cost;
                }
            }
        }
        cout<<car_buy<<endl;
    }

return 0;
}
