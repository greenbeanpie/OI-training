#include<bits/stdc++.h>
#define LL long long
#define push_back pb
#define mk make_pair
#define debug cout<<"------------------------\n";
#define fi first
#define se second
#define ls s*2
#define rs s*2+1
#define mid (l+r)/2
#define tol ls,l,mid
#define tor rs,mid+1,r
using namespace std;
const int M=1010;
int c,t;
int n,m,k;
LL d;
LL g[M][M];
LL f[M][M];
void solve1(){
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	for(int i=1;i<=m;++i){
		int x,y;
		LL v;
		scanf("%d%d%lld",&x,&y,&v);
		if(y<=k) g[x][y]+=v;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=k;++j)
			g[i][j]+=g[i][j-1];
	for(int i=1;i<=n;++i){
		for(int j=0;j<=min(i-1,k);++j)
			f[i][0]=max(f[i][0],f[i-1][j]);
		for(int j=1;j<=min(i,k);++j){
			f[i][j]=f[i-1][j-1]-d+g[i][j];
		}
	}
	LL ans=0;
	for(int i=0;i<=k;++i)
		ans=max(ans,f[n][i]);
	cout<<ans<<endl;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		if(c<=25) solve1();
	}
	return 0;
}
