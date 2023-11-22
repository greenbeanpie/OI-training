#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	bool y;
};
vector<node> g[100005];
int a[100005],num[100005],ans,dis[100005],cnt;
bool u[100005],us[100005],use[100005];
int zhi(int x,bool u){
	if(!u||x==3)return x;
	if(x==1)return 2;
	return 1;
}
void fuzhi(int x){
	if(num[x]==3)ans++;
	for(int i=0;i<g[x].size();i++){
		int t=g[x][i].x,u=g[x][i].y;
		num[t]=zhi(num[x],u);
		fuzhi(t);
	}
}
void d(int x){
	use[x]=1;
	cnt++;
	for(int i=0;i<g[x].size();i++){
		int t=g[x][i].x;
		if(!use[t])d(t);
	}
}
void dfs(int x,int k){
	if(us[x]==1){
		cnt=0;
		d(x);
		if((k-dis[x])%2==1){
			ans+=cnt;
		}
		return;
	}
	dis[x]=k;
	us[x]=1;
	if(!a[x])d(x);
	else dfs(a[x],k+(u[x]==1));
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		ans=0;
		int n,m;
		cin>>n>>m;
		memset(a,0,sizeof(a));
		memset(num,0,sizeof(num));
		memset(u,0,sizeof(u));
		memset(us,0,sizeof(us));
		memset(dis,0,sizeof(dis));
		memset(use,0,sizeof(use));
		for(int i=1;i<=n;i++)g[i].clear();
		while(m--){
			char op;
			int p,q;
			cin>>op>>p;
			if(op=='T')
				num[p]=2,a[p]=0;
			else if(op=='F')
				num[p]=1,a[p]=0;
			else if(op=='U')
				num[p]=3,a[p]=0;
			else {
				cin>>q;
				a[p]=q;
				if(op=='+')u[p]=0;
				else u[p]=1;
			}
			
		}
		for(int i=1;i<=n;i++){
			if(!num[i]&&a[i]){
				g[a[i]].push_back({i,u[i]});
			}
		}
		
		for(int i=1;i<=n;i++){
			if(num[i]){
				fuzhi(i);
			}
		}
		if(C==3||C==4){
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(!num[i]&&a[i]&&!use[i]){
				dfs(i,0);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}