#include<bits/stdc++.h>
#define For(i,l,r) for(int i=l,i##end=r;i<=i##end;++i)
#define rFor(i,r,l) for(int i=r,i##end=l;i>=i##end;--i)
#define all(a) a.begin(),a.end()
using namespace std;
using ll=long long;
using pii=array<int,2>;
const int N=3e3+10;
int n; string s[N];
int ans[N];
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int m; cin>>n>>m;
	//cerr<<n<<" "<<m<<endl;
	For(i,1,n) cin>>s[i],sort(all(s[i]),greater<>());
	//For(i,1,n) cerr<<s[i]<<endl; cerr<<endl; return 0;
	For(i,1,n) ans[i]=1;
	string f=s[1];
	For(i,2,n) {
		string b=s[i];
		reverse(all(b));
		//cerr<<b<<" "<<f<<endl;
		ans[i]&=b<f;
		f=min(f,s[i]);
	}
	f=s[n];
	rFor(i,n-1,1) {
		string b=s[i];
		reverse(all(b));
		ans[i]&=b<f;
		f=min(f,s[i]);
	}
	For(i,1,n) cout<<ans[i];
}