/*Author : Vineet Kumar */
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
using namespace std;

#define FOR(i,a,b) 	for(int i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) 	FOR(i,0,n)
#define INF		INT_MAX
#define ALL(x) 		x.begin(),x.end()
#define LET(x,a)	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v) 	IFOR(it,v.begin(),v.end())
#define pb 		push_back
#define sz(x) 		int(x.size())
#define mp 		make_pair
#define fill(x,v)	memset(x,v,sizeof(x))
#define max(a,b)	((a)>(b)?(a):(b))
#define min(a,b)	((a)<(b)?(a):(b))
#define	si(n)		scanf("%d",&n)
#define pi(n)		printf("%d ",n)
#define pil(n)		printf("%d\n",n)
#define sd(n)		scanf("%lf",&n)
#define sl(n)		scanf("%lld",&n)
#define pl(n)		printf("%lld\n",n)
#define ss(n)		scanf("%s",n)
#define scan(v,n)	vector<int> v;rep(i,n){ int j;si(j);v.pb(j);}
#define mod (int)(1e9 + 7)
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define maxn 1000001
int id[maxn],siz[maxn];
int root(int i)
{
	while(i!=id[i])
	{
		id[i] = id[id[i]];
		i = id[i];
	}
	return i;
}
bool connected(int p,int q)
{
	return root(p) == root(q);
}
void Union(int p,int q)
{
	int i = root(p);
	int j = root(q);
	if(i==j)
		return;
	if(siz[i] < siz[j])
	{
		id[i] = j;
		siz[j] += siz[i];
	}
	else
	{
		id[j] = i;
		siz[i] += siz[j];
	}
}
int main()
{
	int i,j,t;
	//for(si(t);t--;)
freopen("C:\\Users\\cyber\\Desktop\\codechef\\input.txt", "r", stdin);
	LL n;
	cin >> n;
	int m;
	si(m);
	rep(i,n+1)
	{
		id[i] = i;
		siz[i] = 1;
	}
	int x,y;
	rep(i,m)
	{
		si(x);
		si(y);
		Union(x,y);
	}
	set<PI> q;
	FOR(i,1,n+1)
	{
		j = root(i);
		q.insert(mp(j,siz[j]));
	}
	LL ans = (n*(n-1))/2,l;
	EACH(it,q)
	{
		l = (*it).second;
		ans -= (l*(l-1))/2;
	}
	cout << ans << endl;
	return 0;
}
