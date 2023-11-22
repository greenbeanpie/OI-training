#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0;
	bool f=false;
	char c=getchar();
	while(!isdigit(c))
	{
		f=(c=='-');
		c=getchar();
	}
	while(isdigit(c))
	{
		s=(s<<3)+(s<<1)+c-'0';
		c=getchar();
	}
	return f?-s:s;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+'0');
}
int res,c,t,n,m,mp[15],mp2[15],p[100005],q[100005],l[100005];
char tp[100005];
int sol()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(mp[i]==3)
		{
			cnt++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		mp2[i]=mp[i];
	}
	for(int i=1;i<=m;i++)
	{
		if(tp[i]=='T')
		{
			mp2[p[i]]=1;
		}
		else if(tp[i]=='F')
		{
			mp2[p[i]]=2;
		}
		else if(tp[i]=='U')
		{
			mp2[p[i]]=3;
		}
		else if(tp[i]=='+')
		{
			mp2[p[i]]=mp2[q[i]];
		}
		else
		{
			if(mp2[q[i]]==1)
			{
				mp2[p[i]]=2;
			}
			else if(mp2[q[i]]==2)
			{
				mp2[p[i]]=1;
			}
			else
			{
				mp2[p[i]]=3;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(mp[i]!=mp2[i])
		{
			return INT_MAX;
		}
	}
	return cnt;
}
void dfs(int d)
{
	if(d!=n)
	{
		for(int i=1;i<=3;i++)
		{
			mp[d+1]=i;
			dfs(d+1);
		}
	}
	else
	{
		res=min(res,sol());
	}
}
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();
	t=read();
	if(c==1||c==2)
	{
		while(t--)
		{
			res=INT_MAX;
			n=read();
			m=read();
			for(int i=1,x,y;i<=m;i++)
			{
				tp[i]=getchar();
				while(tp[i]!='T'&&tp[i]!='F'&&tp[i]!='U'&&tp[i]!='+'&&tp[i]!='-')
				{
					tp[i]=getchar();
				}
				p[i]=read();
				if(tp[i]=='+'||tp[i]=='-')
				{
					q[i]=read();
				}
			}
			dfs(0);
			write(res);
			putchar('\n');
		}
	}
	if(c==3||c==4)
	{
		while(t--)
		{
			memset(l,0,sizeof(l));
			n=read();
			m=read();
			for(int i=1,x,y;i<=m;i++)
			{
				tp[i]=getchar();
				while(tp[i]!='T'&&tp[i]!='F'&&tp[i]!='U')
				{
					tp[i]=getchar();
				}
				p[i]=read();
			}
			for(int i=m;i>=1;i--)
			{
				if(l[p[i]])
				{
					continue;
				}
				if(tp[i]=='T')
				{
					l[p[i]]=1;
				}
				else if(tp[i]=='F')
				{
					l[p[i]]=2;
				}
				else
				{
					l[p[i]]=3;
				}
			}
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				cnt+=(l[i]==3);
			}
			write(cnt);
			putchar('\n');
		}
	}
	if(c==5||c==6)
	{
		while(t--)
		{
			memset(l,0,sizeof(l));
			n=read();
			m=read();
			for(int i=1,x,y;i<=m;i++)
			{
				tp[i]=getchar();
				while(tp[i]!='+'&&tp[i]!='U')
				{
					tp[i]=getchar();
				}
				p[i]=read();
				if(tp[i]=='+')
				{
					q[i]=read();
				}
			}
			for(int i=m;i>=1;i--)
			{
				if(tp[i]=='U')
				{
					l[p[i]]=1;
				}
			}
			for(int i=1;i<=m;i++)
			{
				if(tp[i]=='+')
				{
					if(l[p[i]])
					{
						l[q[i]]=1;
					}
					else
					{
						l[q[i]]=0;
					}
				}
				if(tp[i]=='U')
				{
					l[p[i]]=1;
				}
			}
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				cnt+=(l[i]==1);
			}
			write(cnt);
			putchar('\n');
		}
	}
	return 0;
}