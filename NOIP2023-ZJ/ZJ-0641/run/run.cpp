#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define foR(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+5;
int id,T,n,m,k,d;
int x[N],y[N],z[N];
int ans=-inf;
int tot=0;
int f[1005][1005];
bool vis[1005][1005];
inline void dfs(int step,int res,int K) {
	if(step==n+1) {
		ans=max(ans,res);
		return;
	}
//	if(vis[step][K]) return;
	dfs(step+1,res,0);
	if(K>=k) {/*vis[step][K]=true,f[step][K]=res;*/return;}
	int p=-d;
	if(step==x[tot+1]) {
		++tot;
		if(K+1>=y[tot]) p+=z[tot];
	}
	dfs(step+1,res+p,K+1);
//	vis[step][K]=true,f[step][K]=max(res,res+p);
	if(step==x[tot]) --tot;
	return;
}
signed main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&id,&T);
	cin>>n>>m>>k>>d;
	For(i,1,m) scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*
1 1
10 10
T 3
+ 1 2
- 7 1
+ 2 10
T 6
- 1 4
U 3
+ 7 10
F 5
+ 6 9
*/
