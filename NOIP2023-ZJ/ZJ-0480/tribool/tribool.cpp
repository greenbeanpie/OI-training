#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >g[500100];
int col[500100];
int sz;
int fa[500100],used[500100];
int zong;
int n,m;
int zhi[500100],fl[500100];
int tmp;
void dfs(int x,int pre){
//	cout<<sz<<endl;
	col[x]=pre;used[x]=1;sz++;
	if (!fa[x]&&zhi[x]==0)zong=1;
	else if (!fa[x]&&zhi[x]!=col[x])zong=1;
	for (auto i:g[x]){
		tmp=i.second==1?pre:-pre;
		if (used[i.first]==0)dfs(i.first,tmp);
		else if (tmp!=col[i.first]) zong=1;
	}
}
void solve(){
	cin>>n>>m;
//	cout<<n<<"***"<<m<<endl;
	for (int i=1;i<=n;i++)
	fa[i]=i,zhi[i]=0,fl[i]=1,used[i]=col[i]=0,g[i].clear();
	for (int i=1;i<=m;i++)
	{
		char v;
		int x,y;
		cin>>v;
		if (v=='-') {
			scanf("%d%d",&x,&y);//cin>>x>>y;
			if (fa[y]){
				fa[x]=fa[y];
				fl[x]=-fl[y];
			}else {
				fa[x]=0;
				zhi[x]=-zhi[y];
			}
		}else if (v=='+'){
			scanf("%d%d",&x,&y);
			if (fa[y]){
			fa[x]=fa[y];
			fl[x]=fl[y];
			}else {
				fa[x]=0;
				zhi[x]=zhi[y];
			}
		}else if (v=='T'){
			scanf("%d",&x);
			fa[x]=0;
			zhi[x]=1;
		}else if (v=='F'){
			scanf("%d",&x);
			fa[x]=0;
			zhi[x]=-1;
		}else if (v=='U'){
			scanf("%d",&x);
			fa[x]=0;
			zhi[x]=0;
		}
	}
	//for (int i=1;i<=n;i++)
	//cout<<fa[i]<<"***"<<fl[i]<<endl;
	for (int i=1;i<=n;i++)
	if (fa[i]!=0)g[fa[i]].push_back({i,fl[i]}),g[i].push_back({fa[i],fl[i]});
	int ans=0;
	for (int i=1;i<=n;i++)
	if (!fa[i]&&!used[i]){
		zong=0,sz=0,dfs(i,zhi[i]),ans+=zong*sz;
		//cout<<ans<<"*$$$**"<<i<<endl;
	}
//	cout<<ans<<"*******";
	for (int i=1;i<=n;i++)
	if (!used[i]){//cout<<i<<"****\n";
		zong=0,sz=0,dfs(i,1),ans+=zong*sz;//cout<<"*****\n";
	//	cout<<ans<<"*$$$**"<<i<<endl;
	}cout<<ans<<endl;
//	exit(0);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int ch,T;
	cin>>ch>>T;
	while(T--)solve();
}