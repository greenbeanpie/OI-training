#include<bits/stdc++.h>
#define maxn int(5e5+5)
using namespace std;
int n, m, a[maxn], b[maxn], c[maxn], d[maxn];
bool pstive;
bool dfs(int x, int place) {
	if(pstive?(c[place]-d[x]<=0):c[place]-d[x]>=0) return 0;
	if(x>=m) {
		for(int i = place+1; i <= n; i++)
			if(pstive?(c[i]-d[m]<=0):(c[i]-d[m]>=0)) return 0;
 		return 1;
	}
	if(place>=n) {
		for(int i = x+1; i <= m; i++)
			if(pstive?(c[n]-d[i]<=0):(c[n]-d[i]>=0)) return 0;
 		return 1;
	}
	bool ret = 0;
	while(place<=n
	&& (pstive?(c[place]-d[x]>0):(c[place]-d[x]<0))) {
		ret|=dfs(x+1, place);
		place++;
	}
	return ret;
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int op, q;
	cin>>op>>n>>m>>q;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1; i <= m; i++) cin>>b[i];
	for(int i = 1; i <= n; i++) c[i]=a[i];
	for(int i = 1; i <= m; i++) d[i]=b[i];
	if(c[1]-d[1]>0) pstive = 1;
	else if(c[1]-d[1]<0) pstive = 0;
	else cout << 0;
	if(c[1]!=d[1]) {
		if((c[n]-d[m]>=0&&pstive==0)||(c[n]-d[m]<=0&&pstive==1)) cout << 0;
		else cout << dfs(1, 1);
	}
	int k1, k2, p1, p2;
	while(q--) {
		cin>>k1>>k2;
		for(int i = 1; i <= n; i++) c[i]=a[i];
		for(int i = 1; i <= m; i++) d[i]=b[i];
		for(int i = 1; i <= k1; i++) {cin>>p1>>p2; c[p1]=p2;}
		for(int j = 1; j <= k2; j++) {cin>>p1>>p2; d[p1]=p2;}
		if(c[1]-d[1]>0) pstive = 1;
		else if(c[1]-d[1]<0) pstive = 0;
		else {cout << 0; continue;}
		if((c[n]-d[m]>=0&&pstive==0)||(c[n]-d[m]<=0&&pstive==1)) {cout << 0; continue;}
		cout << dfs(1, 1);
	}
	cout << endl;
	return 0;
}
