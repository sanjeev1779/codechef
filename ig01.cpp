#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define LL long long
using namespace std;
main()
{
    int test_cases;
    char n1[102];
    char n2[102];
    int a[26];
    int b[26];
    char ans_arr[6][12] = {"FRIENDS", "LOVE", "ADORE", "MARRIAGE","ENEMIES", "SISTER"};
    int l1,l2,left,i,rem,prev_rem,c;
    cin>>test_cases;
    char ch[7]="FLAMES";
    while(test_cases--)
    {
        cin>>n1;
        cin>>n2;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        l1= strlen(n1);
        l2= strlen(n2);

        for(i=0;i<l1;i++)
        {
            a[n1[i]-65]++;
        }

        for(i=0;i<l2;i++)
        {
            b[n2[i]-65]++;
        }
        int s=0;
        for(i=0;i<26;i++)
        {
            if(a[i]>b[i])
                  {
                      a[i]-= b[i];
                      b[i]=0;
                      s+= a[i];
                  }
            else
                {
                    b[i]-= a[i];
                    a[i]=0;
                    s+= b[i];
                }
        }
        c=6;
        int cut[6]={0};
        while(c>1)
            {
                rem= s%c;
                rem--;
                new_word="";
                c--;
                int l= strlen(ch);
                for(i=0;i<l;i++)
                {
                    if(i!=rem)
                        strcat(new_word,ch[i]);
                }
                strcpy(ch,new_word);
            }



    }
return 0;
}
