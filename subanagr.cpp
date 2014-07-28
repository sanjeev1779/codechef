#include<stdio.h>
#include<string.h>
#include<string.h>
#include<iostream>
using namespace std;
main()
{
    int n,i,j,k;
    char w[105];
    int a[26];
    int minm[26];
    cin>>n;
    memset(minm,0,sizeof(minm));

    scanf("%s",w);
    int l=strlen(w);
    for(j=0;j<l;j++)
    {
        minm[w[j]-97 ]++;
    }
    for(i=1;i<n;i++)
    {
        scanf("%s",w);

        memset(a,0,sizeof(a));
        l=strlen(w);
        //cout<<"length= "<<l<<endl;
        for(j=0;j<l;j++)
        {
            a[w[j]-97]++;
        }

        //finding the minm number of alphabets in the word
        for(k=0;k<26;k++)
        {
            if(a[k] < minm[k])
            {
                minm[k]=a[k];
            }
        }
    }
    int flag=1;
    for(i=0;i<26;i++)
    {
        if(minm[i]>0)
        {
            flag=0;
            break;
        }
    }

    if(flag==0)
    {
        for(i=0;i<26;i++)
         {
             if(minm[i]>0)
                {
                    //printf("%c = %d\n",(i+97),minm[i]);
                    for(j=0;j<minm[i];j++)
                    {
                        //cout<<(i+97);
                        printf("%c",(i+97));
                    }
                }

         }
    }

    else
    {
        cout<<"no such string\n";
    }
return 0;
}
