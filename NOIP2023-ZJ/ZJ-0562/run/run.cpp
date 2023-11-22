#include <bits/stdc++.h>

typedef long long ll;

const int N=1e5+5;

int c,T;
int n,m,k,d;

struct A
{
	int l,r;ll v;
	int k;
}a[N];

//std::mt19937 rd(std::random_device{}());

ll anss;

void dfs(int x,int L,int R,ll s)
{
	if(x>n)
	{
		anss=std::max(anss,s);
		return;
	}
	if(a[x].l>=R+2||(a[x].l>=R+1&&L==R+1))L=a[x].l,R=L-1;
	if(a[x].r-L+1<=k)
	{
		s-=std::max(0,(a[x].r-R)*d);
		dfs(x+1,L,std::max(R,a[x].r),s+a[x].v);
	}
	dfs(x+1,L,R,s);
}

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	scanf("%d%d",&c,&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;++i)
		{
			int x,y;ll v;scanf("%d%d%lld",&x,&y,&v);
			a[i].l=x-y+1;
			a[i].r=x;
			a[i].v=v;
			a[i].k=1;
		}
		for(int i=1;i<=m;++i)
		{
			if(a[i].r-a[i].l+1>k)a[i].k=-1;
			if(a[i].v<=(a[i].r-a[i].l+1)*d)a[i].k=0;
		}
		std::sort(a+1,a+m+1,[](const A &a1,const A &a2){return a1.l!=a2.l?a1.l<a2.l:a1.r<a2.r;});
		dfs(1,1,0,0);
		printf("%lld\n",anss);
	}
	
	return 0;
}