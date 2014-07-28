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
#define max_limit 105
#define undef -2
#define empty -1
#define noEdge 0
#define unmatched 1
#define matched 2
#define forward 0
#define reverse 0
using namespace std;
struct node {
       int even;
       int odd[2];
};
struct elem {
       int vertex,type;
};

int adj_M[max_limit][max_limit];


int blossom[max_limit];
int path[2][max_limit],endPath[2];


bool match[max_limit];


node label[max_limit];


elem queue[2*max_limit];
int queueFront,queueBack;
void initGraph(int n){
     for (int i=0; i<n; i++)
         for (int j=0; j<n; j++) adj_M[i][j]=noEdge;
}

void initAlg(int n){
     queueFront=queueBack=0;
     for (int i=0; i<n; i++){
         blossom[i]=i;
         label[i].even=label[i].odd[0]=label[i].odd[1]=undef;
     }
}

void backtrace (int vert, int pathNum, int stop, int parity, int direction){
     if (vert==stop) return;
     else if (parity==0){
        if (direction==reverse){
           backtrace(label[vert].even,pathNum,stop,(parity+1)%2,reverse);
           path[pathNum][endPath[pathNum]++]=vert;
        }
        else if (direction==forward){
             path[pathNum][endPath[pathNum]++]=vert;
             backtrace(label[vert].even,pathNum,stop,(parity+1)%2,forward);
        }
     }
     else if (parity==1 && label[vert].odd[1]==undef){
        if (direction==reverse){
           backtrace(label[vert].odd[0],pathNum,stop,(parity+1)%2,reverse);
           path[pathNum][endPath[pathNum]++]=vert;
        }
        else if (direction==forward){
             path[pathNum][endPath[pathNum]++]=vert;
             backtrace(label[vert].odd[0],pathNum,stop,(parity+1)%2,forward);
        }
     }

     else if (parity==1 && label[vert].odd[1]!=undef){
          if (direction==reverse){
             backtrace(label[vert].odd[0],pathNum,empty,(parity+1)%2,reverse);
             backtrace(label[vert].odd[1],pathNum,vert,(parity+1)%2,forward);
             path[pathNum][endPath[pathNum]++]=vert;
          }
          else if (direction==forward){
               backtrace(label[vert].odd[1],pathNum,vert,(parity+1)%2,reverse);
               backtrace(label[vert].odd[0],pathNum,empty,(parity+1)%2,forward);
               path[pathNum][endPath[pathNum]++]=vert;
          }
     }
}

void enqueue (int vert, int t){
     elem tmp;
     tmp.vertex=vert;
     tmp.type=t;
     queue[queueBack++]=tmp;
}

void newBlossom (int a, int b){
     int i,base,innerBlossom,innerBase,j,p;
     for (i=0; path[0][i]==path[1][i]; i++);
     i--;
     base=blossom[path[0][i]];

     for (j=i; j<endPath[0]; j++) blossom[path[0][j]]=base;
     for (j=i+1; j<endPath[1]; j++) blossom[path[1][j]]=base;
     for (p=0; p<2; p++){
        for (int j=i+1; j<endPath[p]-1; j++){
            if (label[path[p][j]].even==undef){
               label[path[p][j]].even=path[p][j+1];
               enqueue(path[p][j],0);
            }
            else if (label[path[p][j]].odd[0]==undef && label[path[p][j+1]].even==undef){
                 label[path[p][j]].odd[0]=path[p][j+1];
                 enqueue(path[p][j],1);
            }

            else if (label[path[p][j]].odd[0]==undef && label[path[p][j+1]].even!=undef){
                 innerBlossom=blossom[path[p][j]];
                 innerBase=j;
                 for (; blossom[j]==innerBlossom && j<endPath[p]-1; j++);
                 j--;
                 label[path[p][innerBase]].odd[0]=path[p][j+1];
                 label[path[p][innerBase]].odd[1]=path[p][j];
                 enqueue(path[p][innerBase],1);
            }
        }
     }
     if (adj_M[a][b]==unmatched){
        if (label[a].odd[0]==undef)
            {
           label[a].odd[0]=b;
           enqueue(a,1);
           }
        if (label[b].odd[0]==undef){
           label[b].odd[0]=a;
           enqueue(b,1);
        }
     }
     else if (adj_M[a][b]==2){
          if (label[a].even==undef){
             label[a].even=b;
             enqueue(a,0);
          }
          if (label[b].even==undef){
             label[b].even=a;
             enqueue(b,0);
          }
     }
}

void augmentPath (){
     int a,b;
     for (int p=0; p<2; p++){
         for (int i=0; i<endPath[p]-1; i++){
             a=path[p][i];
             b=path[p][i+1];
             if (adj_M[a][b]==unmatched)
                adj_M[a][b]=adj_M[b][a]=2;
             else if (adj_M[a][b]==2)
                  adj_M[a][b]=adj_M[b][a]=unmatched;
         }
     }
     a=path[0][endPath[0]-1];
     b=path[1][endPath[1]-1];
     if (adj_M[a][b]==unmatched) adj_M[a][b]=adj_M[b][a]=2;
     else if (adj_M[a][b]==2) adj_M[a][b]=adj_M[b][a]=unmatched;
     match[path[0][0]]=match[path[1][0]]=true;
}

bool augmentedPath (int n){
     int node,nodenode,i;
     initAlg(n);
     for (i=0; i<n; i++)
     {
        if (!match[i])
        {
             label[i].even=empty;
             enqueue(i,0);
         }
     }

     while (queueFront<queueBack){
         node=queue[queueFront].vertex;
         nodenode=queue[queueFront].type;
         if (nodenode==0){
            for (int i=0; i<n; i++) if (adj_M[node][i]==unmatched){
                if (blossom[node]==blossom[i]);
                else if (label[i].even!=undef){
                     endPath[0]=endPath[1]=0;
                     backtrace(node,0,empty,0,reverse);
                     backtrace(i,1,empty,0,reverse);

                     if (path[0][0]==path[1][0]) newBlossom(node,i);

                     else {
                          augmentPath();
                          return true;
                     }
                }
                else if (label[i].even==undef && label[i].odd[0]==undef){
                     label[i].odd[0]=node;
                     enqueue(i,1);
                }
            }
         }
         else if (nodenode==1){
            for (int i=0; i<n; i++) if (adj_M[node][i]==matched){
                if (blossom[node]==blossom[i]);
                else if (label[i].odd[0]!=undef){
                     endPath[0]=endPath[1]=0;
                     backtrace(node,0,empty,1,reverse);
                     backtrace(i,1,empty,1,reverse);
                     if (path[0][0]==path[1][0]) newBlossom(node,i);
                     else {
                          augmentPath();
                          return true;
                     }
                }
                else if (label[i].even==undef && label[i].odd[0]==undef){
                     label[i].even=node;
                     enqueue(i,0);
                }
            }
         }

         queueFront++;
     }

     return false;
}

void mbp (int n){
    int i;
     for (i=0; i<n; i++) match[i]=false;
     while (augmentedPath(n));
}

main()
{
     freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
       // freopen("C:\\Users\\cyber\\Desktop\\codechef\\output.txt", "w", stdout);
    int n,t,e,a,b,i,j,ans;
    S(t);
    while(t--)
    {
        memset(adj_M,0,sizeof(adj_M));
         scanf("%d %d",&n,&e);
         initGraph(n);
         for (int i=0; i<e; i++){
             scanf(" %d %d",&a,&b);
             if (a!=b)
                adj_M[a-1][b-1]=adj_M[b-1][a-1]=unmatched;
         }
         if(n%2==1)
            printf("NO\n");
         else{
                ans=0;
               mbp(n);
                for (i=0; i<n; i++)
                {
                    for (j=i+1; j<n; j++)
                    {
                        if (adj_M[i][j]==matched)
                       {
                            ans++;
                       }
                    }
                }
            if(ans==n/2)
                printf("YES\n");
            else  printf("NO\n");
         }
    }
    return 0;
}
