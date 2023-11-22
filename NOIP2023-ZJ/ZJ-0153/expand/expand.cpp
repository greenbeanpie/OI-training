#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int op,n,m,q,a[N],b[N],c[N],d[N],flag;
void dfs(int now,int p){
	if(flag)return;
	if(now==m+1){
		bool f=1;
		for(int i=p;i<=n;i++){
			if(a[i]<=b[m])f=0;
		}
		if(f)flag=1;
		return;
	}
	for(int i=p;i<=n;i++){
		bool f=1;
		if(a[i]<=b[now])break;
		for(int j=now;j<=m;j++){
			if(a[i]>b[j])dfs(j+1,i+1);
			else break;
		}
	}
}
void solve(){
	if(1ll*(a[1]-b[1])*(a[n]-b[m])<=0)cout<<0;
	else {
		if(a[1]<b[1]){
			for(int i=1;i<=min(n,m);i++)swap(a[i],b[i]);
			for(int i=min(n,m)+1;i<=max(n,m);i++)swap(a[i],b[i]);
			swap(n,m);
		}
		if(op<=4){
			flag=0;
			dfs(1,1);
			cout<<flag;
		}else cout<<1;
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>op>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i],c[i]=a[i];
	for(int i=1;i<=m;i++)cin>>b[i],d[i]=b[i];
	solve();
	while(q--){
		int kx,ky;
		cin>>kx>>ky;
		for(int i=1;i<=max(n,m);i++)a[i]=b[i]=0;
		for(int i=1;i<=n;i++)a[i]=c[i];
		for(int i=1;i<=m;i++)b[i]=d[i];
		for(int i=1,p,x;i<=kx;i++)cin>>p>>x,a[p]=x;
		for(int i=1,p,x;i<=ky;i++)cin>>p>>x,b[p]=x;
		solve();
	}
	return 0;
}
