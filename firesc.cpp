#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;

int bfs(int start, vector<int> node[], bool visited[])
{
	queue<int> q;
	q.push(start);
	int count = 0;
	while(!q.empty())
	{
		int s = q.front();
		q.pop();
		if(visited[s]==false)
		{
			count++;
			visited[s]=true;
			for(int i=0;i<node[s].size();i++)
			{
				q.push(node[s][i]);
				//visited[node[s][i]]=true;
			}
		}
	}
	return count;
}

int main()
{
	int t;
	freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
	cin>>t;
	while(t--){
		int n,m,FE=0;long long count=1;//FE=FireEscapes
		cin>>n>>m;
		vector <int> node[n+1];
		bool visited[n+1];
		fill(visited,visited+n,false);
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			node[a].push_back(b);
			node[b].push_back(a);
		}

		for(int i=1;i<n+1;i++)
		{
			if(visited[i] == false)
			{
				int b = bfs(i,node,visited);

				//count = mulmod(count,b,1000000007);
				count = (count * b )% 1000000007;
				FE++;
				//cout<<"count:"<<count<<endl;
			}
		}
		cout<<FE<<" "<<count<<endl;
	}
	return 0;
}
