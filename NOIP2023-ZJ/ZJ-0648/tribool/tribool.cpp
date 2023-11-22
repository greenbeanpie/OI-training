#include<bits/stdc++.h>
const int maxn = 1e5+5;
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m;
int a[maxn];
int c,t;
bool vis[maxn];
int ans;
int fa[maxn];
void work(int x){
	if(a[x]!=2&&a[x]!=-2) return ;
	if(fa[x]==x) return ;
	a[x]=0;
	work(fa[x]);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		ans=0;
		for(int i=1;i<=n;i++) fa[i]=i;
		memset(vis,0,sizeof(vis));
		n=read();
		m=read();
		for(register int i=1;i<=n;i++) a[i]=2;
		for(register int i=1;i<=m;i++){
			char op;
			int x,y;
			cin>>op;
			x=read();
			if(op=='T') a[x]=1,fa[x]=x;
			else if(op=='F') a[x]=-1,fa[x]=x;
			else if(op=='U') a[x]=0,fa[x]=x;
			else if(op=='+'){
				y=read();
				fa[x]=y;
				if(vis[x]){
					if(a[x]!=a[y]&&(a[y]==-2||a[y]==2)) work(x);
				}else a[x]=a[y];
				vis[x]=vis[y]=1;
			}else{
				y=read();
				fa[x]=y;
				if(vis[x]){
					if(a[x]!=(-1)*a[y]&&(a[y]==-2||a[y]==2)) work(x);
				}else a[x]=(-1)*a[y];
				vis[x]=vis[y]=1;
			}
		}
		for(int i=1;i<=n;i++) if(a[i]==0) ans++;
//		for(int i=1;i<=n;i++) cout<<a[i]<<' ';
//		puts("");
		cout<<ans<<endl;
	}
	return 0;
}
