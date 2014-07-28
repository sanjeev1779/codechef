#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<climits>
#include<map>
#include<math.h>
#include<algorithm>
#define LL long long
#define P(N) printf("%d\n",N);
#define S(N) scanf("%d",&N);
#define SL(N) scanf("%lld",&N);
#define pb push_back
#define mp make_pair
using namespace std;
int visited[1012][1012];
main()
{
      //  freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
        int t,i,j,N,M,x,y,x1,y1,l,cnt;
        char ch;
        S(t);
        string str;
        while(t--)
        {
            memset(visited,0,sizeof(visited));
            scanf("%d %d %d %d %d",&N,&M, &x,&y,&l);
            cin>>str;
            l= str.length();
            visited[x][y]=1;

            vector<pair<int,int>>vec;
            p[i]= mp(x,y);
            vec.pb(p[i]);

            for(i=0;i<l;i++)
            {
                if(str[i]=='D')
                {
                        y=y-1;
                        visited[x][y]=1;
                        p[i]= mp(x,y);
                        vec.pb(p[i]);
                }
                else  if(str[i]=='U')
                {
                        y=y+1;
                        visited[x][y]=1;
                        p[i]= mp(x,y);
                        vec.pb(p[i]);
                }
                else  if(str[i]=='L')
                {
                        x=x-1;
                        visited[x][y]=1;
                        p[i]= mp(x,y);
                        vec.pb(p[i]);
                }
                else  if(str[i]=='R')
                {
                        x=x+1;
                        visited[x][y]=1;
                        p[i]= mp(x,y);
                        vec.pb(p[i]);
                }
            }
            cnt=0;
            ch=str[l-1];
           // cout<<x<<"  "<<y<<endl;
            //cout<<x<<" \t"<<y<<endl;

            // to be unvisited and visit new one
            switch(ch)
                {
                case 'R':
                    {
                        while(x<=N)
                        {
                            x++;
                            cnt++;
                            if(visited[x][y]==1) break;
                            visited[x][y]=1;
                        }
                        if(x<=N)
                        {
                            cout<<"BODY "<<(cnt-1)<<endl;
                        }
                        else cout<<"WALL "<<(cnt-1)<<endl;
                        break;
                    }
                    case 'L':
                    {
                        while(x>0)
                        {
                            x--;
                            cnt++;
                            if(visited[x][y]==1) break; visited[x][y]=1;
                        }
                        if(x>0)
                        {
                            cout<<"BODY "<<(cnt-1)<<endl;
                        }
                        else cout<<"WALL "<<(cnt-1)<<endl;
                        break;
                    }

                    case 'U':
                    {
                        while(y<=M)
                        {
                            y++;
                            cnt++; if(visited[x][y]==1) break; visited[x][y]=1;
                        }
                        if(y<=M)
                        {
                            cout<<"BODY "<<(cnt-1)<<endl;
                        }
                        else cout<<"WALL "<<(cnt-1)<<endl;
                        break;
                    }

                    case 'D':
                    {
                        while(y>0)
                        {
                            y--;
                            cnt++;if(visited[x][y]==1) break;
                            if(y>=0) visited[x][y]=1;
                        }
                        if(y>0)
                        {
                            cout<<"BODY "<<(cnt-1)<<endl;
                        }
                        else cout<<"WALL "<<(cnt-1)<<endl;
                    }

                }
        }
return 0;
}
