#include<bits/stdc++.h>
using namespace std;
const int N=1009;
typedef long long ll;
typedef pair<int,ll> Pii;
int n,m,c,t,k,d;
vector<Pii> jiang[N];
vector<int> sm[N];
ll dp[N][N];
ll w(int x,int y)
{
	if(upper_bound(jiang[x].begin(),jiang[x].end(),make_pair(y,2147483647000LL)) == jiang[x].begin()) return 0;
	else return (*(upper_bound(jiang[x].begin(),jiang[x].end(),make_pair(y,2147483647000LL))-1)).second;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&k,&d);
		memset(dp,0xcf,sizeof(dp)),dp[0][0]=0;
		for(int i=1,x,y,z;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			jiang[x].push_back(make_pair(y,z));
		}
		for(int i=1;i<=n;i++) sort(jiang[i].begin(),jiang[i].end());
		for(int i=1;i<=n;i++)
			for(int j=1;j<jiang[i].size();j++)
			{
				jiang[i][j].second+=jiang[i][j-1].second;
			}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k;j++)
			{
				dp[i][j]=dp[i-1][j-1]+w(i,j)-d;
			}
			dp[i][0]=*max_element(dp[i-1],dp[i-1]+k+1);
			i;
		}
		printf("%lld\n",*max_element(dp[n],dp[n]+k+1));
		for(int i=1;i<=n;i++) jiang[i].clear();
	}
	
}