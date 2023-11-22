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
int c,t,n,m,a[N],b[N],ans;
char ch;
struct qwq {char opt;int x,y;} s[N];

inline int Check(ri int sum=0)
{
	for(ri int i=1;i<=n;++i)
		a[i]=b[i];
	for(ri int i=1;i<=m;++i)
		if(s[i].opt=='F') a[s[i].x]=0;
		else if(s[i].opt=='T') a[s[i].x]=1;
		else if(s[i].opt=='U') a[s[i].x]=2;
		else if(s[i].opt=='+') a[s[i].x]=a[s[i].y];
		else a[s[i].x]=(a[s[i].y]==2?2:(a[s[i].y]?0:1));
	for(ri int i=1;i<=n;++i)
	{
		sum+=b[i]==2;
		if(a[i]!=b[i]) return inf;
	}
	return sum;
}
inline void Dfs(int x)
{
	if(x==n+1) return void(ans=min(ans,Check()));
	b[x]=0,Dfs(x+1),b[x]=1,Dfs(x+1),b[x]=2,Dfs(x+1);
}

signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	fastcin,cin>>c>>t;
	for(;t;--t)
	{
		cin>>n>>m;
		
		if(c==1||c==2)
		{
			for(ri int i=1;i<=m;++i)
			{
				cin>>s[i].opt>>s[i].x;
				if(s[i].opt=='+'||s[i].opt=='-') cin>>s[i].y;
			}
			ans=inf,Dfs(1),cout<<ans<<endl;
		}
		
		else if(c==3||c==4)
		{
			reset(a,0),ans=0;
			for(ri int i=1,x;i<=m;++i)
				cin>>ch>>x,a[x]=(ch=='U'?2:(ch=='T'?1:0));
			for(ri int i=1;i<=n;++i)
				ans+=a[i]==2;
			cout<<ans<<endl;
		}
		
		else if(c==5||c==6)
		{
			for(ri int i=1;i<=n;++i)
				a[i]=ans=0;
			for(ri int i=1,x,y;i<=m;++i)
			{
				cin>>s[i].opt>>s[i].x;
				if(s[i].opt=='+') cin>>s[i].y,a[s[i].x]=a[s[i].y];
					else a[s[i].x]=2;
			}
			for(ri int i=1;i<=n;++i)
				ans+=a[i]==2;
			ri int lst=0;
			while(lst!=ans)
			{
				lst=ans,ans=0;
				for(ri int i=1,x,y;i<=m;++i)
					if(s[i].opt=='+') a[s[i].x]=a[s[i].y];
						else a[s[i].x]=2;
				for(ri int i=1;i<=n;++i)
					ans+=a[i]==2;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
