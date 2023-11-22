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
int testid,T;
int n,m;
int opt[100005],px[100005],py[100005];

int a[100005],b[100005],ans;
int rev(int val){
	if(val < 2) return val ^ 1;
	return 2;
}
void check(){
	rep(i,1,n) b[i] = a[i];
	rep(i,1,m){
		if(opt[i] == 1){
			b[px[i]] = b[py[i]];
		}else if(opt[i] == 2){
			b[px[i]] = rev(b[py[i]]);
		}else{
			b[px[i]] = py[i];
		}
	}
	rep(i,1,n) if(a[i] != b[i]) return;

	int ssum = 0;
	rep(i,1,n) ssum += (a[i] == 2);
	chkmin(ans,ssum);
}

void dfs(int p){
	if(p == n + 1){
		check();
		return;
	}
	a[p] = 0;
	dfs(p + 1);
	a[p] = 1;
	dfs(p + 1);
	a[p] = 2;
	dfs(p + 1);
}

void solve(){
	scanf("%d%d",&n,&m);

	char op;
	rep(i,1,m){
		do{
			scanf("%c",&op);
		}while(op != '+' && op != '-' && op != 'T' && op != 'F' && op != 'U');
		if(op == '+'){
			opt[i] = 1;
			scanf("%d%d",&px[i],&py[i]);
		}else if(op == '-'){
			opt[i] = 2;
			scanf("%d%d",&px[i],&py[i]);
		}else{
			opt[i] = 3;
			scanf("%d",&px[i]);
			if(op == 'T') py[i] = 0;
			else if(op == 'F') py[i] = 1;
			else py[i] = 2;
		}
	}
	ans = 114514;
	dfs(1);
	printf("%d\n",ans);
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.ans","w",stdout);
	scanf("%d%d",&testid,&T);
	while(T--) solve();
	return 0;
}
//g++ B2.cpp -o B2 -Wall -Wshadow -O2 -std=c++14 -Wno-unused-result