#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=20;

int f[N];

const int M=110;

int c,T,n,m,k,d;

int v[M],r[M],len[M];

int check(int x)
{
	f[0]=0;
	int res=0;
	for(int i=0;i<n;i++)
	if(x & (1<<i))
	{
		f[i+1]=f[i]+1;
		res++;
	}else	f[i+1]=0;
	return res;
}

signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>T;
	
	while(T--)
	{
		cin>>n>>m>>k>>d;
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			cin>>r[i]>>len[i]>>v[i];
		}
		for(int i=1;i<(1<<n)-1;i++)
		{
			int res=-check(i)*d;
			for(int j=1;j<=m;j++)
				if(f[r[j]]>=len[j])	res+=v[j];
			if(res>ans)	ans=res;
		}
		cout<<ans<<"\n";
	}
	return 0;
}