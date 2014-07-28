#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    long long int num,i;
    scanf("%lld",&num);
    long long int maxm_prime=-1;
    for(i=2;i*i<=num;i++)
    {
        while(num%i==0)// i is a prime number
        {
            num/=i;
            if(i>= maxm_prime)
            {
                maxm_prime=i;
            }
        }
    }
    if(num!=1)// num is a prime
    {
        if(num>=maxm_prime)
            maxm_prime=num;
    }
    printf("Greatest prime number in the factor of the given number = %lld\n",maxm_prime);
 return 0;
}
