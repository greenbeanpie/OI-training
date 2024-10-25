#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define int long long
using namespace std;
const int N=1e5+10,INF=1.1e18;
int n,k,a[N],b[N],c[N];
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
inline int calc(int x)
{
	int res=0;
	for(int i=1,w;i<=n;i++)
	{
		w=x-a[i];if(w<=0) continue;w/=b[i];
		res+=upper_bound(c+1,c+1+n,w)-c-1;
	}return res;
} 
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	n=read();for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<=n;i++) c[i]=read();
	sort(c+1,c+1+n);int l=0,r=INF,res=0;k=read();
	while(l<=r)
		if(calc(mid)>=k) res=mid,r=mid-1;
		else l=mid+1;print(res);
	genshin:;flush();return 0;
}
