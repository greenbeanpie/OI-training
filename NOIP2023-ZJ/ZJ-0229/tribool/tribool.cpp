#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e5+5;
int stk[N],dfn[N],low[N],col[N],bep[N],fu[N],id[N];
int n,m,tot=0,top=0,cnt=0;
pii fa[N];
vector<pii> G[N];
void tarjan(int x,int fa){
	stk[++top]=x;
	dfn[x]=low[x]=++tot;
	for(auto y:G[x]){
		if(y.fi==fa) continue;
		if(!dfn[y.fi]){
			tarjan(y.fi,x);
			low[x]=min(low[x],low[y.fi]);
		}
		else low[x]=min(low[x],dfn[y.fi]);
	}
	if(low[x]==dfn[x]){
		int u;
		cnt++;
		do{
			bep[u=stk[top--]]=cnt;
		}while(u!=x);
	}
}
void dfs(int x,int fa){
	for(auto y:G[x]){
		if(y.fi==fa||col[y.fi]!=0) continue;
		col[y.fi]=col[x];
		dfs(y.fi,x);
	}
}
void solve_pts20(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(col[i]==2) ans++;
	}
	cout<<ans<<"\n";
}
void solve(){
	cin>>n>>m;
	cnt=0;
	for(int i=1;i<=n;i++){
		dfn[i]=low[i]=col[i]=stk[i]=bep[i]=fu[i]=0;
		G[i].clear();
		id[i]=i;
		fa[i]={i,0};
	}
	int fl1=0,fl2=0,now=n;
	for(int i=1;i<=m;i++){
		char op;
		int x,y;
		cin>>op;
		if(op=='+'){
			cin>>x>>y;
			id[x]=++now;
			fa[id[x]]={fa[id[y]].fi,fa[id[y]].se};
			fl1++;
		}
		if(op=='-'){
			cin>>x>>y;
			id[x]=++now;
			fa[id[x]]={fa[id[y]].fi,fa[id[y]].se+1};
			fl2++;
		}
		if(op=='T'||op=='F'||op=='U'){
			cin>>x;
			id[x]=++now;
			fa[id[x]]={0,(op=='U')};
			if(op=='T') col[x]=1;
			if(op=='F') col[x]=-1;
			if(op=='U') col[x]=2;
		}
	}
	if(fl1==0&&fl2==0){
		return solve_pts20(),void();
	}
	for(int i=1;i<=n;i++){
		if(fa[id[i]].fi==0) continue;
		if(fa[id[i]].se&1) G[fa[id[i]].fi].push_back({i,-1});
		else G[fa[id[i]].fi].push_back({i,1});
//		cout<<i<<" "<<fa[id[i]].fi<<" "<<fa[id[i]].se<<"\n";
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tot=0,top=0;
			tarjan(i,0);
		}
	}
	for(int i=1;i<=n;i++){
		if(fa[id[i]].fi==0) continue;
		if(bep[i]==bep[fa[id[i]].fi]&&bep[i]>0){
			fu[bep[i]]+=(fa[id[i]].se&1);
		}
	}
	for(int i=1;i<=n;i++){
		if(fu[bep[i]]&1){
			col[i]=2;
		}
	}
	for(int i=1;i<=n;i++){
		if(fa[id[fa[id[i]].fi]].fi==i){
//			cout<<i<<" "<<fa[id[fa[id[i]].fi]].fi<<"\n";
			if(i==fa[id[fa[id[i]].fi]].fi&&(fa[id[i]].se&1?-1:1)+(fa[id[fa[id[i]].fi]].se&1?-1:1)==2) col[i]=2;
			if((fa[id[i]].se&1?-1:1)+(fa[id[fa[id[i]].fi]].se&1?-1:1)==0) col[i]=2;
		}
	}
	for(int i=1;i<=n;i++){
		if(col[i]==2){
			dfs(i,0);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=(col[i]==2);
	}
	cout<<ans<<"\n";
	for(int i=1;i<=now;i++) fa[i]={0,0};
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--) solve();
}
/*
1 1
10 10
- 7 5
+ 5 1
+ 1 7
+ 2 3
+ 3 4
+ 4 6
+ 6 8
- 8 9
+ 9 10
- 10 2




*/
