#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
const int sN=2005;
int cid,n,m,q;
namespace bf{
	int oa[sN],ob[sN],a[sN],b[sN],ex[sN];
	bool f[sN],g[sN];
	inline void sol(){
		int flag=0;
		if(a[1]<b[1])swap(a,b),swap(n,m),flag=1;
		rep(i,0,m)f[i]=0;
		f[0]=1;
		rep(i,1,n){
			g[0]=0;
			rep(j,1,m){
				g[j]=0;
				if(a[i]>b[j])g[j]=g[j-1]|f[j-1]|f[j];
			}
			swap(f,g);
		}
		cout<<f[m];
		if(flag)swap(n,m);
	}
	inline void solve(){
		rep(i,1,n)cin>>a[i],oa[i]=a[i];
		rep(i,1,m)cin>>b[i],ob[i]=b[i];
		sol();
		rep(i,1,q){
			rep(j,1,n)a[j]=oa[j];
			rep(j,1,m)b[j]=ob[j];
			int k1,k2;
			cin>>k1>>k2;
			rep(j,1,k1){int x,y;cin>>x>>y;a[x]=y;}
			rep(j,1,k2){int x,y;cin>>x>>y;b[x]=y;}
			sol();
		}
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>cid>>n>>m>>q;
	if(max(n,m)<=2000)return bf::solve(),0;
	return 0;
}