#include<bits/stdc++.h>
using namespace std;
const int N=5e5+110,Q=66;
int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9' || c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int c,n,m,q,ans[Q],x[N],y[N],t[N],tmp;
int A[N],B[N],dn,dm;
int rcd;
void dfs(int i,int j,int Umin,int Dmax){
	if(i==n && j==m){
		ans[rcd]=1;
		return;
	}
	if(i<n && min(Umin,x[i+1])>Dmax){
		dfs(i+1,j,min(Umin,x[i+1]),Dmax);
	}
	if(j<m && Umin>max(Dmax,y[j+1])){
		dfs(i,j+1,Umin,max(Dmax,y[j+1]));
	}
	if(i<n && j<m && x[i+1]>y[j+1]){
		dfs(i+1,j+1,x[i+1],y[j+1]);
	}
	return;
}
void solve(){
	if(x[1]<y[1]){
		tmp=n;for(int i=1;i<=tmp;i++)t[i]=x[i];
		n=m;for(int i=1;i<=n;i++)x[i]=y[i];
		m=tmp;for(int i=1;i<=m;i++)y[i]=t[i];
	}
	if(x[1]>y[1])dfs(1,1,x[1],y[1]);
	return;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=dn=read(),m=dm=read(),q=read();
	for(int i=1;i<=dn;i++)A[i]=x[i]=read();
	for(int i=1;i<=dm;i++)B[i]=y[i]=read();
	rcd=1;solve();
	for(int o=1;o<=q;o++){
		n=dn,m=dm;
		for(int i=1;i<=dn;i++)x[i]=A[i];
		for(int i=1;i<=dm;i++)y[i]=B[i];
		int kx=read(),ky=read();
		for(int i=1;i<=kx;i++){int p=read(),t=read();x[p]=t;}
		for(int i=1;i<=ky;i++){int p=read(),t=read();y[p]=t;}
		rcd=o+1;solve();
	}
	for(int i=1;i<=q+1;i++)printf("%d",ans[i]);
	printf("\n");
	return 0;
}