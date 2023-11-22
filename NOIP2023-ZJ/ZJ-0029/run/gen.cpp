#include<bits/stdc++.h>
#define Gc() getchar()
#define fi first
#define se second
#define LB lower_bound
#define UB upper_bound
#define Me(x,y) memset(x,y,sizeof x)
#define Mc(x,y) memcpy(x,y,sizeof x)
#define R(n) (rnd()%(n)+1)
using namespace std;using ll=long long;using LL=__int128;
const int N=2e5+5,M=N*4+5,K=1e7+5;const ll INF=4e18;mt19937 rnd(time(0));
int main(){
	freopen("run.in","w",stdout);
	int c=0,t=10,W=1e9;printf("%d %d\n",c,t);
	while(t--){
		int n=R(W),m=R(100000),k=R(n),d=R(1ll*W*m/n);
		printf("%d %d %d %d\n",n,m,k,d);
		for(int i=1;i<=m;i++) {
			int l=R(n),r=R(n);if(l>r) swap(l,r);
			printf("%d %d %d\n",r,r-l+1,R(W));
		}
	}
}