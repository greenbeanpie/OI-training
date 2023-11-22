#include<bits/stdc++.h>
struct opt{char type;int x,y;};
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr),std::cout.tie(nullptr);
	int c,t;
	for(std::cin>>c>>t;t--;){
		int n,m,res=0;
		std::cin>>n>>m;
		std::vector<int>idx(n<<1),val(n),dsu(n<<1);
		std::vector<opt>op(m);
		for(int i=0;i<(n<<1);++i)idx[i]=dsu[i]=i;
		for(int i=0;i<m;++i){
			std::cin>>op[i].type>>op[i].x,--op[i].x;
			if(op[i].type=='+'){
				std::cin>>op[i].y,--op[i].y;
				if(val[op[i].y])val[op[i].x]=val[op[i].y],idx[op[i].x]=op[i].x;
				else idx[op[i].x]=idx[op[i].y],val[op[i].x]=0;
			}
			else if(op[i].type=='-'){
				std::cin>>op[i].y,--op[i].y;
				if(val[op[i].y])val[op[i].x]=val[op[i].y]==1?2:(val[op[i].y]==2?1:3),idx[op[i].x]=op[i].x;
				else{
					int anc=idx[op[i].y];
					if(anc>=n)idx[op[i].x]=anc-n;
					else idx[op[i].x]=anc+n;
					val[op[i].x]=0;
				}
			}
			else val[op[i].x]=op[i].type=='T'?1:(op[i].type=='F'?2:3),idx[op[i].x]=op[i].x;
		}
		for(int i=0;i<n;++i)
		if(!val[i]){
			int anc=idx[i];
			if(anc>=n&&val[anc-n])val[i]=val[anc]==1?2:(val[anc]==2?1:3);
			if(anc<n&&val[anc])val[i]=val[anc];
		}
		std::function<int(int)>find=[&](int x)->int{return x==dsu[x]?x:dsu[x]=find(dsu[x]);};
		for(int i=0;i<n;++i)dsu[find(i)]=find(idx[i]);
		std::vector<std::vector<int>>G(n<<1);
		std::vector<int>col(n<<1),sz(n<<1);
		std::vector<bool>uk(n<<1);
		for(int i=0;i<n;++i)if(val[i]==3||find(i)==find(i+n))uk[find(i)]=true;
		for(int i=0;i<n;++i)if(find(i)!=find(i+n))G[find(i)].emplace_back(find(i+n)),G[find(i+n)].emplace_back(find(i));
		int cnt=0;
		bool flag=false;
		std::function<void(int)>dfs=[&](int u)->void{
			cnt+=sz[u];
			if(uk[u])flag=true;
			for(const int&v:G[u])
			if(!col[v])col[v]=col[u]==1?2:1,dfs(v);
			else if(v!=u&&col[u]==col[v])flag=true;
		};
		for(int i=0;i<n;++i)++sz[find(i)];
		for(int i=0;i<(n<<1);++i)
		if(!col[find(i)]){
			cnt=0,flag=false,col[find(i)]=1,dfs(find(i));
			if(flag)res+=cnt;
		}
		std::cout<<res<<'\n';
	}
	return 0;
}