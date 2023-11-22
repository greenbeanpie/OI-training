#include<bits/stdc++.h>
#define endl '\n'
#define fir first
#define sec second
#define ri register
#define pb push_back
#define mp make_pair
#define int long long
#define inf 2147483647
#define Swap(x,y) ((x)^=(y)^=(x)^=(y))
#define reset(x,y) memset((x),(y),sizeof((x)))
#define fastcin ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
inline int read()
{
	ri int x=0,f=0;ri char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c-'0'),c=getchar();
	return f?-x:x;
}
inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=1e5+10;
int c,t,n,m,k,d,f[21],ans;
struct qwq {int x,y,z;} a[N];
inline void Check()
{
	ri int res=0,cnt=0;
	for(ri int i=1;i<=n;++i)
	{
		if(f[i]) ++cnt,res-=d;
			else cnt=0;
		if(cnt>k) return;
	}
	for(ri int i=1;i<=m;++i)
	{
		ri int flag=0;
		for(ri int j=a[i].x-a[i].y+1;j<=a[i].x;++j)
			if(!f[j]) flag=1;
		if(!flag) res+=a[i].z;
	}
	ans=max(ans,res);
}
inline void Dfs(int x)
{
	if(x==n+1) return void(Check());
	f[x]=0,Dfs(x+1),f[x]=1,Dfs(x+1);
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),t=read();
	for(;t;--t)
	{
		n=read(),m=read(),k=read(),d=read(),ans=-inf;
		for(ri int i=1;i<=m;++i)
			a[i].x=read(),a[i].y=read(),a[i].z=read();
		reset(f,0),Dfs(1),cout<<ans<<endl;
	}
	return 0;
}
