#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#define Min(x,y) x<y?x:y;
using namespace std;
const int N=1e5+5;
int c,t,n,m;
struct node{
	int type,x,y;
}deal[N];
int num[15],ans;
void check(){
	int d[15],cnt=0;
	for(int i=1;i<=n;++i)
		d[i]=num[i];
	for(int i=1;i<=m;++i)
		if(deal[i].type==2) d[deal[i].x]=-d[deal[i].y];
		else if(deal[i].type==3) d[deal[i].x]=d[deal[i].y];
		else d[deal[i].x]=deal[i].type;
	for(int i=1;i<=n;++i){
		if(d[i]!=num[i]) return ;
		if(d[i]==0) ++cnt;
	}
	ans=Min(ans,cnt);
}
void dfs(int now){
	if(now==n+1){
		check();
		return ;
	}
	num[now]=-1;
	dfs(now+1);
	num[now]=0;
	dfs(now+1);
	num[now]=1;
	dfs(now+1);
}
struct edge{
	int v,w;
};
vector<edge>E[N];
queue<int>Q;
int deg[N];
bool vis[N];
int l;
void topo(){
	for(int i=1;i<=n;++i)
		if(!deg[i]){
			Q.push(i);
			vis[i]=true;
		}
	while(!Q.empty()){
		l=Q.front();
		Q.pop();
		cout<<l<<endl;
		for(int i=0;i<E[l].size();++i){
			if(vis[E[l][i].v]) continue;
			--deg[E[l][i].v];
			if(!deg[E[l][i].v]){
				Q.push(E[l][i].v);
				vis[E[l][i].v]=true;
			}
		}
	}
}
int uu;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	char v;int a,b;
	if(c==1||c==2){
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=m;++i){
				cin>>v;
				if(v=='-'){
					deal[i].type=2;
					cin>>deal[i].x>>deal[i].y;
				}
				else if(v=='+'){
					deal[i].type=3;
					cin>>deal[i].x>>deal[i].y;
				}
				else{
					switch(v){
						case 'T':deal[i].type=1;break;
						case 'F':deal[i].type=-1;break;
						case 'U':deal[i].type=0;break;
					}
					cin>>deal[i].x;
				}
			}
			ans=N;
			dfs(1);
			cout<<ans<<endl;
		}
		return 0;
	}
	if(c==3||c==4){
		int nn[N];
		while(t--){
			cin>>n>>m;
			memset(nn,0,sizeof(nn));
			ans=0;
			for(int i=1;i<=m;++i){
				cin>>v>>a;
				switch(v){
					case 'T':nn[a]=1;break;
					case 'F':nn[a]=2;break;
					case 'U':nn[a]=3;break;
				}
			}
			for(int i=1;i<=n;++i)
				if(nn[i]==3) ++ans;
			cout<<ans<<endl;
		}
		return 0;
	}
	return 0;
}