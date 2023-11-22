#include<bits/stdc++.h>
using namespace std;
void fireio() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
}
const int maxn = 3010;
char g[maxn][maxn],dus;
int n,m,cntt[maxn][30];
int judd(int x,int y) {
	int pp = 1,pt = 26;
	while(cntt[x][pp]==0)	pp++;
	while(cntt[y][pt]==0)	pt--;
	if(pp==pt){
		return 0;
	}else if(pp<pt){
		return 1;
	}else{
		return 0;
	}
}
int main() {
	fireio();
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 1; i<=n; i++) {
		cin>>g[i]+1;
	}
	for(int i = 1; i<=n; i++) {
		for(int j = 1; j<=m; j++) {
			int bbb = g[i][j]-'a'+1;
			cntt[i][bbb]++;
		}
	}
	for(int i = 1; i<=n; i++) {
		int flag = 1;
		for(int j = 1; j<=n; j++) {
			if(i==j)	continue;
//
			if(judd(i,j)==0) {
				cout<<"0";
				flag = 0;
				break;
			}
		}
		if(flag)	cout<<"1";
	}
	return 0;
}