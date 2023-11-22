#include<bits/stdc++.h>
using namespace std;

template<class T>inline void read(T&x){
	char last=' ',c;
	while(!isdigit(c=getchar()))last=c;
	x=c^48;
	while(isdigit(c=getchar()))x=(x<<3)+(x<<1)+(c^48);
	if(last=='-')x=-x;
}

const int MAXN=5e5+7;
int n,m,q;
int x[MAXN];
int y[MAXN];
int suf[MAXN];
int dp[3007][3007];

char solve(){
	if(x[1]>y[1]&&x[n]>y[m]){
		dp[1][1]=1;
		for(int j=2;j<=m;++j)dp[1][j]=dp[1][j-1]*(x[1]>y[j]);
		for(int i=2;i<=n;++i)dp[i][1]=dp[i-1][1]*(x[i]>y[1]);
		for(int i=2;i<=n;++i){
			for(int j=2;j<=m;++j){
				if((dp[i][j-1]||dp[i-1][j]||dp[i-1][j-1])&&x[i]>y[j])dp[i][j]=1;
				else dp[i][j]=0;
			}
		}
		return dp[n][m]?'1':'0';
	}
	else if(x[1]<y[1]&&x[n]<y[m]){
		dp[1][1]=1;
		for(int j=2;j<=m;++j)dp[1][j]=dp[1][j-1]*(x[1]<y[j]);
		for(int i=2;i<=n;++i)dp[i][1]=dp[i-1][1]*(x[i]<y[1]);
		for(int i=2;i<=n;++i){
			for(int j=2;j<=m;++j){
				if((dp[i][j-1]||dp[i-1][j]||dp[i-1][j-1])&&x[i]<y[j])dp[i][j]=1;
				else dp[i][j]=0;
			}
		}
		return dp[n][m]?'1':'0';
	}
	else return '0';
}

void solve_easy(){
	read(n),read(m),read(q);
	for(int i=1;i<=n;++i)read(x[i]);
	for(int i=1;i<=m;++i)read(y[i]);
	string ans;
	ans+=solve();
	vector<int>px,vx,py,vy;
	for(int kx,ky;q--;){
		read(kx),read(ky);
		vector<int>().swap(px);
		vector<int>().swap(vx);
		vector<int>().swap(py);
		vector<int>().swap(vy);
		for(int i=0,p,v;i<kx;++i){
			read(p),read(v);
			px.push_back(p);
			vx.push_back(v);
			swap(x[px[i]],vx[i]);
		}
		for(int i=0,p,v;i<ky;++i){
			read(p),read(v);
			py.push_back(p);
			vy.push_back(v);
			swap(y[py[i]],vy[i]);
		}
		ans+=solve();
		for(int i=0;i<kx;++i)swap(x[px[i]],vx[i]);
		for(int i=0;i<ky;++i)swap(y[py[i]],vy[i]);
	}
	cout<<ans<<'\n';
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int Id;read(Id);
	if(Id<=7)solve_easy();
	return 0;
}
