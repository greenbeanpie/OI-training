#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

struct Stu
{
	int x;
	int y;
	int v;
	
	void read()
	{
		scanf("%lld %lld %lld",&x,&y,&v);
	}
};
Stu st[100001];
int maxn = 0;
int n,m,k,d;

void dfs(int t,int sum,string qk,int lx)
{
	if(t > n)
	{
		for(int i = 1;i <= m;i++)
		{
			bool flag = true;
			for(int j = st[i].x-st[i].y+1;j <= st[i].x;j++)
			{
				if(qk[j-1] == '0')
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				sum += st[i].v;
			}
		}
		maxn = max(maxn,sum);
		return;
	}
	if(lx < k)
	{
		dfs(t+1,sum-d,qk+"1",lx+1);
	}
	dfs(t+1,sum,qk+"0",0);
}

void lll()
{
	scanf("%lld %lld %lld %lld",&n,&m,&k,&d);
	for(int i = 1;i <= m;i++)
	{
		st[i].read();
	}
	maxn = 0;
	dfs(1,0,"",0);
	printf("%lld\n",maxn);
}

signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	scanf("%lld %lld",&c,&t);
	while(t--)
	{
		lll();
	}
	return 0;
}
