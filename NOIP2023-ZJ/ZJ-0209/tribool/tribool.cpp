#include<bits/stdc++.h>
using namespace std;
int cc,t,n,m,b[100001],c[100001],ans,xx,yy,fa[100001];
bool ttt[100001];
char ch;
struct dd{
	int op,x,y;
}a[100001];
void dfs(int cs)
{
/*	cout<<cs<<endl;
	for(int i=1;i<=n;i++)
	  cout<<b[i]<<' ';
	cout<<endl;*/
	if(cs==n)
	{
		bool tt=false;
		int sum=0;
//		cout<<cs<<endl;
		for(int i=1;i<=n;i++)
		{
			c[i]=b[i];
			if(b[i]==1)
			  sum++;
	//		cout<<b[i]<<' ';
		}
//		cout<<endl;
		for(int i=1;i<=m;i++)
		{
			if(a[i].op==1)
			  c[a[i].x]=2;
			if(a[i].op==2)
			  c[a[i].x]=0;
			if(a[i].op==3)
			  c[a[i].x]=1;
			if(a[i].op==4)
			  c[a[i].x]=c[a[i].y];
			if(a[i].op==5)
			  c[a[i].x]=2-c[a[i].y];
		}
		for(int i=1;i<=n;i++)
		  if(b[i]!=c[i])
		  {
		  	tt=true;
		  	break;
		  }
		if(!tt)
		  ans=min(ans,sum);
		return;
	}
	b[cs+1]=0;
	dfs(cs+1);
	b[cs+1]=1;
	dfs(cs+1);
	b[cs+1]=2;
	dfs(cs+1);
}
void dfs2(int s)
{
	if(ttt[s])
	{
		b[s]=0;
		return;
	}
	if(fa[s]==-1)
	{
		b[s]=0;
		return;
	}
	ttt[s]=true;
	if(fa[s]!=s)
	  dfs2(fa[s]);
	ttt[s]=false;
	b[s]=b[fa[s]];
	fa[s]=s;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>cc>>t;
	if(cc==1||cc==2)
	{
		for(int ii=1;ii<=t;ii++)
		{
			cin>>n>>m;
			ans=1000000000;
			for(int i=1;i<=m;i++)
			{
				cin>>ch;
				if(ch=='T')
				  a[i].op=1,cin>>a[i].x;
				if(ch=='F')
				  a[i].op=2,cin>>a[i].x;
				if(ch=='U')
				  a[i].op=3,cin>>a[i].x;
				if(ch=='+')
				  a[i].op=4,cin>>a[i].x>>a[i].y;
				if(ch=='-')
				  a[i].op=5,cin>>a[i].x>>a[i].y;
			}
			dfs(0);
			cout<<ans<<endl;
		}
	}else
	if(cc==3||cc==4)
	{
		for(int ii=1;ii<=t;ii++)
		{
			cin>>n>>m;
			ans=0;
			for(int i=1;i<=n;i++)
			  b[i]=-1,ttt[i]=false;
			for(int i=1;i<=m;i++)
			{
				cin>>ch;
				if(ch=='T')
				  cin>>xx,b[xx]=2;
				if(ch=='F')
				  cin>>xx,b[xx]=0;
				if(ch=='U')
				  cin>>xx,b[xx]=1;
			}
			for(int i=1;i<=n;i++)
			  if(b[i]==1)
			    ans++;
			cout<<ans<<endl;
		}
	}else
	if(cc==5||cc==6)
	{
		for(int ii=1;ii<=t;ii++)
		{
			cin>>n>>m;
			ans=0;
			for(int i=1;i<=n;i++)
			  b[i]=0,fa[i]=-1;
			for(int i=1;i<=m;i++)
			{
				cin>>ch;
				if(ch=='U')
				{
					cin>>xx;
					b[xx]=1;
					fa[xx]=xx;
				}
				if(ch=='+')
				{
					cin>>xx>>yy;
					if(xx!=yy)
					{
						if(fa[yy]==yy)
					  	  b[xx]=b[yy],fa[xx]=xx;else
					  	  b[xx]=0,fa[xx]=yy;
					}
				}
			}
			for(int i=1;i<=n;i++)
			 // if(fa[i]!=i&&fa[i]!=-1)
			    dfs2(i);
		//	cout<<ii<<endl;
		//	for(int i=1;i<=n;i++)
		//	  cout<<i<<' '<<fa[i]<<endl;
			for(int i=1;i<=n;i++)
			  if(b[i])
			    ans++;//,cout<<i<<' ';
			cout<<ans<<endl;
		}
	}
	return 0;
}