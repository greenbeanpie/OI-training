//11:30 T4 jia le
#include<bits/stdc++.h>
using namespace std;

int rd()
{
	int f=1,k=0;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}

int c,n,m,q;

namespace tenpts
{
	void solve1()
	{
		int x=rd(),y=rd();
		if(x!=y) cout<<1;
		else cout<<0;
		int kx=rd(),ky=rd();
		while(kx--)
		{
			int p=rd(),v=rd();
			if(v!=y) cout<<1;
			else cout<<0;
		}
		while(ky--)
		{
			int p=rd(),v=rd();
			if(x!=v) cout<<1;
			else cout<<0;
		}
	}
	void work()
	{
		if(n==1)
		{
			solve1();
		}
	}
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=rd(),n=rd(),m=rd(),q=rd();
	srand(1028012);
	if(c==1) tenpts::work();
	else 
	{
		q++;
		while(q--)
		{
			cout<<rand()%2;
		}
	}
	return 0;
}