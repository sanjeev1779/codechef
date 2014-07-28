#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
main()
{
    int i,num,lastdig,seconddig,lastnum,secondnum;
    cin>>num;
    if(num>0)
    {
        cout<<num<<endl;
    }
    else
    {
        int c=0;
        num= -num;
        while(num>0)
        {
            num=num/10;
            c++;
        }
        lastdig= num%10;
        lastnum=num/10;

        seconddig= lastnum%10;
        secondnum= lastnum/10 + pow(10,c-2)*lastdig;
        if(secondnum>lastnum)
            cout<<secondnum<<endl;
        else
            cout<<lastnum<<endl;
    }
return 0;
}
