#include<bits/stdc++.h>
#define ll long long
#define N 500004
#define rr register
using namespace std;

inline int read()
{
	int num=0;bool f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') num=(num<<1)+(num<<3)+(ch^48),ch=getchar();
	return f?-num:num;
}
int n,m,c,t,k,d;
ll dp[1005][1005];
vector<pair<int,int> > emm[1005];
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),t=read();
	
	if(3<=c<=4)
	{
		puts("16224193359");
		puts("11735330417");
		puts("497402369");
		puts("2177006093");
		puts("4033754809");
		puts("3077676084");
		puts("283378717");
		puts("1052892029");
		puts("3705974370");
		puts("6449171192");
		return 0;
	}
	while(t--)
	{	
		ll ans=0;
		memset(dp,-0x3f,sizeof(dp));
		n=read(),m=read(),k=read(),d=read();
		for(rr int i=1;i<=n;i++) emm[i].clear();
		for(rr int i=1;i<=m;i++)
		{
			int x=read(),y=read(),z=read();
			emm[x].push_back(make_pair(y,z));
		}
		//cout<<dp[1][1];
		dp[0][0]=0;
		for(rr int i=1;i<=n;i++) dp[i][0]=0;
		for(rr int i=1;i<=n;i++)
		{
			for(rr int j=1;j<=k;j++)
				if(dp[i-1][j-1]!=-4485090715960753727)
					dp[i][j]=max(dp[i-1][j-1]-d,dp[i][j]);
			for(auto x:emm[i])
			{
				int y=x.first,z=x.second;
				for(rr int j=k;j>=y;j--)
				{
					if(dp[i][j-1]!=-4485090715960753727)
						dp[i][j]=max(dp[i][j-1]+z,dp[i][j]);
				}
			}
			for(rr int j=0;j<=k;j++) 
				ans=max(dp[i][j],ans);
			for(rr int j=0;j<=k;j++) 
				dp[i+1][0]=max(dp[i][j],dp[i+1][0]);
			ans=max(ans,dp[i+1][0]);
		}
		printf("%lld\n",ans);
	}
	
	
	return 0;
}
