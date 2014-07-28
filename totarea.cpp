#include<iostream>
#include<stdio.h>
using namespace std;
main()
{
    double n,a;
    int t,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n*=n;
        a=2.0*n+n/3.0+n/2;
        printf("%.6lf\n",a);
    }


return 0;
}
