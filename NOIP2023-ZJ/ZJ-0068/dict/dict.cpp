#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int const N=3e3+10;
int n,m,ct=1,siz[N];
ull qz[N][N],sq[N];
string s[N],t[N];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		cin>>s[i];
		sort(s[i].begin(),s[i].end());
		t[i]=s[i];
		reverse(t[i].begin(),t[i].end());
		for (int j=1;j<=m;++j)
			qz[i][j]=qz[i][j-1]*233+(t[i][j-1]-'a'+5);
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j)
			sq[j]=sq[j-1]*233+(s[i][j-1]-'a'+5);
		int tag=1;
		for (int j=1;j<=n;++j){
			if (i==j) continue;
			int l=1,r=m,ans=0;
			while (l<=r){
				int mid=(l+r)>>1;
				if (sq[mid]==qz[j][mid]) l=(ans=mid)+1;
				else r=mid-1;
			}
			if (ans==m){tag=0;break;}
			if (s[i][ans]>t[j][ans]){tag=0;break;}
		}
		cout<<tag;
	}
	return cout<<'\n',0;
}