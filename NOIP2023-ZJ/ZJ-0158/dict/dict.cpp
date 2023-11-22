#include <bits/stdc++.h>
using namespace std;
const int N=3010;
int n,m,b[N][30],c[N];
string a[N];
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;++i) {
		cin>>a[i];
		for (int j=0;j<a[i].size();++j) b[i][a[i][j]-'a']++;
		for (int j=0;j<=25;++j) if (b[i][j]!=0) {c[i]=j; break;}
		for (int j=24;j>=0;--j) b[i][j]+=b[i][j+1];
	}
	for (int i=1;i<=n;++i) {
		int flag=1;
		for (int j=1;j<=n;++j) if (i!=j) {
			if (b[j][c[i]+1]<=0) {flag=0; break;}
		}
		cout<<flag;
	}
	return 0;
}
