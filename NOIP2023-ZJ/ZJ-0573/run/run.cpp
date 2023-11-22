#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int c,t;
int n,m,k,d;
int dp[N][2],ke[N][2];

struct node
{
	int x,y,v;
}a[N];

bool cmp(node x,node y)
{
	return x.x<y.x;
}

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		memset(ke,0,sizeof(ke));
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].v;
		}
		sort(a+1,a+m+1,cmp);
		
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			int e=a[i].x-a[i-1].x;
			dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
			if(a[i].v-a[i].y*d>0&&a[i].y<=k)
			{
				dp[i][1]=dp[i-1][0]+a[i].v-a[i].y*d;
				ke[i][1]=a[i].y;
			}
			ans=max(ans,dp[i][1]);
			if(ke[i-1][1]+e<=k)
			{
				if(ke[i-1][1]+e>=a[i].y)
				{
					if(a[i].v-e*d>0)
					{
						if(dp[i][1]<dp[i-1][1]+a[i].v-e*d)
						{
							ke[i][1]=ke[i-1][1]+e;
							dp[i][1]=dp[i-1][1]+a[i].v-e*d;
							ans=max(ans,dp[i][1]);
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
