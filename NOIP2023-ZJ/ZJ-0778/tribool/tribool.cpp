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

int cnt;
int head[100005];
struct eg{
	int to,nxt,w;
}edge[200005];

void make(int u,int v,int w){
	edge[++cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}

int bel[100005],frp[100005],mrk[100005],vis[100005],flg,sz;
void dfs(int u){
	sz++;
	if(mrk[u]) flg = 0;
	for(int i = head[u];i;i = edge[i].nxt){
		int v = edge[i].to;
		if(vis[v] == -1){
			vis[v] = vis[u] ^ edge[i].w;
			dfs(v);
		}else if(vis[v] != (vis[u] ^ edge[i].w)){
			flg = 0;
		}
	}
}

void solve(){
	cnt = 0;
	memset(vis,-1,sizeof(vis));
	memset(head,0,sizeof(head));
	memset(bel,0,sizeof(bel));
	memset(frp,0,sizeof(frp));
	memset(mrk,0,sizeof(mrk));
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		bel[i] = i;
		frp[i] = 0;
	}

	char op;
	int p,q;
	rep(i,1,m){
		do{
			scanf("%c",&op);
		}while(op != '+' && op != '-' && op != 'T' && op != 'F' && op != 'U');

		scanf("%d",&p);
		if(op == '+'){
			scanf("%d",&q);
			bel[p] = bel[q];
			frp[p] = frp[q];
		}else if(op == '-'){
			scanf("%d",&q);
			bel[p] = bel[q];
			frp[p] = frp[q];
			if(bel[p]){
				frp[p] ^= 1;
				assert(frp[p] <= 1);
				continue;
			}
			if(frp[p] <= 1) frp[p] ^= 1;
		}else if(op == 'T'){
			bel[p] = 0;
			frp[p] = 0;
		}else if(op == 'F'){
			bel[p] = 0;
			frp[p] = 1;
		}else{
			assert(op == 'U');
			bel[p] = 0;
			frp[p] = 2;
		}
	}

	rep(u,1,n){
		if(bel[u]){
			make(u,bel[u],frp[u]);
			make(bel[u],u,frp[u]);
		}else if(frp[u] == 2){
			mrk[u] = 1;
		}
	}

	int ans = 0;
	rep(u,1,n){
		if(vis[u] != -1) continue;
		vis[u] = 0;
		flg = 1;sz = 0;
		dfs(u);
		if(!flg) ans += sz;
	}
	printf("%d\n",ans);
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&testid,&T);
	while(T--) solve();
	return 0;
}
//g++ B.cpp -o B -Wall -Wshadow -O2 -std=c++14 -Wno-unused-result -fsanitize=address,undefined
//memest all!