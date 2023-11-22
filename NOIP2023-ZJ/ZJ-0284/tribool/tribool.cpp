#include<bits/stdc++.h>
using namespace std;
int ans,n,m,type,t;
char op[100005];
int a[100005][2];
int c[15],st[15];
int q[100005];
int vis[100005];
int fa[100005];
int siz[100005];
bool check()
{
	for (int i=1;i<=n;i++)
		st[i]=c[i];
/*	for (int i=1;i<=n;i++)
		cout<<st[i]<<' ';
	cout<<endl;*/
	for (int i=1;i<=m;i++)
	{
		if (op[i]=='T') 
			c[a[i][0]]=1;else
		if (op[i]=='F')
			c[a[i][0]]=0;else
		if (op[i]=='U')
			c[a[i][0]]=2;else
		if (op[i]=='+')
		{
			int x=a[i][0],y=a[i][1];
			c[x]=c[y];
		}else
		{
			int x=a[i][0],y=a[i][1];
			if (c[y]==0) c[x]=1;
			else if (c[y]==1) c[x]=0;
			else c[x]=2;
		}
	}
	bool flag=true;
	for (int i=1;i<=n;i++)
		if (st[i]!=c[i])
		{
			flag=false;
			break;
		}
/*	for (int i=1;i<=n;i++)
		cout<<c[i]<<' ';
	cout<<endl;
	system("pause");*/
	for (int i=1;i<=n;i++)	c[i]=st[i];
	return flag;
}
void dfs(int d)
{
	if (d>n)
	{
		if (check())
		{
			int sum=0;
			for (int i=1;i<=n;i++)
				if (c[i]==2)
					sum++;
			
			ans=min(ans,sum);
		}
		return;
	}
	c[d]=0;
	dfs(d+1);
	c[d]=1;
	dfs(d+1);
	c[d]=2;
	dfs(d+1);
}
int find(int x)
{
	return x== fa[x] ? fa[x] : fa[x]=find(fa[x]);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&type,&t);
	if (type<=2)
	{
		while (t--)
		{
			scanf("%d%d",&n,&m);getchar();
			for (int i=1;i<=m;i++,getchar())
			{
				scanf("%c ",&op[i]);
				if (op[i]=='-'||op[i]=='+')
					scanf("%d%d",&a[i][0],&a[i][1]);
				else 
					scanf("%d",&a[i][0]);
			}
			/*for (int i=1;i<=m;i++,cout<<endl)
			{
				cout<<op[i]<<' ';
				if (op[i]=='-'||op[i]=='+')
					cout<<a[i][0]<<' '<<a[i][1];
				else 
					cout<<a[i][0];
			}*/
			ans=1e9;
			//cout<<"!!!!!!"<<endl;
			dfs(1);
			printf("%d\n",ans);
		}
		return 0;
	}else if (type>2&&type<=4)
	{
		while (t--)
		{
			scanf("%d%d",&n,&m);getchar();
			for (int i=1;i<=n;i++)
				q[i]=1e9;
			for (int i=1;i<=m;i++,getchar())
			{
				scanf("%c ",&op[i]);
				if (op[i]=='-'||op[i]=='+')
					scanf("%d%d",&a[i][0],&a[i][1]);
				else 
					scanf("%d",&a[i][0]);
			}
			ans=0;
			for (int i=1;i<=m;i++)
			{
				if (op[i]=='T')
					q[a[i][0]]=1;
				if (op[i]=='F')
					q[a[i][0]]=0;
				if (op[i]=='U')
					q[a[i][0]]=2;
			}
			for (int i=1;i<=n;i++)
				if (q[i]==2)
					ans++;
			printf("%d\n",ans);
		}
		return 0;
	}else if (type>4&&type<=6)
	{
		while (t--)
		{
			scanf("%d%d",&n,&m);getchar();
			for (int i=1;i<=n;i++)
				siz[i]=1,vis[i]=0,fa[i]=i,q[i]=1e9;
			for (int i=1;i<=m;i++,getchar())
			{
				scanf("%c ",&op[i]);
				if (op[i]=='-'||op[i]=='+')
					scanf("%d%d",&a[i][0],&a[i][1]);
				else 
					scanf("%d",&a[i][0]);
			}
			ans=0;
			for (int i=1;i<=m;i++)
				if (op[i]=='+')
				{
					int x=a[i][0],y=a[i][1];
					int rx=find(x),ry=find(y);
					//cout<<<<' '<<a[i][1]<<endl;
					fa[rx]=ry;
					siz[ry]++;
					q[x]=q[y];
				}else
					q[a[i][0]]=2;
		for (int i=1;i<=n;i++)
			if (fa[i]==i&&q[i]==2) ans=ans+siz[i],vis[i]=1;
			else if (q[i]==2&&vis[fa[i]]==0) ans++;
		printf("%d\n",ans);
		}
		
		return 0;
	}
	return 0;
}
// qing kong
// mle
// huan hang
