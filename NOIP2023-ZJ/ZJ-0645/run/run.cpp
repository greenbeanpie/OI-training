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
ll c,t,n,m,k,d,x,y,v,as;
void slv()
{
	n=rd(),m=rd(),k=rd(),d=rd(),as=0;
	while(m--)
	{
		x=rd(),y=rd(),v=rd();
		if(y<=k&&v>y*d) as+=v-y*d;
	}	
	wt(as),puts("");
}
int main()
{
	freopen("run.in","r",stdin);freopen("run.out","w",stdout);
	c=rd(),t=rd();while(t--)slv();
	return 0;
}
