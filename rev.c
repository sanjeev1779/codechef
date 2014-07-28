#include<stdio.h>
main()
{
  char seven[9]="00000110";
  int decimal[10];
  int i;
  for(i=1;i<=1;i++)
  {

     decimal[i]=pow(2,7)*(seven[8*i-8]-'0')+pow(2,6)*(seven[8*i-7]-'0')+pow(2,5)*(seven[8*i-6]-'0')+pow(2,4)*(seven[8*i-5]-'0')+pow(2,3)*(seven[8*i-4]-'0')+pow(2,2)*(seven[8*i-3]-'0')+pow(2,1)*(seven[8*i-2]-'0')+pow(2,0)*(seven[8*i-1]-'0');

   }
   char c='5';
   printf(" %d",decimal[i-1]);
}
