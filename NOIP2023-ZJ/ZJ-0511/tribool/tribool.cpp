#include<bits/stdc++.h>
using namespace std;//WY AK IOI!!!
inline long long read()
{
	long long s=0,k=1;
	char r=getchar();
	while(!isdigit(r)) k=(r=='-')?-1:1,r=getchar();
	while(isdigit(r)) s=s*10+r-'0',r=getchar();
	return s*k;
}
#define d read()
#define ll long long
#define Maxn 100010
#define Size 100010
#define pb push_back
#define mp make_pair
#define fi first
#define se second
struct tribo
{
	ll id;bool x;
	tribo(ll Id=-1,bool X=false):id(Id),x(X){}
	tribo operator-(){return tribo(id,!x);}
	tribo operator+(){return tribo(id,x);}
	tribo operator=(const char &r)
	{
		x=false;
		switch(r)
		
		{
			case 'T':id=-1;break;
			case 'F':id=-2;break;
			case 'U':id=-3;break;
		}
	}
}a[Size];
ll color[Size];
ll vis[Size],tag=0;
void dfs(ll id,ll pre)
{
	vis[id]=1,color[id]=-pre;
	ll v=a[id].id;
	if(v<0)color[id]=-v;
	else
	{
		if(vis[v]&&color[v]<0)
		{
			if((pre^((a[id].x)?3:0))!=-color[v])
				color[v]=3;
			else color[v]=pre^((a[id].x)?3:0);
		}
		else if(!vis[v]) dfs(v,pre^((a[id].x)?3:0));
		if(a[id].x)
		{
			color[id]=3^color[v];
			if(!color[id]) color[id]=3;
		}
		else color[id]=color[v];
	}
}
void solve()
{
	ll n=d,m=d;
	for(int i=1;i<=n+3;i++)
		a[i]=tribo(i,0),vis[i]=0,color[i]=0;
	for(int i=0;i<m;i++)
	{
		char op;cin>>op;
		if(op!='+'&&op!='-'){ll x=d;a[x]=op;}
		else
		{
			ll x=d,y=d;
			if(op=='+') a[x]=a[y];
			else a[x]=-a[y];
		}
	}
	for(int i=1;i<=n;i++)
		if(!color[i]) dfs(i,1);
	ll cnt=0;
	for(int i=1;i<=n;i++) cnt+=(color[i]==3);
	printf("%lld\n",cnt);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ll tid=d,t=d;
	while(t--)
		solve();
}
