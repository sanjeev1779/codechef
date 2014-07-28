#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


// this template belongs to sakhsim1994
//
int visited[53];
int n;
double dp(int Array[][3],int i, int visited[]) // Array, N, visited
{
    double ans;
    if(i==n+1)
    {
        return 1.0;

    }
    if(visited[ Array[i][1]]==0 && visited[ Array[i][2]]==0)
    {
         visited[ Array[i][1]]=1;
        ans= ((double)Array[i][0]/100.0)* dp(Array,i+1,visited);
        visited[ Array[i][1]]=0;
         visited[ Array[i][2]]=1;
         ans+= (1-((double)Array[i][0]/100.0))* dp(Array,i+1,visited);
         visited[ Array[i][2]]=0;
         return ans;
    }
    if(visited[ Array[i][1]]==0 && visited[ Array[i][2]]==1)
    {
        visited[ Array[i][1]]=1;
        ans= ((double)Array[i][0]/100.0)* dp(Array,i+1,visited);
        visited[ Array[i][1]]=0;
        return ans;
    }
     if(visited[ Array[i][1]]==1 && visited[ Array[i][2]]==0)
    {
         visited[ Array[i][2]]=1;
         ans= (1-((double)Array[i][0]/100.0))* dp(Array,i+1,visited);
         visited[ Array[i][2]]=0;
         return ans;
    }

     if(visited[ Array[i][1]]==1 && visited[ Array[i][2]]==1)
    {
            return 0.0;
    }


    return ans;
}
main()
{
    int j;
     int Array[55][3];
    int T;
    double answer;

    scanf("%d",&T);
   for(int k=0;k<T;k++)
    {
         memset(Array,0,sizeof(Array));
        memset(visited,0,sizeof(visited));

        scanf("%d",&n);

        for(j=1;j<=n;j++)
        {
            scanf("%d %d %d",&Array[j][0],&Array[j][1],&Array[j][2]); //probability

        }




            answer= dp(Array,1,visited);
            printf("%.6lf\n",answer);


    }
return 0;
}

