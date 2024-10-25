#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+2e5;
namespace IO{
	const int sz=1<<22;
	char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
	inline char gc(){
//		return getchar();
		return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++):*p1++;
	}
	template<class T> void gi(T& x){
		x=0; char c=gc();
		for(;c<'0'||c>'9';c=gc());
		for(;c>='0'&&c<='9';c=gc())
			x=x*10+(c-'0');
	}
	inline void flush(){fwrite(b,1,t-b,stdout),t=b; }
	inline void pc(char x){*t++=x; if(t-b==sz) flush(); }
	template<class T> void pi(T x,char c='\n'){
		if(x==0) pc('0'); int t=0;
		if(x<0) pc('-'),x=-x;
		for(;x;x/=10) p[++t]=x%10+'0';
		for(;t;--t) pc(p[t]); pc(c);
	}
	struct F{~F(){flush();}}f;
}
using IO::gi;
using IO::pi;
vector<int> h[N];
int nxt[N];
ll sum[N];
int main(){
    freopen("enumeration.in", "r", stdin);
    freopen("enumeration.out", "w", stdout);	
	int T=1;
	while(T--){
		int n,n3,p; scanf("%d%d%d",&n,&n3,&p);
		for(int i=0;i<=p+p;++i) h[i].clear();
		memset(sum,0,sizeof(ll)*(p+p+1));
		vector<vector<int> > f;
		for(int c=n3+1;c<=p;++c)
			for(int k=0;n3+c*k<=p+p;++k){
				sum[n3+c*k]++;
				h[n3+c*k].push_back(c);
			}
		nxt[p+p+1]=1e9; sum[p+p+1]=0;
		for(int i=p+p;i>=0;--i){
			sum[i]+=sum[i+1];
			if(h[i].empty()) nxt[i]=nxt[i+1];
			else nxt[i]=i;
		}
		long long ans=0;
		for(int a=1;a<=p;++a){
			int n1=(1ll*n*n+1)%a;
			ans+=sum[n1]-sum[n1+p+1];
			for(int n2=nxt[n1];n2<=n1+p;n2=nxt[n2+1]){
				if(f.size()==(int)1e5) break;
				for(int j=0;j<h[n2].size();++j){
					f.push_back({a,n2-n1,h[n2][j]});
					if(f.size()==(int)1e5) break;
				}
			}
		}
		pi(ans);
		for(auto x:f){
			pi(x[0],' '),pi(x[1],' '),pi(x[2],'\n');
		}
	}
	return 0;
	
}
