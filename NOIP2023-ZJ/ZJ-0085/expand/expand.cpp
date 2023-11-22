#include<cstdio>
#include<iostream>
#define ll long long
#define ull unsigned ll
#define Tp template<typename _T>
Tp _T mabs(_T x){ return x<0?-x:x; }
Tp _T mmin(_T x,_T y){ return x<y?x:y; }
Tp _T mmax(_T x,_T y){ return x<y?y:x; }
Tp void mswap(_T &x,_T &y){ _T t=x; x=y; y=t; return; }
using namespace std;
#define maxn 500039
int id,n,m,q,a[maxn],b[maxn];
int f[2039][2039];
void solve(){
	if(a[1]==b[1]){ cout<<'0'; return; }
	if(n>2000||m>2000){
		int i,j,ti,tj;
		i=j=1;
		while(1){
			ti=i,tj=j;
			while(i<n&&j<m&&a[i+1]!=b[j+1]&&(a[i+1]>b[j+1])==(a[1]>b[1])) i++,j++;
			while(i<n&&a[i+1]!=b[j]&&(a[i+1]>b[j])==(a[1]>b[1])) i++;
			while(j<m&&a[i]!=b[j+1]&&(a[i]>b[j+1])==(a[1]>b[1])) j++;
			if(i==n&&j==m){ cout<<'1'; return; }
			if(i==ti&&j==tj){ cout<<'0'; return; }
		} return;
	}
	int i,j; f[0][0]=1;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++)
		if(a[i]!=b[j]&&(a[i]>b[j])==(a[1]>b[1]))
			f[i][j]=(f[i-1][j]|f[i][j-1]|f[i-1][j-1]);
		else f[i][j]=0;
//	for(i=1;i<=n;i++) for(j=1;j<=m;j++) cout<<f[i][j],(j==m)&&(cout<<'\n');
//	cout<<'\n';
//	for(i=1;i<=n;i++) for(j=1;j<=m;j++)
//		if(a[i]!=b[j]&&(a[i]>b[j])==(a[1]>b[1]))
//			cout<<1,(j==m)&&(cout<<'\n');
//		else cout<<0,(j==m)&&(cout<<'\n');
	cout<<f[n][m]; return;
}
int kx,ky,px[maxn],vx[maxn],py[maxn],vy[maxn],val;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin>>id>>n>>m>>q; int i;
	for(i=1;i<=n;i++) cin>>a[i]; for(i=1;i<=m;i++) cin>>b[i];
	solve();
	while(q--){
		cin>>kx>>ky;
		for(i=1;i<=kx;i++) cin>>px[i]>>val,vx[i]=a[px[i]],a[px[i]]=val;
		for(i=1;i<=ky;i++) cin>>py[i]>>val,vy[i]=b[py[i]],b[py[i]]=val;
		solve();
		for(i=kx;i>=1;i--) a[px[i]]=vx[i];
		for(i=ky;i>=1;i--) b[py[i]]=vy[i];
	} cout<<'\n'; return 0;
}
