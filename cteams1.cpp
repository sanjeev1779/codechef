#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

int main() {
	int N;
    scanf("%d",&N);
    priority_queue<pii,vector<pii>,less<pii> > young;
    priority_queue<pii,vector<pii>,greater<pii> > old;
    int sy=0, so=0;
    for (int i=1;i<=N;i++) {
    	int a,r;
    	scanf("%d %d",&a,&r);
		if (old.empty() || a<old.top().first) { young.push(make_pair(a,r)); sy+=r; }
		else { old.push(make_pair(a,r)); so+=r; }

    	if (young.size()>old.size()+1) {
    		pair<int,int> p = young.top();
    		young.pop(); old.push(p);
    		sy-=p.second; so+=p.second;
    	} else if (young.size()<old.size()) {
    		pair<int,int> p = old.top();
    		old.pop(); young.push(p);
    		so-=p.second; sy+=p.second;
    	}
    	printf("%d\n",abs(sy-so));
    }
    return 0;
}
