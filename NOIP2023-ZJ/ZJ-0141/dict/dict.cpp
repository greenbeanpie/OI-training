#include <bits/stdc++.h>
#include <string>
//#define int long long
using namespace std;
const int N = 3e3+5;
const int M = 30;
int n, m;
string s[N];
namespace point1 {
	inline bool cmp(char fi,char se) {
		return fi>se;
	}

	inline void solve() {
		for(int i=1; i<=n; ++i) sort(s[i].begin(),s[i].end(),cmp);
		string mx,smx;
		mx=min(s[1],s[2]),smx=max(s[1],s[2]);
		for(int i=3; i<=n; ++i) {
			smx=min(smx,s[i]);
			if(smx<mx) swap(smx,mx);
		}
		for(int i=1; i<=n; ++i) {
			string x=s[i]==mx?smx:mx;
			sort(s[i].begin(),s[i].end());
			if(s[i]<x) cout<<1;
			else cout<<0;
		}
		exit(0);
	}
}

namespace point2 {
	inline void solve() {
		puts("1");
		exit(0);
	}
}

namespace point3 {
	int mx[M],smx[M],cnt[N][M],Now[M];
	inline bool check(int a[M],int b[M]) {
		for(int i=25; ~i; --i) if(a[i]!=b[i]) return b[i]<a[i];
		return 0;
	}
	inline void solve() {
		for(int i=1; i<=n; ++i) for(int j=0; j<m; ++j) cnt[i][s[i][j]-'a']++;
		if(check(cnt[1],cnt[2])) {
			for(int j=0; j<26; ++j) smx[j]=cnt[1][j];
			for(int j=0; j<26; ++j) mx[j]=cnt[2][j];
		} else {
			for(int j=0; j<26; ++j) smx[j]=cnt[2][j];
			for(int j=0; j<26; ++j) mx[j]=cnt[1][j];
		}
		for(int i=3; i<=n; ++i) {
			if(check(smx,cnt[i])) for(int j=0; j<26; ++j) smx[j]=cnt[i][j];
			if(check(mx,smx)) for(int j=0; j<26; ++j) swap(smx[j],mx[j]);
		}
//		for(int j=0; j<=4; ++j) cout<<mx[j]<<" ";cout<<endl;
		for(int i=1; i<=n; ++i) {
			bool flag=1;
			for(int j=0; j<26; ++j) flag&=cnt[i][j]==mx[j];
			for(int j=0; j<26; ++j) Now[j]=flag?smx[j]:mx[j];
			int fr=0,en=0;
			for(int j=25; ~j; --j) if(cnt[i][j]) fr=j;
			for(int j=0; j<26; ++j) if(Now[j]) en=j;
//			cout<<"\n"<<fr<<" "<<en<<"---\n";
//			for(int j=0; j<=5; ++j) cout<<Now[j]<<" ";cout<<endl;
//			for(int j=0; j<=5; ++j) cout<<cnt[i][j]<<" ";cout<<endl;
			if(fr<en) cout<<"1";
			else if(fr>en) cout<<"0";
			else if(fr==en) cout<<"0";
		}
		exit(0);
	}
}
signed main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; ++i) cin>>s[i];
	if(n==1) point2 :: solve();
	if(n<=1000) point1 :: solve();
	point3 :: solve();
	return 0;
}
/*
4 7
aabcdde
aaaabdd
aaaabdd
dddeeff
*/
