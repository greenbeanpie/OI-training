//Private Eye,dancing with the wind.The last time.
#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define ll long long

inline int read()
{
	char c(getchar());
	int s(0);
	while(c<48) c=getchar();
	while(c>47) s=(s<<1)+(s<<3)+(c^48),c=getchar();
	return s;
}

namespace Dimly{
	int n,m,k;
	ll d,f[MAXN];
	struct data{
		int t1;
		ll t2;
	};
	inline data newdata(int t1_,ll t2_)
	{
		data s;
		s.t1=t1_;
		s.t2=t2_;
		return s;
	}
	inline bool cmp(data s1,data s2)
	{
		return s1.t1<s2.t1;
	}
	vector<data> g[MAXN];
	void solve()
	{
		scanf("%d%d%d%lld",&n,&m,&k,&d),f[0]=0;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=k;i++) f[i]=-1e18;
		for(int i=1;i<=m;i++)
		{
			int s1,s2;ll s3;
			scanf("%d%d%lld",&s1,&s2,&s3);
			if(s2>k) continue;
			g[s1].push_back(newdata(s2,s3));
		}
		for(int i=1;i<=n;i++)
		{
			sort(g[i].begin(),g[i].end(),cmp);
			ll qwq=f[0];
			for(int j=k;j>=1;j--)
			{
				if(j==1)
				{
					f[0]=max(f[0],f[1]);
					f[1]=qwq-d;
				}
				else
				{
					f[0]=max(f[0],f[j]);
					f[j]=f[j-1]-d;	
				}
			}
			ll add=0;int pos=0;
			for(int j=0;j<=k;j++)
			{
				while(pos!=(int)g[i].size())
					if(g[i][pos].t1==j) add+=g[i][pos].t2,pos++;
					else break;
				f[j]+=add;
			}
		}
		ll ans=-1e18;
		for(int i=0;i<=k;i++)
			ans=max(ans,f[i]);
		printf("%lld\n",ans);
	}
}

namespace DimlyB{
	int n,m,k,s1,s2;ll d,ans,s3;
	void solve()
	{
		scanf("%d%d%d%lld",&n,&m,&k,&d),ans=0;
		for(int i=1;i<=m;i++)
		{
			s1=read(),s2=read(),s3=read();
			if(s2>k) continue;
			ans+=max(0ll,s3-s2*d);
		}
		printf("%lld\n",ans);
	}
}

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	if(c==17 or c==18)
	{
		while(T--)
			DimlyB::solve();
		return 0;
	}
	while(T--)
		Dimly::solve();
	return 0;
}
//This is the 9th and the last time for OI competitions in Hangzhou.
//CSP-J2019,CSP-J2020,CSP-S2020,CSP-S2021,CSP-S2022,NOIP2022,ZJOI2023,CSP-S2023,NOIP2023.
//Also WC2023 and PKUSC2023,for totally 11 times.
//So,this time,I finally have to say,"Away From OI".
