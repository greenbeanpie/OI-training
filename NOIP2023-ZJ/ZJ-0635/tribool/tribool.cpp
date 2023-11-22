#include <bits/stdc++.h>//60
using namespace std;
const int N=1e5+5;
const int T=1e5+1;
const int U=1e5+2;
int fa[N];
int p[N];
bool a[N];
int c,t,n,m,cnt;
int ans;
char v;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch<='9'&&ch>='0') { x=(x<<3)+(x<<1)+ch-48; ch=getchar(); }
	return x*f;
}
int find(int x)
{
	if(a[x]) return x;
	a[x]=true;
	p[++cnt]=x;
	if(fa[x]!=x&&fa[x]!=-x&&fa[x]<T&&fa[x]>-T)
	{
		if(fa[x]>0) fa[x]=find(fa[x]);
		else fa[x]=-find(-fa[x]);
	}
	return fa[x];
}
void init() { for(int i=1;i<=cnt;i++) a[p[i]]=false;}
void init_() { for(int i=1;i<=n;i++) fa[i]=i; ans=0;}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();t=read();
	while(t--)
	{
		n=read();m=read();
		init_();
		while(m--)
		{
			scanf("%c",&v);
			if(v>='A'&&v<='Z')
			{
				int i=read();
				if(v=='T') fa[i]=T;
				if(v=='F') fa[i]=-T;
				if(v=='U') fa[i]=U;
			}
			else
			{
				int i=read(),j=read();
				if(v=='+') fa[i]=j;
				else fa[i]=-j;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cnt=0;
			int b=find(i);
			init();
			if(b==-i) fa[i]=U;
		}
		for(int i=1;i<=n;i++)
		{
			cnt=0;
			int b=find(i);
			init();
			if(b==U||b==-U) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
