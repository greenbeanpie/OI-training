#include<bits/stdc++.h>


using namespace std;
const int N=1e5+10;
int t,c;
int n,m;
int a[N],b[N];//U -1,T 1 ,F 0
struct node{
	char op;
	int x,y;
}ccf[55];
int mn=1e9+7;
int now=0;
int dfs(int d)
{
	if(d==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]=b[i];
		}
		for(int i=1;i<=m;i++)
		{
			int v=ccf[i].op,x=ccf[i].x,y=ccf[i].y;
			if(v=='T'||v=='F'||v=='U')
			{
				if(v=='T') a[x]=1;
				if(v=='F') a[x]=0;
				if(v=='U') a[x]=-1;
			}
			else
			{
				if(v=='+') a[x]=a[y];
				else
				{
					if(a[y]==-1) a[x]=a[y];
					else a[x]=1-a[y];
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=b[i]) return 0;
		}
		mn=min(now,mn);
		return 0;
	}
	if(now>mn) return 0;
	for(int i=1;i>=-1;i--)
	{
		b[d]=i;
		if(i==-1) now++;
		dfs(d+1);
		if(i==-1) now--;
	}
	return 0;
}
int mian()
{
	scanf("%d%d",&n,&m);
	if(c==1||c==2)
	{
		for(int i=1;i<=m;i++)
		{
			char v;
			int x,y;
			scanf("%s",&v);
			if(v=='T'||v=='F'||v=='U')
			{
				scanf("%d",&x);
			}
			else
			{
				scanf("%d%d",&x,&y);
			}
			ccf[i].op=v,ccf[i].x=x,ccf[i].y=y;
		}
		dfs(1);
		printf("%d\n",mn);
	}
	else if(c==3||c==4)
	{
		for(int i=1;i<=m;i++)
		{
			char v;
			int x;
			scanf("%s %d",&v,&x);
			if(v=='T') a[x]=1;
			if(v=='F') a[x]=0;
			if(v=='U') a[x]=-1;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==-1) ans++;
		}
		printf("%d\n",ans);
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			char v;
			scanf("%s",&v);
			if(v=='T'||v=='F'||v=='U')
			{
				int x;
				scanf("%d",&x);
				if(v=='T') a[x]=1;
				if(v=='F') a[x]=0;
				if(v=='U') a[x]=-1;
			}
			else
			{
				int x,y;
				scanf("%d%d",&x,&y);
				if(v=='+') a[x]=a[y];
				else
				{
					if(a[y]==-1) a[x]=a[y];
					else a[x]=1-a[y];
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==-1) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
//™™™™
//§§§§§§§§§√

//完了 暴力炸了 
// 看我0分拿下

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);

	scanf("%d%d",&c,&t);
	while(t--)
	{
		mian();
	}


	return 0;
}



//zsy dalao orz
//sjh dalao orz
//lzy dalao orz
//大佬们保佑我
//骗分出省一