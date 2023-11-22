#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define foR(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=3e3+5;
int n,m,ans[N];
char cc[N];
string c;
string cmx[N],cmn[N];
inline bool check(int x) {
	For(i,1,n) {
		if(x==i) continue;
		if(cmn[x]>=cmx[i]) return false;
	}
	return true;
}
signed main() {
	//bf
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	For(i,1,n) {
		cin>>c;
		sort(c.begin(),c.end());
		cmn[i]=c;
		sort(c.begin(),c.end(),greater<char>());
		cmx[i]=c;
	}	
	For(i,1,n) ans[i]=check(i);	
	For(i,1,n) printf("%lld",ans[i]);
	return 0;
}
