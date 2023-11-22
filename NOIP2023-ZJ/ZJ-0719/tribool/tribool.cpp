#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,m;
signed main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--) {
		cin>>n>>m;
		long double x[n+10];
		for(int i=1; i<=n; ++i) x[i]=i;
		char v[m+10];
		int a[m+10],b[m+10];
		for(int i=1; i<=m; ++i) {
			cin>>v[i];
			if(v[i]=='T'||v[i]=='U'||v[i]=='F') {
				cin>>a[i];
				b[i]=0;
			} else {
				cin>>a[i]>>b[i];
			}
		}
		for(int i=1; i<=m; ++i) {
			if(v[i]=='U') x[a[i]]=0;
			if(v[i]=='T'||v[i]=='F') x[a[i]]=a[i];
			if(v[i]=='+') {
				if(x[b[i]]==-x[a[i]]) x[a[i]]=0;
				else x[a[i]]=x[b[i]];
			}
			if(v[i]=='-') {
				if(x[b[i]]==x[a[i]]) x[a[i]]=0;
				else x[a[i]]=-x[b[i]];
			}
		}
		bool flag[n+10];
		for(int i=1; i<=n; ++i) flag[i]=false;
		for(int i=m; i>=1; i--) {
			if(v[i]=='+'&&x[a[i]]!=0&&flag[a[i]]==false) {
				if(x[b[i]]==-x[a[i]]) x[a[i]]=0;
				else x[a[i]]=x[b[i]];
				flag[a[i]]=true;
			}
			if(v[i]=='-'&&x[a[i]]!=0&&flag[a[i]]==false) {
				if(x[b[i]]==x[a[i]]) x[a[i]]=0;
				else x[a[i]]=-x[b[i]];
				flag[a[i]]=true;
			}
		}
		for(int i=1; i<=m; ++i) {
			if((v[i]=='+'||v[i]=='-')&&(x[a[i]]==0||x[b[i]]==0)) {
				x[a[i]]=0;
				x[b[i]]=0;
			}
		}
		int ans=0;
		for(int i=1; i<=n; ++i) {
//			cout<<x[i];
			if(x[i]==0) ans++;
		}
		cout<<ans;
	}
	return 0;
}
/*
1 1
3 4
- 2 1
- 3 2
+ 1 3
U 1
*/
