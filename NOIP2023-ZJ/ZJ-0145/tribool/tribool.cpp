#include<bits/stdc++.h>
using namespace std;
struct node
{
	int op,id,f;
}a[100005];
int c,t,n,m;
int b[100005];
int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int main ()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;i++)
		{
			a[i].op=2;a[i].id=i;a[i].f=1;
			b[i]=0;
		}
		while(m--)
		{
			char op=getchar();
			if(op=='T')
			{
				int x=read();
				a[x].op=1;
			}
			if(op=='F')
			{
				int x=read();
				a[x].op=-1;
			}
			if(op=='U')
			{
				int x=read();
				a[x].op=0;
			}
			if(op=='+')
			{
				int x=read(),y=read();
				if(a[y].op==2)
				{
					a[x].op=2;a[x].id=a[y].id;a[x].f=a[y].f;
				}
				else
				{
					a[x].op=a[y].op;
				}
			}
			if(op=='-')
			{
				int x=read(),y=read();
				if(a[y].op==2)
				{
					a[x].op=2;a[x].id=a[y].id;a[x].f=-a[y].f;
				}
				else
				{
					a[x].op=-a[y].op;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if((a[i].op==2)&&(b[i]==0))
			{
				int p=i,f=1;
				while((b[p]==0)&&(a[p].op==2))
				{
					b[p]=f;
					f*=a[p].f;
					p=a[p].id;
				}
				if(a[p].op!=2)
				{
					int p1=i;
					while(a[p1].op==2)
					{
						a[p1].op=a[p].op*f*b[p1];
						p1=a[p1].id;
					}
					continue;
				}
				if(b[p]!=f)
				{
					p=i;
					while((b[p]!=0)&&(a[p].op==2))
					{
						a[p].op=0;
						p=a[p].id;
					}
				}
				else
				{
					p=i;
					while((b[p]!=0)&&(a[p].op==2))
					{
						a[p].op=b[p];
						p=a[p].id;
					}
				}
			}
		}
		int s=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].op==0)
			{
				s++;
			}
		}
		printf("%d\n",s);
	}
}