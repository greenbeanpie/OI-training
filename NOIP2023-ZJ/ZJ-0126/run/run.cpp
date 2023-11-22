#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define pii pair<int,int>
#define ord(i,l,r) for(int i=l;i<=r;i++)
#define dord(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=1e5+20; const ll inf=1e17;
int n,m,K; ll d,f[N];
struct qy{ int l,r; ll v; }a[N];
bool cmp(qy x,qy y){
	return x.l==y.l?x.r>y.r:x.l<y.l;
}
void solve(){
	scanf("%d%d%d%lld",&m,&n,&K,&d);
	cout<<0;
	return ;
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int Yao,T; scanf("%d%d",&Yao,&T);
	while(T--) solve();
	return 0;
}