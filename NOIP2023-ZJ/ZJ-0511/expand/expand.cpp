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
#define Maxn 10010
#define Size 10010
#define pb push_back
#define mp make_pair
#define fi first
#define se second
vector<ll>a,b,c,A,B;
map<pair<ll,ll>,ll>vis;
bool dfs(ll id,ll x)
{
	if(vis.find(mp(id,x))!=vis.end())
		return vis[mp(id,x)];
	if(id==b.size())
	{
		if(c[x]>b.back()) return 1;
		return 0;
	}
	for(int i=x;i<a.size();i++)
	{
		if(b[id]>=a[i]) break;
		if(dfs(id+1,x)||dfs(id,x+1)||dfs(id+1,x+1)) return vis[mp(id,x)]=1;
	}
	return vis[mp(id,x)]=0;
}
bool check()
{
	c.clear(),vis.clear();
	for(int i=0;i<a.size();i++) c.pb(a[i]);
	for(int i=0;i<b.size();i++) c.pb(b[i]);
	sort(c.begin(),c.end());
	c.resize(unique(c.begin(),c.end())-c.begin());
	for(int i=0;i<a.size();i++)
		a[i]=lower_bound(c.begin(),c.end(),a[i])-c.begin()+1;
	for(int i=0;i<b.size();i++)
		b[i]=lower_bound(c.begin(),c.end(),b[i])-c.begin()+1;
	c.clear();
	c.pb(0x3f3f3f3f3f3f3f3f);
	for(int i=a.size()-1;i>=0;i--) c.pb(min(c.back(),a[i]));
	reverse(c.begin(),c.end());
	if(a[0]<b[0]) return 0;
	return dfs(0,0);
}
void solve(ll k1,ll k2)
{
	a=A,b=B;
	while(k1--)
	{
		ll x=d,y=d;
		a[x-1]=y;
	}
	while(k2--)
	{
		ll x=d,y=d;
		b[x-1]=y;
	}
	if((a[0]-b[0])*(a.back()-b.back())<0)
	{
		putchar('0');
		return;
	}
	ll ma=a[0],mb=b[0];
	for(int i=1;i<a.size();i++) ma=max(ma,a[i]);
	for(int i=1;i<b.size();i++) mb=max(mb,b[i]);
	bool flag=0;
	if(ma<mb) swap(a,b);
	if(check()) putchar('1');
	else putchar('0');
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	d;ll n=d,m=d,q=d;
	for(int i=1;i<=n;i++) A.pb(d);
	for(int i=1;i<=m;i++) B.pb(d);
	solve(0,0);
	while(q--)
	{
		ll k1=d,k2=d;
		solve(k1,k2);
	}
}
