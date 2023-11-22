/*
shaber dayangli.
jide duipai.
*/
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

int read(){
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 200005
#define inf 0x3f3f3f3f

int n,m;
int id[maxn],rev[maxn],col[maxn];
vector<pii>e[maxn];
bool vis[maxn];
int q[maxn],hd,tl,res;

int dis[maxn];
void bfs(int st)
{
	q[hd=tl=1]=st;
	vis[st]=1;
	dis[st]=0;
	while(hd<=tl){
		int u=q[hd++];
		for(auto it:e[u]){
			int v=it.fi,w=it.se;
			if(!vis[v])q[++tl]=v,vis[v]=1,dis[v]=dis[u]^w;
		}
	}
	bool hav=0;
	For(i,1,tl) if(id[q[i]]==-1) hav=1;
	if(hav){
		hav=0;
		For(i,1,tl) if(col[q[i]]>=2) hav=1;
		if(hav) res+=tl;
		return;
	}
	bool dif=0;
	For(i,1,tl){
		int u=q[i];
		for(auto it:e[u]){
			int v=it.fi,w=it.se;
			if(dis[v]!=(dis[u]^w)) dif=1;
		}
	}
	if(dif) res+=tl;
}

void work()
{
	n=read(),m=read();
	For(i,1,n)id[i]=i,rev[i]=0,col[i]=0,e[i].clear(),vis[i]=0;
	For(i,1,m){
		char ch;
		do ch=getchar();while(ch!='T' && ch!='F' && ch!='U' && ch!='+' && ch!='-');
		if(isalpha(ch)){
			int x=read();
			id[x]=-1,rev[x]=0;
			if(ch=='U')col[x]=2;
			if(ch=='T')col[x]=1;
			if(ch=='F')col[x]=0;
		}
		if(ch=='+'){
			int u=read(),v=read();
			id[u]=id[v],rev[u]=rev[v];
			col[u]=col[v];
		}
		if(ch=='-'){
			int u=read(),v=read();
			id[u]=id[v],rev[u]=rev[v]^1;
			col[u]=col[v]^1;
			if(col[u]==3)col[u]=2;
		}
	}
	For(i,1,n){
		if(id[i]!=-1){
			int u=i,v=id[i],w=rev[i];
			e[u].pb(mkp(v,w));
			e[v].pb(mkp(u,w));
		}
	}
	res=0;
	For(i,1,n)
		if(!vis[i])bfs(i);
	cout<<res<<"\n";
}

signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	read();int T=read();
	while(T--)work();
	return 0;
}
/*
shaber dayangli.
*/