#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int p[100001];
int tax[100001];

int find( int a)
{
	int root = a;
	while ( p[a] != a)
		a = p[a];
	while ( root != a)
	{
	  int root2 = p[root];
	  p[root] = a;
	  root = root2;
	}
	return a;
}

main()
{


		int n,m,a,b,q,i,root,root2,counter;
		scanf("%d %d",&n,&m);
		for (i = 0; i < n; i++)
			p[i] = i;


		for ( i = 0; i < m;i++)
		{
			scanf("%d %d",&a,&b);
			root = find(a);
			root2 = find(b);
			p[root2] = root;

		}

		for(i=0;i<n;i++)
            scanf("%d",&tax[i]); // storing tax of i
		counter = 0;
		for ( i = 0; i < n;i++)
		{
			if ( p[i] == i)
			  counter++;
		}
		printf("%d\n",counter);

return 0;
}
