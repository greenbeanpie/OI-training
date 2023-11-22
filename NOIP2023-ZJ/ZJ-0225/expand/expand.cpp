#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
using LL=long long;
using pii=pair<int,int>;
const int N=2e3+9;
int CDX,_;
int n,m,x[N],y[N];
pii mx[500009],my[500009];
vector<int> ans;
bool dfs(int i,int j,int g){
	if (i==n && j==m) return true;
	if(g){
		if(i<n && j<m && x[i+1]>y[j+1] && dfs(i+1,j+1,g)) return true;
		if(i<n && x[i+1]>y[j] && dfs(i+1,j,g)) return true;
		if(j<m && x[i]>y[j+1] && dfs(i,j+1,g)) return true;
	}else{
		if(i<n && j<m && x[i+1]<y[j+1] && dfs(i+1,j+1,g)) return true;
		if(i<n && x[i+1]<y[j] && dfs(i+1,j,g)) return true;
		if(j<m && x[i]<y[j+1] && dfs(i,j+1,g)) return true;
	}
	return false;
}
void solve(bool fir){
	int k1,k2;
	if(fir){
		scanf("%d%d",&k1,&k2);
		for(int a,i=1;i<=k1;i++){
			scanf("%d%d",&mx[i].first,&a);
			mx[i].second=x[mx[i].first];
			x[mx[i].first]=a;
		}
		for(int a,i=1;i<=k2;i++){
			scanf("%d%d",&my[i].first,&a);
			my[i].second=y[my[i].first];
			y[my[i].first]=a;
		}
	}
	if(x[1]==y[1]){
		ans.push_back(0);
	}else if(x[1]>y[1]){
		if(dfs(1,1,1)) ans.push_back(1);
		else ans.push_back(0);
	}else{
		if(dfs(1,1,0)) ans.push_back(1);
		else ans.push_back(0);
	}
	if(fir){
		for(int i=1;i<=k1;i++) x[mx[i].first]=mx[i].second;
		for(int i=1;i<=k2;i++) y[my[i].first]=my[i].second;
	}
}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&CDX,&n,&m,&_);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=1;i<=m;i++) scanf("%d",&y[i]);
	solve(0);
	while(_--) solve(1);
	for(int i=0;i<ans.size();i++) printf("%d",ans[i]);
	puts("");
	return 0;
}
/*
遗憾 第一次noip  有点急------
*/