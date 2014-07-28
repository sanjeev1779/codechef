#include<stdio.h>
#include<string.h>
int main()
{
  int i,j,t,ctr,n;
   char txt[101];
  scanf("%d",&t);
     for(j=0;j<t;j++)
      {
       ctr=0;
       scanf("%s",txt);
       printf("%s\n",txt);
       n=strlen(txt);
       for(i=0;i<n;i++)
       {
        printf("%c\n",txt[i]);
        if(txt[i]==65 || txt[i]=='D' || txt[i]=='O' || txt[i]=='P' || txt[i]=='Q' || txt[i]=='R')
            {ctr=ctr+1;  printf("%c\n",txt[i]);}
        if(txt[i]=='B')
        {ctr=ctr+2;  printf("%c\n",txt[i]);}
       }
       printf("%d \n",ctr);
      }

   return 0;
}
