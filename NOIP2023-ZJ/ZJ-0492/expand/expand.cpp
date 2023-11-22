#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)>>1)
#define ls(p) p<<1
#define rs(p) p<<1|1
#define lson ls(p),l,mid
#define rson rs(p),mid+1,r
using namespace std;
const int maxn=5e5+5,M=INT_MAX;
int c,n,m,q;
struct point{
	int maxx=0,minn=M;
}x[maxn<<2],y[maxn<<2];
int a[maxn],changex[maxn],changey[maxn];
int ymax=0,ymin=M,xmax=0,xmin=M;
inline void buildx(int p,int l,int r)
{
	if(l==r)
	{
		x[p].maxx=a[l];
		x[p].minn=a[l];
		return ;
	}
	buildx(lson);buildx(rson);
	x[p].maxx=max(x[ls(p)].maxx,x[rs(p)].maxx);
	x[p].minn=min(x[ls(p)].minn,x[rs(p)].minn);
}
inline void buildy(int p,int l,int r)
{
	if(l==r)
	{
		y[p].maxx=a[l];
		y[p].minn=a[l];
		return ;
	}
	buildy(lson);buildy(rson);
	y[p].maxx=max(y[ls(p)].maxx,y[rs(p)].maxx);
	y[p].minn=min(y[ls(p)].minn,y[rs(p)].minn);
}
inline void updatex(int p,int l,int r,int L,int R,int k)
{
	if(l>R||r<L) return;
	if(l==r)
	{
		x[p].maxx=k;
		x[p].minn=k;
		return;
	}
	updatex(lson,L,R,k);
	updatex(rson,L,R,k);
	x[p].maxx=max(x[ls(p)].maxx,x[rs(p)].maxx);
	x[p].minn=min(x[ls(p)].minn,x[rs(p)].minn);
}
inline void updatey(int p,int l,int r,int L,int R,int k)
{
	if(l>R||r<L) return;
	if(l==r)
	{
		y[p].maxx=k;
		y[p].minn=k;
		return;
	}
	updatey(lson,L,R,k);
	updatey(rson,L,R,k);
	y[p].maxx=max(y[ls(p)].maxx,y[rs(p)].maxx);
	y[p].minn=min(y[ls(p)].minn,y[rs(p)].minn);
}
inline int queryxmax(int p,int l,int r,int L,int R)
{
	if(l>R||r<L) return 0;
	if(l==r) return x[p].maxx;
	return max(queryxmax(lson,L,R),queryxmax(rson,L,R));
}
inline int queryxmin(int p,int l,int r,int L,int R)
{
	if(l>R||r<L) return M;
	if(l==r) return x[p].minn;
	return min(queryxmin(lson,L,R),queryxmin(rson,L,R));
}
inline int queryymax(int p,int l,int r,int L,int R)
{
	if(l>R||r<L) return 0;
	if(l==r) return y[p].maxx;
	return max(queryymax(lson,L,R),queryymax(rson,L,R));
}
inline int queryymin(int p,int l,int r,int L,int R)
{
	if(l>R||r<L) return M;
	if(l==r) return y[p].minn;
	return min(queryymin(lson,L,R),queryymin(rson,L,R));
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	buildx(1,1,n);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	buildy(1,1,m);
	int yy1=queryymax(1,1,m,1,1),yym=queryymax(1,1,m,m,m),xx1=queryxmax(1,1,n,1,1),xxn=queryxmax(1,1,n,n,n);
	int flag1=yy1>xx1?1:0;
	int flag2=yym>xxn?1:0;
	if(flag1!=flag2||queryymax(1,1,m,1,1)==queryxmax(1,1,n,1,1)||queryymax(1,1,m,m,m)==queryxmax(1,1,n,n,n)) cout<<0;
	else if(flag1==0)//x up
	{
		if(queryymax(1,1,m,2,m-1)>=queryxmax(1,1,n,1,n)) cout<<0;
		else if(queryxmin(1,1,n,2,n-1)<=queryymin(1,1,m,1,m)) cout<<0;
//		else if(queryxmin(1,1,n,2,n-1)<=min(yym,yy1)) cout<<0;
		else cout<<1;
	}
	else
	{
		if(queryxmax(1,1,n,2,n-1)>=queryymax(1,1,m,1,m)) cout<<0;
		else if(queryymin(1,1,m,2,m-1)<=queryxmin(1,1,n,1,n)) cout<<0;
//		else if(queryymin(1,1,m,2,m-1)<=min(xxn,xx1)) cout<<0;
		else cout<<1;
	}
	while(q--)
	{
		for(int i=1;i<=n;i++) changex[i]=0;
		for(int i=1;i<=m;i++) changey[i]=0;
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		for(int i=1;i<=kx;i++)
		{
			int p,num;
			scanf("%d%d",&p,&num);
			changex[p]=queryxmax(1,1,n,p,p);
			updatex(1,1,n,p,p,num);
		}
		for(int i=1;i<=ky;i++)
		{
			int p,num;
			scanf("%d%d",&p,&num);
			changey[p]=queryymax(1,1,m,p,p);
			updatey(1,1,m,p,p,num);
		}
		int yy1=queryymax(1,1,m,1,1),yym=queryymax(1,1,m,m,m),xx1=queryxmax(1,1,n,1,1),xxn=queryxmax(1,1,n,n,n);
		int flag1=yy1>xx1?1:0;
		int flag2=yym>xxn?1:0;
		if(flag1!=flag2||yy1==xx1||yym==xxn)
		{
			cout<<0;
			for(int i=1;i<=n;i++)
				if(changex[i]) updatex(1,1,n,i,i,changex[i]);
			for(int i=1;i<=m;i++)
				if(changey[i]) updatey(1,1,m,i,i,changey[i]);
			continue;
		}
		if(flag1==0)//x up
		{
			if(queryymax(1,1,m,2,m-1)>=queryxmax(1,1,n,1,n))
			{
				cout<<0;
				for(int i=1;i<=n;i++)
					if(changex[i]) updatex(1,1,n,i,i,changex[i]);
				for(int i=1;i<=m;i++)
					if(changey[i]) updatey(1,1,m,i,i,changey[i]);
				continue;
			}
			if(queryxmin(1,1,n,2,n-1)<=queryymin(1,1,m,1,m)||queryxmin(1,1,n,2,n-1)<=min(yym,yy1))
			{
				cout<<0;
				for(int i=1;i<=n;i++)
					if(changex[i]) updatex(1,1,n,i,i,changex[i]);
				for(int i=1;i<=m;i++)
					if(changey[i]) updatey(1,1,m,i,i,changey[i]);
				continue;
			}
			cout<<1;
			for(int i=1;i<=n;i++)
				if(changex[i]) updatex(1,1,n,i,i,changex[i]);
			for(int i=1;i<=m;i++)
				if(changey[i]) updatey(1,1,m,i,i,changey[i]);
			continue;
		}
		else
		{
			if(queryxmax(1,1,n,2,n-1)>=queryymax(1,1,m,1,m))
			{
				cout<<0;
				for(int i=1;i<=n;i++)
					if(changex[i]) updatex(1,1,n,i,i,changex[i]);
				for(int i=1;i<=m;i++)
					if(changey[i]) updatey(1,1,m,i,i,changey[i]);
				continue;
			}
			if(queryymin(1,1,m,2,m-1)<=queryxmin(1,1,n,1,n)||queryymin(1,1,m,2,m-1)<=min(xx1,xxn))
			{
				cout<<0;
				for(int i=1;i<=n;i++)
					if(changex[i]) updatex(1,1,n,i,i,changex[i]);
				for(int i=1;i<=m;i++)
					if(changey[i]) updatey(1,1,m,i,i,changey[i]);
				continue;
			}
			cout<<1;
			for(int i=1;i<=n;i++)
				if(changex[i]) updatex(1,1,n,i,i,changex[i]);
			for(int i=1;i<=m;i++)
				if(changey[i]) updatey(1,1,m,i,i,changey[i]);
			continue;
		}
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 3 3 1
8 6 9
1 7 4
0 2
1 8
3 5
*/
