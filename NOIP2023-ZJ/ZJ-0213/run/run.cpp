#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
int n,m,k,d,x[100005],y[100005],v[100005];
vector <pair<int,int>> t;
int f[100005][2];
void work()
{
	cin>>n>>m>>k>>d;
	rep(i,1,m)cin>>x[i]>>y[i]>>v[i];
	t.clear();
	rep(i,1,m)
		t.push_back({x[i]-y[i]+1,i});
	sort(t.begin(),t.end());
	f[0][0]=0,f[0][1]=0;
	int p=0;
	rep(i,1,n)
	{
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		while(p<n-1&&t[p].first<=i)p++;
		int tp=p,sum=0;
		f[i][1]=-0x3f3f3f3f3f3f3f3f;
		per(j,i,max(1ll,i-k+1))
		{
			while(tp>=0&&t[tp].first>=j)
			{
				int num=t[tp].second;
				if(x[num]<=i)
					sum+=v[num];
				tp--;
			}
			f[i][1]=max(f[i][1],f[j-1][0]+sum-(i-j+1)*d);
		}
	}
	int ans=0;
	rep(i,1,n)
	{
		ans=max(ans,f[i][0]);
		ans=max(ans,f[i][1]);
	}
	cout<<ans<<endl;
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
		work();
}