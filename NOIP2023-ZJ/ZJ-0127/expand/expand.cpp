#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define MP make_pair
#define pii pair<int,int>
using namespace std;
constexpr int N=500005,inf=2e9;
int Cas,n,m,Q,n_,m_,a[N],b[N],aa[N],bb[N],Min[N],top,st[N];
bool chkmax(int &x,int y){return (x<y?x=y,1:0);}
bool chkmin(int &x,int y){return (x>y?x=y,1:0);}
void solve(){
	if(a[1]==b[1]||a[n]==b[m])return cout<<0,void();
	if((a[1]<b[1])!=(a[n]<b[m]))return cout<<0,void();
	if(a[1]<b[1]){
		for(int i=1;i<=max(n,m);i++)swap(a[i],b[i]);
		swap(n,m);
	}
	int Min1=inf,Min2=inf,Max1=-1,Max2=-1;
	for(int i=1;i<=n;i++)chkmax(Max1,a[i]),chkmin(Min1,a[i]);
	for(int i=1;i<=m;i++)chkmax(Max2,b[i]),chkmin(Min2,b[i]);
	if(Min1<=Min2||Max1<=Max2)return cout<<0,void();
	Min[0]=inf;Max1=-1;top=0;
	for(int i=1;i<=m;i++){
		Min[i]=min(Min[i-1],b[i]);
		if(b[i]>b[st[top]])st[++top]=i;
	}
	for(int i=1,j=1;i<=n&&j<=top;i++){
		chkmax(Max1,a[i]);
		for(;j<=top&&b[st[j]]<Max1;j++);
		if(j<=top&&a[i]<=Min[st[j]])return cout<<0,void();
	}
	Min[m+1]=inf;Max1=-1;top=0;
	for(int i=m;i>=1;i--){
		Min[i]=min(Min[i+1],b[i]);
		if(b[i]>b[st[top]])st[++top]=i;
	}
	for(int i=n,j=1;i>=1&&j<=top;i--){
		chkmax(Max1,a[i]);
		for(;j<=top&&b[st[j]]<Max1;j++);
		if(j<=top&&a[i]<=Min[st[j]])return cout<<0,void();
	}
	cout<<1;
}
void init(){
	n=n_,m=m_;
	for(int i=1;i<=max(n,m);i++)a[i]=aa[i],b[i]=bb[i];
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>Cas>>n>>m>>Q;n_=n,m_=m;
	for(int i=1;i<=n;i++)cin>>a[i],aa[i]=a[i];
	for(int i=1;i<=m;i++)cin>>b[i],bb[i]=b[i];
	solve();init();
	while(Q--){
		int k1,k2;cin>>k1>>k2;
		for(int i=1;i<=k1;i++){
			int x,y;cin>>x>>y;
			a[x]=y;
		}
		for(int i=1;i<=k2;i++){
			int x,y;cin>>x>>y;
			b[x]=y;
		}
		solve();init();
	}
	cout<<'\n';
	return 0;
}