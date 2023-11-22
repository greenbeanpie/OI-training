#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0; bool f=1; char c=getchar();
	while(c<48||c>57) f^=(c==45), c=getchar();
	while(c>=48&&c<=57) x=x*10+(c^48), c=getchar();
	return (f?x:-x);
}
int n, m, a[500105], b[500105];
bool query(int x, int y, bool t){
	if(x>n) return (y==m&&(t?a[n]>b[m]:a[n]<b[m]));
	bool c=0;
	if(t?a[x]>b[y]:a[x]<b[y])
		c|=query(x+1, y, t);
	for(int i=y+1; i<=m; i++)
		if(t?a[x]<=b[i]:a[x]>=b[i]) break;
		else c|=query(x+1, i, t);
	return c;
}
int f[500105][2], g[500105][2];
int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int id=read(), q;
	n=read(), m=read(), q=read();
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1; i<=m; i++) b[i]=read();
	putchar((query(1, 1, 0)|query(1, 1, 1))^48);
	while(q--){
		int s=read(), t=read();
		for(int i=1; i<=s; i++) f[i][0]=read(), f[i][1]=read();
		for(int i=1; i<=t; i++) g[i][0]=read(), g[i][1]=read();
		for(int i=1; i<=s; i++) swap(a[f[i][0]], f[i][1]);
		for(int i=1; i<=t; i++) swap(b[g[i][0]], g[i][1]);
		putchar((query(1, 1, 0)|query(1, 1, 1))^48);
		for(int i=1; i<=s; i++) swap(a[f[i][0]], f[i][1]);
		for(int i=1; i<=t; i++) swap(b[g[i][0]], g[i][1]);
	}
	putchar('\n');
	return 0;
}