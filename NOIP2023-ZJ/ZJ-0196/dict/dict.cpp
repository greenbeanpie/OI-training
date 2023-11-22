#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
char s1[N][N],s2[N][N];
inline bool cmp1(char x,char y) {
	return x < y;
}
inline bool cmp2(char x,char y) {
	return x > y;
}
inline bool check(int u,int v) {
	if(!u||!v) return 0;
	for(int i=1; i<=m; i++) {
		if(s2[u][i]<s2[v][i]) return 1;
		if(s2[u][i]>s2[v][i]) return 0;
	}
	return 0;
}
inline int query(int u,int v) {
	if(!v) return 1;
	for(int i=1; i<=m; i++) {
		if(s1[u][i]<s2[v][i]) return 1;
		if(s1[u][i]>s2[v][i]) return 0;
	}
	return 0;
}
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%s",s2[i]+1);
		for(int j=1; j<=m; j++) s1[i][j]=s2[i][j];
		sort(s1[i]+1,s1[i]+m+1,cmp1);
		sort(s2[i]+1,s2[i]+m+1,cmp2);
	}
	int p1=0,p2=0;
	for(int i=1; i<=n; i++) {
		if(!p1||check(i,p1)) p2=p1,p1=i;
		else if(!p2||check(i,p2)) p2=i;
	}
	for(int i=1; i<=n; i++) {
		if(i==p1) cout<<query(i,p2);
		else cout<<query(i,p1);
	}
	return 0;
}
