#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return x*f;
}
const int maxn=500005;
int n,m,q,a[maxn],b[maxn];
int mx[maxn],mn[maxn],tot,v[maxn];
inline bool solve(int a[],int b[],int n,int m){
	tot=0;
//	memset(mx,0,sizeof mx),memset(mn,0,sizeof mn),memset(v,0,sizeof v);
	for(int i=1;i<=n;i++) mx[i]=mn[i]=v[i]=0;
	int cmx=a[1];
	mx[1]=1,mn[1]=a[1];tot=1;
	for(int i=2;i<=n;i++){
		if(a[i]>cmx){
			cmx=a[i];
			mx[++tot]=i;
			mn[tot]=a[i];
		}
		else mn[tot]=min(mn[tot],a[i]);
	}
	for(int i=1;i<=m;i++) if(b[i]>=cmx) return 0;
	int cur=1;
	for(int i=1;i<=tot;i++) v[mx[i]]=mn[i];
	for(int i=1;i<mx[tot];i++){
		if(a[i]<=b[cur]) return 0;
		if(v[i]&&v[i]!=a[i]){
			while(cur<=m&&b[cur]>=v[i]&&b[cur]<a[i]) cur++;
			if(cur>m) return 0;
			if(b[cur]>=a[i]){
				return 0;
			}
		}
//		cout<<i<<" "<<cur<<'\n';
	}
	for(int i=1;i<=n;i++) mx[i]=mn[i]=v[i]=0;
	cmx=a[n];
	mx[1]=n,mn[1]=a[n];tot=1;
	for(int i=n-1;i>=1;i--){
		if(a[i]>cmx){
			cmx=a[i];
			mx[++tot]=i;
			mn[tot]=a[i];
		}
		else mn[tot]=min(mn[tot],a[i]);
	}
	cur=m;
	for(int i=1;i<=tot;i++) v[mx[i]]=mn[i];
	for(int i=n;i>mx[tot];i--){
//		cout<<i<<" "<<cur<<' '<<v[i]<<' '<<a[i]<<' '<<b[cur]<<'\n';
		if(a[i]<=b[cur]) return 0;
		if(v[i]&&v[i]!=a[i]){
			while(cur>=1&&b[cur]>=v[i]&&b[cur]<a[i]) cur--;
			if(cur<1) return 0;
			if(b[cur]>=a[i]) return 0;
		}
//		cout<<i<<" "<<cur<<'\n';
	}
	return 1;
}
inline void ssolve(){
//	for(int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<'\n';
//	for(int j=1;j<=m;j++) cout<<b[j]<<" ";cout<<'\n';
//	if(a[n]>b[m]) cout<<"bukeneng|!!!!\n";
	int x=solve(a,b,n,m);
	if(x){
		putchar('1');
		return;
	}
	x=solve(b,a,m,n);
	putchar('0'+x);
//	putchar('\n');
}
int c[maxn],d[maxn];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	n=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=c[i]=read();
	for(int i=1;i<=m;i++) b[i]=d[i]=read();
	ssolve();
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++) a[j]=c[j];
		for(int j=1;j<=m;j++) b[j]=d[j];
		int kx=read(),ky=read();
		for(int j=1;j<=kx;j++){
			int x,y;x=read(),y=read();
			a[x]=y;
		}
		for(int j=1;j<=ky;j++){
			int x,y;x=read(),y=read();
			b[x]=y;
		}
		ssolve();
	}
	return 0;
}