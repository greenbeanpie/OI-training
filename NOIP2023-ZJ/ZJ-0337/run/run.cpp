#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
#define endl "\n"
#define mem(a,b) memset((a),0,sizeof(a))
using namespace std;
const int M=1e5+5;
const ll inf=1e18;
int c,T,n,m,k,cnt=1;
ll d;
struct node{
	int x,y;
	ll z;
}q[M];
ll dp[2][M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cnt=1;
		cin>>n>>m>>k>>d;
		FOR(i,1,m) cin>>q[i].x>>q[i].y>>q[i].z;
		q[m+1].x=-1;
		sort(q+1,q+m+1,[](node x,node y){return x.x<y.x;});
		int w=1;
		FOR(i,0,k+1) dp[1][i]=dp[0][i]=0;
		dp[w][0]=0;
		FOR(i,1,n){
			w^=1;
			dp[w][k+1]=0;
			FOR(j,0,min(i,k)){
				dp[w][j]=-inf;
				if(j==0){
					dp[w][j]=max(dp[w][j],dp[w^1][k+1]);
					dp[w][k+1]=max(dp[w][k+1],dp[w][j]);
//					cout<<i<<" "<<j<<" "<<dp[w][j]<<endl;
					continue;
				}
				dp[w][j]=dp[w^1][j-1]-d;
				int qwq=cnt;
//				cout<<"qwq "<<q[cnt].x<<" "<<i<<" "<<q[cnt].y<<" "<<j<<endl;
				while(q[cnt].x==i){
					if(q[cnt].y<=j) dp[w][j]+=q[cnt].z;
					cnt++;
				}
				if(j!=min(i,k)) cnt=qwq;
				dp[w][k+1]=max(dp[w][k+1],dp[w][j]);
//				cout<<i<<" "<<j<<" "<<dp[w][j]<<endl;
			}
		}
		cout<<dp[w][k+1]<<endl;
	}
	return (0-0);
}

