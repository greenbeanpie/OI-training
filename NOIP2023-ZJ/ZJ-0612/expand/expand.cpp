#include<bits/stdc++.h>
using namespace std;
int C,n,m,Q;
int a[500005],b[500005],c[500005],d[500005],ans[500005];
void copy(int &N,int &M){
	if(a[1]<b[1]){
		for(int i=1;i<=m;i++) c[i]=b[i];
		for(int i=1;i<=n;i++) d[i]=a[i];
		N=m,M=n;
	}
	if(a[1]>b[1]){
	    for(int i=1;i<=n;i++) c[i]=a[i];
		for(int i=1;i<=m;i++) d[i]=b[i];
		N=n,M=m;
	}
}
void work(int id){
	long long f=((long long)(a[1]-b[1]))*((long long)(a[n]-b[m]));
	if(f<=0){
		ans[id]=0;
		return;
	}
	int N,M;
	copy(N,M);
	int pos=0;
	for(int i=1;i<=N;i++){
		while(c[i]>d[pos+1]&&pos<M) pos++;
		while(c[i]<=d[pos]&&pos>0) pos--;
		if(!pos){
			ans[id]=0;
			return;
		}
	}
	if(pos==M) ans[id]=1;
	else ans[id]=0;
	return;
}
void solve(){
	work(1);
	for(int i=1;i<=n;i++) c[i]=a[i];
	for(int i=1;i<=m;i++) d[i]=b[i];
	for(int i=1;i<=Q;i++){
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		for(int j=1;j<=kx;j++){
			int pos,v;
			scanf("%d%d",&pos,&v);
			a[pos]=v;
		}
		for(int j=1;j<=ky;j++){
			int pos,v;
			scanf("%d%d",&pos,&v);
			b[pos]=v;
		}
		work(i+1);
		for(int j=1;j<=n;j++) a[j]=c[j];
		for(int j=1;j<=m;j++) b[j]=d[j];
	}
	for(int i=1;i<=Q+1;i++) printf("%d",ans[i]);
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&C,&n,&m,&Q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	if(n<=2000&&m<=2000) solve();
	return 0;
}
