#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define il inline
#define re register
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
//#define int ll
#define pii pair<int,int>
#define mp make_pair
#define F(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DF(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define G(i,u) for(int (i)=head[(u)];(i);(i)=nxt[(i)])
il ll read(){ll x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}return x*f;}
const int N=1010,M=100010;
int n,m,k;
ll d;
struct MS
{
	ll r,len,v;
}a[M];
ll dp[N][N];
vector<MS> vec[N];
il bool cmp(MS x,MS y)
{
	if(x.r!=y.r) return x.r<y.r;
	else if(x.len!=y.len) return x.len<y.len;
	else return x.v>y.v;
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int C=read(),T=read();
	if(C==17||C==18)
	{
		while(T--)
		{
			n=read(),m=read(),k=read(),d=read();
			ll ans=0;
			F(i,1,m)
			{
				ll r=read(),len=read(),v=read();
				if(len<=k&&len<=r&&v>len*d)
					ans+=v-len*d;
			}
			printf("%lld\n",ans);
		}
	}
	else
	{
		while(T--)
		{
			n=read(),m=read(),k=read(),d=read();
			F(i,1,m)
				a[i].r=read(),a[i].len=read(),a[i].v=read();
			sort(a+1,a+m+1,cmp);
			F(i,1,n) vec[i].clear();
			F(i,1,m)
				vec[a[i].r].push_back(a[i]);
			memset(dp,-0x3f,sizeof(dp));
			dp[0][0]=0;
			F(i,1,n)
			{
				F(j,0,min(i-1,k)) dp[i][0]=max(dp[i][0],dp[i-1][j]);
				F(j,1,min(i,k))
				{
					dp[i][j]=dp[i-1][j-1]-d;
					for(auto x:vec[i])
					{
						if(j>=x.len) dp[i][j]+=x.v;
					}
				}
			}
			ll ans=-LINF;
//			F(i,1,10)
//				F(j,0,min(i,k))
//					cout<<i<<" "<<j<<":"<<dp[i][j]<<endl;
//			cout<<endl;
			F(j,0,k)
			{
				ans=max(ans,dp[n][j]);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
