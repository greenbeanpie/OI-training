#include<bits/stdc++.h>
using namespace std;
#define cmp(i, j) (flag?x[i]>y[j]:x[i]<y[j])

const int N=500020;
const int Q=120;

int n, m;
int x[N], y[N];
int xx[N], yy[N];
int c, q;
int dp[2020][2020];
bool flag;//true f>g false f<g

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	cin>>c>>n>>m>>q;
	for(int i=1; i<=n; ++i){
		cin>>xx[i];
		x[i]=xx[i];
	}
	for(int i=1; i<=m; ++i){
		cin>>yy[i];
		y[i]=yy[i];
	}
	if((long long)(x[1]-y[1])*(x[n]-y[m])<=0) cout<<"0";
	else{
		if(x[1]>y[1]) flag=true;
		else flag=false;
		if(c<=7){
			memset(dp, false, sizeof dp);
			dp[1][1]=true;
			for(int i=2; i<=m; ++i)
				dp[1][i]=dp[1][i-1]&&cmp(1,i);
			for(int i=2; i<=n; ++i){
				for(int j=1; j<=m; ++j)
					dp[i][j]=cmp(i,j)&&(dp[i-1][j]||dp[i][j-1]||dp[i-1][j-1]);
			}
			if(dp[n][m]) cout<<"1";
			else cout<<"0";
		}
	}
	while(q--){
		int kx,ky;
		cin>>kx>>ky;
		for(int i=1; i<=n; ++i)
			x[i]=xx[i];
		for(int i=1; i<=m; ++i)
			y[i]=yy[i];
		for(int i=1; i<=kx; ++i){
			int p, v;
			cin>>p>>v;
			x[p]=v;
		}
		for(int i=1; i<=ky; ++i){
			int p,v;
			cin>>p>>v;
			y[p]=v;
		}
		if((long long)(x[1]-y[1])*(x[n]-y[m])<=0){
			cout<<"0";
			continue;
		}
		if(x[1]>y[1]) flag=true;
		else flag=false;
		if(c<=7){
			memset(dp, false, sizeof dp);
			dp[1][1]=true;
			for(int i=2; i<=m; ++i)
				dp[1][i]=dp[1][i-1]&&cmp(1,i);
			for(int i=2; i<=n; ++i){
				for(int j=1; j<=m; ++j)
					dp[i][j]=cmp(i,j)&&(dp[i-1][j]||dp[i][j-1]||dp[i-1][j-1]);
			}
			if(dp[n][m]) cout<<"1";
			else cout<<"0";
		}
	}
	
	cout<<endl;
	
	return 0;
}