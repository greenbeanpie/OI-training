#include <iostream>
using namespace std;
int c,t,n,m,a[100001],b[100001],ans=9999999;
struct command
{
	char tp;
	int x,y;
}cd[100001];
bool check()
{
	for(int i=1;i<=n;++i)
		b[i]=a[i];
	for(int i=1;i<=m;++i)
	{
		if(cd[i].tp=='U') b[cd[i].x]=2;
		else if(cd[i].tp=='T') b[cd[i].x]=1;
		else if(cd[i].tp=='F') b[cd[i].x]=0;
		else if(cd[i].tp=='+') b[cd[i].x]=b[cd[i].y];
		else
		{
			if(b[cd[i].y]==2)
				b[cd[i].x]=2;
			else if(b[cd[i].y]==1)
				b[cd[i].x]=0;
			else
				b[cd[i].x]=1;
		}
	}
	for(int i=1;i<=n;++i)
		if(a[i]!=b[i])
			return false;
	return true;
}
void dfs(int st,int uk)
{
	if(uk>=ans)
		return;
	if(st==n+1)
	{
		if(check())
			ans=uk;
		return;
	}
	a[st]=1;
	dfs(st+1,uk);
	a[st]=0;
	dfs(st+1,uk);
	a[st]=2;
	dfs(st+1,uk+1);
	a[st]=-1;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;++i)
			a[i]=-1;
		if(c==3 or c==4)
		{
			for(int i=1;i<=m;++i)
			{
				char v;
				int cx;
				cin>>v>>cx;
				if(v=='U') a[cx]=2;
				else if(v=='T') a[cx]=1;
				else a[cx]=0;
			}
			ans=0;
			for(int i=1;i<=n;++i)
				if(a[i]==2)
					ans++;
			cout<<ans<<endl;
		}
		else if(c==5 or c==6)
		{
			for(int i=1;i<=m;++i)
			{
				char v;
				int cx,cy;
				cin>>v;
				cd[i].tp=v;
				if(v=='U')
				{
					cin>>cx;
					cd[i].x=cx;
				}
				else
				{
					cin>>cx>>cy;
					cd[i].x=cx;
					cd[i].y=cy;
				}
			}
			while(!check())
				for(int i=1;i<=n;++i)
					a[i]=b[i];
			ans=0;
			for(int i=1;i<=n;++i)
				if(a[i]==2)
					ans++;
			cout<<ans<<endl;
		}
		else
		{
			ans=9999999;
			for(int i=1;i<=m;++i)
			{
				char v;
				int cx,cy;
				cin>>v;
				cd[i].tp=v;
				if(v=='U' or v=='T' or v=='F')
				{
					cin>>cx;
					cd[i].x=cx;
				}
				else
				{
					cin>>cx>>cy;
					cd[i].x=cx;
					cd[i].y=cy;
				}
			}
			dfs(1,0);
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
