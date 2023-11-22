#include<bits/stdc++.h>
#define M 100005
using namespace std;
int id,t,n,m,ans,a[M],c[M],nxt[M];
bool vis[M];
struct order{
	int op,x,y;
}b[M];
vector<int> g[M];
vector<int> ch;
void dfs(int p){
	if(p>n){
		int res=0;
		for(int i=1;i<=n;i++){
			c[i]=a[i];
			if(a[i]==0) res++; 
		}
		for(int i=1;i<=m;i++){
			int op=b[i].op,x=b[i].x,y=b[i].y;
			if(op==1){
				c[x]=y;
			}
			else if(op==2){
				if(y>0) c[x]=c[y];
				else c[x]=-c[-y];
			}
		}
		bool f=1;
		for(int i=1;i<=n;i++){
			if(c[i]!=a[i]){
				f=0;
				break;
			}
		}
		if(f) ans=min(ans,res);
		return;
	}
	a[p]=1;
	dfs(p+1);
	a[p]=-1;
	dfs(p+1);
	a[p]=0;
	dfs(p+1);
}
void flood(int p){
	for(int i=0;i<g[p].size();i++){
		int to=g[p][i];
		if(!vis[to]){
			vis[to]=1;
			flood(to);
		}
	}
}
void read(){
	for(int i=1;i<=m;i++){
		char ch;
		cin>>ch;
		if(ch=='T'||ch=='F'||ch=='U'){
			b[i].op=1;
			int x;
			scanf("%d",&x);
			b[i].x=x;
			if(ch=='T') b[i].y=1;
			else if(ch=='F') b[i].y=-1;
			else if(ch=='U') b[i].y=0;
		}
		else if(ch=='+'||ch=='-'){
			b[i].op=2;
			int x,y;
			scanf("%d%d",&x,&y);
			b[i].x=x;
			if(ch=='+') b[i].y=y;
			else if(ch=='-') b[i].y=-y;
		}
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>id>>t;
	if(id==1||id==2){
		while(t--){
			ans=1e9;
			cin>>n>>m;
			read();
			dfs(1);
			printf("%d\n",ans);
		}
	}
	if(id==3||id==4){
		while(t--){
			ans=0;
			cin>>n>>m;
			read();
			for(int i=1;i<=n;i++) a[i]=1;
			for(int i=1;i<=m;i++){
				int x=b[i].x,y=b[i].y;
				a[x]=y;
			}
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
			}
			printf("%d\n",ans);
		}
	}
	if(id==5||id==6){
		while(t--){
			ans=0;
			cin>>n>>m;
			read();
			for(int i=1;i<=n;i++) a[i]=1;
			for(int i=1;i<=m;i++){
				int op=b[i].op,x=b[i].x,y=b[i].y;
				if(op==1){
					a[x]=0;
				}
			}
			for(int i=1;i<=n;i++){
				int op=b[i].op,x=b[i].x,y=b[i].y;
				if(op==2){
					nxt[y]=x;
				}
			}
			for(int i=1;i<=n;i++) vis[M]=0;
			for(int i=1;i<=n;i++){
				if(a[i]!=0||vis[i]) continue;
				vis[i]=1;
				int to=nxt[i];
				while(!vis[to]){
					a[to]=0;
					vis[to]=1;
					to=nxt[to];
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
			}
			printf("%d\n",ans);
		}
	}
	if(id==7||id==8){
		while(t--){
			ans=0;
			ch.clear();
			for(int i=1;i<=n;i++) vis[i]=0;
			cin>>n>>m;
			read();
			for(int i=1;i<=n;i++) a[i]=1;
			for(int i=1;i<=m;i++){
				int op=b[i].op,x=b[i].x,y=b[i].y;
				if(op==2){
					int k;
					if(y>0){
						k=a[y];
					}
					else{
						k=-a[-y];
					}
					if(k!=a[i]) ch.push_back(i);
					g[x].push_back(y);
					g[y].push_back(x);
				}
			}
			for(int i=0;i<ch.size();i++){
				int now=ch[i];
				if(vis[i]) continue;
				flood(i);
			}
			for(int i=1;i<=n;i++) if(vis[i]) ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}
