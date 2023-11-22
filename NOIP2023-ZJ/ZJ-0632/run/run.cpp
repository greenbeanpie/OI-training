#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define LL long long
using namespace std;
const int MAXM=1e5;
int c ,t,n,m,k,d;
LL f[MAXM/100+5][1005];
//LL g[MAXM/100][1005];
struct data
{
	int x ,y , v;
	bool friend operator <(data A,data B)
	{
		if (A.x ==B.x )
			return A.y <B.y ;
		return A.x <B.x ;
	}
} cha[MAXM];
void in(int &x)
{
	x=0;
	char ch=getchar();
	while (ch>'9' || ch<'0')
		ch=getchar();
	while (ch>='0' && ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	in(c),in(t);
	while (t--)
	{
		in(n),in(m),in(k),in(d);
		for (int i=1;i<=m;i++)
			in(cha[i].x),in(cha[i].y ),in(cha[i].v );
		sort(cha+1,cha+1+m);
		if (c<=25)
		{
			int mx=min(n,k);
			for (int i=1;i<=n;i++)	
				for (int j=0;j<=mx;j++)	
					f[i][j]=-0x3f3f3f3f3f3f3f3f;
			f[0][0]=0;
			int now=1;
			for (int i=1;i<=n;i++)
			{
				int ed=min(mx,i);
				LL sum=0;
				for (int j=0;j<=ed;j++)
				{
					if (j>0)
					{
						LL trans=1LL*f[i-1][j-1]-1LL*d;
						while (i==cha[now].x  )
						{
							if (j>=cha[now].y )
							{
								sum+=1LL*cha[now].v ;
								now++;
							}
							else
								break;
						}
						if (trans+sum>f[i][j])
							f[i][j]=trans+sum;
					}
					if (f[i-1][j]>f[i][0])
						f[i][0]=f[i-1][j];
				}
				while (i==cha[now].x )
					now++;
			}
			LL ans=-0x3f3f3f3f3f3f3f3f;
			for (int i=0;i<=mx;i++)
			{
				if (f[n][i]>ans)
					ans=f[n][i];
			}
		printf("%lld\n",ans);
		}
	}
	
	return 0;
}
