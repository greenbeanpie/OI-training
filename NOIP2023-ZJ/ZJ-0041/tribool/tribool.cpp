#include<bits/stdc++.h>
using namespace std;
const int maxn=100005,maxm=600005;
int cur[maxn][2],_nd=0;
int fa[maxm],tot;
inline int f(){
	++tot;fa[tot]=tot;
	return tot;
}
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
inline void lk(int u,int v){
	int fu=getfa(u),fv=getfa(v);
	if(fu==fv) return;
	if(fu!=_nd) fa[fu]=fv;
	else fa[fv]=fu;
}
inline void solve(){
	tot=0;memset(cur,0,sizeof cur);memset(fa,0,sizeof fa);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cur[i][0]=i,cur[i][1]=i+n;tot=2*n;
	for(int i=1;i<=2*n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		char v;cin>>v;
		int d,g;cin>>d;
		if(v=='+'||v=='-'){
			cin>>g;
			if(g==d){
				if(v=='-') swap(cur[d][0],cur[d][1]);
				continue;
			}
		}
		cur[d][0]=f();cur[d][1]=f();
		if(v=='+'){
			lk(cur[d][1],cur[g][1]);
			lk(cur[d][0],cur[g][0]);
		}
		else if(v=='-'){
			lk(cur[d][1],cur[g][0]);
			lk(cur[d][0],cur[g][1]);
		}
		else{
			if(v=='T') lk(cur[d][1],_nd);
			else if(v=='F') lk(cur[d][0],_nd);
			else lk(cur[d][0],cur[d][1]);
		}
	}
	for(int i=1;i<=n;i++)
		lk(i,cur[i][0]),lk(i+n,cur[i][1]);
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(getfa(i)==getfa(i+n)) cnt++;
	cout<<cnt<<'\n';
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--) solve();
	return 0;
}