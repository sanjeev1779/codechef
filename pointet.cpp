#include<stdio.h>
#include<iostream>
using namespace std;

main()
{

    int number=15,c,i,bito,bite;
    for(i=0;i<4;i+=2)
{
        bito = number & (1 << i);
        bite=number & (1 << (i+1));
       // cout<<bito<<" "<<bite<<"\n";
        if(bito!=bite)
        {
           if(bito==0)
           {
               number|=1<<i ;
               number&= ~(1<<(i+1));
           }
            else
            {
               number &= ~(1<<i);
               number |= 1<<(i+1) ;
            }
        }
}
printf("%d",number);

}
