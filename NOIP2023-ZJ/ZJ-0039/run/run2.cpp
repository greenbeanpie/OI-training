#include<bits/stdc++.h>
using namespace std;

constexpr int maxn=100010;

int l[maxn],r[maxn],v[maxn];

int main()
{
	freopen("run.in","r",stdin);
	freopen("run2.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		int n,m,k,d,i,j;
		long long ans=0;
		cin>>n>>m>>k>>d;
		for(i=1;i<=m;i++) cin>>r[i]>>l[i]>>v[i],r[i]--,l[i]=r[i]-l[i]+1;
		for(i=0;i<(1<<n);i++)
		{
			int row=0;
			for(j=0;j<n;j++)
			{
				if(i>>j&1)
				{
					row++;
					if(row==k+1) break;
				}
				else row=0;
			}
			if(j<n) continue;
			long long tmp=-1LL*d*__builtin_popcount(i);
			for(j=1;j<=m;j++) if((i>>l[j]&((1<<(r[j]-l[j]+1))-1))==(1<<(r[j]-l[j]+1))-1) tmp+=v[j];
			ans=max(ans,tmp);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
