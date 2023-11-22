#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,l,r) for(ll i=l,i##e=r;i<=i##e;++i)
#define Rep(i,l,r) for(ll i=l,i##e=r;i<i##e;++i)
#define FOR(i,l,r) for(ll i=l,i##e=r;i>=i##e;--i)
ll read(){
	char c=getchar();ll v=0;bool f=1;
	for(;'0'>c||c>'9';c=getchar())
	    if(c=='-') f = 0;
	for(;'0'<=c&&c<='9';c=getchar())
	    v = (v<<1)+(v<<3)+(c^48);
	return f?v:-v;
}
ll c;
const ll N = 1e5+10;
const ll inf = 2e18;
//ll abs(ll x){return x>=0?x:-x;}
namespace W1{
ll fm[N],ok[N],vis[N],cgh[N],now;
ll dfs(ll p,ll cg){
	if(abs(ok[p])<now) return ok[p];//real val
	if(vis[p]==now) return cgh[p]==cg?now:0;//circle
	vis[p] = now,cgh[p] = cg;
	ll v = fm[p];
	if(v>0) ok[p] = dfs(v,cg);
	else ok[p] = -dfs(-v,cg^1);
	return ok[p];
}
void work(){
	ll n=read(),m=read();
	For(i,1,n) fm[i] = i;
	ll fT = n+1,fF = -fT,fU = 0;
	//0=U,n+1=T,-(n+1)=F
	char c;
	For(ooo,1,m){
		scanf(" %c",&c);ll u,v;
		if(c=='T') fm[read()] = fT;
		if(c=='F') fm[read()] = fF;
		if(c=='U') fm[read()] = fU;
		if(c=='+'){
			u=read(),v=read();
//			if(fm[v]==fT) fm[u] = fT;
//			else if(fm[v]==fF) fm[u] = fF;
//			else if(fm[v]==fU) fm[u] = fU;
//			else 
			fm[u] = fm[v];
		}
		if(c=='-'){
			u=read(),v=read();
//			if(fm[v]==fT) fm[u] = fT;
//			else if(fm[v]==fF) fm[u] = fF;
//			else if(fm[v]==fU) fm[u] = fU;
//			else 
			fm[u] = -fm[v];
		}
	}
	
	For(i,1,n){
		ok[i] = inf;vis[i] = 0,cgh[i] = 0;
		if(fm[i]==fU) ok[i] = 0;//0 = U
		if(fm[i]==fT) ok[i] = 1;//>0 = T
		if(fm[i]==fF) ok[i] = -1;//<0 = F
	}
    now = 10;
	For(i,1,n) if(ok[i]==inf){
		++now;dfs(i,0);//havn't change
//		if(flag==1) dfs2(i,1);
//		if(flag==0) dfs2(i,0);
	}
	ll cnt = 0;
	For(i,1,n) if(ok[i]==0) ++cnt;
	printf("%lld\n",cnt);
}
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	c=read();ll t=read();
	For(qwq,1,t) W1::work();
	
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
while(!q.empty()) q.pop();
	For(i,1,n) son[i].clear();
	For(i,1,n){
		ok[i] = inf;
		if(fm[i]==fU)
		    q.push(i),ok[i] = 0;//U
		else if(fm[i]==fT)
		    q.push(i),ok[i] = 1;//T
		else if(fm[i]==fF)
		    q.push(i),ok[i] = -1;//F
		else{
			if(fm[i]==i)
			    q.push(i),ok[i] = 1;//T
			else if(fm[i]==-i)
			    q.push(i),ok[i] = 0;//U
		    else son[abs(fm[i])].push_back(i);
		}
	}
	while(!q.empty()){
		ll qf = q.front();q.pop();
		Rep(i,0,son[qf].size()){
			ll v = son[qf][i];
			if(fm[v]==qf) ok[v] = ok[qf];
			else ok[v] = -ok[qf];
			q.push(v);
		}
	}
//	For(i,1,n) printf("%lld ",ok[i]);puts("");
	
	nowinf = inf;
	For(i,1,n) if(ok[i]==inf){//circle
		//guess to be T
		ll flag = dfs(i,10);
//		if(flag==3) dfs2(i,nowinf-10);
		if(flag==1) dfs2(i,1);
		if(flag==0) dfs2(i,0);
	}
//	For(i,1,n) printf("%lld ",ok[i]);puts("");
	
	ll cnt = 0;
	For(i,1,n) if(ok[i]==0) ++cnt;
	printf("%lld\n",cnt);
*/
