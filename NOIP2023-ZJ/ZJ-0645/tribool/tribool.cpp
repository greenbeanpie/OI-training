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
const int N=1e5+5;
int c,t,n,m,x,y,as;
char v;
bool u[N];
void slv()
{
	n=rd(),m=rd();memset(u,0,sizeof u);
	while(m--)
	{
		v=gch,x=rd();
		if(v=='U')u[x]=1;
		if(v=='T'||v=='F')u[x]=0;
		if(v=='+'||v=='-')y=rd();
	}
	as=0;
	for(int i=1;i<=n;i++)if(u[i])as++;
	wt(as),puts("");
}
int main()
{
	freopen("tribool.in","r",stdin);freopen("tribool.out","w",stdout);
	c=rd(),t=rd();while(t--)slv();
	return 0;
}
