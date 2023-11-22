#include<bits/stdc++.h>
#define lowbit(x) x&-x
#define int long long 
using namespace std;
const int N=1e5+5;
int op,t,n,m,k,d;
struct P{
	int l,r,v;
	bool operator<(const P&o)const{
		return r<o.r;
	}
}a[N];
namespace P36{
	int dp[1005][1005];
	struct BIT{
		int c[1005];
		void add(int x,int y){for(int i=x;i<=n;i+=lowbit(i))c[i]+=y;}
		int query(int x){int res=0;for(int i=x;i;i-=lowbit(i))res+=c[i];return res;}
		int query(int l,int r){return query(r)-query(l-1);}
	}bit;
	void solve(){
		memset(bit.c,0,sizeof bit.c);
		memset(dp,-0x3f,sizeof dp);
		int now=1;
		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=k;j++)dp[i][0]=max(dp[i][0],dp[i-1][j]);
			while(now<=m&&a[now].r==i){
				bit.add(a[now].l,a[now].v);
				++now;
			}
			for(int j=1;j<=min(i,k);j++){
				dp[i][j]=max(dp[i][j],dp[i-j][0]+bit.query(i-j+1,i)-j*d);
			}
		}
		int ans=-1e18;
		for(int i=0;i<=k;i++)ans=max(ans,dp[n][i]);
		cout<<ans<<endl;
	}
}
namespace P44{
	void solve(){
		int res=0;
		for(int i=1;i<=m;i++){
			int l=a[i].l,r=a[i].r,v=a[i].v;
			if(r-l+1<=k)res+=max(0ll,v-(r-l+1)*d);
		}
		cout<<res<<endl;
	}
}

signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>op>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		for(int i=1,x,y,v;i<=m;i++){
			cin>>x>>y>>v;
			a[i]=<%x-y+1,x,v%>;
		}
		sort(a+1,a+m+1);
		if(op<=9)P36::solve();
		else if(op==17||op==18)P44::solve();
	}
	return 0;
}
/*
1 1
3 2 2 1
2 2 4
3 2 3
*/
