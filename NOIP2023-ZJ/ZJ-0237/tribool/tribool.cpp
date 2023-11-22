//0=U 1=T 2=F !=(v*2)%3
#include <bits/stdc++.h>

namespace Solve {

const int maxn=1e5;
int n, m, head[maxn*3+5], nxt[maxn*3*2+5], to[maxn*3*2+5], edgenum, cnt, ck;
char s[5];
int vis[maxn*3+5];

void add(int u, int v) {
	++edgenum;
	nxt[edgenum]=head[u];
	to[edgenum]=v;
	head[u]=edgenum;
	return ;
}

struct node {
	bool sure, ton;
	int val;
}var[maxn+5];

int id(int u, int mod) {
	if(u%mod==0) return mod;
	return u%mod;
}

void dfs(int u) {
	vis[u]=ck;
	if(u<=n) {
		++cnt;
	}
	for(int e=head[u]; e; e=nxt[e]) {
		if(vis[to[e]]==ck) continue;
		if(var[id(to[e], n)].sure&&var[id(to[e], n)].val!=(to[e]-1)/n) {
			cnt=-1;
		}
		if(vis[id(to[e]+n, n*3)]==ck||vis[id(to[e]+n*2, n*3)]==ck) {
			cnt=-1;
		}
		dfs(to[e]);
	}
	return ;
}

void solve() {
	memset(head, 0, sizeof(head));
	memset(nxt, 0, sizeof(nxt));
	edgenum=0;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) {
		var[i].sure=false;
		var[i].ton=true;
		var[i].val=i;
	}
	int a, b;
	for(int i=1; i<=m; ++i) {
		scanf("%s", s);
		if(s[0]=='T') {
			scanf("%d", &a);
			var[a].sure=true;
			var[a].val=1;
		} else if(s[0]=='F') {
			scanf("%d", &a);
			var[a].sure=true;
			var[a].val=2;
		} else if(s[0]=='U') {
			scanf("%d", &a);
			var[a].sure=true;
			var[a].val=0;
		} else if(s[0]=='+') {
			scanf("%d%d", &a, &b);
			var[a]=var[b];
		} else {
			scanf("%d%d", &a, &b);
			var[a]=var[b];
			if(var[b].sure) {
				var[a].val=(var[a].val*2)%3;
			} else {
				var[a].ton=!var[a].ton;
			}
		}
	}
	for(int i=1; i<=n; ++i) {
		if(!var[i].sure) {
			if(var[i].ton) {
				add(i, var[i].val);
				add(var[i].val, i);
				add(i+n, var[i].val+n);
				add(var[i].val+n, i+n);
				add(i+n*2, var[i].val+n*2);
				add(var[i].val+n*2, i+n*2);
			} else {
				add(i, var[i].val);
				add(var[i].val, i);
				add(i+n, var[i].val+n*2);
				add(var[i].val+n*2, i+n);
				add(i+n*2, var[i].val+n);
				add(var[i].val+n, i+n*2);
			}
		}
	}
	int ans=0;
	memset(vis, 0, sizeof(vis));
	for(int i=1; i<=n; ++i) {
		if(vis[i]) continue;
		int mini=2100000000;
		if(!var[i].sure||var[i].val==0) {
			cnt=0;
			++ck;
			dfs(i);
//			std::cerr<<'a'<<cnt<<std::endl;
			if(cnt!=-1) {
				mini=std::min(mini, cnt);
			}
		}
		if(!var[i].sure||var[i].val==1) {
			cnt=0;
			++ck;
			dfs(i+n);
//			std::cerr<<'b'<<cnt<<std::endl;
			if(cnt!=-1) {
				mini=std::min(mini, cnt);
			}
		}
		if(!var[i].sure||var[i].val==2) {
			cnt=0;
			++ck;
			dfs(i+n*2);
//			std::cerr<<'c'<<cnt<<std::endl;
			if(cnt!=-1) {
				mini=std::min(mini, cnt);
			}
		}
		ans+=mini;
	}
	printf("%d\n", ans);
	return ;
}

}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while(t--) {
		Solve::solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}