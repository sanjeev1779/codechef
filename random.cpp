#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
main()
{
    int i,n;
    int cnt=0;
    for(i=0;i<1000;i++)
    {
        int a= randomize(100);
       // cout<<a<<"\n";
        if(a%2==0)
         cnt++;
    }
    cout<<cnt<<endl;
}
