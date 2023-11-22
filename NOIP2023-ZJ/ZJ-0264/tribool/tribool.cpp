#include <bits/stdc++.h>
using namespace std;
const int N=4e5+10;
int n,m,id,T,a[N],ans,x,y;
char ch;
int numedge,head[N],to[N],nxt[N],dis[N],vis[N],d[N],b[N],siz[N];
void add(int u,int v,int w){
	nxt[++numedge]=head[u];
	to[numedge]=v;
	dis[numedge]=w;
	head[u]=numedge;
}
int qufan(int x){
	if (x<=n) return x+n;
	if (x<=2*n) return x-n;
	if (x==2*n+1) return 2*n+2;
	if (x==2*n+2) return 2*n+1;
	return 2*n+3;
}
void dfs(int u,int w,int fa,int fath){
	d[u]=w;siz[fath]++;vis[u]=1;
	for (int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if (v==fa) continue;
		if (vis[v]){
			if (d[u]^d[v]^dis[i]) b[fath]=1;
			continue;
		}
		dfs(v,w^dis[i],u,fath);
	}
}
int rd(){
	int x=0,w=0;
	char ch=getchar();
	while (!isdigit(ch)){
		if (ch=='-') w=1;
		ch=getchar();
	}
	while (isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return w?-x:x;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	id=rd(),T=rd();
	while (T--){
		n=rd(),m=rd();
		for (int i=1;i<=n;++i) a[i]=i,head[i]=0;
		for (int i=1;i<=m;++i){
			ch=getchar();
			while (!(ch=='T'||ch=='F'||ch=='U'||ch=='+'||ch=='-')) ch=getchar();
			if (ch=='T'){
				x=rd();
				a[x]=2*n+1;
			}
			if (ch=='F'){
				x=rd();
				a[x]=2*n+2;
			}
			if (ch=='U'){
				x=rd();
				a[x]=2*n+3;
			}
			if (ch=='+'){
				x=rd();y=rd();
				a[x]=a[y];
			}
			if (ch=='-'){
				x=rd();y=rd();
				a[x]=qufan(a[y]);
			}
		}
		ans=numedge=0;
		for (int i=1;i<=n;++i)
		if (a[i]<=n) add(a[i],i,0),add(i,a[i],0);
		else if (a[i]<=2*n) add(a[i]-n,i,1),add(i,a[i]-n,1);
		else if (a[i]==2*n+3) add(i,i,1);
		for (int i=1;i<=n;++i) vis[i]=b[i]=siz[i]=0;
		for (int i=1;i<=n;++i)
		if (!vis[i]){
			dfs(i,0,0,i);
			if (b[i]) ans+=siz[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
