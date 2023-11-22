#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll _=2005;
void Max(ll &x,ll y){if(y>x)x=y;}
ll ID,N,n,m,k,t,x,y,z,a[_][_],d[_],i,j;
inline ll p(ll x,ll y){--x;return a[y][y]-a[x][y]-a[y][x]+a[x][x];}
void P(){
	cin>>n>>m>>k>>t;
	for(i=0;i<_;i++)for(j=0;j<_;j++)a[i][j]=0;
	while(m--)cin>>x>>y>>z,a[x-y+1][x]+=z;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	d[0]=0;
	for(i=1;i<=n;i++){
		d[i]=d[i-1];
		for(j=max(1ll,i-k+1);j<=i;j++){
			Max(d[i],p(j,i)-(i-j+1)*t+(j>1?d[j-2]:0));
		}
	}
	cout<<d[n]<<'\n';
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>ID>>N;while(N--)P();
}