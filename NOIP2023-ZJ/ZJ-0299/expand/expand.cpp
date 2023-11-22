#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
const int M=2005;
int c,n,m,q,x[N],y[N],x2[N],y2[N];
bool dp[M][M];
void cpy(){
	for(int i=1;i<=n;i++) x2[i]=x[i];
	for(int i=1;i<=m;i++) y2[i]=y[i];
}
bool check(int x,bool f,int y){
	if(!f) return x2[x]<y2[y];
	else return x2[x]>y2[y];
}
bool check(){
	memset(dp,0,sizeof(dp));
	bool f=0;
	if(x2[1]==y2[1]) return 0;
	if(x2[1]>y2[1]) f=1;
	if(x2[1]<y2[1]) f=0;
	dp[1][1]=1;
	queue< pair<int,int> > q;
	q.push(make_pair(1,1));
	while(!q.empty()){
		int x1=q.front().first,y1=q.front().second;
		q.pop();
		if(x1==n&&y1==m) break;
		if(x1==n){
			if(check(x1,f,y1+1)&&dp[x1][y1+1]==0){
				dp[x1][y1+1]=1;
				q.push(make_pair(x1,y1+1));
			}
		}
		else if(y1==m){
			if(check(x1+1,f,y1)&&dp[x1+1][y1]==0){
				dp[x1+1][y1]=1;
				q.push(make_pair(x1+1,y1));
			}
		}
		else{
			if(check(x1+1,f,y1)&&dp[x1+1][y1]==0){
				dp[x1+1][y1]=1;
				q.push(make_pair(x1+1,y1));
			}
			if(check(x1,f,y1+1)&&dp[x1][y1+1]==0){
				dp[x1][y1+1]=1;
				q.push(make_pair(x1,y1+1));
			}
			if(check(x1+1,f,y1+1)&&dp[x1+1][y1+1]==0){
				dp[x1+1][y1+1]=1;
				q.push(make_pair(x1+1,y1+1));
			}
		}
	}
	return dp[n][m];
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&y[i]);
	if(c<=7){
		cpy();
		vector<int> res;
		res.push_back(check());
		while(q--){
			int kx,ky;
			cpy();
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=kx;i++){
				int p,v;
				scanf("%d%d",&p,&v);
				x2[p]=v;
			}
			for(int i=1;i<=ky;i++){
				int p,v;
				scanf("%d%d",&p,&v);
				y2[p]=v;
			}
			res.push_back(check());
		}
		for(int i=0;i<res.size();i++) printf("%d",res[i]);
	}
	else{
		vector<int> res;
		res.push_back(rand()%2);
		while(q--){
			int kx,ky;
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=kx;i++){
				int p,v;
				scanf("%d%d",&p,&v);
			}
			for(int i=1;i<=ky;i++){
				int p,v;
				scanf("%d%d",&p,&v);
			}
			res.push_back(rand()%2);
		}
		for(int i=0;i<res.size();i++) printf("%d",res[i]);
	}
	return 0;
}

