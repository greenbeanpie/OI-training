#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=1e5+5;
int c,T;
int n,m,k,d;
int x[N],y[N],v[N],da[N];
int ans;
inline void init()
{
	n=read(),m=read(),k=read(),d=read();
	for(int i=1;i<=m;i++) x[i]=read(),y[i]=read(),v[i]=read(),da[x[i]]=i;
}
inline void work(int x,int num,int sum,int tot)
{
	int re=tot;
	if(sum>k) return;
	if(x==n+1) 
	{
		ans=max(tot,ans);
		return;
	}
	if(da[x]!=0&&sum>=y[da[x]]) re+=v[da[x]];
	work(x+1,num,0,re);
	work(x+1,num+1,sum+1,re-d);
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),T=read();
	while(T--)
	{
		ans=0;
		init();
		work(0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
