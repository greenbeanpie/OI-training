#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
char s[N][N];
bool b[N];
int t[N][30];
int mi[N];

void ck(const int &x) {
	for(int i=1; i<=n; ++i) {
		if(i==x)continue;
		if(t[i][mi[x]]==m){
			b[x]=0;
			return;
		}
	}
	b[x]=1;
	return;
}

void sol() {
	for(int i=1;i<=n;++i)mi[i]=26;
	for(int i=1; i<=n; ++i) {
		for(int j=0; j<m; ++j){
			++t[i][s[i][j]-'a'];
			if(mi[i]>s[i][j]-'a')mi[i]=s[i][j]-'a';
		}
		for(int j=1;j<26;++j)t[i][j]+=t[i][j-1];
	}
	for(int i=1; i<=n; ++i)ck(i);
	for(int i=1;i<=n;++i){
		if(b[i])cout<<1;
		else cout<<0;
	}
}

int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1; i<=n; ++i)cin>>s[i];
	if(n==1) {
		cout<<1;
		return 0;
	} else sol();
	return 0;
}