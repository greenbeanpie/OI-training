#include <bits/stdc++.h>
using namespace std;
int n, m, w[3005][28], p[2]={1, 0};
bool cmp(int a, int b){
	for(int i=26; i>=1; i--)
		if(w[a][i]!=w[b][i])
			return w[a][i]<w[b][i];
	return 0;
}
bool fscmp(int a, int b){
	if(!b) return 1;
	int s=1, t=26;
	while(!w[a][s]) ++s;
	while(!w[b][t]) --t;
	return s<t;
}
int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		string s; cin>>s;
		for(int j=0; j<m; j++)
			++w[i][s[j]^96];
	}
	for(int i=2; i<=n; i++)
		if(cmp(i, p[0])) p[0]=i;
	for(int i=1; i<=n; i++){
		if(i==p[0]) continue;
		if(p[1]&&!cmp(i, p[1])) continue;
		p[1]=i;
	}
	for(int i=1; i<=n; i++)
		putchar(fscmp(i, p[p[0]==i])^48);
	putchar('\n');
	return 0;
}