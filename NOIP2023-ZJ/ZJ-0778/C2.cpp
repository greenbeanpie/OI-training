#include <bits/stdc++.h>
#define rep(i,j,k) for(int i = (j);i <= (k);i++)
#define per(i,j,k) for(int i = (j);i >= (k);i--)
#define ll long long
#define pii pair<int,int>
#define SZ(S) (int)S.size()
#define mkp make_pair
#define uint unsigned int
using namespace std;

template <class P>
void chkmax(P &x,P y){
	if(x < y) x = y;
}

template <class Q>
void chkmin(Q &x,Q y){
	if(x > y) x = y;
}
int testid,n,m,q;
int aa[500005],bb[500005],a[500005],b[500005];

int dp[2005][2005];
int solve(){
	int frp = 0;
	if(a[1] < b[1]){
		frp = 1;
		swap(n,m);
		rep(i,1,max(n,m)) swap(a[i],b[i]);
	}
	dp[1][1] = (a[1] > b[1]);
	rep(i,1,n){
		rep(j,1,m){
			if(i == 1 && j == 1) continue;
			dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
			if(a[i] <= b[j]) dp[i][j] = 0;
		}
	}

	if(frp){
		swap(n,m);
		return dp[m][n];
	}
	return dp[n][m];
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.ans","w",stdout);
	scanf("%d%d%d%d",&testid,&n,&m,&q);
	rep(i,1,n) scanf("%d",&aa[i]);
	rep(i,1,m) scanf("%d",&bb[i]);

	copy(aa + 1,aa + n + 1,a + 1);
	copy(bb + 1,bb + m + 1,b + 1);
	printf("%d",solve());

	rep(i,1,q){
		copy(aa + 1,aa + n + 1,a + 1);
		copy(bb + 1,bb + m + 1,b + 1);
		int kx,ky,pos,val;
		scanf("%d%d",&kx,&ky);
		while(kx--){
			scanf("%d%d",&pos,&val);
			a[pos] = val;
		}
		while(ky--){
			scanf("%d%d",&pos,&val);
			b[pos] = val;
		}
		printf("%d",solve());
	}
	printf("\n");
	return 0;
}
//g++ C2.cpp -o C2 -Wall -Wshadow -O2 -std=c++14 -Wno-unused-result