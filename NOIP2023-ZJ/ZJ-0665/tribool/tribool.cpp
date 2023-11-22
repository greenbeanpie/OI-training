#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
const int maxn=2e5+10;
int subtask,testcase;

namespace solve12{
	int n,m;
	int a[11],ans;
	struct node{
		int id,tag;
	}p[maxn];
	inline void init(){
		for(int i=1;i<=n;i++){
			p[i].id=i;
			p[i].tag=0;
		}
	}
	inline bool check(){
		int tmp[11];
		memset(tmp,0,sizeof(tmp));
		for(int i=1;i<=n;i++){
			if(p[i].id){
				if(p[i].tag==0){
					tmp[i]=a[p[i].id];
				}else{
					tmp[i]=(a[p[i].id]==2?a[p[i].id]:a[p[i].id]^1);
				}
			}else{
				tmp[i]=p[i].tag;
			}
			if(a[i]!=tmp[i])return 0;
		}
		return 1;
	}
	inline void dfs(int pos,int sum){
		if(pos>n){
			if(check()){
				ans=min(ans,sum);
			}
			return;
		}
		for(int i=0;i<=2;i++){
			a[pos]=i;
			dfs(pos+1,sum+(i==2));
		}
	}
	inline void solve(){
		n=read();m=read();
		init();
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch^'+'&&ch^'-'&&ch^'T'&&ch^'F'&&ch^'U')ch=getchar();
			if(ch=='+'){
				int u=read(),v=read();
				p[u].id=p[v].id;
				p[u].tag=p[v].tag;
			}else if(ch=='-'){
				int u=read(),v=read();
				p[u].id=p[v].id;
				if(p[v].tag!=2)p[u].tag=p[v].tag^1;
				else p[u].tag=p[v].tag;
			}else if(ch=='T'){
				int u=read();
				p[u].id=0;
				p[u].tag=1;
			}else if(ch=='F'){
				int u=read();
				p[u].id=0;
				p[u].tag=0;
			}else if(ch=='U'){
				int u=read();
				p[u].id=0;
				p[u].tag=2;
			}
		}
		ans=n;
		dfs(1,0);
		printf("%lld\n",ans);
	}
}

namespace solve34{
	int n,m;
	int val[maxn];
	int cnt;
	inline void init(){
		cnt=0;
		for(int i=1;i<=n;i++)val[i]=0;
	}
	inline void solve(){
		n=read();m=read();
		init();
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch^'+'&&ch^'-'&&ch^'T'&&ch^'F'&&ch^'U')ch=getchar();
			if(ch=='+'){
			}else if(ch=='-'){
			}else if(ch=='T'){
				int u=read();
				if(val[u])--cnt;
				val[u]=0;
			}else if(ch=='F'){
				int u=read();
				if(val[u])--cnt;
				val[u]=0;
			}else if(ch=='U'){
				int u=read();
				if(!val[u])++cnt;
				val[u]=1;
			}
		}
		printf("%lld\n",cnt);
	}
}

namespace solve56{
	int n,m;
	int a[11],ans;
	struct node{
		int id,tag;
	}p[maxn];
	inline void init(){
		for(int i=1;i<=n;i++){
			p[i].id=i;
			p[i].tag=0;
		}
	}
	inline bool check(){
		int tmp[11];
		memset(tmp,0,sizeof(tmp));
		for(int i=1;i<=n;i++){
			if(p[i].id){
				if(p[i].tag==0){
					tmp[i]=a[p[i].id];
				}else{
					tmp[i]=(a[p[i].id]==2?a[p[i].id]:a[p[i].id]^1);
				}
			}else{
				tmp[i]=p[i].tag;
			}
			if(a[i]!=tmp[i])return 0;
		}
		return 1;
	}
	inline void dfs(int pos,int sum){
		if(pos>n){
			if(check()){
				ans=min(ans,sum);
			}
			return;
		}
		for(int i=0;i<=2;i++){
			if(i==1)continue;
			a[pos]=i;
			dfs(pos+1,sum+(i==2));
		}
	}
	inline void solve(){
		n=read();m=read();
		init();
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch^'+'&&ch^'-'&&ch^'T'&&ch^'F'&&ch^'U')ch=getchar();
			if(ch=='+'){
				int u=read(),v=read();
				p[u].id=p[v].id;
				p[u].tag=p[v].tag;
			}else if(ch=='-'){
			}else if(ch=='T'){
			}else if(ch=='F'){
			}else if(ch=='U'){
				int u=read();
				p[u].id=0;
				p[u].tag=2;
			}
		}
		ans=n;
		dfs(1,0);
		printf("%lld\n",ans);
	}
}

signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	subtask=read();
	testcase=read();
	while(testcase--){
		if(subtask==1||subtask==2){
			solve12::solve();
		}else if(subtask==3||subtask==4){
			solve34::solve();
		}else if(subtask==5||subtask==6){
			solve56::solve();
		}else if(subtask==7||subtask==8){
			solve12::solve();
		}else{
			solve12::solve();
		}
	}
}
