#include<bits/stdc++.h>
using namespace std;
int c,t;
//T=1,F=2,U=3;
int a[100010];
int vis[100010];
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c==3||c==4){
	while(t--) {
		int n,m;
		cin>>n>>m;
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		while(m--) {
			char opt;
			cin>>opt;
			if(opt=='U') {
				int k;
				cin>>k;
				a[k]=3;
				vis[k]=1;
			}
			if(opt=='T') {
				int k;
				cin>>k;
				a[k]=1;
				vis[k]=1;
			}
			if(opt=='F') {
				int k;
				cin>>k;
				a[k]=2;
				vis[k]=1;
			}
			
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==3&&vis[i]==1)ans+=1;
		}
		cout<<ans<<endl;
	}
	}
	return 0;
}
