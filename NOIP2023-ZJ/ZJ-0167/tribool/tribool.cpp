#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int f[N], dep[N], x[N], gg[N];

int xl[N], cur;

int find(int x)
{
	if(x==f[x]) return x;
	int y = x;
	cur = 0;
	while(y!=f[y])
	{
		xl[++cur] = y;
		y = f[y];
	}
	xl[++cur] = y;
	for(int i=cur-1;i;i--)
	{
		dep[xl[i]] += dep[xl[i+1]];
		f[xl[i]] = f[xl[i+1]];
	}
	return f[x];
}

int dd(int x, int n)
{
	if(x>0)
	{
		if(x>n) return x - n;
		return x + n;
	}
	if(x==-1) return -2;
	if(x==-2) return -1;
	if(x==-3) return -3;
	return -4;
}

void solve()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for(i=1;i<=n;i++) x[i] = i;
	for(int _=1;_<=m;_++)
	{
		char v = getchar();
		while(v!='T'&&v!='F'&&v!='U'&&v!='+'&&v!='-')
			v = getchar();
		int i, j;
		scanf("%d", &i);
		if(v=='+'||v=='-') scanf("%d", &j);
		if(v=='+') x[i] = x[j];
		else if(v=='-') x[i] = dd(x[j],n);
		else
		{
			if(v=='T') x[i] = -1;
			if(v=='F') x[i] = -2;
			if(v=='U') x[i] = -3;
		}
	}
	for(i=1;i<=n;i++) f[i] = i, dep[i] = gg[i] = 0;
	for(i=1;i<=n;i++)
	{
//		printf("%d\n", i);
		int y = x[i];
		if(y<0)
		{
			gg[i] = y;
			continue;
		}
		else if(y<=n)
		{
			find(i);find(y);
			if(f[i]==f[y])
			{
				if((dep[i]-dep[y])%2!=0) gg[i] = -3;
				continue; 
			}
			else
			{
				dep[f[i]] = dep[i] - dep[y];
				f[f[i]] = f[y];
			}
		}
		else
		{
			y -= n;
			find(i);find(y);
			if(f[i]==f[y])
			{
				if((dep[i]-dep[y])%2==0) gg[i] = -3;
				continue;
			}
			else
			{
				dep[f[i]] = dep[i] + 1 - dep[y];
				f[f[i]] = f[y];
			}
		}
	}
	for(i=1;i<=n;i++)
		if(gg[i]==-3)
			gg[find(i)] = -3;
	int ans = 0;
	for(i=1;i<=n;i++)
		if(gg[find(i)]==-3)
			ans++;
	printf("%d\n", ans);
	return;
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while(t--) solve();
	return 0;
}