#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=(l),i##_end=(r);i<i##_end;++i)
using namespace std;
constexpr int N=25,M=1e5+5;
int tt,n,m,k,d,a[M],v[M];
int main()
{
	scanf("%*d%d",&tt);
	while(tt--)
	{
		scanf("%d%d%d%d",&n,&m,&k,&d);
		F(i,0,m)
		{
			int x,y;scanf("%d%d%d",&x,&y,&v[i]);
			a[i]=(1<<x)-(1<<(x-y));
		}
		long long ans=0;
		F(i,0,1<<n)
		{
			int ii=i;
			F(j,1,k+1)ii&=i>>j;
			if(ii)continue;
			long long sum=-(long long)d*__builtin_popcount(i);
			F(j,0,m)if((i&a[j])==a[j])sum+=v[j];
			ans=max(ans,sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
