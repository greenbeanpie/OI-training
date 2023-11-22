#include<bits/stdc++.h>
using namespace std;
int f[100008];
int head[100008],to[100008],next_[100008],tot=0;
int tt[100008];
int sum;
void add(int u,int v)
{
	next_[++tot]=head[u];
	head[u]=tot;
	to[tot]=v;
	return;
}
void dfs(int u,int fa)
{
	if(u==fa||u==fa) return;
	int i;
	for(i=head[u];i;i=next_[i])
	{
		if(to[i]!=fa&&to[i]!=u)
		sum++;
		dfs(to[i],u);
	}
	return;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t,n,m,cnt;
	char ch;
	int i,j,x,y;
	cin>>c>>t;
	if(t==3||t==4)
	for(i=1;i<=t;i++)
	{
		cnt=0;
		cin>>n>>m;
		for(j=1;j<=100000;j++) tt[j]=0;
		for(j=1;j<=m;j++)
		{
			ch=getchar();
			while(ch!='T'&&ch!='F'&&ch!='U') ch=getchar();
			cin>>x;
			if(ch=='T') tt[x]=1;
			else if(ch=='F') tt[x]=2;
			else if(ch=='U') tt[x]=3;
		}
		for(j=1;j<=n;j++)
		if(tt[j]==3)
		cnt++;
		cout<<cnt<<endl;
	}
	else
	for(i=1;i<=t;i++)
	{
		tot=0;
		cin>>n>>m;
		head[0]=0;
		to[0]=0;
		next_[0]=0;
		for(j=1;j<=n;j++)
		{
			f[j]=j;
			head[j]=0;
			to[j]=0;
			next_[j]=0;
		}
		for(j=1;j<=m;j++)
		{
			ch=getchar();
			while(ch!='T'&&ch!='F'&&ch!='U'&&ch!='+'&&ch!='-')
			ch=getchar();
			cin>>x;
			if(ch=='U') f[x]=0;
			else if(ch=='+'||ch=='-')
			{
				cin>>y;
				if(ch=='+') f[x]=f[y];
				else f[x]=-f[y];
			}
			
		}
		for(j=1;j<=n;j++)
		{
			if(f[j]==-j) f[j]=0;
		//	if(f[j]!=j)
		//cout<<endl<<f[j]<<" "<<j<<endl;
		f[j]=abs(f[j]);
			add(f[j],j);
		}
		sum=0;
		dfs(0,100008);
		cout<<sum<<endl;
	}
	return 0;
}
