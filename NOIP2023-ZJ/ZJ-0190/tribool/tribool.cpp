#include<bits/stdc++.h>
using namespace std;
int MIN,n,m,a[15],b[15],fa[100005],x[100005],y[100005],tot=0,head[100005],son[100005],nxt[100005];
char ch[100005],d[100005];
void dfs(int now,int s)
{
	int i;
	if(s>=MIN) return;
	if(now>n)
	{
		for(i=1;i<=n;i++)
			b[i]=a[i];
		for(i=1;i<=m;i++)
		{
			if(ch[i]=='T') a[x[i]]=1;
			if(ch[i]=='F') a[x[i]]=0;
			if(ch[i]=='U') a[x[i]]=-1;
			if(ch[i]=='+') a[x[i]]=a[y[i]];
			if(ch[i]=='-')
			{
				if(a[y[i]]==-1) a[x[i]]=-1;
				else a[x[i]]=1-a[y[i]];
			}
		}
		bool flag=1;
		for(i=1;i<=n;i++)
			if(a[i]!=b[i]) flag=0;
		if(flag) MIN=min(MIN,s);
		return;
	}
	for(i=-1;i<=1;i++)
	{
		a[now]=i;
		if(i==-1) dfs(now+1,s+1);
		else dfs(now+1,s);
	}
}
void bl(int now)
{
	d[now]='U';
	for(int i=head[now];i;i=nxt[i])
		bl(son[i]);
	head[now]=0;
}
void add(int x,int y)
{
	tot++;
	nxt[tot]=head[x];
	head[x]=tot;
	son[tot]=y;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int i,c,t,j;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++)
		{
			getchar();
			ch[i]=getchar();
			if(ch[i]=='T'||ch[i]=='F'||ch[i]=='U') scanf("%d",x+i);
			else scanf("%d%d",x+i,y+i);
		}
		if(c==1||c==2)
		{
			MIN=INT_MAX;
			dfs(1,0);
			printf("%d\n",MIN);
		}
		if(c==3||c==4)
		{
			int ans=0;
			for(i=1;i<=m;i++)
				d[x[i]]=ch[i];
			for(i=1;i<=n;i++)
				ans+=(d[i]=='U');
			printf("%d\n",ans);
		}
		if(c==5||c==6)
		{
			tot=0;
			for(i=1;i<=n;i++)
				head[i]=0,d[i]=' ';
			for(i=1;i<=m;i++)
			{
				if(ch[i]=='U') bl(x[i]);
				else
				{
					add(y[i],x[i]);
					if(fa[x[i]])
					{
						for(j=head[x[i]];j;j=nxt[j])
							add(fa[x[i]],son[j]);
						head[x[i]]=0;
					}
					fa[x[i]]=y[i];
				}
			}
			int ans=0;
			for(i=1;i<=n;i++)
				ans+=(d[i]=='U');
			printf("%d\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
