#include<bits/stdc++.h>
using namespace std;
struct edge{int nxt,to;}e[200010];
int C,T,n,m,cnt,a[100010],b[100010],h[100010],x,xx[100010],y,yy[100010],v[100010],vis[100010],sz[100010],rt,ans;
char op,oo[100010];
bool f[100010],flag;
void add(int u,int v){e[++cnt].nxt=h[u],e[cnt].to=v,h[u]=cnt;}
void find(int u){
	vis[u]=1;
	if(!a[u]){rt=u,flag=b[u]==0;return;}
	if(vis[a[u]])rt=a[u],flag=v[a[u]]!=v[u]*b[u];
	else v[a[u]]=v[u]*b[u],find(a[u]);
}
void dfs(int u,int fa){
	sz[u]=1,vis[u]=1;
	int s=0;
	for(int i=h[u];i;i=e[i].nxt){
		if(e[i].to!=fa&&e[i].to!=rt)dfs(e[i].to,u),sz[u]+=(!s||e[i].to!=a[u]?sz[e[i].to]:0);
		if(e[i].to==a[u]&&a[a[u]]==u)s++;
	}
}
void dfs_(int st){
	if(st>n){
		bool flag=1;int s=0;
		for(int i=1;i<=n;i++)b[i]=a[i];
		for(int i=1;i<=m;i++){
			if(oo[i]=='T')b[xx[i]]=1;
			if(oo[i]=='F')b[xx[i]]=-1;
			if(oo[i]=='U')b[xx[i]]=0;
			if(oo[i]=='+')b[xx[i]]=b[yy[i]];
			if(oo[i]=='-')b[xx[i]]=-b[yy[i]];
		}
		for(int i=1;i<=n;i++)if(a[i]!=b[i])flag=0;
		for(int i=1;i<=n;i++)s+=a[i]==0;
		if(flag)ans=min(ans,s);
		return;
	}
	a[st]=1,dfs_(st+1),a[st]=0,dfs_(st+1),a[st]=-1,dfs_(st+1);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>m,cnt=ans=0,memset(b,0,sizeof(b)),memset(h,0,sizeof(h)),memset(vis,0,sizeof(vis)),memset(sz,0,sizeof(sz)),memset(f,0,sizeof(f));
		if(C<=2){
			ans=1000000;
			for(int i=1;i<=m;i++){
				cin>>oo[i];
				if(oo[i]=='T'||oo[i]=='F'||oo[i]=='U')cin>>xx[i];
				else cin>>xx[i]>>yy[i];
			}
			dfs_(0);
		}else if(C<=4){
			for(int i=1;i<=m;i++)cin>>op>>x,a[x]=op;
			for(int i=1;i<=n;i++)ans+=a[x]=='U';
		}else if(C<=6){
			for(int i=1;i<=n;i++)a[i]=1;
			for(int i=1;i<=m;i++){
				cin>>op;
				if(op=='U')cin>>x,a[x]=0;
				else cin>>x>>y,a[x]=a[y];
			}
			for(int i=1;i<=n;i++)ans+=a[x]==0;
		}else{
			for(int i=1;i<=n;i++)a[i]=i,b[i]=1;
			for(int i=1;i<=m;i++){
				cin>>op;
				if(op=='T')cin>>x,a[x]=0,b[x]=1,f[x]=1;
				if(op=='F')cin>>x,a[x]=0,b[x]=-1,f[x]=1;
				if(op=='U')cin>>x,a[x]=0,b[x]=0,f[x]=1;
				if(op=='+'){
					cin>>x>>y;
					if(!f[y])a[x]=y,b[x]=1;
					else a[x]=y,b[x]=b[y],f[x]=1;
				}
				if(op=='-'){
					cin>>x>>y;
					if(!f[y])a[x]=y,b[x]=-1;
					else a[x]=y,b[x]=-b[y],f[x]=1;
				}
			}
			for(int i=1;i<=n;i++)if(a[i])add(i,a[i]),add(a[i],i);
			for(int i=1;i<=n;i++)if(!vis[i]){
				vis[i]=1,find(i),dfs(rt,(a[a[rt]]==rt?0:a[rt]));
				if(flag)ans+=sz[rt];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}