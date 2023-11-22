#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,m,usd[N],d[N],vis[N],ans;
char c;
vector<int>g[N],v[N];
struct P{
	int val;	//0/1/2 a[i]=F/T/U
	int k,rev;	//rev=0/1 a[i]=a[k]/!a[k]
}a[N];
void dfs(int x){
	if(usd[x]) return ;
	usd[x]=1,ans++;
	for(int y:g[x]) dfs(y);
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%*d%d",&t);
	while(t--){
		scanf("%d%d",&n,&m),ans=0;
		for(int i=1;i<=n;i++)
			a[i].val=-1,a[i].k=i,a[i].rev=0,
			usd[i]=vis[i]=d[i]=0,g[i].clear(),v[i].clear();
		for(int i=1,x,y;i<=m;i++){
			scanf(" %c",&c);
			if(c=='T'||c=='F'||c=='U')
				scanf("%d",&x),
				a[x].val=c=='T'?1:(c=='F'?0:2),
				a[x].k=a[x].rev=-1;
			if(c=='+')
				scanf("%d%d",&y,&x),
				a[y]=a[x];
			if(c=='-'){
				scanf("%d%d",&y,&x);
				if(~a[x].val){
					a[y].val=a[x].val==0?1:(a[x].val==1?0:2);
					a[y].k=a[y].rev=-1;
				}
				else if(~a[x].k){
					a[y].val=-1;
					a[y].k=a[x].k,a[y].rev=a[x].rev^1;
				}
			}
		}
		for(int i=1;i<=n;i++)
			if(~a[i].k)
				g[i].push_back(a[i].k),g[a[i].k].push_back(i),
				v[i].push_back(a[i].k),d[a[i].k]++;
		queue<int>q;
		for(int i=1;i<=n;i++)
			if(!d[i]) q.push(i);
		while(q.size()){
			int x=q.front();q.pop();
			for(int y:v[x])
				if(!--d[y]) q.push(y);
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]&&d[i]){
				int x=i,rev=0;
				while(1){
					if(vis[x]) break;
					vis[x]=1;
					if(~a[x].k) x=a[x].k,rev^=a[x].rev;
				}
				if(rev) dfs(i);
			}
			if(a[i].val==2) dfs(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
