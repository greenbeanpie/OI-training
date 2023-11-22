#include<bits/stdc++.h>
using namespace std;
int rd()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=x*10+(ch^48),ch=getchar();
	return x*f;
}
const int N=5e5+5;
int c,n,m,q,x[N],y[N],tx[N],ty[N],kx,ky,p,v,t;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=rd(),n=rd(),m=rd(),q=rd();
	for(int i=1;i<=n;++i)
		tx[i]=rd();
	for(int i=1;i<=m;++i)
		ty[i]=rd();
	bool flag=true;
	for(int i=1;i<=n;++i)
		if(tx[i]==0)
		{
			flag=false;
			break;
		}
	if(flag)
		for(int i=1;i<=m;++i)
			if(ty[i]==0)
			{
				flag=false;
				break;
			}
	if((tx[1]-ty[1])*(tx[n]-ty[m])<=0)
		flag=false;
	if(flag)
		printf("1");
	else
		printf("0");
	while(q--)
	{
		for(int i=1;i<=n;++i)
			x[i]=tx[i];
		for(int i=1;i<=m;++i)
			y[i]=ty[i];
		kx=rd(),ky=rd();
		while(kx--)
		{
			p=rd(),v=rd();
			x[p]=v;
		}
		while(ky--)
		{
			p=rd(),v=rd();
			y[p]=v;
		}
		bool flag=true;
		for(int i=1;i<=n;++i)
			if(x[i]==0)
			{
				flag=false;
				break;
			}
		if(flag)
			for(int i=1;i<=m;++i)
				if(y[i]==0)
				{
					flag=false;
					break;
				}
		if((x[1]-y[1])*(x[n]-y[m])<=0)
			flag=false;
		if(flag)
			printf("1");
		else
			printf("0");
	}
	return 0;
}