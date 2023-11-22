#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int c,t;
int n,m;
vector<int>mp[N],sc[N],G[N];
int ans[N],las[N],vis[N],in[N];
int dfn[N],sccans[N],low[N],dfncnt;
int s[N],top;
int scc[N],scccnt;
void tarjan(int now){
	dfn[now]=low[now]=++dfncnt;
	s[++top]=now;
	for(int i=0;i<mp[now].size();++i){
		int v=abs(mp[now][i]);
		if(!dfn[v]) {
			tarjan(v);
			low[now]=min(low[now],low[v]);
		}else if(!scc[v]) low[now]=min(low[now],dfn[v]);
	}
	if(low[now]==dfn[now]){
		scccnt++;
		scc[now]=scccnt;
		sc[scccnt].push_back(now);
		while(s[top]!=now){
			sc[scccnt].push_back(s[top]);
			scc[s[top]]=scccnt;
			top--;
		}
		top--;
	}
}
int T,F,preans[N],l[N],r[N],bk[N];
bool ff;
void dfs(int now,int op){
	preans[now]=op;
//	printf("%d %d!\n",now,preans[now]);
	for(int i=0;i<mp[now].size();++i){
		int v=mp[now][i],cnt=1;
		if(v<0) v=-v,cnt=-1;
		if(scc[now]==scc[v]){
//			printf("%d %d %d@\n",now,v,cnt);
			if(!preans[v])dfs(v,op*cnt);
			else if(op*cnt!=preans[v]){
			    ff=1;
			    return ;
		    }
		}
	}
}
int Ans,sccsiz[N];
void check(int x){
	int now=sc[x][0];
	sccsiz[x]=sc[x].size();
	if(sc[x].size()==1) {
		int tt=ans[now],cnt=1;
		if(ans[now]<0) tt=-tt,cnt=-1;
		if(ans[now]==T||ans[now]==F||ans[now]==0) sccans[x]=ans[now];
		else if(ans[now]==now) sccans[x]=T;
		else sccans[x]=scc[tt]*cnt;
//		printf("%d %d!\n",now,ans[now]);
        return ;
	}
	ff=0;
	dfs(now,T);
	if(ff) {
//		printf("%d!\n",now);
        sccans[x]=0; 
	} else {
		sccans[x]=bk[x];
		if(!bk[x]) sccans[x]=T;
	}
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
    	scanf("%d%d",&n,&m);
    	T=n+1,F=-T;
    	for(int i=0;i<=n;++i)ans[i]=i,mp[i].clear(),G[i].clear(),sc[i].clear(),sccsiz[i]=bk[i]=las[i]=vis[i]=in[i]=0;
    	for(int i=0;i<=n;++i) dfn[i]=low[i]=scc[i]=sccans[i]=preans[i]=l[i]=r[i]=0;
    	dfncnt=0,scccnt=0,Ans=0;
    	for(int i=1;i<=m;++i){
    		char c;
    		int x,y;
    		scanf(" %c",&c);
    		if(c=='+'){
    			scanf("%d%d",&x,&y);
    			ans[x]=y; 
			}else if(c=='-'){
                scanf("%d%d",&x,&y);
                if(x==y) ans[x]=0;
                else ans[x]=-y; 
			}else {
				scanf("%d",&x);
				if(c=='T') ans[x]=T;
				if(c=='F') ans[x]=F;
				if(c=='U') ans[x]=0;
			}
		}
		for(int i=1;i<=n;++i){
			if(ans[i]>0) mp[ans[i]].push_back(i);
			else mp[-ans[i]].push_back(-i);
			l[i]=abs(ans[i]),r[i]=i;
		}
		for(int i=1;i<=n;++i) {
			if(!dfn[i]) top=0,tarjan(i);
		}
		for(int i=1;i<=n;++i){
			int u=l[i],v=r[i];
			if(scc[u]==scc[v]) continue;
			if(scc[u]!=scc[v]){
				G[scc[u]].push_back(scc[v]);
				bk[scc[v]]=scc[u];
			}
//			printf("%d %d!\n",u,v);
		}
		for(int i=1;i<=scccnt;++i){
			check(i);
		}
//		printf("%d!\n",T);
//		for(int i=1;i<=n;++i) printf("%d ",scc[i]);
		queue<int>q;
		for(int i=1;i<=scccnt;++i) if(sccans[i]==0||sccans[i]==T||sccans[i]==F) q.push(i);
		while(q.size()){
			int x=q.front();
			las[x]=sccans[x],vis[x]=1;
			if(las[x]==0) Ans+=sccsiz[x];
//			printf("%d!\n",las[x]);
			q.pop(); 
			for(int i=0;i<G[x].size();++i){
				int v=G[x][i],cnt=1;
//				printf("%d%d!\n",x,v);
				if(v<0) cnt=-1,v=-v;
				if(vis[v]) continue;
				vis[v]=1;
				sccans[v]=cnt*sccans[x];
				q.push(v);
			}
		}		
		
		printf("%d\n",Ans);
	}
	
	return 0;
}
