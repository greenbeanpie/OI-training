#include<bits/stdc++.h>
using namespace std;

#define int long long
#define il inline
#define rg register

il int read()
{
	int re=0,k=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')k=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){re=re*10+ch-48;ch=getchar();}
	return re*k;
}

il void write(int x)
{
	if(x<0)return putchar('-'),write(-x),void();
	if(x<10)return putchar(x+48),void();
	return write(x/10),write(x%10),void();
}

int n,m,f[2][2],g[2][2],a[500005],ans,cnt,t;

void sol(int x)
{
	f[0][0]=f[0][1]=g[0][1]=g[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		int t=i&1;
		if(f[t^1][0]>f[t^1][1]||(f[t^1][0]==f[t^1][1]&&g[t^1][0]<g[t^1][1]))
			f[t][0]=f[t^1][0],g[t][0]=g[t^1][0];
		else f[t][0]=f[t^1][1],g[t][0]=g[t^1][1];
		f[t][1]=f[t^1][0]+x+a[i];
		g[t][1]=g[t^1][0]+1;
	}
	if(f[n&1][0]>f[n&1][1]||(f[n&1][0]==f[n&1][1]&&g[n&1][0]<g[n&1][1]))
		ans=f[n&1][0],cnt=g[n&1][0];
	else ans=f[n&1][1],cnt=g[n&1][1];
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("P1484.in","r",stdin);
	freopen("P1484_TJ.out","w",stdout);
#endif
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sol(0);
	if(cnt<=m)//看函数的峰在不在 0-m 内。
	{
		write(ans);
		return 0;
	}
	int l=-10000000ll,r=0;
	while(l<=r)//wqs 二分。
	{
		int mid=(l+r)>>1ll;
		sol(mid);
		//cerr<<cnt<<" "<<mid<<" "<<ans<<endl;
		if(cnt<=m)
		{
			t=ans-m*mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	write(t);
}