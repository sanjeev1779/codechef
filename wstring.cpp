#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define LL long long
#define max_size 26
using namespace std;

#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked

inline void writeInt(int x)
{
     if(x==-1)
     {
              PUTCHAR('-');
              PUTCHAR('1');
              PUTCHAR('\n');
     }
     else
     {
       int i = 10;
       char buf[11];
      // buf[10] = 0;
      buf[10] = '\n';

     do
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
     }
}



inline int fastRead_int()
{
        int noRead=0;
        char p=getchar_unlocked();
        for(; p<33;) {
                p=getchar_unlocked();
        };
        while(p>32) {
                noRead = (noRead << 3) + (noRead << 1) + (p - '0');
                p=getchar_unlocked();
        }
        return noRead;
};

inline void fastRead_string(char *str)
{
    register char c = 0;
    register int i = 0;
    while (c < 33)
        c = getchar_unlocked();
    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }
    str[i] = '\0';
}


int maxm_value_first_Edge( int a[][26] ,int index,int b[] )
{
    int i,j;

        for(j=0;j<26;j++)
        {
                b[j]= b[j] + a[index][j];
        }
        int maxm=b[0];
        for(i=1;i<26;i++)
        {
            if(b[i]>=maxm)
            {
                maxm=b[i];
            }
        }
        return maxm;
}
int maxm_value_fourth_Edge( int a[][26] ,int c[], int index )
{


        int i,j;
        for(i=0;i<26;i++)
        {
            c[i]=c[i]- a[index][i];
        }
        int maxm=c[0];
        for(i=1;i<26;i++)
        {
            if(c[i]>=maxm)
            {
                maxm=c[i];
            }
        }
        return maxm;
}

int maxm_value_of_array(int b[][26],int index)
{
        int maxm=b[index][0],i,j;
        for(i=1;i<26;i++)
        {
            if( b[index][i]>=maxm)
                maxm=b[index][i];
        }
        return maxm;
}

main()
{
        int test_cases,i,k,first_Edge,second_Edge,third_Edge,fourth_Edge,ans;
        test_cases=fastRead_int();
        int c[26],b[26];

        while(test_cases--)
        {
            memset(b,0,sizeof(b));
            memset(c,0,sizeof(c));
            char ws[10005];
            fastRead_string(ws);
            int l=strlen(ws);
            int a[l][26];
            memset(a,0,sizeof(a));
            int j=0;
            int hash_pos[l];
            for(i=0;i<l;i++)
            {
                if(ws[i]=='#')
                {
                    hash_pos[j]=i;
                    j++;
                }
                else a[j][ ws[i]-97 ]++;
            }

             int num_of_hashes=j;
            for(j=0;j<26;j++)
            {
                for(i=2;i<=num_of_hashes;i++)
                    c[j]+= a[i][j];
            }

                        int maxm_ans=0;
                        for(i=0;i<num_of_hashes-2;i++)
                        {
                            ans=0;
                            first_Edge=maxm_value_first_Edge(a,i,b);
                            second_Edge=maxm_value_of_array(a,i+1 ) ;
                            third_Edge=maxm_value_of_array(a,i+2 ) ;
                            fourth_Edge= maxm_value_fourth_Edge(a,c, i+2 );
                            if(first_Edge!=0 && second_Edge!=0 && third_Edge!=0 && fourth_Edge!=0 )
                             {
                                 ans= first_Edge + second_Edge + third_Edge + fourth_Edge+3;
                             }
                             if(ans>= maxm_ans)
                             {
                                 maxm_ans=ans;
                             }
                        }

                            writeInt(maxm_ans);
        }
return 0;
}
