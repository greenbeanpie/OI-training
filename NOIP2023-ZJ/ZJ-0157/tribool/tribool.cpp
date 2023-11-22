#include <bits/stdc++.h>

using namespace std;

int read() {
	int x=0, f=0; char c=getchar();
	while (!isdigit(c)) f|=c=='-', c=getchar();
	while (isdigit(c)) x=(x<<3)+(x<<1)+(c^48), c=getchar();
	return f ? -x : x;
}

const int N=1e5+10;
int n, m, u[N], w[N], ans;
struct node {
	int a, b, c;
} v[N];

void check() {
	int cnt=0;
	for (int i=1; i<=n; i++) u[i]=w[i], cnt+=(u[i]==2);
	for (int i=1; i<=m; i++) {
		if (v[i].a==1) u[v[i].b]=1;
		if (v[i].a==2) u[v[i].b]=0;
		if (v[i].a==3) u[v[i].b]=2;
		if (v[i].a==4) u[v[i].b]=u[v[i].c];
		if (v[i].a==5) u[v[i].b]=(u[v[i].c]==2) ? 2 : (u[v[i].c]^1);
	}
	for (int i=1; i<=n; i++)
		if (u[i]!=w[i]) return;
	ans=min(ans, cnt);
}

void dfs(int x) {
	if (x==n+1) {
		check();
		return;
	}
	w[x]=0, dfs(x+1);
	w[x]=1, dfs(x+1);
	w[x]=2, dfs(x+1);
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int C=read(), T=read();
	while (T--) {
		n=read(), m=read();
		for (int i=1; i<=m; i++) {
			char c; c=getchar();
			while (c!='T' && c!='F' && c!='U' && c!='+' && c!='-') c=getchar();
			if (c=='T') v[i]=(node){1, read(), 0};
			if (c=='F') v[i]=(node){2, read(), 0};
			if (c=='U') v[i]=(node){3, read(), 0};
			if (c=='+') {
				int x=read(), y=read();
				v[i]=(node){4, x, y};
			}
			if (c=='-') {
				int x=read(), y=read();
				v[i]=(node){5, x, y};
			}
		}
		if (C>=1 && C<=2) {
			ans=n;
			dfs(1);
			printf("%d\n", ans);
			continue;
		}
		if (C>=3 && C<=4) {
			ans=0;
			for (int i=1; i<=n; i++) u[i]=0;
			for (int i=1; i<=m; i++) {
				if (v[i].a==1) u[v[i].b]=1;
				if (v[i].a==2) u[v[i].b]=0;
				if (v[i].a==3) u[v[i].b]=2;
			}
			for (int i=1; i<=n; i++) ans+=(u[i]==2);
			printf("%d\n", ans);
			continue;
		}
		if (C>=5 && C<=6) {
			ans=n; int ans1=n+1;
			for (int i=1; i<=n; i++) u[i]=0;
			while (ans!=ans1) {
				ans1=ans; ans=0;
				for (int i=1; i<=m; i++) {
					if (v[i].a==3) u[v[i].b]=2;
					if (v[i].a==4) u[v[i].b]=u[v[i].c];
				}
				for (int i=1; i<=n; i++)
					if (u[i]==2) ans++;
			}
			printf("%d\n", ans);
			continue;
		}
	}
	return 0;
}