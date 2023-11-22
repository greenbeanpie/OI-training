#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int MAXN=5e5+5,inf=1e9+7;
int n,m,k,d,x[MAXN],y[MAXN],v[MAXN],maxn,c,t;
void dfs(int i,int w,int pla,int j){
	if(i==x[j+1])j+=1;
	if(pla>=y[j])w+=v[j];
	if(i==n){
		maxn=max(w,maxn);
		return ;
	}
	if(pla<=k)dfs(i+1,w-d,pla+1,j);
	dfs(i+1,w,pla,j);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		maxn=0;
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x[i],&y[i],&v[i]);
		}
		dfs(1,0,0,0);
		printf("%d\n",maxn);
	}
	return 0;
}