#include<bits/stdc++.h>
using namespace std;
int C,T;
namespace T21{
	int n,m,ans,c[15],b[15],x[15],y[15];
	char opt[15][15];
	void dfs(int p){
		if(p==n+1){
			for(int i=1;i<=n;i++) c[i]=b[i];
			for(int i=1;i<=m;i++){
				if(opt[i][0]=='-'){
					int u=x[i],v=y[i];
					if(c[v]==3) c[u]=3;
					else c[u]=3-c[v];
				}
				else if(opt[i][0]=='+'){
					int u=x[i],v=y[i];
					c[u]=c[v];
				}
				else{
					if(opt[i][0]=='T') c[x[i]]=1;
					if(opt[i][0]=='F') c[x[i]]=2;
					if(opt[i][0]=='U') c[x[i]]=3;
				}
			}
			for(int i=1;i<=n;i++) if(c[i]!=b[i]) return;
			int cnt=0;
			for(int i=1;i<=n;i++) cnt+=(b[i]==3);
			ans=min(ans,cnt);
			return;
		}
		b[p]=1;dfs(p+1);
		b[p]=2;dfs(p+1);
		b[p]=3;dfs(p+1);
	}
	void solve(){
		while(T--){
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				scanf("%s",opt[i]);
				if(opt[i][0]=='-'||opt[i][0]=='+') scanf("%d%d",&x[i],&y[i]);
				else scanf("%d",&x[i]);
			}
			ans=1e9;
			dfs(1);
			printf("%d\n",ans);
		}
	}
}
namespace T22{
	int n,m,ans,val[100005];
	void solve(){
		while(T--){
			scanf("%d%d",&n,&m);
			for(int i=1;i<=n;i++) val[i]=0;
			for(int i=1,x;i<=m;i++){
				char opt[5];scanf("%s",opt);
				scanf("%d",&x);
				if(opt[0]=='T') val[x]=1;
				if(opt[0]=='F') val[x]=2;
				if(opt[0]=='U') val[x]=3;
			}
			ans=0;
			for(int i=1;i<=n;i++) ans+=(val[i]==3);
			printf("%d\n",ans);
		}
	}
}
namespace T23{
	int n,m,ans,res,val[1005],x[1005],y[1005];
	char opt[1005][5];
	void solve(){
		while(T--){
			scanf("%d%d",&n,&m);
			for(int i=1;i<=n;i++) val[i]=0;
			for(int i=1;i<=m;i++){
				scanf("%s",opt[i]);
				scanf("%d",&x[i]);
				if(opt[i][0]=='U');
				if(opt[i][0]=='+') scanf("%d",&y[i]);
			}
			ans=res=0;
			do{
				ans=res;
				for(int i=1;i<=m;i++){
					if(opt[i][0]=='U')val[x[i]]=3;
					if(opt[i][0]=='+')val[x[i]]=val[y[i]];
				}
				res=0;
				for(int i=1;i<=n;i++) res+=(val[i]==3);
			}while(res!=ans);
			printf("%d\n",ans);
		}
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&C,&T);
	if(C<=2){
		T21::solve();
		return 0;
	}
	if(C<=4){
		T22::solve();
		return 0;
	}
	if(C<=5){
		T23::solve();
		return 0;
	}
	return 0;
}