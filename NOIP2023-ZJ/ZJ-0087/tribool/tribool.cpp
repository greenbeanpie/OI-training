#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
const int N=1e5+5;
int cid,T,n,m,rt[N],non[N],vis[N],sz[N],sf[N],ans[N],fa[N+N];
pair<int,int>p[N];
queue<int>q;
vector<int>G[N];
inline int tb(char c){
	if(c=='T')return 1;
	if(c=='F')return -1;
	return 0;
}
inline int nott(int c){if(c!=0)return -c;return 0;}
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void solve(){
	cin>>n>>m;
	rep(i,1,n){
		p[i]=mp(1,i),fa[i]=i;
		non[i]=rt[i]=vis[i]=0;
		ans[i]=2,G[i].clear(),sz[i]=0;
	}
	rep(i,1,m){
		char c;int x,y;
		cin>>c>>x;
		if(c=='T'||c=='F'||c=='U')p[x]=mp(0,tb(c));
		else{
			cin>>y;
			if(c=='+')p[x]=mp(p[y].fi,p[y].se);
			else{
				if(p[y].fi!=0)p[x]=mp(-p[y].fi,p[y].se);
				else p[x]=mp(0,nott(p[y].se));
			}
		}
	}
//	rep(i,1,n)printf("pair i=%d:[%d %d]\n",i,p[i].fi,p[i].se);
	rep(i,1,n){
		int tp=p[i].fi,x=p[i].se;
		if(tp==1){
			int u=find(i),v=find(x);
			fa[u]=v;
		}
		if(tp==0)sf[i]=x,vis[i]=1;
		if(tp==-1)non[i]=x;
	}
	rep(i,1,n)rt[i]=find(i);
	rep(i,1,n){
		++sz[rt[i]];
		if(vis[i])vis[rt[i]]=1,sf[rt[i]]=sf[i];
		if(non[i])G[rt[i]].eb(rt[non[i]]),G[rt[non[i]]].eb(rt[i]);
	}
	rep(i,1,n+n)fa[i]=i;
	rep(i,1,n)if(sz[i]){
		if(vis[i])ans[i]=sf[i];
		else{
			for(auto x:G[i]){
				int u=find(i),v=find(x);
				if(u==v)ans[i]=0;
				else fa[u]=find(x+n),fa[find(i+n)]=find(x);
			}
		}
	}
	rep(i,1,n)if(!ans[i])q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:G[u])if(ans[v]==2)ans[v]=0,q.push(v);
	}
	int sum=0;
	rep(i,1,n)if(!ans[i])sum+=sz[i];
	cout<<sum<<'\n';
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>cid>>T;
	while(T--)solve();
	return 0;
}