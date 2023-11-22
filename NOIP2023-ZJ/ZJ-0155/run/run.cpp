#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct node
{
	int l,x,y,v;
	bool operator < (const node &o)const
	{
		return l<o.l;
	}
}a[N];
int c[N],m,k,d,ans;
void check()
{
	int cur=0,las=-5,res=0;
	for(int i=1;i<=m;i++)
	{
		if(!c[i])continue;
		if(las>=a[i].x)res+=a[i].v;
		else if(las+1<a[i].l)cur=k-a[i].y,las=a[i].x,res+=a[i].v-a[i].y*d;
		else if(cur<a[i].x-las)return;
		else cur-=a[i].x-las,las=a[i].x,res+=a[i].v-(a[i].x-las)*d;
	}
	ans=max(ans,res);
	return;
}
void dfs(int p)
{
	if(!p)return check(),void();
	c[p]=0,dfs(p-1);
	c[p]=1,dfs(p-1);
	return;
}
void solve()
{
	ans=m=0;
	int n,tmp;
	cin>>n>>tmp>>k>>d;
	while(tmp--)
	{
		++m;
		cin>>a[m].x>>a[m].y>>a[m].v;
		a[m].l=a[m].x-a[m].y+1;
		if(a[m].y>k)m--;
	}
	sort(a+1,a+m+1);
	dfs(m);
	cout<<ans<<endl;
	return;
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	int T;
	cin>>T;cin>>T;
	while(T--)solve();
	return 0;
}/*goodbye OI, AFOed.*/