#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+7;
struct node{
	int maxe,mine;
}tree[MAXN<<2][2];
int a[MAXN],b[MAXN];
void change(int p,int l,int r,int x,int v,int op)
{
	if(l==r&&l==x)
	{
		tree[p][op].mine=v;
		tree[p][op].maxe=v;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid)
	change(p*2,l,mid,x,v,op);
	if(mid<x)
	change(p*2+1,mid+1,r,x,v,op);
	tree[p][op].maxe=max(tree[p*2][op].maxe,tree[p*2+1][op].maxe);
	tree[p][op].mine=min(tree[p*2][op].mine,tree[p*2+1][op].mine);
	return ;
}
node ask(int p,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)
		return tree[p][1];
	int mid=(l+r)>>1;
	node ans,ansl,ansr;
	ansl.mine=ansr.mine=1e9+7;
	ansl.maxe=ansr.maxe=-1e9-7;
	if(x<=mid)
		ansl=ask(p*2,l,mid,x,y);
	if(mid<y)
		ansr=ask(p*2+1,mid+1,r,x,y);
	ans.mine=min(ansl.mine,ansr.mine);
	ans.maxe=max(ansl.maxe,ansr.maxe);
	return ans;
}
node query(int p,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)
		return tree[p][0];
	int mid=(l+r)>>1;
	node ans,ansl,ansr;
	ansl.mine=ansr.mine=1e9+7;
	ansl.maxe=ansr.maxe=-1e9-7;
	if(x<=mid)
		ansl=query(p*2,l,mid,x,y);
	if(mid<y)
		ansr=query(p*2+1,mid+1,r,x,y);
	ans.mine=min(ansl.mine,ansr.mine);
	ans.maxe=max(ansl.maxe,ansr.maxe);
	return ans;
}
void build(int p,int l,int r)
{
	if(l==r)
	{
		tree[p][0].maxe=tree[p][0].mine=a[l];
		tree[p][1].maxe=tree[p][1].mine=b[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	tree[p][0].maxe=max(tree[p*2][0].maxe,tree[p*2+1][0].maxe);
	tree[p][0].mine=min(tree[p*2][0].mine,tree[p*2+1][0].mine);
	tree[p][1].maxe=max(tree[p*2][1].maxe,tree[p*2+1][1].maxe);
	tree[p][1].mine=min(tree[p*2][1].mine,tree[p*2+1][1].mine);
	return ;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q;
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i(1);i<=n;++i)
	scanf("%d",&a[i]);
	for(int i(1);i<=m;++i)
	scanf("%d",&b[i]);
	build(1,1,max(n,m));
	if(n==2&&m==2)
	{
		if(query(1,1,max(n,m),1,1).mine==ask(1,1,max(n,m),1,1).mine||query(1,1,max(n,m),n,n).mine==ask(1,1,max(n,m),m,m).mine)
			printf("0");
		else
			printf("1");
	}
	else
	if(n==2&&m==1)
	{
		if(query(1,1,max(n,m),1,1).mine==ask(1,1,max(n,m),1,1).mine||query(1,1,max(n,m),n,n).mine==ask(1,1,max(n,m),m,m).mine)
			printf("0");
		else
		{
			if(query(1,1,max(n,m),1,n).mine>ask(1,1,max(n,m),1,m).maxe||query(1,1,max(n,m),1,n).maxe<ask(1,1,max(n,m),1,m).mine)
				printf("1");
			else
				printf("0");
		}
	}
	else
	if(n==1&&m==2)
	{
		if(query(1,1,max(n,m),1,1).mine==ask(1,1,max(n,m),1,1).mine||query(1,1,max(n,m),n,n).mine==ask(1,1,max(n,m),m,m).mine)
			printf("0");
		else
		{
			if(query(1,1,max(n,m),1,n).mine>ask(1,1,max(n,m),1,m).maxe||query(1,1,max(n,m),1,n).maxe<ask(1,1,max(n,m),1,m).mine)
				printf("1");
			else
				printf("0");
		}
	}
	else
	{
		if(query(1,1,max(n,m),1,1).mine==ask(1,1,max(n,m),1,1).mine||query(1,1,max(n,m),n,n).mine==ask(1,1,max(n,m),m,m).mine)
			printf("0");
		else
		{
			bool opt=0;
			for(int i(1);i<=min(n,m);++i)
			{
				node x=query(1,1,max(n,m),1,i),y=ask(1,1,max(n,m),1,i);
				if((x.mine<=y.mine&&x.maxe>=y.maxe)||(x.mine>=y.mine&&x.maxe<=y.maxe))
				{
					printf("0");
					opt=1;
					break;
				}
			}
			if(opt==0)
			printf("1");
		}
	}
	while(q--)
	{
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		while(kx--)
		{
			int u,x;
			scanf("%d%d",&u,&x);
			change(1,1,max(n,m),u,x,0);
		}
		while(ky--)
		{
			int u,x;
			scanf("%d%d",&u,&x);
			change(1,1,max(n,m),u,x,1);
		}
		if(n==2&&m==2)
		{
			if(query(1,1,max(n,m),1,1).mine==ask(1,1,max(n,m),1,1).mine||query(1,1,max(n,m),n,n).mine==ask(1,1,max(n,m),m,m).mine)
				printf("0");
			else
				printf("1");
		}
		else
		if(n==2&&m==1)
		{
			if(query(1,1,max(n,m),1,1).mine==ask(1,1,max(n,m),1,1).mine||query(1,1,max(n,m),n,n).mine==ask(1,1,max(n,m),m,m).mine)
				printf("0");
			else
			{
				if(query(1,1,max(n,m),1,n).mine>ask(1,1,max(n,m),1,m).maxe||query(1,1,max(n,m),1,n).maxe<ask(1,1,max(n,m),1,m).mine)
					printf("1");
				else
					printf("0");
			}
		}
		else
		if(n==1&&m==2)
		{
			if(query(1,1,max(n,m),1,1).mine==ask(1,1,max(n,m),1,1).mine||query(1,1,max(n,m),n,n).mine==ask(1,1,max(n,m),m,m).mine)
				printf("0");
			else
			{
				if(query(1,1,max(n,m),1,n).mine>ask(1,1,max(n,m),1,m).maxe||query(1,1,max(n,m),1,n).maxe<ask(1,1,max(n,m),1,m).mine)
					printf("1");
				else
					printf("0");
			}
		}
		else
		{
			if(query(1,1,max(n,m),1,1).mine==ask(1,1,max(n,m),1,1).mine||query(1,1,max(n,m),n,n).mine==ask(1,1,max(n,m),m,m).mine)
				printf("0");
			else
			{
				bool opt=0;
				for(int i(1);i<=min(n,m);++i)
				{
					node x=query(1,1,max(n,m),1,i),y=ask(1,1,max(n,m),1,i);
					if((x.mine<=y.mine&&x.maxe>=y.maxe)||(x.mine>=y.mine&&x.maxe<=y.maxe))
					{
						printf("0");
						opt=1;
						break;
					}
				}
				if(opt==0)
				printf("1");
			}
			build(1,1,max(n,m));
		}
	}
	return 0;
}
