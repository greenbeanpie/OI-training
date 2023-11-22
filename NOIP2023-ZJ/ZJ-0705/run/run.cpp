#include<bits/stdc++.h>
#define int long long int
using namespace std;

const int N=1e4+30;

int dp[N][N];
int c,t;
int n,m,k,d;
int ans=-0x3f3f3f3f;

struct CLG
{
	int x,y,v;
}clg[N];

signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	
	while(t--)
	{
		ans=-0x3f3f3f3f;
		memset(dp,-0x3f,sizeof(dp));
		cin>>n>>m>>k>>d;
		
		for(int i=1;i<=m;i++)
		{
			cin>>clg[i].x>>clg[i].y>>clg[i].v;
		}
		
		dp[1][0]=0;
		dp[1][1]=-d;
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
			{
				if(i<j) break;
				if(j==0)
				{
					for(int l=0;l<=k;l++)
					{
						dp[i][0]=max(dp[i][0],dp[i-1][l]);
					}
				}
				else
				{
					dp[i][j]=dp[i-1][j-1]-d;
				}
			}
			
			for(int j=1;j<=m;j++)
			{
				if(i==clg[j].x) dp[i][clg[j].y]+=clg[j].v;
			}
		}
		
		for(int i=0;i<=k;i++)
		{
			ans=max(ans,dp[n][i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}

/*18784868253
16074392325
1276336325
3570868132
5185210815
4682122111
338941168
1586503061
4774212754
8031648728*/

