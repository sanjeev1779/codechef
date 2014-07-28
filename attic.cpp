#include<stdio.h>
#include<math.h>
#include<string.h>
#define LL long long
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

main()
{
    int test_Cases,jump,i,j;
    scanf("%d",&test_Cases);
    char ch[5000005];
   // string ch;
    while(test_Cases--)
    {
       // cin>>ch;
       fastRead_string(ch);
        int l=strlen(ch);
        int prev_jump=0;
        int ans=0;
        for(i=0;i<l;)
        {
            jump=1;

            if(ch[i]=='.')
            {
                for(j=i;j<l;j++)
                {
                    if(ch[j]=='.')
                        jump++;
                    else
                        break;
                }
                i=i+jump;
                if(jump>prev_jump)
                {
                    ans++;
                    prev_jump=jump;
                }
            }

            else
            {
                i++;
            }

        }
       // cout<<ans<<endl;
       writeInt(ans);

    }
return 0;
}
