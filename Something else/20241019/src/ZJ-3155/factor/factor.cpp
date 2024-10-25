#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define int long long
using namespace std;
const int N=1e5+10,INF=1.1e18;
struct BIT
{
	int n,c[N];BIT(){memset(c,0,sizeof c);}
	void clear(int x){for(;x<=n;x+=x&-x) c[x]=0;}
	void modify(int x,int w){for(;x<=n;x+=x&-x) c[x]=max(c[x],w);}
	int query(int x){int res=0;for(;x;x-=x&-x) res=max(res,c[x]);return res;}
}tt;
struct node{int a,b,c,w;}a[N];
int n;
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
inline bool cmp1(node x,node y){return x.a<y.a;}
inline bool cmp2(node x,node y){return x.b<y.b;}
inline void cdq(int l,int r)
{
	if(l==r) return;cdq(l,mid);
	sort(a+l,a+1+mid,cmp2);
	sort(a+mid+1,a+r+1,cmp2);int j=l;
	for(int i=mid+1;i<=r;i++)
	{
		while(a[j].b<a[i].b&&j<=mid) tt.modify(a[j].c,a[j].w),j++;
		a[i].w=max(a[i].w,tt.query(a[i].c)+1);
	}for(int i=l;i<j;i++) tt.clear(a[i].c);
	sort(a+l,a+1+mid,cmp1);sort(a+mid+1,a+r+1,cmp1);cdq(mid+1,r);
}
signed main()
{
	freopen("factor.in","r",stdin);
	freopen("factor.out","w",stdout);
	tt.n=n=read();for(int i=1;i<=n;i++) a[i].a=i,a[i].b=read();
	for(int i=1;i<=n;i++) a[i].c=read(),a[i].w=1;cdq(1,n);int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,a[i].w);print(ans);
	genshin:;flush();return 0;
}
