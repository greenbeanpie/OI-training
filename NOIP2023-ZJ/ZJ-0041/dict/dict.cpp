#include<bits/stdc++.h>
using namespace std;
int cnt[3005][26],f[3005],l[3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
//		if(i==728) cerr<<s<<'\n';
//		assert(s.size()==m);
		for(int j=1;j<=m;j++) cnt[i][s[j-1]-'a']++;
		for(int j=0;j<26;j++) if(cnt[i][j]){f[i]=j;break;}
		for(int j=25;j>=0;j--)if(cnt[i][j]){l[i]=j;break;}
//		if(l[i]==0) cerr<<i<<'\n';
//		cout<<f[i]<<' '<<l[i]<<'\n';
	}
	for(int i=1;i<=n;i++){
		bool ff=1;
		for(int j=1;j<=n&&ff;j++){
			if(j==i) continue;
			if(f[i]>=l[j]) ff=0;
		}
//		if(i==729) cerr<<f[i]<<' '<<l[i]<<' '<<ff<<'\n';
		cout<<ff;
	}
	cout<<'\n';
	return 0;
}

