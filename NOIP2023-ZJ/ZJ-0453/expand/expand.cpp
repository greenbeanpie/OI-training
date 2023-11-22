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
const int M = 3010;
int c,n,m,q;
int n1,m1;
int f[M][M];
int a[M],b[M];
int x[M],y[M],z[M];
int ans=0;
int sum=0;
int tim;
queue<int> s;
void S(){
	memset(f,0,sizeof f);
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(x[i]>y[j]) {
				if(f[i-1][j]||f[i-1][j-1]||f[i][j-1])
					f[i][j]=1;
			}
		}
	if(f[n][m]) ans=1;
}
void solve1(){
	ans=0;
	++tim;
	n=n1,m=m1;
	if(x[1]>y[1]&&x[n]>y[m]) S();
	else if(x[1]<y[1]&&x[n]<y[m]){
		memcpy(z,x,sizeof z);
		memcpy(x,y,sizeof x);
		memcpy(y,z,sizeof y);
		swap(n,m);
		S();
	} else {
		s.push(0);
		return ;
	}
	s.push(ans);
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n1>>m1>>q;
	if(c<=20) {
		for(int i=1;i<=n1;++i) scanf("%d",&a[i]),x[i]=a[i];
		for(int i=1;i<=m1;++i) scanf("%d",&b[i]),y[i]=b[i];
		solve1();
		for(int i=1;i<=q;++i){
			for(int j=1;j<=n1;++j) x[j]=a[j];
			for(int j=1;j<=m1;++j) y[j]=b[j];
			int k1,k2;
			cin>>k1>>k2;
			for(int j=1;j<=k1;++j){
				int u,v;
				scanf("%d%d",&u,&v);
				x[u]=v;
			}
			for(int j=1;j<=k2;++j){
				int u,v;
				scanf("%d%d",&u,&v);
				y[u]=v;
			}
			solve1();
		}
		while(!s.empty()) cout<<s.front(),s.pop();
		return 0;
	}
	return 0;
}
