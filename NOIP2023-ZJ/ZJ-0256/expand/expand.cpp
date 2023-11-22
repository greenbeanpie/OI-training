#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1010;
int c,n,m,q;
int a[N],b[N];
void solve(){
	int i,j;
	if(n==1&&m==1){
		if(a[1]!=b[1]) cout<<"1";
		else cout<<0;
		return;
	}
	if(n==1&&m==2){
		if(a[1]<b[1]&&a[1]<b[2]) cout<<1;
		else if(a[1]>b[1]&&a[1]>b[2]) cout<<1;
		else cout<<0;
		return;
	}
	if(n==2&&m==1){
		if(b[1]<a[1]&&b[1]<a[2]) cout<<1;
		else if(b[1]>a[1]&&b[1]>a[2]) cout<<1;
		else cout<<0;
		return;
	}
	if(n==2&&m==2){
		if(a[1]<b[1]&&a[2]<b[2]) cout<<1;
		else if(a[1]>b[1]&&a[2]>b[2]) cout<<1;
		else cout<<0;
		return;
	}
	if(a[1]<b[1]&&a[n]>b[m]){cout<<0;return;}
	if(a[1]>b[1]&&a[n]<b[m]){cout<<0;return;}
	cout<<0;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int i,j;
	int T;
	cin>>c>>n>>m>>q;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	solve();
	for(i=1;i<=q;i++){
		int k,kk;
		cin>>k>>kk;
		for(j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[x]=y;
		}
		for(j=1;j<=kk;j++){
			int x,y;
			cin>>x>>y;
			b[x]=y;
		}solve();
	}
}
