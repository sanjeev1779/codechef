#include<stdio.h>
#include<string.h>

int vis[53];
int n;
double dp(int Array[][3],int i, int vis[]) // Array, N, vis
{
    double ans;
    if(i==n+1)
    {
        return 1.0;

    }
    if(vis[ Array[i][1]]==0 && vis[ Array[i][2]]==0)
    {
         vis[ Array[i][1]]=1;
        ans= ((double)Array[i][0]/100.0)* dp(Array,i+1,vis);
        vis[ Array[i][1]]=0;
         vis[ Array[i][2]]=1;
         ans+= (1-((double)Array[i][0]/100.0))* dp(Array,i+1,vis);
         vis[ Array[i][2]]=0;
         return ans;
    }
    if(vis[ Array[i][1]]==0 && vis[ Array[i][2]]==1)
    {
        vis[ Array[i][1]]=1;
        ans= ((double)Array[i][0]/100.0)* dp(Array,i+1,vis);
        vis[ Array[i][1]]=0;
        return ans;
    }
     if(vis[ Array[i][1]]==1 && vis[ Array[i][2]]==0)
    {
         vis[ Array[i][2]]=1;
         ans= (1-((double)Array[i][0]/100.0))* dp(Array,i+1,vis);
         vis[ Array[i][2]]=0;
         return ans;
    }

     if(vis[ Array[i][1]]==1 && vis[ Array[i][2]]==1)
    {
            return 0.0;
    }


    return ans;
}
main()
{
    int j;
     int Array[52][3];
    int T;
    double ans1;

    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        memset(Array,0,sizeof(Array));
        scanf("%d",&n);

        for(j=1;j<=n;j++)
        {
            scanf("%d %d %d",&Array[j][0],&Array[j][1],&Array[j][2]); //probability

        }




            ans1= dp(Array,1,vis);
            printf("%.6lf\n",ans1);


    }
return 0;
}

