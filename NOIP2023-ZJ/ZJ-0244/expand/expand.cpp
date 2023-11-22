#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define fi first
#define se second
using namespace std;
template<typename T_>void operator+=(vector<T_>&x,const T_&y){x.push_back(y);}
template<typename T_>void Max(T_&x,const T_&y){if(y>x)x=y;}
template<typename T_>void Min(T_&x,const T_&y){if(y<x)x=y;}
const int N=3e3+7,inf=1e9+7;
int C,n,m,q,a[N],b[N],mxa[N],mia[N],mxb[N],mib[N];
bool f[N][N];
int ka,kb,pa[N],pb[N],va[N],vb[N];
void work(){
	if(C==1)return cout<<(a[1]!=b[1]),void();
	if(C==2)return cout<<((a[1]<b[1]&&a[2]<b[2])||(a[1]>b[1]&&a[2]>b[2])),void();
	if(a[1]==b[1])return cout<<0,void();
	bool flg=a[1]>b[1];
	memset(f,0,sizeof(f)),f[1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1)continue;
			if(flg){
				if(a[i]>b[j])f[i][j]|=f[i-1][j]|f[i][j-1]|f[i-1][j-1];
			}
			else if(a[i]<b[j])f[i][j]|=f[i-1][j]|f[i][j-1]|f[i-1][j-1];
		}
	}
	for(int i=n;i>0;i--)
		mxa[i]=max(a[i],mxa[i+1]),
		mia[i]=min(a[i],mia[i+1]);
	for(int i=m;i>0;i--)
		mxb[i]=max(b[i],mxb[i+1]),
		mib[i]=min(b[i],mib[i+1]);
	for(int i=1;i<=n;i++)if(f[i][m]){
		if(!flg){
			if(mxa[i+1]<b[m])return cout<<1,void();
		}
		else if(mia[i+1]>b[m])return cout<<1,void();
	}
	for(int j=1;j<=m;j++)if(f[n][j]){
		if(!flg){
			if(a[n]<mib[j+1])return cout<<1,void();
		}
		else if(a[n]>mxb[j+1])return cout<<1,void();
	}
	cout<<0;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>q;
	mia[n+1]=mib[m+1]=inf;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	work();
	for(int T=1;T<=q;T++){
		cin>>ka>>kb;
		for(int i=1;i<=ka;i++)
			cin>>pa[i]>>va[i],swap(a[pa[i]],va[i]);
		for(int i=1;i<=kb;i++)
			cin>>pb[i]>>vb[i],swap(b[pb[i]],vb[i]);
		work();
		for(int i=1;i<=ka;i++)swap(a[pa[i]],va[i]);
		for(int i=1;i<=kb;i++)swap(b[pb[i]],vb[i]);
	}
	cout<<'\n';
	return 0;
}
