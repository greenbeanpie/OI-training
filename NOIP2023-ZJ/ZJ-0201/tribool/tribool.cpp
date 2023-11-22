#include<bits/stdc++.h>
using namespace std;
int c,T;
namespace Subtask1{
	const int N=15;
	int n,m,ans=1e9,val[N];
	struct nd{
		int op,x,y;
	}q[N];
	inline bool chk(){
		int tmp[N];
		memcpy(tmp,val,sizeof(tmp));
		for(int i=1;i<=m;i++){
			if(q[i].op==1) tmp[q[i].x]=q[i].y;
			else if(q[i].op==2) tmp[q[i].x]=tmp[q[i].y];
			else tmp[q[i].x]=-tmp[q[i].y];
		}
		for(int i=1;i<=n;i++)
			if(tmp[i]!=val[i]) return 0;
		return 1;
	}
	inline int cnt(){
		int res=0;
		for(int i=1;i<=n;i++)
			if(!val[i]) res++;
		return res;
	}
	void dfs(int x){
		if(x>n){
			if(chk()) ans=min(ans,cnt());
			return;
		}
		val[x]=1;
		dfs(x+1);
		val[x]=-1;
		dfs(x+1);
		val[x]=0;
		dfs(x+1);
	}
	inline void solve(){
		ans=1e9;
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			char s[5];
			cin>>s+1;
			if(s[1]>='A'&&s[1]<='Z'){
				q[i].op=1;
				cin>>q[i].x;
				if(s[1]=='T') q[i].y=1;
				if(s[1]=='F') q[i].y=-1;
				if(s[1]=='U') q[i].y=0;
			}
			else{
				if(s[1]=='+') q[i].op=2;
				else q[i].op=3;
				cin>>q[i].x>>q[i].y;
			}
		}
		dfs(1);
		cout<<ans<<"\n";
	}
}
namespace Subtask2{
	const int N=1e5+5;
	int n,m,val[N];
	bool vis[N];
	struct nd{
		int op,x,y;
	}q[N];
	inline int cnt(){
		int res=0;
		for(int i=1;i<=n;i++)
			if(!val[i]&&vis[i]) res++;
		return res;
	}
	inline void solve(){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			vis[i]=val[i]=0;
		for(int i=1;i<=m;i++){
			char s[5];
			cin>>s+1;
			if(s[1]>='A'&&s[1]<='Z'){
				q[i].op=1;
				cin>>q[i].x;
				if(s[1]=='T') q[i].y=1;
				if(s[1]=='F') q[i].y=-1;
				if(s[1]=='U') q[i].y=0;
			}
			else{
				if(s[1]=='+') q[i].op=2;
				else q[i].op=3;
				cin>>q[i].x>>q[i].y;
			}
		}
		for(int i=m;i>=1;i--)
			if(!vis[q[i].x]){
				val[q[i].x]=q[i].y;
				vis[q[i].x]=1;
			}
		cout<<cnt()<<"\n";
	}
}
namespace Subtask3{
	const int N=1e5+5;
	int n,m,fa[N],sz[N];
	int cnt[N],vis[N];
	struct nd{
		int op,x,y;
	}q[N];
	int find(int x){
		return x==fa[x]?x:find(fa[x]);
	}
	inline bool merge(int x,int y){
		int fx=find(x),fy=find(y);
		if(fx==fy) return 0;
		fa[fx]=fy,sz[fy]+=sz[fx];
		return 1;
	}
	inline void solve(){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cnt[i]=vis[i]=0;
		for(int i=0;i<=n;i++){
			fa[i]=i;
			sz[i]=1;
		}
		for(int i=1;i<=m;i++){
			char s[5];
			cin>>s+1;
			if(s[1]>='A'&&s[1]<='Z'){
				q[i].op=1;
				cin>>q[i].x;
				if(s[1]=='T') q[i].y=1;
				if(s[1]=='F') q[i].y=-1;
				if(s[1]=='U') q[i].y=0;
				vis[q[i].x]++;
			}
			else{
				if(s[1]=='+') q[i].op=2;
				else q[i].op=3;
				cin>>q[i].x>>q[i].y;
				vis[q[i].x]++;
			}
		}
		for(int i=1;i<=m;i++){
			cnt[q[i].x]++;
			if(vis[q[i].y]==cnt[q[i].y]||!cnt[q[i].y]){
				if(vis[q[i].x]==cnt[q[i].x]){
					fa[q[i].x]=q[i].x;
					merge(q[i].x,q[i].y);
				}
			}
		}
		cout<<sz[find(0)]-1<<"\n";
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>T;
	if(c==1||c==2){
		while(T--) Subtask1::solve();
	}
	else if(c==3||c==4){
		while(T--) Subtask2::solve();
	}
	else if(c==5||c==6){
		while(T--) Subtask3::solve();
	}
	return 0;
}