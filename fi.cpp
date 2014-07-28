#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
#define LL_max 200000000000
#define mod 1000000007

#define LL long long
#define mp make_pair
#define pb push_back

vector<int> cnt[100001];

int main()
{
	int n, q;
	cin>> n>> q;
	int a[n];
	for(int i=0; i<n; i++){
		cin>> a[i];
		for(int j=1; j<=sqrt(a[i]); j++)
		if(a[i]%j==0)
		{
			//cout << i<< " "<< j<< " "<< a[i]<< endl;
			cnt[j].pb(i);
			if(j*j!=a[i])
				cnt[a[i]/j].pb(i);
		}
	}

	for(int i=0; i<13; i++, cout << endl){
		cout << i<< " ";
		for(int j=0; j<cnt[i].size(); j++)
		cout << cnt[i][j]<< " ";
	}
	cout << endl;

	while(q--)
	{
		int L, R, k;
		cin>> L>> R>> k;
		L--; R--;
		if(k==1)
		{
			cout << R-L+1<< endl;
			continue;
		}
		int kk=k;
		int res=upper_bound(cnt[kk].begin(), cnt[kk].end(), R)-lower_bound(cnt[kk].begin(), cnt[kk].end(), L);
		cout << res<< endl;
	}

	return 0;
}
