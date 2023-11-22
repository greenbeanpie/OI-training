#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;

int c,t;
int n,m,k,d;

namespace s1{
	const int N=1010;
	vector<pair<int,int> > vec[N];
	bool cmp(pair<int,int> a,pair<int,int> b){
		return a.fi<b.fi;
	}
	int dp[N][N];
	void solve(){
		cin>>n>>m>>k>>d;
		for(int i=1;i<=n;i++) vec[i].clear();
		for(int i=1,x,y,v;i<=m;i++){
			cin>>x>>y>>v;
			vec[x].pb({y,v});
		}
		for(int i=1;i<=n;i++)
			if(vec[i].size()) sort(vec[i].begin(),vec[i].end(),cmp);
		int Max=0;
		for(int i=1;i<=n;i++){
			dp[i][0]=Max;int now=0,sz=vec[i].size(),res=0;
			for(int j=1;j<=min(i,k);j++){
				while(now<sz&&vec[i][now].fi<=j) res+=vec[i][now].se,now++;
				dp[i][j]=dp[i-1][j-1]-d+res;Max=max(Max,dp[i][j]);
			}
		}
		cout<<Max<<'\n';
	}
}

namespace s2{
	const int N=1e5+1e3,inf=1e18;
	vector<pair<int,int> > vec[N];
	#define ls rt<<1
	#define rs rt<<1|1
	#define lson ls,l,mid
	#define rson rs,mid+1,r
	int tr[N<<2],lazy[N<<2];
	void push_up(int rt){tr[rt]=max(tr[ls],tr[rs]);}
	void push_down(int rt){
		if(lazy[rt]){
			int k=lazy[rt];lazy[rt]=0;
			tr[ls]+=k,tr[rs]+=k,lazy[ls]+=k,lazy[rs]+=k;
		}
	}
	void build(int rt,int l,int r){
		tr[rt]=0,lazy[rt]=0;
		if(l==r) return;
		int mid=(l+r)>>1;build(lson),build(rson);push_up(rt);
	}
	void update(int rt,int l,int r,int ul,int ur,int k){
		if(ul<=l&&r<=ur) return tr[rt]+=k,lazy[rt]+=k,void();
		push_down(rt);int mid=(l+r)>>1;
		if(ul<=mid) update(lson,ul,ur,k);
		if(mid<ur) update(rson,ul,ur,k);
		push_up(rt);
	}
	void modify(int rt,int l,int r,int pos,int k){
		if(l==r) return tr[rt]=k,void();
		push_down(rt);int mid=(l+r)>>1;
		if(pos<=mid) modify(lson,pos,k);
		else modify(rson,pos,k);
		push_up(rt);
	}
	int query(int rt,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr) return tr[rt];
		push_down(rt);int mid=(l+r)>>1,res=-inf;
		if(ql<=mid) res=max(res,query(lson,ql,qr));
		if(mid<qr) res=max(res,query(rson,ql,qr));
		push_up(rt);return res;
	}
	void solve(){
		cin>>n>>m>>k>>d;build(1,0,n);int Max=-inf;
		for(int i=1;i<=n;i++) vec[i].clear();
		for(int i=1,x,y,v;i<=m;i++) cin>>x>>y>>v,vec[x].pb({y,v});
		for(int i=1;i<=n;i++){
			int num1=query(1,0,n,0,i-1),num2=query(1,0,n,0,0);
			modify(1,0,n,0,num1);modify(1,0,n,i,num2);
			int lim=max(1ll,i-k+1);
			update(1,0,n,lim,i,-d);
			for(auto x:vec[i]){
				if(x.fi>i||x.fi>k) continue;
				int bgn=i-x.fi+1,v=x.se;
				update(1,0,n,lim,bgn,v);
			}
			//printf("i:%d 4:%d\n",i,query(1,0,n,4,4));
		}
		cout<<tr[1]<<'\n';
	}
}

namespace s3{
	const int N=1e5+10,inf=1e18;
	int x[N],y[N],v[N];
	int X[N],cnt,dp[2][110],pre,cur,ans;
	vector<pair<int,int> > vec[N];
	bool cmp(pair<int,int> a,pair<int,int> b){
		return a.fi<b.fi;
	}
	void solve(){
		cin>>n>>m>>k>>d;cnt=0;
		for(int i=1;i<=m;i++){
			cin>>x[i]>>y[i]>>v[i];
			X[++cnt]=x[i];
		}
		sort(X+1,X+cnt+1);cnt=unique(X+1,X+cnt+1)-X-1;
		//cout<<cnt<<'\n';
		for(int i=1;i<=cnt;i++) vec[i].clear();
		for(int i=1;i<=m;i++){
			int pos=lower_bound(X+1,X+cnt+1,x[i])-X;
			vec[pos].pb({y[i],v[i]});
		}
		for(int i=1;i<=cnt;i++) if(vec[i].size()) sort(vec[i].begin(),vec[i].end(),cmp);
		pre=0,cur=1;for(int j=0;j<=k;j++) dp[0][j]=dp[1][j]=0;
		for(int i=1;i<=cnt;i++){
			swap(cur,pre);
			int Max=-inf;
			for(int j=0;j<=min(X[i],k);j++)
				Max=max(dp[pre][j],Max),dp[cur][j]=0;
			dp[cur][0]=ans;int now=0,sz=vec[i].size(),res=0;
			ans=max(ans,Max);
			for(int j=1;j<=min(X[i],k);j++){
				while(now<sz&&vec[i][now].fi<=j) res+=vec[i][now].se,now++;
				if(i-j+1<=X[i-1])
					dp[cur][j]=dp[pre][j-(X[i]-X[i-1])]-d*(X[i]-X[i-1])+res;
				else dp[cur][j]=Max-(j*d)+res;
				ans=max(ans,dp[cur][j]);
			}
		}
		cout<<ans<<'\n';
	}
}

signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c<10) while(t--) s1::solve();
	else if(c<15) while(t--) s2::solve();
	else if(c<17) while(t--) s3::solve();
	return 0;
}
/*
1 2
5 3 3 2
2 2 10
4 3 15
5 2 10
3 2 2 1
2 2 4
3 2 3
*/
