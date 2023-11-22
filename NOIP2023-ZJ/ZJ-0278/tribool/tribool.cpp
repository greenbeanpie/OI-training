#include <iostream>
#include <cstring>
//#include <bits/exc++.h>
using namespace std;
const int maxn=1e5+5,inf=0x3f3f3f3f;
int n,m,ans,a[maxn],ops[maxn],xs[maxn],ys[maxn],b[maxn];
char op[10];
int fa[maxn];bool vis[maxn];
int findfa(int x){
	return (fa[x]==x?x:(fa[x]=findfa(fa[x])));
}
void dfs(int step){
	if (step==n+1){
		for (int i=1;i<=n;++i) b[i]=a[i];
		for (int i=1;i<=m;++i){
			if (ops[i]==1) b[xs[i]]=1;
			else if (ops[i]==2) b[xs[i]]=-1;
			else if (ops[i]==3) b[xs[i]]=0;
			else if (ops[i]==4) b[xs[i]]=b[ys[i]];
			else if (ops[i]==5) b[xs[i]]=-b[ys[i]];
		}
		bool flg=true;
		for (int i=1;i<=n;++i) if (a[i]!=b[i]){flg=false;break;}
		if (flg){
			int cnt=0;
			for (int i=1;i<=n;++i) cnt+=(a[i]==0);
			ans=min(ans,cnt);
		}
		return;
	}
	a[step]=1;
	dfs(step+1);
	a[step]=0;
	dfs(step+1);
	a[step]=-1;
	dfs(step+1);
	return;
}
void work(int c){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		scanf("%s",op);
		if (op[0]=='T'){
			int x;scanf("%d",&x);
			ops[i]=1;xs[i]=x;
		}
		else if (op[0]=='F'){
			int x;scanf("%d",&x);
			ops[i]=2;xs[i]=x;
		}
		else if (op[0]=='U'){
			int x;scanf("%d",&x);
			ops[i]=3;xs[i]=x;
		}
		else if (op[0]=='+'){
			int x,y;scanf("%d%d",&x,&y);
			ops[i]=4;xs[i]=x;ys[i]=y;
		}
		else if (op[0]=='-'){
			int x,y;scanf("%d%d",&x,&y);
			ops[i]=5;xs[i]=x;ys[i]=y;
		}
	}
	if (c==1){
		ans=inf;
		dfs(1);
		printf("%d\n",ans);
		return;
	}
	else if (c==2){
		ans=inf;
		dfs(1);
		printf("%d\n",ans);
		return;
	}
	else if (c==3){
		ans=0;
		for (int i=1;i<=m;++i){
			if (ops[i]==1) a[xs[i]]=1;
			else if (ops[i]==2) a[xs[i]]=-1;
			else if (ops[i]==3) a[xs[i]]=0;
		}
		for (int i=1;i<=n;++i) ans+=(a[i]==0);
		printf("%d\n",ans);
		return;
	}
	else if (c==4){
		ans=0;
		for (int i=1;i<=m;++i){
			if (ops[i]==1) a[xs[i]]=1;
			else if (ops[i]==2) a[xs[i]]=-1;
			else if (ops[i]==3) a[xs[i]]=0;
		}
		for (int i=1;i<=n;++i) ans+=(a[i]==0);
		printf("%d\n",ans);
		return;
	}
	else if (c==5||c==6){
		ans=0;
		memset(a,0x3f,sizeof a);
//		memset(vis,0,sizeof vis);
//		for (int i=1;i<=n;++i) fa[i]=i;
		for (int i=1;i<=m;++i){
			if (ops[i]==3) a[xs[i]]=0;
			else if (ops[i]==4){
				a[xs[i]]=a[ys[i]];
			}
		}
//		for (int i=1;i<=n;++i) findfa(i);
//		for (int i=1;i<=n;++i)
//			if (a[i]==0) vis[fa[i]]=1;
//		for (int i=1;i<=n;++i) if (vis[fa[i]]) a[i]=0;
		for (int i=1;i<=n;++i) ans+=(a[i]==0);
		printf("%d\n",ans);
		return;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;scanf("%d%d",&c,&t);
	while (t--) work(c);
	return 0;
}
