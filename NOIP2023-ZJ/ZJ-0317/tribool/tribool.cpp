#include<bits/stdc++.h>
#define N 100010
using namespace std;
int c,t,n,m,ans,f[N],f1[N],f2[N];
char op[N];
inline int read()
{
	int aa=0,op=1;
	char ch=getchar();
	while (!isdigit(ch))
	{
		if (ch=='-') op=-1;
		ch=getchar();
	}
	while (isdigit(ch))
	{
		aa=aa*10+(int)(ch-'0');
		ch=getchar();
	}
	return aa*op;
}
inline void check()
{
	int num=0;
	int b[N];
	for (int i=1;i<=n;i++)
	{
		if (f[i]==3) num++;
		b[i]=f[i];
	}
	for (int i=1;i<=m;i++)
	{
		if (op[i]=='+') b[f1[i]]=b[f2[i]];
		if (op[i]=='-') 
		{
			if (b[f2[i]]==1) b[f1[i]]=2;
			  else if (b[f2[i]]==2) b[f1[i]]=1;
					else if (b[f2[i]]==3) b[f1[i]]=3;
		}
		if (op[i]=='T') b[f1[i]]=1;
		if (op[i]=='F') b[f1[i]]=2;
		if (op[i]=='U') b[f1[i]]=3;
	}
	bool p=1;
	for (int i=1;i<=n;i++)
	  if (b[i]!=f[i])
	  {
	  	p=0; break;
	  }
	if (p) ans=min(ans,num);
	return;
}
inline void dfs(int x)
{
	if (x>n)
	{
		check(); return;
	}
	f[x]=1; dfs(x+1);
	f[x]=2; dfs(x+1);
	f[x]=3; dfs(x+1); f[x]=0;
}
inline void solve1()
{
	while (t--)
	{
		n=read(); m=read();
		for (int i=1;i<=n;i++) f[i]=0;
		for (int i=1;i<=m;i++) 
		{
			f1[i]=0; f2[i]=0;
		}
		for (int i=1;i<=m;i++)
		{
			op[i]=getchar();
			if (op[i]=='-'||op[i]=='+')
			{
				f1[i]=read(); f2[i]=read();
			}
			if (op[i]=='U'||op[i]=='T'||op[i]=='F') f1[i]=read();
		}
		ans=1e9;
		dfs(1);
		printf("%d\n",ans);
	}
}
inline void solve2()
{
	char op;
	int num;
	while (t--)
	{
		n=read(); m=read();
		for (int i=1;i<=n;i++) f[i]=0;
		while (m--)
		{
			op=getchar(); num=read();
			if (op=='T') f[num]=1;
			if (op=='F') f[num]=2;
			if (op=='U') f[num]=3;
		}
		int ans=0;
		for (int i=1;i<=n;i++)
		  if (f[i]==3) ans++;
		printf("%d\n",ans);
	}
}
inline void solve3()
{
	char op;
	while (t--)
	{
		n=read(); m=read();
		for (int i=1;i<=n;i++) f[i]=0;
		while (m--)
		{
			op=getchar();
			if (op=='U') 
			{
				int x;
				x=read(); f[x]=3;
			}
			if (op=='+')
			{
				int x,y;
				x=read(); y=read();
				f[x]=f[y];
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++) 
		  if (f[i]==3) ans++;
		printf("%d\n",ans);
	}
}
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read(); t=read();
	if (c==1||c==2) solve1();
	if (c==3||c==4) solve2();
	if (c==5||c==6) solve3();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
