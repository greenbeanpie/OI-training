#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForD(i,j,k) for(int i=(j);i>=(k);--i)
#define ll long long
using namespace std;
int fa[100005][22],w[100005][22],bel[100005],nw[100005];
int ans[100005],nxt[100005],qz[100005];
// T:-1, F:-2  U:-3
vector<int> E[100005];
#define pb push_back
void bfs(int S){
	queue<int> q;q.push(S);
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int v:E[u]){
			if(ans[v]!=-1) continue;
			ans[v]=ans[u]; q.push(v);
		}
	}
}
int fz[100005];
void dfs(int u){
	if(nxt[u]==0){
		fz[u]=0;
		return;
	}
	if(fz[nxt[u]]){
		if((qz[u]==1?3-fz[u]:fz[u])==fz[nxt[u]]) ans[nxt[u]]=1;
		else ans[nxt[u]]=0;
		bfs(nxt[u]); fz[u]=0;
		return;
	}
	fz[nxt[u]]=(qz[u]==1?3-fz[u]:fz[u]);
	dfs(nxt[u]);
	fz[u]=0;
//	cout<<"  "<<u<<endl;
//	fz[u]=1;
//	while(1){
//		if(nxt[u]==0) return;
//		if(fz[nxt[u]]){
//			if((qz[u]==1?3-fz[u]:fz[u])==fz[nxt[u]]) ans[nxt[u]]=1;
//			else ans[nxt[u]]=0;
//			bfs(nxt[u]);
//			break;
//		}
//		fz[nxt[u]]=(qz[u]==1?3-fz[u]:fz[u]);
//		u=nxt[u];
//	}
}
void solve(){
	int n,m; cin>>n>>m;
	For(i,1,n) ans[i]=-1;
	For(i,1,n){
		ans[i]=-1,nxt[i]=qz[i]=fz[i]=nw[i]=0;
		while(E[i].size()) E[i].pop_back();
	}
	For(i,1,m) bel[i]=0;
	For(i,1,m){
		int v,u;
		char op; cin>>op>>v;
		if(op=='+'||op=='-'){
			cin>>u;
			fa[i][0]=nw[u]; nw[v]=i;
			if(op=='-') w[i][0]=1;
			bel[i]=u;
		}else{
			nw[v]=i;
			if(op=='T') bel[i]=-1;
			if(op=='F') bel[i]=-2;
			if(op=='U') bel[i]=-3;
		}
	}
	For(k,1,20) For(i,1,m) fa[i][k]=fa[fa[i][k-1]][k-1],
						w[i][k]=(w[i][k-1]+w[fa[i][k-1]][k-1])&1;
	For(nd,1,n){
		int e=nw[nd],s=0;
		ForD(k,20,0) if(fa[e][k]){
			s=(s+w[e][k])&1; e=fa[e][k];
		}
		int fn=bel[e]; s=(s+w[e][0])&1;
		//cout<<e<<" "<<nd<<" "<<fn<<" "<<s<<endl;
		if(fn==-3) ans[nd]=0;
		else if(fn==-1) ans[nd]=1;
		else if(fn==-2) ans[nd]=1;
		else{
			if(fn==nd){
				ans[nd]=(s==0?1:0);
			}else{
				E[fn].pb(nd);
				nxt[nd]=fn; qz[nd]=s;
			}
		}
	}
	For(i,1,n) if(ans[i]!=-1) bfs(i);
	For(i,1,n) if(ans[i]==-1) fz[i]=1,dfs(i);
	int cnt=0;
	For(i,1,n) cnt+=(ans[i]==0);
	cout<<cnt<<endl;
	For(i,1,n) For(j,0,20) fa[i][j]=w[i][j]=0;
	//...
}
signed main(){
	freopen("tribool.in","r",stdin); freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	int c,t; cin>>c>>t;
	while(t--) solve();
	return 0;
}