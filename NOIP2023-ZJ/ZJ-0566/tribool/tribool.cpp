#include <bits/stdc++.h>
using namespace std;
int c,t,m,n,jl[10005][4],b[10005],ans,ts[100005];
bool pd(){
	int bb[10005];
	memset(bb,0,sizeof(bb));
	for(int i=1;i<=n;i++)bb[i]=b[i];
	for(int i=1;i<=m;i++){
		if(jl[i][1]==2){
			bb[jl[i][2]]=bb[jl[i][3]];
			continue;
		}
		if(jl[i][1]==3){
			bb[jl[i][2]]=-bb[jl[i][3]];
			continue;
		}
		bb[jl[i][2]]=jl[i][1];
	}
	for(int i=1;i<=n;i++)if(b[i]!=bb[i]) return 0;
	return 1;
}
void dfs(int k,int sum){
	if(sum>ans) return ;
	if(k==n+1){
		if(pd())ans=min(ans,sum);
		return;
	}
	b[k]=1;
	dfs(k+1,sum);
	b[k]=-1;
	dfs(k+1,sum);
	b[k]=0;
	dfs(k+1,sum+1);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==3||c==4){
	while(t--){
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			char ch;
			int opt;
			cin>>ch;
		    scanf("%d",&opt);
			if(ch=='T')ts[opt]=0;
			if(ch=='F')ts[opt]=1;
			if(ch=='U')ts[opt]=2;
		}
		for(int i=1;i<=n;i++)if(ts[i]==2) ans++;
		printf("%d\n",ans);
	}
	}else{
	while(t--){
		memset(b,0,sizeof(b));
		ans=INT_MAX;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			char ch;
			int opt,x,y;
			cin>>ch;
			if(ch=='T'||ch=='F'||ch=='U'){
				scanf("%d",&opt);
				if(ch=='T')jl[i][1]=1;
				if(ch=='F')jl[i][1]=-1;
				if(ch=='U')jl[i][1]=0;
				jl[i][2]=opt;
			}
			if(ch=='+'||ch=='-'){
				scanf("%d%d",&x,&y);
				if(ch=='+')jl[i][1]=2;
				if(ch=='-')jl[i][1]=3;
				jl[i][2]=x;
				jl[i][3]=y;
			}
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}