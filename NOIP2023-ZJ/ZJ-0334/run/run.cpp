#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1003;
const int M=100005;
const ll mi=-10000000000000005;
ll t,c,n,m,k,d,f[N][N];
struct node{
	ll x,y,v;
}a[M];
bool cmp(node x,node y){
	if(x.x!=y.x)return x.x<y.x;
	return x.y<y.y;
}
void solve(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
	for(int i=0;i<=n;i++)for(int j=0;j<=k;j++)f[i][j]=mi;
	f[0][0]=0;
	for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].v);
	sort(a+1,a+1+m,cmp);
	ll p=1,ma=0;
	for(int i=1;i<=n;i++){
		f[i][0]=ma;
		for(int j=1;j<=k;j++){
			f[i][j]=f[i-1][j-1]-d;
		}
		ll sum=0;
		for(int j=1;j<=k;j++){
			while(p<=m&&a[p].x==i&&a[p].y<=j){
				sum+=a[p].v; p++;
			}
			f[i][j]+=sum;
		}
		ma=mi;
		for(int j=0;j<=k;j++)ma=max(ma,f[i][j]);
	}
	printf("%lld\n",ma);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%lld%lld",&t,&c);
	while(c--)solve();
	return 0;
}