#include<bits/stdc++.h>
using namespace std; constexpr int maxn(1e5+10);
int n,m,ans,ori[maxn];
struct operation{ char op; int x,y; }op[maxn];
inline void solve(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) ori[i]=1;
	for(int i=1;i<=m;i++){
		cin >> op[i].op >> op[i].x;
		if(op[i].op=='U') ori[op[i].x]=0;
		else cin >> op[i].y,ori[op[i].x]=ori[op[i].y];
	}
	for(int t=1;t<=500;t++){
		for(int i=1;i<=m;i++){
			char op=::op[i].op; int x=::op[i].x,y=::op[i].y;
			assert(op=='U'||op=='+');
			if(op=='U') ori[x]=0;
			else ori[x]=ori[y];
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)
		if(!ori[i]) res++;
	cout << res << '\n';
}
signed main(){ freopen("tribool.in","r",stdin),freopen("brute.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	int winc,T; cin >> winc >> T; while(T--) solve();
	return 0;
}
/*
6 1
5 5
+ 3 1
U 1
U 2
U 1
+ 5 4
*/
