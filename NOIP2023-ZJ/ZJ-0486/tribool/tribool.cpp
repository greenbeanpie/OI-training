#include<bits/stdc++.h>
using namespace std;
int t,n,c,m;
int a[100005];
int ans;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			char v;
			cin>>v;
			int x;cin>>x;
			if(v=='T') a[x]=1;
			else if(v=='F') a[x]=2;
			else if(v=='U') a[x]=3;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==3) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
