#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t,n,m,cnt=0;
int fa[3*N],vis[N];
vector<int> ve[3*N];
struct node{
	int zhi;
	int id;
}op[N];
int find(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int op1=find(x),op2=find(y);
	if(op1==op2) return;
	fa[op1]=op2;
	for(auto to:ve[op1])
		ve[op2].push_back(to);
	ve[op1].clear();
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>c>>t;
	if(c==3 || c==4){
		while(t--){
			cin>>n>>m;int ans=0;
			memset(vis,0,sizeof(vis));
			for(int i=1;i<=m;i++){
				char opt;int a;
				cin>>opt;
				if(opt=='T'){
					cin>>a;
					vis[a]=1;
				}
				if(opt=='F'){
					cin>>a;
					vis[a]=0;
				}
				if(opt=='U'){
					cin>>a;
					vis[a]=-1;
				}
			}
			for(int i=1;i<=n;i++) 
			if(vis[i]==-1) ans++;
			cout<<ans<<'\n';
		}
	}
	else{
		while(t--){
			cin>>n>>m;int ans=0;cnt=0;
			for(int i=1;i<=(1<<n);i++) 
			fa[i]=i,ve[i].push_back(i);
			for(int i=1;i<=m;i++){
				char opt;int a,b;
				cin>>opt;
				if(opt=='+'){
					cin>>a>>b;
					merge(a,b);
					merge(a+n,b+n);
				}
				else if(opt=='-'){
					cin>>a>>b;
					merge(a,b+n);
					merge(a+n,b);
				}
				else if(opt=='T'){
					cin>>a;
					op[++cnt].zhi=1;
					op[cnt].id=a;
				}
				else if(opt=='F'){
					cin>>a;
					op[++cnt].zhi=0;
					op[cnt].id=a;
				}
				else if(opt=='U'){
					cin>>a;
					op[++cnt].zhi=-1;
					op[cnt].id=a;
				}
			}
			for(int i=1;i<=n;i++)
				if(find(i)==find(i+n)) ans++,vis[i]=-1;
			for(int i=1;i<=cnt;i++){
				int id=op[i].id;
				if(vis[id]==-1 || op[i].zhi==1||
				op[i].zhi==0) continue;
				for(auto to:ve[find(id)])
					if(vis[to]!=-1)vis[to]=-1,ans++;
			}
			cout<<ans<<'\n';
			for(int i=1;i<=(1<<n);i++) 
			ve[i].clear(),vis[i]=0;		
		}
	}
	return 0;
}
