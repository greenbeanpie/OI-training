#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
int read()
{
	int f=1,s=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<1)+(s<<3)+(c-'0');c=getchar();}
	return s*f;
}
struct node
{
	int num;
	int qd=0;
}a[MAXN];
int n,m;
bool flag[MAXN];
int main()
{
	//duoceqingkong
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	c=read();t=read();
	for(int pos=1;pos<=t;pos++)
	{
		n=read();m=read();
		for(int i=1;i<=n;i++)
		{
			a[i].num=0;
			a[i].qd=0;
			flag[i]=0;
		}
		char c;
		int p1,p2;
		for(int i=1;i<=m;i++)
		{
			cin>>c;//p1=read();p2=read();
			if(c=='U'){p1=read();a[p1].qd=1;}
			else if(c=='T'){p1=read();a[p1].qd=2;}
			else if(c=='F'){p1=read();a[p1].qd=3;}
			else if(c=='+')
			{
				p1=read();p2=read();
				a[p1].qd=0;
				if(a[p2].num)a[p1].num=a[p2].num;
				else a[p1].num=p2;
			}
			else if(c=='-')
			{
				p1=read();p2=read();
				a[p1].qd=0;
				if(a[p2].num)a[p1].num=a[p2].num*-1;
				else a[p1].num=p2*-1;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].num==-i)
			{
				ans++;
				flag[i]=1;
				continue;
			}
			if(flag[abs(a[i].num)]||a[i].qd==1)
			{
				ans++;
				continue;
			}
			if(a[i].num<0)
			{
				if(a[-a[i].num].num==i)
				ans++;
				flag[i]=1;
				flag[a[i].num]=1;
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}

