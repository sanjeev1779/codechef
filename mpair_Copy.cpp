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
using namespace std;
typedef vector<int> Component;
vector<Component> components;
void dfs(int u){
    components.back().push_back(u);
    visited[ u ] = true;
    for( int v = 0 ; v < adjacency[u].size(); ++v ){
        if( !visited[ adjacency[u][v] ] ){
            dfs( adjacency[u][v] );
        }
    }
}



main()
{
    int vertex;
    S(vertex);


    for( int i = 0 ; i < vertex ; ++i ){    // Loop through all possible vertex
    if( !visited[ i ] ){          //if we have not visited any one component from that node
        components.push_back(Component());
        dfs( i );                  //we travel from node i the entire graph is formed
    }
}

    printf("Case %d: %d component (s) connected (s)\n" ,cont++, components.size());

        for (j=0;j<components.size();j++){
           Component& component = components[j];
           std::sort(component.begin(), component.end());
           for(int k=0; k<component.size(); k++) {
             printf("%d ", component[k]);
           }
           printf("\n");
        }
        components.clear();

return 0;
}
