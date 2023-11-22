#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1e3;

int c,n,m,q,a[N],b[N];

namespace s1{
	int c[N],d[N],pos1[N],pos2[N];
	int k1=0,k2=0;
	void init(){
		for(int i=1;i<=k1;i++) c[pos1[i]]=a[pos1[i]];
		for(int i=1;i<=k2;i++) d[pos2[i]]=b[pos2[i]];
	}
	int dp[2010][2010];
	void solve(){
		for(int i=1;i<=n;i++) c[i]=a[i];
		for(int i=1;i<=m;i++) d[i]=b[i];
		for(int _=0;_<=q;_++){
			if(_>0){
				cin>>k1>>k2;
				for(int i=1,p,x;i<=k1;i++)
					cin>>p>>x,c[p]=x,pos1[i]=p;
				for(int i=1,p,x;i<=k2;i++)
					cin>>p>>x,d[p]=x,pos2[i]=p;	
			}
			if(c[1]==d[1]){
				cout<<0;
				init();continue;
			}
			int op=0;
			if(c[1]>d[1]) op=1;
			else op=-1;
			//printf("_:%d\n",_);
			//for(int i=1;i<=n;i++) printf("%d ",c[i]);puts("");
			//for(int i=1;i<=m;i++) printf("%d ",d[i]);puts("");
			dp[1][1]=1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(i==1&&j==1) continue;
					else if(dp[i][j-1]&&(c[i]-d[j])*op>0) dp[i][j]=1;
					else if(dp[i-1][j]&&(c[i]-d[j])*op>0) dp[i][j]=1;
					else if(dp[i-1][j-1]&&(c[i]-d[j])*op>0) dp[i][j]=1;
					else dp[i][j]=0;
				}
			}
			cout<<dp[n][m];init();
		}
	}
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	if(c<8) s1::solve();
	return 0;
}
/*
3 3 3 3
8 6 9
1 7 4
1 0
3 0
0 2
1 8
3 5
1 1
2 8
1 7
*/
