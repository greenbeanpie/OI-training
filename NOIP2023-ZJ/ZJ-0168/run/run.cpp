#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 200005
#define M 100005
using namespace std;
int f[N],g[N],n,m,k,d,x[M],y[M],v[M],h[N],mx;
bool cmp(int X,int Y){
	return y[X]<y[Y];
}
vector<int>vec[N];
void solve(){
	int tot=0;
	scanf("%lld %lld %lld %lld",&n,&m,&k,&d);
	for(int i=1;i<=m;i++){
		scanf("%lld %lld %lld",&x[i],&y[i],&v[i]);
		h[++tot]=x[i]-y[i],h[++tot]=x[i];
	}
	sort(h+1,h+tot+1);
	tot=unique(h+1,h+tot+1)-h-1;
	for(int i=1;i<=m;i++){
		x[i]=lower_bound(h+1,h+tot+1,x[i])-h;
		vec[x[i]].pb(i);
	}
	for(int i=1;i<=tot;i++)
		sort(vec[i].begin(),vec[i].end(),cmp);
	for(int i=1;i<=tot;i++)f[i]=g[i]=-INF;f[0]=mx=0;
	for(int i=2;i<=tot;i++){
		g[0]=mx;
		int sum=0,pos=0;
		for(int j=1;j<=i;j++){//从h[i-j]+1~h[i]全部打卡的最大收益 
			if(h[i]-h[i-j]>k)break;
			while(pos<vec[i].size()&&y[vec[i][pos]]<=h[i]-h[i-j])sum+=v[vec[i][pos]],pos++;
			g[j]=f[j-1]-d*(h[i]-h[i-1])+sum;
			mx=max(mx,g[j]);
		}
		for(int j=0;j<=i;j++){
			if(h[i]-h[i-j]>k)break;
			f[j]=g[j],g[j]=-INF;
		}
	}
	printf("%lld\n",mx);
	for(int i=1;i<=tot;i++)
		if(vec[i].size())vec[i].clear();
}
void solve_B(){
	int ans=0;
	scanf("%lld %lld %lld %lld",&n,&m,&k,&d); 
	for(int i=1,X,Y,V;i<=m;i++){
		scanf("%lld %lld %lld",&X,&Y,&V);
		if(Y<=k&&d*Y<V)ans+=V-d*Y;
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int  Type,T;scanf("%lld %lld",&Type,&T);
	while(T--){
		if(Type<=16)solve();
		if(Type==17||Type==18)solve_B();
	}
	return 0;
}

