#include <bits/stdc++.h>
#define rep(i,j,k) for(int i = (j);i <= (k);i++)
#define per(i,j,k) for(int i = (j);i >= (k);i--)
#define ll long long
#define pii pair<int,int>
#define SZ(S) (int)S.size()
#define mkp make_pair
#define uint unsigned int
#define eb emplace_back
using namespace std;

template <class P>
void chkmax(P &x,P y){
	if(x < y) x = y;
}

template <class Q>
void chkmin(Q &x,Q y){
	if(x > y) x = y;
}
int testid,T;
int n,m,K,d;
vector <pii> P[200005];

ll a[200005],dp[200005];
void solve(){
	scanf("%d%d%d%d",&n,&m,&K,&d);
	rep(i,1,n) P[i].clear();
	rep(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		P[x].eb(mkp(x - y + 1,v));
	}
	ll ans = 0;
	rep(i,1,n){
		dp[i] = 0;
		if(i >= 2) chkmax(ans,dp[i - 2]);
		a[i] = ans;

		for(pii I:P[i]) rep(k,1,I.first) a[k] += I.second;
		rep(j,max(1,i - K + 1),i) chkmax(dp[i],a[j] - 1ll * d * (i - j + 1));
	}
	chkmax(ans,dp[n - 1]);
	chkmax(ans,dp[n]);
	printf("%lld\n",ans);
}

int main(){
	freopen("run.in","r",stdin);
	freopen("run.ans","w",stdout);
	scanf("%d%d",&testid,&T);
	while(T--) solve();
	return 0;
}
//g++ D2.cpp -o D2 -Wall -Wshadow -O2 -std=c++14 -Wno-unused-result