#include<bits/stdc++.h>
using namespace std;
int C,n,m,T,k1,k2,p[1000010],v[1000010],l[500010],r[500010],a[500010],b[500010],ans;
void dfs(int st){
	if(st>n){
		if(r[n]==m&&l[1]==1)ans=1;
		return;
	}
	l[st]=r[st-1];
	for(int i=l[st];i<=m;i++){
		if(a[1]<b[1]&&a[st]>=b[i]||a[1]>b[1]&&a[st]<=b[i])break;
		r[st]=i,dfs(st+1);
	}
	l[st]=r[st-1]+1;
	for(int i=l[st];i<=m;i++){
		if(a[1]<b[1]&&a[st]>=b[i]||a[1]>b[1]&&a[st]<=b[i])break;
		r[st]=i,dfs(st+1);
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>C>>n>>m>>T;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	if(a[1]<b[1]&&a[n]<b[m]||a[1]>b[1]&&a[n]>b[m])dfs(1);
	cout<<ans;
	while(T--){
		ans=0;
		cin>>k1>>k2;
		for(int i=1;i<=k1;i++)cin>>p[i]>>v[i],swap(a[p[i]],v[i]);
		for(int i=1;i<=k2;i++)cin>>p[i+k1]>>v[i+k1],swap(b[p[i+k1]],v[i+k1]);
		if(a[1]<b[1]&&a[n]<b[m]||a[1]>b[1]&&a[n]>b[m])dfs(1);
		cout<<ans;
		for(int i=1;i<=k1;i++)a[p[i]]=v[i];
		for(int i=1;i<=k2;i++)b[p[i+k1]]=v[i+k1];
	}
	return 0;
}