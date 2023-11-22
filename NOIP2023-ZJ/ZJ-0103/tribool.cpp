//FSZ with yingxue-cat
#include<bits/stdc++.h>
using namespace std;
int fanz(int x){
	if(x>0)return (x%2==0?x-1:x+1);
	if(x==-1)return x;
	return -5-x;
}
int cs[500005];
char op[15];
int fa[500005],cnt[500005];
int findfather(int x){
	return x==fa[x]?x:fa[x]=findfather(fa[x]);
}
vector<pair<int,int>>g[500005];
int col[500005];
bool dfs(int x){
	for(auto pi:g[x]){
		int cu=pi.first,c2=pi.second;
		if(!col[cu]){
			col[cu]=col[x]*c2;
			if(dfs(cu))return 1;
		}else if(col[cu]!=col[x]*c2)return 1;
	}
	return 0;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	//int aa=clock();
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)cs[i]=2*i;
		while(m--){
			scanf("%s",op+1);
			if(op[1]=='+'){
				int i,j;
				scanf("%d%d",&i,&j);
				cs[i]=cs[j];
			}else if(op[1]=='-'){
				int i,j;
				scanf("%d%d",&i,&j);
				cs[i]=fanz(cs[j]);
			}else{
				int i;
				scanf("%d",&i);
				if(op[1]=='T')cs[i]=-2;
				else if(op[1]=='F')cs[i]=-3;
				else cs[i]=-1;
			}
		}
		int ans=0;
		for(int i=1;i<=n+3;++i)fa[i]=i,cnt[i]=(i<=n);
		for(int i=1;i<=n;++i)g[i].clear();
		for(int i=1;i<=n;++i){
			if(cs[i]>0){
				if(cs[i]%2==0)g[i].emplace_back(cs[i]/2,1);
				else g[i].emplace_back((cs[i]+1)/2,-1);
			}
			int x=findfather(i),y=findfather(cs[i]>0?(cs[i]+1)/2:n-cs[i]);
			if(x==y)continue;
			fa[y]=x,cnt[x]+=cnt[y];
		}
		for(int i=1;i<=n;++i)col[i]=0;
		for(int i=1;i<=n;++i)if(findfather(i)==i){
			int mb=0;
			for(int j=n+1;j<=n+3;++j)if(findfather(j)==i)mb=j;
			if(mb){
				if(mb==n+1)ans+=cnt[i];
				continue;
			}
			col[i]=1;
			if(dfs(i))ans+=cnt[i];
		}
		printf("%d\n",ans);
	}
	//cerr<<1.0*(clock()-aa)/CLOCKS_PER_SEC<<endl;
	return 0;
}
