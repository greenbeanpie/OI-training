#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
const int N=1005;
const ll inf=1e18;
struct node{
	int l,r,v;
}seg[N];
int cid,T,n,m,k,d,p[N+N];
ll f[N+N][2],dp[N][N],cost[N+N][N+N];
vector<pair<int,int>>op[N];
template<typename T>
inline void rd(T&x){
	x=0;int f=1;char c=getchar();
	while (c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=f;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	rd(cid),rd(T);
	if(cid<=9){
		while(T--){
			rd(n),rd(m),rd(k),rd(d);
			rep(i,1,n)op[i].clear();
			rep(i,1,m){
				int x,y,v;
				rd(x),rd(y),rd(v);
				if(y<=k)op[x].eb(mp(y,v));
			}
			rep(i,1,k)dp[0][i]=-inf;
			dp[0][0]=0;
			rep(i,1,n){
				rep(j,0,k)dp[i][j]=-inf;
				dp[i][0]=dp[i-1][0];
				rep(j,0,k-1)if(dp[i-1][j]!=-inf){
					dp[i][j+1]=dp[i-1][j]-d;
					dp[i][0]=max(dp[i][0],dp[i-1][j]);
				}
				dp[i][0]=max(dp[i][0],dp[i-1][k]);
				for(auto u:op[i]){
					int l=u.fi,w=u.se;
					rep(j,l,k)if(dp[i][j]!=-inf)dp[i][j]+=w;
				}
			}
			ll ans=0;
			rep(i,0,k)ans=max(ans,dp[n][i]);
			cout<<ans<<'\n';
		}
		exit(0);
	}
	if(cid>=10&&cid<=14){
		while(T--){
			rd(n),rd(m),rd(k),rd(d);
			rep(i,1,n)op[i].clear();
			int cnt=0,tot=0;
			rep(i,1,m){
				int x,y,v;
				rd(x),rd(y),rd(v);
				if(y<=k)seg[++cnt]=(node){x-y+1,x,v};
			}
			rep(i,1,cnt)p[++tot]=seg[i].l,p[++tot]=seg[i].r;
			sort(p+1,p+1+tot);
			int m=unique(p+1,p+1+tot)-p-1;
//			printf("m=%d\n",m);
//			rep(i,1,m)printf("%d ",p[i]);
			rep(i,1,m)rep(j,i,m)cost[i][j]=0;
			rep(i,1,cnt){
				int L=lower_bound(p+1,p+1+m,seg[i].l)-p;
				int R=lower_bound(p+1,p+1+m,seg[i].r)-p;
				cost[L][R]+=seg[i].v;
			}
			rep(len,1,m){
				rep(i,1,m-len+1){
					int j=i+len-1;
					cost[i][j]+=cost[i][j-1]+cost[i+1][j]-cost[i+1][j-1];
				}
			}
			ll ans=0;
			f[0][0]=f[0][1]=0;
//			f[0]=0;
			rep(i,1,m){
				f[i][0]=f[i][1]=-inf;
				rep(j,1,i){
					if(p[i]-p[j]+1<=k){
						if(j>1&&p[j-1]+1==p[j])
							f[i][1]=max(f[i][1],f[j-1][0]-1LL*(p[i]-p[j]+1)*d+cost[j][i]);
						else f[i][1]=max(f[i][1],max(f[j-1][0],f[j-1][1])-1LL*(p[i]-p[j]+1)*d+cost[j][i]);
					}
				}
				f[i][0]=max(f[i-1][1],f[i-1][0]);
				ans=max(ans,max(f[i][0],f[i][1]));
			}
			cout<<ans<<'\n';
		}
		exit(0);
	}
	if(cid>=15&&cid<=16){
		while(T--){
			rd(n),rd(m),rd(k),rd(d);
			ll ans=0;
			rep(i,1,m){
				int x,y,v;
				rd(x),rd(y),rd(v);
				if(y<=k)ans+=max(0LL,v-1LL*y*d);
			}
			cout<<ans<<'\n';
//			write(ans);puts("");
		}
		exit(0);
	}
	return 0;
}