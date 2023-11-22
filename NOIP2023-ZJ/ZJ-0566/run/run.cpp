#include <bits/stdc++.h>
using namespace std;
int c,t,n,m,u,d,jl[1005][3],ans;
void dfs(int k,int cnt,int sum){
	if(k==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(cnt<u){
		if(jl[k][1]>0&&cnt+1>=jl[k][1])dfs(k+1,cnt+1,sum-d+jl[k][2]);else dfs(k+1,cnt+1,sum-d);
		dfs(k+1,0,sum);
	}else dfs(k+1,0,sum);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&u,&d);
		memset(jl,0,sizeof(jl));
		for(int i=1;i<=m;i++){
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			jl[x][1]=y; jl[x][2]=v;
		}
		dfs(1,0,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}