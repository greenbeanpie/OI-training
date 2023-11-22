#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
constexpr int max_m=200000;
constexpr int max_n=max_m*2+1;
vector<int> pos;
vector<pii> vec[max_n+1];
array<int,3>que[max_m+1];
ll f[max_n+1];
void test(){
	int n,m,k,d;
	scanf("%d%d%d%d",&n,&m,&k,&d);
	pos.clear();
	pos.emplace_back(0);
	for(int i=1; i<=m; ++i){
		int&x=que[i][0],&y=que[i][1],&v=que[i][2];
		scanf("%d%d%d",&x,&y,&v);
		if(y>k){
			--i,--m;
			continue;
		}
		pos.emplace_back(x);
		pos.emplace_back(x-y);
	}
	sort(pos.begin(),pos.end());
	pos.erase(unique(pos.begin(),pos.end()),pos.end());
	n=pos.size()-1;
	for(int i=1; i<=n; ++i)
		vec[i].clear();
	// for(int i=0; i<=n; ++i)
	// 	fprintf(stderr,"pos %d: %d\n",i,pos[i]);
	for(int i=1; i<=m; ++i){
		const int r=lower_bound(pos.begin(),pos.end(),que[i][0])-pos.begin();
		const int l=lower_bound(pos.begin(),pos.end(),que[i][0]-que[i][1])-pos.begin();
		vec[r].emplace_back(l,que[i][2]);
	}
	f[0]=0;
	for(int i=1; i<=n; ++i){
		const ll v=ll(pos[i]-pos[i-1])*d;
		ll mx=0;
		for(int j=0; j<i; ++j)
			if(f[j]>mx)
				mx=f[j];
		f[i]=mx;
		for(int j=0; j<i; ++j)
			f[j]-=v;
		const int lft=lower_bound(pos.begin(),pos.end(),pos[i]-k)-pos.begin();
		for(const pii&p:vec[i])
			for(int j=lft; j<=p.first; ++j)
				f[j]+=p.second;
		// for(int j=0; j<=i; ++j)
		// 	fprintf(stderr,"%d: %lld\n",j,f[j]);
	}
	ll mx=0;
	for(int j=0; j<=n; ++j)
		if(f[j]>mx)
			mx=f[j];
	printf("%lld\n",mx);
}
int main(){
	int t;
	for(scanf("%*d%d",&t); t; test(),--t);
	return 0;
}