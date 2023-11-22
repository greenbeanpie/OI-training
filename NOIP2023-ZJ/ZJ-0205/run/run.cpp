#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5,INF=0x3f3f3f3f;
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return s*f;
}
struct node
{
	int x,y,v;
	bool operator < (node t)const
	{
		return x<t.x;
	}
}p[N];
int n,m,K,d,f[N*2],c,T,a[N*2];
set<pair<int,int> >s;
inline void solve()
{
	n=read(),m=read(),K=read(),d=read();
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		p[i].x=read(),p[i].y=read(),p[i].v=read();
		a[++cnt]=p[i].x,a[++cnt]=p[i].x-p[i].y;
	}
	sort(a+1,a+cnt+1);
	int L=unique(a+1,a+cnt+1)-a-1;
//	for(int i=1;i<=L;i++) printf("%d ",a[i]);
//	cout<<L<<'\n';
	
	sort(p+1,p+m+1);
	if(c>=17)
	{
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			if(p[i].y>K) continue;
			int temp=p[i].v-p[i].y*d;
			if(temp>0) ans+=temp;
		}
		cout<<ans<<'\n';
		return;
	}
	memset(f,0,sizeof(f));
	s.clear();
	s.insert({-INF,0});
	for(int i=0,cur=1;i<=L;i++)//i+1
	{
		while(cur<=m&&p[cur].x<=a[i])
		{
			s.insert({p[cur].x-p[cur].y,p[cur].v});
			cur++;
		}
		auto pos=s.end();pos--;
		int now=0,temp=f[i];
		for(int j=i-1;a[i]-a[j]<=K&&j>=0;j--)//ed=i-j
		{
			now-=d*(a[j+1]-a[j]);
			while((*pos).first>=a[j]) now+=(*pos).second,pos--;
			temp=max(temp,now+f[j]);
		}
		f[i+1]=temp;
	}
	cout<<f[L+1]<<'\n';
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),T=read();
	while(T--) solve();
	return 0;
}
