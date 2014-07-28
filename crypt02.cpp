#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define pb push_back
#define mp make_pair
using namespace std;

string reverse_word(string word)
{
    string rev_word="";
    int l=word.size();
    for(int i=l-1;i>=0;i--)
        rev_word+=word[i];
    return rev_word;
}
main()
{
    int x,x1,x2,y1,y2,i,j,k,flag=0,found=0,l;
    char a[102][102];
    string str,word,word_rev;
    cin>>x;
    for(i=1;i<=x;i++)
    {
        cin>>str;
        for(j=1;j<=x;j++)
        {
            a[i][j]=str[j-1];
        }
    }
    while(1)
    {
        cin>>word;
        flag=0;
        found=0;
        word_rev= reverse_word(word);
        l = word.size();
        if(word!="0")
        {
            // horizontal left to right and right to left
            for(i=1;i<=x;i++)
            {
                for(j=1;j<=x-l+1;j++)
                {
                    string match="";
                    for(k=j;k<=j+l-1;k++)
                    {
                        match= match+a[i][k];
                    }
                    if(match==word)
                    {
                        x1= i,y1=j,x2=i,y2=j+l-1;
                        flag=1;
                        found=1;
                        break;
                    }
                    else if(word_rev==match)
                    {
                        x1= i,y1=j+l-1,x2=i,y2=j;
                        found=1;
                        flag=1; break;
                    }
                }
                if(flag) break;
             }

             //vertical from top to bottom
             if(!found){
             for(j=1;j<=x;j++)
             {
                 for(i=1;i<=x-l+1;i++)
                 {
                    string match="";
                    for(k=i;k<=i+l-1;k++)
                        match= match+ a[k][j];
                    if(match==word)
                    {
                        x1=i,y1=j, x2=i+l-1,y2=j;
                        found=1;
                        flag=1;break;
                    }
                 }
                 if(flag) break;
             }
             }

             //diagonal from left corner to right bottom
             if(!found)
             {
                 for(i=1;i<=x-l+1;i++)
                 {
                     for(j=1;j<=x-l+1;j++)
                     {
                         string match="";
                         for(k=0;k<=l-1;k++)
                         {
                             match+= a[i+k][j+k];
                         }
                         if(match==word)
                         {
                             x1=i,y1=j, x2=i+l-1,y2=j+l-1;
                             found=1;
                             flag=1;break;
                         }
                         else if(match==word_rev)
                         {
                             x1=i+l-1,y1=j+l-1, x2=i,y2=j; found=1;
                             flag=1;break;
                         }
                     }
                     if(flag) break;
                 }
             }
                 //diagonal
                 if(!found)
                 {
                     for(i=1;i<=x-l+1;i++)
                     {
                         for(j=x;j>=l;j--)
                         {
                             string match="";
                             for(k=0;k<l;k++)
                             {
                                 match+= a[i+k][j-k];
                             }
                              if(match==word)
                             {
                                 x1=i,y1=j, x2=i+l-1,y2=j-l+1; found=1;
                                 flag=1;break;
                             }
                             else if(match==word_rev)
                             {
                                 x1=i+l-1,y1=j-l+1, x2=i,y2=j; found=1;
                                 flag=1;break;
                             }
                          }
                             if(flag) break;
                     }
                 }// last if closed

                 if(found==0)
                    printf("Not found\n");
                 else
                    printf("%d,%d %d,%d\n",x1,y1,x2,y2);
        }
        else
            break;
    }


return 0;
}
