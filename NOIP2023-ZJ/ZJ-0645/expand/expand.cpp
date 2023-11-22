#include<bits/stdc++.h>
#define ll long long
#define gch getchar()
using namespace std;
ll rd()
{
	ll f=1,x=0;char c;
	while(!isdigit(c=gch))if(c==45)f=-1;
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=gch;
	return f*x;
}
void wt(ll x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)wt(x/10);
	putchar(x%10+'0');
}
const int N=5e5+5;
int c,n,m,q,kx,ky,px,vx,py,vy,x[N],y[N],xx[N],yy[N];
bool ck1()
{
	if(x[1]>=y[1])return 0;
	for(int i=1;i<=min(n,m);i++)
		if(x[i]>=y[i]&&x[i]>=y[i-1])return 0;
	return 1;
}
bool ck2()
{
	if(x[1]<=y[1])return 0;
	for(int i=1;i<=min(n,m);i++)
		if(x[i]<=y[i]&&x[i]<=y[i-1])return 0;
	return 1;
}
bool slv()
{
	for(int i=1;i<=n;i++)x[i]=xx[i];
	for(int i=1;i<=m;i++)y[i]=yy[i];
	kx=rd(),ky=rd();
	for(int i=1;i<=kx;i++)px=rd(),vx=rd(),x[px]=vx;
	for(int i=1;i<=ky;i++)py=rd(),vy=rd(),y[py]=vy;
	return (ck1()||ck2());
}
int main()
{
	freopen("expand.in","r",stdin);freopen("expand.out","w",stdout);
	c=rd(),n=rd(),m=rd(),q=rd();
	
	for(int i=1;i<=n;i++)xx[i]=x[i]=rd();
	for(int i=1;i<=m;i++)yy[i]=y[i]=rd();
	wt((ck1()||ck2()));
	while(q--)wt(slv());
	return 0;
}
