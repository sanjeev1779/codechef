#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string.h>
#define inf 1000000
#define LL long long
using namespace std;
int p[100002];
int tax[100002];
int find(int a)
{
    int root= a,root2;
    while(p[a]!=a)
        a=p[a];
    while(root!=a)
    {
        root2= p[root];
        p[root]=a;
        root=root2;
    }
    return a;
}
main()
{
    int n,m,root_u,root_v,u,v,i,x,y,ans=0;
    int edge[10000][2];
    int minm_root[10001];
    for(i=0;i<100001;i++)
        minm_root[i]=inf;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        p[i]=i;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&edge[i][0],&edge[i][1]);
    }
    for(i=1;i<=n;i++)
            scanf("%d",&tax[i]); // storing tax of i
    for(i=1;i<=m;i++)
    {
        x= edge[i][0];
        y= edge[i][1];
        root_u = find(x);
        root_v= find(y);
        p[root_v]= root_u;

        if( tax[x]>0 || tax[y]>0)
        {
            if(tax[x]>=0 && tax[y]>=0){
            int z= min( tax[x], tax[y]);
            minm_root[root_u]= min( minm_root[root_u], z);
            minm_root[y]=0;
            }
            else if(tax[x]>0)
            {
                minm_root[root_u]= min( minm_root[root_u], tax[x]);
                minm_root[y]=0;
            }
            else
            {
                minm_root[root_u]= min( minm_root[root_u], tax[y]);
                minm_root[x]=0;
            }


        }

     /*  printf("minm of the edges= %d\n ",z);

        printf("%d is the parent of %d\n",root_u,edge[i][0]);
        printf("%d is the parent of %d\n",root_v,edge[i][1]);
        printf("%d is the parent of %d\n",p[root_v],root_u);
        printf("\n");
        cout<<"root = "<<root_u<<"and "<<minm_root[root_u]<<endl;*/

    }
    for(i=1;i<=n;i++)
    {

        printf("p[%d]=%d\n",i,p[i]);
        printf("minm_root[%d]= %d\n",i,minm_root[i]);
    }
    int counter=0;
    int c=0;
    int flag=0;
    int total_sum=0, min_r=1000000;
    for(i=1;i<=n;i++)
    {
       if(minm_root[i]==1000000 )
       {
           if(tax[i]<0)
           {
               flag=1;
                printf("-1\n");
                break;
           }
           else
           {

            minm_root[i]= tax[i];
            printf("minm_root[]= %d\n",minm_root[i]);
           }
       }
       if(minm_root[i]>0 )
         {
           // cout<<"root = "<<i<<"and "<<minm_root[i]<<endl;

            total_sum+= minm_root[i];
            min_r = min( min_r, minm_root[i]);
            c++;

         }
    }
    if(flag==0)
    {
        ans= total_sum + (c-2)* min_r;
        printf("%d\n",ans);
    }
return 0;
}



