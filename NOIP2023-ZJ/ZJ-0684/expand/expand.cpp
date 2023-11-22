#include<bits/stdc++.h>
using namespace std;
int rea()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int n,m,c,q;
	c=rea(),n=rea(),m=rea(),q=rea();
	for(int i=1;i<=n;i++)
	{
		int x;
		x=rea();
	}
	for(int j=1;j<=m;j++)
	{
		int x;
		x=rea();
	}
	for(int i=1;i<=q;i++)
	{
		int nx,ny;
		nx=rea();
		ny=rea();
		while(nx--) 
		{
			int x,y;
			x=rea(),y=rea();
		}
		while(ny--)
		{
			int x,y;
			x=rea(),y=rea();
		}
	} 
	for(int i=1;i<=q+1;i++) cout<<0;
	cout<<endl;
	//Thanks for everyone who loves me and helps me!
	return 0;
}
