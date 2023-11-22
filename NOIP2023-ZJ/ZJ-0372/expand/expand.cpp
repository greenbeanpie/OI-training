#include <bits/stdc++.h>
#define MAXN 2009
#define MAXB 21
#define rep(i,s,t) for(int i=(s);i<=(t);i++)
#define dep(i,s,t) for(int i=(s);i>=(t);i--)
using namespace std;
int n,m,q;
int a[MAXN],b[MAXN],A[MAXN],B[MAXN];
struct SGT {
	int st[MAXN][MAXB];
	int lg2[MAXN];
	void init() {
		rep(i,1,n) {
			st[i][0]=b[i];
			
		}
	}
};
inline int getpre(int L,int R,int v) { // last place in [L,R] that < v
	assert(b[L]<v);
	dep(i,R,L) if(B[i]<v) return i;
}
int dp[MAXN][MAXN];
bool getans() {
//	cout<<endl;
//	cout<<"RER"<<endl;
	if(a[1]<b[1])
		swap(a,b);
	if(a[n]<=b[m]||a[1]==b[1]) return 0;
//	rep(i,1,n) cout<<a[i]<<" ";
//	cout<<endl;
//	rep(i,1,m) cout<<b[i]<<" ";
//	cout<<endl;
	dp[0][1]=1;
	rep(i,1,n) {
		if(a[i]>b[1]&&dp[i-1][1])
			dp[i][1]=1;
		else dp[i][1]=0;
		rep(j,1,m) {
			if(j>=2) {
			
			if(a[i]>b[j])
				dp[i][j]=(dp[i-1][j]||dp[i-1][j-1]||dp[i][j-1]);
			else dp[i][j]=0;
			}
//			cout<<"dp "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}

	}
	return dp[n][m];
}
int main () {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int C;
	cin>>C>>n>>m>>q;
	rep(i,1,n) cin>>A[i];
	rep(i,1,m) cin>>B[i];
	rep(i,1,n) a[i]=A[i],b[i]=B[i];
	cout<<getans();
	rep(t,1,q) {
		int kx,ky,p,v;
		cin>>kx>>ky;
		rep(i,1,n) a[i]=A[i],b[i]=B[i];
		rep(i,1,kx) {
			cin>>p>>v;
			a[p]=v;
		}
		rep(i,1,ky) {
			cin>>p>>v;
			b[p]=v;
		}

		cout<<getans();
	}
	return 0;
}
