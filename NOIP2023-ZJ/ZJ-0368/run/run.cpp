#include<bits/stdc++.h>
using namespace std;
#define fq(i,l,r) for(int i=(l);i<=(r);i++)
#define ffq(i,r,l) for(int i=(r);i>=(l);i--)
#define int long long
const int N=2e5+10,inf=1e17+9;
int c,T,n,m,k,d,x,y,v;
struct A{int x,y,v;} a[N];
namespace B{
	void solve(){
		int ans=0;
		fq(i,1,m) 
		if(a[i].y<=k&&a[i].y*d<=a[i].v&&a[i].x-a[i].y>=0) 
		ans+=a[i].v-a[i].y*d;
		printf("%lld\n",ans);
	}
}
namespace bl{
	int f[3002][3002],mx[3002];
	vector<int> vis[3002];
	void solve(){
		f[0][0]=0;
		fq(i,1,n){
			fq(j,0,k) f[i][j]=-inf;
			mx[i]=-inf;
		}mx[0]=0;
		fq(i,0,n) vis[i].clear();
		fq(i,1,m) vis[a[i].x].push_back(i);
		fq(i,1,n){
			fq(j,0,k) if(i>=j){
				for(int u:vis[i]){
					if(j>=a[u].y)
					f[i][j]=max(f[i][j],
					f[i-a[u].y][j-a[u].y]+a[u].v-a[u].y*d);
				}
				if(j>=1) f[i][j]=max(f[i-1][j-1]-d,f[i][j]);
				else f[i][j]=max(f[i][j],mx[i-1]);
				mx[i]=max(mx[i],f[i][j]);
			}
		}
//		fq(i,1,n) fq(j,0,k) cout<<i<<"-"<<j<<":"<<f[i][j]<<endl;
		printf("%lld\n",mx[n]);
	}
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);	
	cin>>c>>T;
	while(T--){
		cin>>n>>m>>k>>d;
		fq(i,1,m) scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].v);
		if(c==18||c==17) B::solve(); 
		else bl::solve();   
	}
		
}