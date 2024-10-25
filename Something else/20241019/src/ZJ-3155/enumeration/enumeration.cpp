#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define int long long
using namespace std;
const int N=1e5+10,INF=1e5;
struct BIT
{
	int n,c[N];BIT(){memset(c,0,sizeof c);}
	void clear(int x){for(;x<=n;x+=x&-x) c[x]=0;}
	void modify(int x,int w){for(;x<=n;x+=x&-x) c[x]+=w;}
	int query(int x){int res=0;for(;x;x-=x&-x) res+=c[x];return res;}
	int qry(int l,int r){return query(r)-query(l-1);}
}tt;
int x,y,n,ans;
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
signed main()
{
	freopen("enumeration.in","r",stdin);
	freopen("enumeration.out","w",stdout);
	x=read(),y=read(),tt.n=n=read();
	for(int i=1;i<=n;i++) tt.modify((x*x+1)%i+1,1);
	for(int i=y+1;i<=n;i++) for(int w=y;w<=(n<<1);w+=i)
		ans+=tt.qry(max(w-n+1,1ll),min(w+1,n));
	print(ans);put('\n');ans=min(ans,INF);
	for(int a=1;a<=n;a++)
	{
		int w=(x*x+1)%a;
		if(y-w>=0)
		{
			for(int c=y+1;c<=n;c++)
			{
				print(a),put(' '),print(y-w),put(' '),print(c),put('\n');
				if(!--ans) goto genshin;
			}
		}
		for(int b=max(0ll,2*y+1-w);b<=n;b++)
		{
			int k=w+b-y,lim=sqrt(k);vector<int>e;
			for(int c=1;c<=min(n,lim);c++)
				if(k%c==0)
				{
					if(k/c!=c&&k/c>y&&k/c<=n) e.emplace_back(k/c);
					if(c<=y) continue;
					print(a),put(' '),print(b),put(' '),print(c),put('\n');
					if(!--ans) goto genshin;
				}reverse(e.begin(),e.end());
			for(auto c:e)
			{
				print(a),put(' '),print(b),put(' '),print(c),put('\n');
				if(!--ans) goto genshin;
			}
		}
	}
	genshin:;flush();return 0;
}
