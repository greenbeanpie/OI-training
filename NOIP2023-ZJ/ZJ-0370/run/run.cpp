#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=100005;
int qwq,T,dp[2003][2003];
int n,m,k,d,inf,ans,b[N];
struct qwqq{
	int x,y,w;
}c[N];
bool cmp(qwqq xa,qwqq xb) {
	if (xa.x==xb.x) return xa.y<xb.y;
	return xa.x<xb.x;
}

signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>qwq>>T;
	inf=1e9+7; inf*=inf;
	if (qwq==17||qwq==18) {
		while (T--) {
			cin>>n>>m>>k>>d;
			for (int i=1;i<=m;i++) cin>>c[i].x>>c[i].y>>c[i].w;
			sort(c+1,c+m+1,cmp);
			ans=0;
			for (int i=1;i<=m;i++) {
				int l=c[i].x-c[i].y+1,r=c[i].x;
				if (l<=0) continue;
				if (r-l+1>k) continue;
				if (c[i].w>d*(r-l+1)) ans=ans+c[i].w-d*(r-l+1); 
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	else {
		while (T--) {
			cin>>n>>m>>k>>d;
			for (int i=1;i<=m;i++) cin>>c[i].x>>c[i].y>>c[i].w;
			sort(c+1,c+m+1,cmp);
			for (int i=1;i<=n;i++) 
				for (int j=0;j<=k;j++) dp[i][j]=-inf;
			dp[0][0]=dp[1][0]=0;
			int p=1;
			for (int i=1;i<=n;i++) {
		//			cout<<"i="<<i<<endl;
				for (int j=0;j<=k;j++) dp[i][0]=max(dp[i][0],dp[i-1][j]);
				for (int j=0;j<=k;j++) b[j]=0;
				while (p<=m&&c[p].x==i) { //c[p].y-k:+c[p].w
					if (c[p].y<=k) {
						b[c[p].y]+=c[p].w;
					}
					p++;
				}
				for (int j=1;j<=k;j++) b[j]+=b[j-1];
		//			cout<<"b:";for (int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
				for (int j=1;j<=k;j++) {
					dp[i][j]=max(dp[i-1][j-1]-d+b[j],dp[i][j]);
				}
			}
			ans=0;
			for (int i=0;i<=k;i++) ans=max(ans,dp[n][i]);
			cout<<ans<<'\n';
		}
		return 0;
	}
	
	
	
	return 0;
}

/*

5 1
6 3 3 2
4 3 10
5 2 9
4 3 1

5











#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=100005;
int qwq,T,dp[5][N];
int n,m,k,d,inf,ans,b[N];
struct qwqq{
	int x,y,w;
}c[N];
bool cmp(qwqq xa,qwqq xb) {
	if (xa.x==xb.x) return xa.y<xb.y;
	return xa.x<xb.x;
}

signed main(){
//	freopen("run.in","r",stdin);
//	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>qwq>>T;
	inf=1e9+7; inf*=inf;
	if (qwq==17||qwq==18) {
		while (T--) {
			cin>>n>>m>>k>>d;
			for (int i=1;i<=m;i++) cin>>c[i].x>>c[i].y>>c[i].w;
			sort(c+1,c+m+1,cmp);
			ans=0;
			for (int i=1;i<=m;i++) {
				int l=c[i].x-c[i].y+1,r=c[i].x;
				if (l<=0) continue;
				if (r-l+1>k) continue;
				if (c[i].w>d*(r-l+1)) ans=ans+c[i].w-d*(r-l+1); 
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	else {
		while (T--) {
			cin>>n>>m>>k>>d;
			for (int i=1;i<=m;i++) cin>>c[i].x>>c[i].y>>c[i].w;
			sort(c+1,c+m+1,cmp);
			for (int i=0;i<=1;i++) 
				for (int j=0;j<=k;j++) dp[i][j]=-inf;
			for (int j=0;j<=k;j++) dp[0][j]=0;
			dp[0][0]=dp[1][0]=0;
			int p=1;
			for (int i=1;i<=n;i++) {
				for (int j=0;j<=k;j++) dp[i&1][j]=-inf;
				if (i==1) dp[1][0]=0;
		//			cout<<"i="<<i<<endl;
				for (int j=0;j<=k;j++) dp[i&1][0]=max(dp[i&1][0],dp[(i+1)&1][j]);
				for (int j=0;j<=k;j++) b[j]=0;
				while (p<=m&&c[p].x==i) { //c[p].y-k:+c[p].w
					if (c[p].y<=k) {
						b[c[p].y]+=c[p].w;
					}
					p++;
				}
				for (int j=1;j<=k;j++) b[j]+=b[j-1];
		//			cout<<"b:";for (int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
				for (int j=1;j<=k;j++) {
					dp[i&1][j]=max(dp[(i+1)&1][j-1]-d+b[j],dp[i&1][j]);
				}
			}
			ans=0;
			for (int i=0;i<=k;i++) ans=max(ans,dp[n&1][i]);
			cout<<ans<<'\n';
		}
		return 0;
	}
	
	
	
	return 0;
}


*/
