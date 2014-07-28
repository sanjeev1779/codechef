#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int solve(k, dis , *adj) //k=current intersection, dis= total distance travelled, adj is matrxix
{

}
main()
{
    int test_cases,m,n,i,j;

    cin>>test_cases;
    while(test_cases--)
    {
        cin>>n>>m;
        //set the distance between the edges
        int adj[n][n];
        memset(adj,0,sizeof(adj));
        while(m--)
        {
            cin>>a>b>>c;
            adj[i--][j--]=c;
            adh[j--][i--]=c;
        }

        ans=solve(0,0,adj[n][n]);
        cout<<ans;
    }

return 0;
}
