#include <bits/stdc++.h>
#define int long long
#define F(a,b,c) for(int a=b ; a<=c ; a++)
#define open(A) { freopen(#A".in" , "r" , stdin); freopen(#A".out" , "w" , stdout); }
using namespace std;


const int LXB=2e6+5;
const int lxb=3e3+5;
const int mod=998244353;
const int INF=mod+114514;







int n,m,k,d;
int a[LXB] , b[LXB] , c[LXB];
int p[lxb][lxb][2];
int f[LXB][30];

struct day
{
	int a,b,c;
	bool operator < (const day k){
		return a<k.a;
	}
}dz[LXB];

void solve()
{
	cin>>n>>m>>k>>d;
	int md=0;
	int ans=0;
	F(i,1,m) {
		cin>>dz[i].a>>dz[i].b>>dz[i].c;
		if(dz[i].b>k) dz[i].c=0;
		md = max(md,dz[i].b);
	}
	sort(dz+1 , dz+1+m);
	int p=1;
	memset(f,sizeof(f),0);
	F(i,1,n){
		while(i==dz[p].a){
		 	for(int j=min(i,k);j>=dz[p].b;j--) f[i][j] = max(f[i-dz[p].b][j-dz[p].b]-dz[p].b*d+dz[p].c , f[i][j]) , ans=max(ans,f[i][j]);
		 	p++;
		}
	}
	cout<<ans<<endl;
}



signed main()
{
	int T=1,c;
	open(run);
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
}
