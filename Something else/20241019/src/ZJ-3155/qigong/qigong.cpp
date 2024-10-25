#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define int long long
using namespace std;
const int N=1e5+10,INF=1.1e18;
int n,k,tot,a[N],mp[N];pair<int,int>b[N];
namespace Fast_IO
{
	static char buf[1000000],*paa=buf,*pd=buf,out[10000000];int length=0;
	#define getchar() paa==pd&&(pd=(paa=buf)+fread(buf,1,1000000,stdin),paa==pd)?EOF:*paa++
	inline int read()
	{
		int x(0),t(1);char fc(getchar());
		while(!isdigit(fc)){if(fc=='-') t=-1;fc=getchar();}
		while(isdigit(fc)) x=(x<<1)+(x<<3)+(fc^48),fc=getchar();
		return x*t;
	}
	inline void flush(){fwrite(out,1,length,stdout);length=0;}
	inline void put(char c){if(length==9999999) flush();out[length++]=c;}
	inline void put(string s){for(char c:s) put(c);}
	inline void print(int x)
	{
		if(x<0) put('-'),x=-x;
		if(x>9) print(x/10);
		put(x%10+'0');
	}
	inline bool chk(char c) { return !(c>='a'&&c<='z'||c>='A'&&c<='Z'||c>='0'&&c<='9'); }
	inline bool ck(char c) { return c!='\n'&&c!='\r'&&c!=-1&&c!=' '; }
	inline void rd(char s[],int&n)
	{
		s[++n]=getchar();
		while(chk(s[n])) s[n]=getchar();
		while(ck(s[n])) s[++n]=getchar();
		n--;
	}
}
using namespace Fast_IO;
inline int calc(int i)
{
	int x=0,s=0;
	for(int j=1;j<=i;j++)
	{
		if(mp[j]){x+=a[j]/2,s+=a[j];continue;}
		if(x>=a[j]) x/=2;
		else s+=a[j]-x,x=a[j]/2;
	}return s;
}
inline int dfs(int u,int ed)
{
	if(u==ed+1) return calc(ed);
	int res=dfs(u+1,ed);mp[u]=1;res=min(res,dfs(u+1,ed));
	mp[u]=0;return res;
}
signed main()
{
//	system("fc qigong.out ex_qigong1.out");
	freopen("qigong.in","r",stdin);
	freopen("qigong.out","w",stdout);
	n=read();for(int i=1;i<=n;i++) a[i]=read();
	if(n<=10)
	{
		for(int i=1;i<=n;i++) print(dfs(1,i)),put(' ');
		goto genshin;
	}
	for(int i=1;i<=n;i++)
	{
		tot=0;int x=0,ans=0,s=0,lst=i;
		while(a[lst]<=a[lst-1]/2&&lst>=1) lst--;
		for(int j=1;j<=lst;j++) b[++tot]={a[j],j};
		sort(b+1,b+1+tot);
		for(int j=1;j<=i;j++)
			if(x>=a[j]) x/=2;
			else s+=a[j]-x,x=a[j]/2;
		ans=s;
		for(int k=1;k<=tot;k++)
		{
			mp[b[k].second]=1;s=x=0;
			for(int j=1;j<=i;j++)
			{
				if(mp[j]){x+=a[j]/2,s+=a[j];continue;}
				if(x>=a[j]) x/=2;
				else s+=a[j]-x,x=a[j]/2;
			}int mx=0;
			for(int j=1;j<=i;j++) mx=max(mx/2,a[j]);
			mx/=2;if(mx<x) mp[b[k].second]=0;ans=min(ans,s);
		}for(int j=1;j<=i;j++) mp[j]=0;
		print(ans);put(' ');
	}
	genshin:;flush();return 0;
}
