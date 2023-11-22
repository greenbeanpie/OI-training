#include<bits/stdc++.h>
#define within :
using namespace std;
const int N=1e5+5;
inline char read_char(){
	char ch=getchar();
	while(ch!='T'&&ch!='F'&&ch!='U'&&ch!='+'&&ch!='-')
		ch=getchar();
	return ch;
}
inline int read(){
	char ch=getchar();int x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
int n,m,v[N],a[N],siz,len,d[N];
bool vis[N];
vector<int>G[N];
queue<int>q;
void dfs(int x,int fa){
	vis[x]=1;siz++;int typ;
	for(int v within G[x]){
		if(v==fa||v==-fa) continue;
		if(v>0) typ=1;
		else v=-v,typ=-1;
		if(vis[v]){len=d[x]-d[v]+(typ==-1);continue;}
		d[v]=d[x]+(typ==-1);dfs(v,x);
	}
}
inline void LJY(){
	n=read();m=read();
	for(int i=1;i<=n;i++) v[i]=i,vis[i]=a[i]=0,G[i].clear();
	while(m--){
		char opt=read_char();
		if(opt=='T') v[read()]=1e5+1;
		else if(opt=='F') v[read()]=-(1e5+1);
		else if(opt=='U') v[read()]=0;
		else if(opt=='+'){
			int x=read(),y=read();
			v[x]=v[y];
		}else{
			int x=read(),y=read();
			v[x]=-v[y];
		}
	}
	for(int i=1;i<=n;i++)
		if(v[i]!=0&&v[i]!=1e5+1&&v[i]!=-1e5-1){
			if(v[i]>0) G[i].push_back(v[i]),G[v[i]].push_back(i);
			else G[i].push_back(v[i]),G[-v[i]].push_back(-i);
		}
		else a[i]=v[i],q.push(i),vis[i]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v within G[u]){
			int id=v,typ=1;if(id<0)
				id=-id,typ=-1;
			if(vis[id]) continue;
			a[id]=typ*a[u];q.push(id);vis[id]=1;
		}
	}int ans=0;
	for(int i=1;i<=n;i++) if(vis[i]) ans+=(!a[i]);
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			d[i]=0;siz=len=0;dfs(i,0);
			if(len&1) ans+=siz;
		}
	printf("%d\n",ans);
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;c=read();t=read();while(t--) LJY();
	return 0;
}
// ? pts