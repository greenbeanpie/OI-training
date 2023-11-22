#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 200005
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-48;ch=getchar();}
	return s*f;
}
int c,t,n,m,ans=inf;
int a[N],b[N],fa[N];
char op[N],st[N],ed[N],tmp[N];
char f(char s)
{
	if(s=='T') return 'F';
	if(s=='F') return 'T';
	return 'U';
}
inline void dfs(int step,int sum)
{
//	cout<<step<<" "<<sum<<endl;
	if(sum>=ans) return;
	if(step==n+1)
	{
		for(int i=1;i<=n;i++) tmp[i]=st[i];
		for(int i=1;i<=m;i++)
		{
			if(op[i]=='+') tmp[a[i]]=tmp[b[i]];
			else if(op[i]=='-') tmp[a[i]]=f(tmp[b[i]]);
			else tmp[a[i]]=op[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(st[i]!=tmp[i]) break;
			if(i==n) ans=sum;
		}
		return;
	}
	st[step]='T'; dfs(step+1,sum);
	st[step]='F'; dfs(step+1,sum);
	st[step]='U'; dfs(step+1,sum+1);
}
inline int find(int r)
{
	return r==fa[r]?r:fa[r]=find(fa[r]);
}
inline void merge(int a,int b)
{
	fa[find(a)]=find(b);
}
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>op[i];
			cin>>a[i];
			if(op[i]=='-'||op[i]=='+') cin>>b[i];
		}
		if(c==1||c==2)
		{
			ans=inf;
			dfs(1,0);
			cout<<ans<<endl;
			continue;
		}
		if(c==3||c==4)
		{
			ans=0;
			for(int i=1;i<=n;i++) ed[i]='K';
			for(int i=1;i<=m;i++) ed[a[i]]=op[i];
			for(int i=1;i<=n;i++) if(ed[i]=='U') ans++;
			cout<<ans<<endl;
			continue;
		}
		if(c==5||c==6)
		{
			ans=0; fa[0]=0;
			for(int i=1;i<=n;i++) fa[i]=i;
			for(int i=1;i<=m;i++)
			{
				if(op[i]=='U') fa[a[i]]=0;
				else fa[a[i]]=find(b[i]);
			}
			for(int i=1;i<=n;i++) if(find(i)==0) ans++;
			cout<<ans<<endl;
			continue;
		}
		if(c==7||c==8)
		{
			ans=0; fa[0]=0;
			for(int i=1;i<=2*n;i++) fa[i]=i;
			for(int i=1;i<=m;i++)
			{
				if(op[i]=='+') merge(a[i],b[i]),merge(a[i]+n,b[i]+n);
				else merge(a[i],b[i]+n),merge(a[i]+n,b[i]);
			}
			for(int i=1;i<=n;i++) if(find(i)==find(i+n)) ans++;
			cout<<ans<<endl;
		}
	}
	return 0;
}
