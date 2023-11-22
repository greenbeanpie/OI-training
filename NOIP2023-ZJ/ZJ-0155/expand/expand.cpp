#include <bits/stdc++.h>
using namespace std;
const int N=2005,MN=5e5+5;
int ta[MN],tb[MN],a[MN],b[MN],px[MN],py[MN],dp[N][N],n,m;
vector<int> ans;
void solve()
{
	if(n>2000||m>2000)
	{
		ans.emplace_back(a[1]!=b[1]&&a[n]!=b[m]&&(a[n]<b[m])==(a[1]<b[1]));
		return;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j]||(a[i]<b[j])!=(a[1]<b[1]))dp[i][j]=0;
			else dp[i][j]=dp[i-1][j-1]|dp[i][j-1]|dp[i-1][j];
		}
	}
	ans.emplace_back(dp[n][m]);
	return;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int c,q;
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>ta[i],a[i]=ta[i];
	for(int i=1;i<=m;i++)cin>>tb[i],b[i]=tb[i];
	solve();
	while(q--)
	{
		int kx,ky;
		cin>>kx>>ky;
		for(int i=1;i<=kx;i++)
		{
			int v;
			cin>>px[i]>>v;
			a[px[i]]=v;
		}
		for(int i=1;i<=ky;i++)
		{
			int v;
			cin>>py[i]>>v;
			b[py[i]]=v;
		}
		solve();
		for(int i=1;i<=kx;i++)a[px[i]]=ta[px[i]];
		for(int i=1;i<=ky;i++)b[py[i]]=tb[py[i]];
	}
	for(int x:ans)cout<<x;
	return 0;
}
