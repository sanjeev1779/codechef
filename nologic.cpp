#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
main()
{
    int test_cases,i,l;
    scanf("%d",&test_cases);
    getchar();
    int a[127];
    char w[320];
    while(test_cases--)
    {
        memset(a,0,sizeof(a));
        gets(w);
        l=strlen(w);
       // w = tolower(w);
        for(i=0;i<l;i++)
        {
            if( isalpha(w[i]))
                w[i]= tolower(w[i]);
            if(w[i]>=97 && w[i]<=122 )
                a[w[i]]++;
        }

        int flag=1;
        for(i=97;i<123;i++)
        {
            if(a[i]==0)
            {
                flag=0; //this element is not present, so we can't have "~" ans
                break;
            }
        }
        if(flag==0)
        {

            for(i=97;i<123;i++)
            {
                if(a[i]==0)
                {
                    printf("%c",(i));
                }
            }
        }
        if(flag==1) //everyone is present
            cout<<"~";
      cout<<endl;
    }

return 0;
}
