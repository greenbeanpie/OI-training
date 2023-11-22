#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define M 1005
using namespace std;
int n,m,a[N],b[N];
int oria[N],orib[N];
int op,q;
bool pp;
int all;
//int xla;list a's gs
int aa[5000],bb[5000];
//int xlb;list b's gs
bool check(int x1,int x2,int x3,int y1,int y2,int y3)
{
	ll dec1,dec2,dec3;
	dec1=x1-y1;
	dec2=x2-y2;
	dec3=x3-y3;
	if ((1ll)*dec1*dec2>0&&(1ll)*dec1*dec3>0&&(1ll)*dec2*dec3>0) return true;
	return false;
}
bool check()
{
	for (int i=1;i<=n;i++)
	{
		bool pig=false;
		for (int j=1;j<=all*2-1;j++)
		{
			if (aa[j]==a[i])
			{
				pig=true;
				break;
			}
		}
		if (pig==false) return false;
	}
	for (int i=1;i<=m;i++)
	{
		bool pig=false;
		for (int j=1;j<=all*2-1;j++)
		{
			if (bb[j]==b[i])
			{pig=true;break;}
		}
		if (pig==false) return false;
	}
	for (int i=1;i<=all*2-1;i++)
		for (int j=1;j<=all*2-1;j++)
		if (i!=j)
		{
			ll dd1=aa[i]-bb[i],dd2=aa[j]-bb[j];
			if ((1ll)*dd1*dd2<=0) return false;
		}
	/*for (int i=1;i<=all*2-1;i++)
	cout<<aa[i]<<" ";cout<<endl;
	for (int i=1;i<=all*2-1;i++)
	cout<<bb[i]<<" ";cout<<endl;*/
	
	return true;
}
void buildb(int hhh,int noww)
{
	if (pp) return ;
	if (hhh==all*2-1)
	{
		if (check()) pp=true;
		return ;
	}
	for (int i=noww;i<=m;i++)
		if (m-i+hhh+1<=all*2-1)
		{
			bb[hhh+1]=b[i];
			buildb(hhh+1,i);
		}
	return ;
}
void dfs(int x,int now)
{
	if (pp) return ;
	if (x==all*2-1)
	{
		buildb(1,1);
		return ;
	}
	for (int i=now;i<=n;i++)
		//for (int j=n-i+x+1;j<=all*2-1)
		if (n-i+x+1<=all*2-1)
		{
			aa[x+1]=a[i];
			dfs(x+1,i);
		}
	return ;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&op,&n,&m,&q);
	for (int i=1;i<=n;i++)
		scanf("%d",&oria[i]);
	for (int i=1;i<=m;i++)
		scanf("%d",&orib[i]);
	if (op==1)
	{
		for (int i=1;i<=n;i++) a[i]=oria[i];
		for (int i=1;i<=m;i++) b[i]=orib[i];
		if (a[1]!=b[1]) cout<<1;
		else cout<<0;
		while (q>0)
		{
			for (int i=1;i<=n;i++) a[i]=oria[i];
			for (int i=1;i<=m;i++) b[i]=orib[i];
			int xxx,yyy;
			scanf("%d%d",&xxx,&yyy);
			for (int i=1;i<=xxx;i++)
			{
				int xxxx,yyyy;
				scanf("%d%d",&xxxx,&yyyy);
				a[xxxx]=yyyy;
			}
			for (int i=1;i<=yyy;i++)
			{
				int xxxx,yyyy;
				scanf("%d%d",&xxxx,&yyyy);
				b[xxxx]=yyyy;
			}
			if (a[1]!=b[1]) cout<<1;
			else cout<<0;
			q--;
		}
		return 0;
	}
	if (op==2)
	{
		if (n==2&&m==2)
		{
		for (int i=1;i<=n;i++) a[i]=oria[i];
		for (int i=1;i<=m;i++) b[i]=orib[i];
		if (check(a[1],a[2],a[2],b[1],b[2],b[2])||check(a[1],a[1],a[2],b[1],b[2],b[2])||check(a[1],a[2],a[2],b[1],b[1],b[2])) cout<<1;
			else cout<<0;
		while (q>0)
		{
			for (int i=1;i<=n;i++) a[i]=oria[i];
			for (int i=1;i<=m;i++) b[i]=orib[i];
			int xxx,yyy;
			scanf("%d%d",&xxx,&yyy);
			for (int i=1;i<=xxx;i++)
			{
				int xxxx,yyyy;
				scanf("%d%d",&xxxx,&yyyy);
				a[xxxx]=yyyy;
			}
			for (int i=1;i<=yyy;i++)
			{
				int xxxx,yyyy;
				scanf("%d%d",&xxxx,&yyyy);
				b[xxxx]=yyyy;
			}
			//cout<<a[1]<<" "<<a[2]<<" "<<b[1]<<" "<<b[2]<<endl;
			if (check(a[1],a[2],a[2],b[1],b[2],b[2])||check(a[1],a[1],a[2],b[1],b[2],b[2])||check(a[1],a[2],a[2],b[1],b[1],b[2])) cout<<1;
			else cout<<0;
			q--;
		}
		}
		else
		{
			if (n==1&&m==2)
			{
				for (int i=1;i<=n;i++) a[i]=oria[i];
				for (int i=1;i<=m;i++) b[i]=orib[i];
				if (check(a[1],a[1],a[1],b[1],b[2],b[2])||check(a[1],a[1],a[1],b[1],b[1],b[2])) cout<<1;
				else cout<<0;
				while (q>0)
				{
					for (int i=1;i<=n;i++) a[i]=oria[i];
					for (int i=1;i<=m;i++) b[i]=orib[i];
					int xxx,yyy;
					scanf("%d%d",&xxx,&yyy);
					for (int i=1;i<=xxx;i++)
					{
						int xxxx,yyyy;
						scanf("%d%d",&xxxx,&yyyy);
						a[xxxx]=yyyy;
					}
					for (int i=1;i<=yyy;i++)
					{
						int xxxx,yyyy;
						scanf("%d%d",&xxxx,&yyyy);
						b[xxxx]=yyyy;
					}
					//cout<<a[1]<<" "<<a[2]<<" "<<b[1]<<" "<<b[2]<<endl;
					if (check(a[1],a[1],a[1],b[1],b[2],b[2])||check(a[1],a[1],a[1],b[1],b[1],b[2])) cout<<1;
					else cout<<0;
					q--;
				}
			}
			else
			{
				for (int i=1;i<=n;i++) a[i]=oria[i];
				for (int i=1;i<=m;i++) b[i]=orib[i];
				if (check(a[1],a[2],a[2],b[1],b[1],b[1])||check(a[1],a[1],a[2],b[1],b[1],b[1])) cout<<1;
				else cout<<0;
				while (q>0)
				{
					for (int i=1;i<=n;i++) a[i]=oria[i];
					for (int i=1;i<=m;i++) b[i]=orib[i];
					int xxx,yyy;
					scanf("%d%d",&xxx,&yyy);
					for (int i=1;i<=xxx;i++)
					{
						int xxxx,yyyy;
						scanf("%d%d",&xxxx,&yyyy);
						a[xxxx]=yyyy;
					}
					for (int i=1;i<=yyy;i++)
					{
						int xxxx,yyyy;
						scanf("%d%d",&xxxx,&yyyy);
						b[xxxx]=yyyy;
					}
					//cout<<a[1]<<" "<<a[2]<<" "<<b[1]<<" "<<b[2]<<endl;
					if (check(a[1],a[2],a[2],b[1],b[1],b[1])||check(a[1],a[1],a[2],b[1],b[1],b[1])) cout<<1;
					else cout<<0;
					q--;
				}
			}
		}
		return 0;
	}
	//cout<<"RP++"<<endl;
	all=max(n,m);
	for (int i=1;i<=n;i++) a[i]=oria[i];
	for (int i=1;i<=m;i++) b[i]=orib[i];
	pp=false;
	aa[1]=a[1];bb[1]=b[1];
	dfs(1,1);
	if (pp) cout<<1;else cout<<0;
	while (q>0)
	{
		for (int i=1;i<=n;i++) a[i]=oria[i];
		for (int i=1;i<=m;i++) b[i]=orib[i];
		int xxx,yyy;
		scanf("%d%d",&xxx,&yyy);
		for (int i=1;i<=xxx;i++)
		{
			int xxxx,yyyy;
			scanf("%d%d",&xxxx,&yyyy);
			a[xxxx]=yyyy;
		}
		for (int i=1;i<=yyy;i++)
		{
			int xxxx,yyyy;
			scanf("%d%d",&xxxx,&yyyy);
			b[xxxx]=yyyy;
		}
		pp=false;
		aa[1]=a[1];bb[1]=b[1];
		dfs(1,1);
		if (pp) cout<<1;else cout<<0;
		q--;
	}
	return 0;
//	int xnow=1,ynow=1;
//	while (xnow<=n&&ynow<=m)
//	{
//		if (a[xnow]>b[ynow]) ynow++;
//		else xnow++; 
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
