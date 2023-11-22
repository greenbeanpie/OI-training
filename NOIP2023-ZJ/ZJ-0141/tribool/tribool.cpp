#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 1e5+5;
inline int read() {
	int x;
	scanf("%d",&x);
	return x;
}
int n, m,OP;
int dy[131];
struct opera {
	int opt,x,y;
} op[N];
namespace point1 {
	const int N2 = 15;
	int a[N2],b[N2],ans;

	inline void js() {
		for(int i=1; i<=n; ++i) a[i]=b[i];
		int tot=0;
		for(int i=1; i<=n; ++i) tot+=a[i]==1;
		for(int j=1; j<=m; ++j) {
			int opt=op[j].opt,x=op[j].x,y=op[j].y;
			if(opt==0) a[x]=y;
			if(opt==1) a[x]=a[y];
			if(opt==2) a[x]=2-a[y];
		}
		bool flag=1;
		for(int i=1; i<=n; ++i) flag&=a[i]==b[i];
		if(flag) ans=min(ans,tot);
	}

	inline void dfs(int now) {
		if(now==n+1) return js();
		for(int i=0; i<3; ++i) b[now]=i,dfs(now+1);
	}

	inline void solve() {
		ans=n;
		dfs(1);
		cout<<ans<<"\n";
	}
}

namespace point2 {
	int a[N];
	inline void solve() {
		memset(a,-1,sizeof a);
		for(int i=1; i<=m; ++i) {
			int opt=op[i].opt,x=op[i].x,y=op[i].y;
			a[x]=y;
		}
		int tot=0;
		for(int i=1; i<=n; ++i) tot+=a[i]==1;
		cout<<tot<<"\n";
	}
}

inline void solve() {
	n=read(),m=read();
	for(int i=1; i<=m; ++i) {
		char c;
		cin>>c;
		if(c=='-') op[i]=<%2,read(),read()%>;
		else if(c=='+') op[i]=<%1,read(),read()%>;
		else op[i]=<%0,read(),dy[c]%>;
	}
	if(OP<=2) return point1 :: solve();
	if(OP<=4) return point2 :: solve();
	 
}
signed main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	dy['T']=0,dy['F']=2,dy['U']=1;
	int x=OP=read(),T=read();
	while(T--) solve();
	return 0;
}
