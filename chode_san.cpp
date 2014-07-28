#include<map>
#include<stack>
#include<iostream>
#include<cstring>
#include<stdio.h>
//

/*
inline void fastInput(int &xwith) {

    register int c = getchar();

    x = 0;

    int neg = 0;



    for(; ((c<48 || c>57) && c != '-'); c = getchar());



    if(c=='-') {

        neg = 1;

        c = getchar();

    }



    for(; c>47 && c<58 ; c = getchar()) {

        x = (x<<1) + (x<<3) + c - 48;

    }



    if(neg)

        x = -x;

}

inline void fastLongInput(long int &x) {

    register int c = getchar();

    x = 0;

    int neg = 0;



    for(; ((c<48 || c>57) && c != '-'); c = getchar());



    if(c=='-') {

        neg = 1;

        c = getchar();

    }



    for(; c>47 && c<58 ; c = getchar()) {

        x = (x<<1) + (x<<3) + c - 48;

    }



    if(neg)

        x = -x;

}

unsigned long long int fast_mod_power(LL a,unsigned int b,LL mod)
{
  LL mul=1;
    while(b>0)
    {
      switch(b%4)
      {
        case 3: mul= (mul*a)%mod;
        case 2: mul= (mul*a)%mod;
        case 1: mul= (mul*a)%mod;
      }
      b/=4;
      a=((((((a*a)%mod)*a)%mod)*a)%mod);
    }

  return  (unsigned int )(mul%mod);
}

*/
// code starts from here
using namespace std;
main()
{
    int arr[31];
    int test,xwith,cipherlength,k,i,z;
    cin>>test;

    int maxm;
    string firststring;
    int encipher[31];
      char secondstring[150123];
   for(int zz=0;zz<test;z++)
    {

        z=-1;
        cin>>firststring;
        getchar();// dis is added for adding one extra character line
        gets(secondstring);
         cipherlength= strlen(secondstring);
        memset(encipher,0,sizeof(encipher));
        memset(arr,0,sizeof(arr));

        for(i=0;i<cipherlength;i++)
        {
            xwith= secondstring[i];
            if(xwith>=97 && xwith<=122)arr[xwith - 'a']+=1;
            else if(xwith>=65 && xwith<=90)arr[xwith-'A']+=1;
        }
        k=25;

        while(true)
        {
            maxm=-1;
            for(i=0;i<26;i++)
                if(arr[i]>=maxm)
                {
                    maxm=arr[i];;
                }
            if(maxm==0)break;
            for(i=25;i>=0;i--)
            {
                if(arr[i]==maxm)
                {
                    arr[i]=0;
                    encipher[i]=firststring[k];k=k-1;
                  //  c= (char)(enc[x-'a']-32);
                }
            }
        }

        for(i=0;i<cipherlength;i++)
        {
            xwith=secondstring[i];
            if(xwith>=65 && xwith<=90)
            {
                //c= (char)(enc[x-'a']-32);
                printf("%c",encipher[xwith-65]-32);
            }
            else if(xwith>=97 && xwith<=122)
            {
                //c= (char)(enc[x-'a']-32);
                printf("%c",encipher[xwith-97]);
            }
            else
                printf("%c",xwith);
        }
        //print a new line after the cipher text
        printf("\n");
    }
return 0;
}
// code ends here
