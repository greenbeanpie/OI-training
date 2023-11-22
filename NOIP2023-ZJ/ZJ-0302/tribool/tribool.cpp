#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int a[N],b[N],f[N],fa[N],siz[N],y[N];
int n,m;
char read_char(){
	char ch=getchar();
	while (ch!='T'&&ch!='F'&&ch!='U'&&ch!='+'&&ch!='-') ch=getchar();
	return ch;
}
int read(){
	int cnt=0;
	char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while ('0'<=ch&&ch<='9') cnt=cnt*10+ch-'0',ch=getchar();
	return cnt;
}
int find(int x){
	if (fa[x]==x) return x;
	y[x]=find(fa[x]);
	f[x]^=f[fa[x]];
	fa[x]=y[x];
	return y[x];
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int opt=read(),T=read();
	while (T--){
		n=read(),m=read();
		int ans=0;
		for (int i=1;i<=n;i++)
			a[i]=i,b[i]=-1,fa[i]=i,f[i]=0,siz[i]=1;
		while (m--){
			char ch=read_char();
			if (ch=='U'){
				int x=read();
				a[x]=n+1;
				b[x]=2;
			} else if (ch=='T'){
				int x=read();
				a[x]=n+1;
				b[x]=1;
			} else if (ch=='F'){
				int x=read();
				a[x]=n+1;
				b[x]=0;
			} else if (ch=='+'){
				int x=read(),y=read();
				if (a[y]==n+1) a[x]=n+1,b[x]=b[y];
				else a[x]=a[y],b[x]=b[y];
			} else if (ch=='-'){
				int x=read(),y=read();
				if (a[y]==n+1){
					a[x]=n+1;
					if (b[y]==2) b[x]=2; else b[x]=b[y]^1;
				} else a[x]=-a[y],b[x]=b[y];
			}
		}
		for (int i=1;i<=n;i++)
			if (a[i]==n+1){
				if (b[i]==2) ans++;
			} else {
				int u=i,v=a[i],d=0;
				if (v<0) v=-v,d=1;
				int fu=find(u),fv=find(v);
				if (fu!=fv){
					if (b[fu]==2&&b[fv]!=2) {
						fa[fv]=fu;
						f[fv]=d^f[u]^f[v];
						siz[fu]+=siz[fv];
						ans+=siz[fv];
					} else if (b[fv]==2&&b[fu]!=2) {
						fa[fu]=fv;
						f[fu]=d^f[u]^f[v];
						siz[fv]+=siz[fu];
						ans+=siz[fu];
					} else {
						fa[fv]=fu;
						f[fv]=d^f[u]^f[v];
						siz[fu]+=siz[fv];
					}
				} else 
					if (d^f[u]^f[v]==1) b[fu]=2,ans+=siz[fu];
			}
		printf("%d\n",ans);
	}
	return 0;
}
