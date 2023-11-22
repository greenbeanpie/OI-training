#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int c,t,n,m,ans;
char s[5];
int val[N*2],va[N*2];
int fal(int x){
	if(x=='T') return 'F';
	if(x=='F') return 'T';
	if(x=='U') return 'U';
}
struct opt{
	char v;
	int x,y;
}a[N];
void st2(){ //TFU
	ans=0;
	for(int i=1;i<=m;i++) val[a[i].x]=a[i].v;
	for(int i=1;i<=n;i++)
		if(val[i]=='U') ++ans;
	printf("%d\n",ans);
}
vector<int> e[N*2],sc[N*2],f[N*2];
int dfn[N*2],low[N*2],st[N*2],ins[N*2],ind=0,tp=0;
int scc[N*2],vis[N*2],cnt=0;
void init(){
	for(int i=1;i<=n*2;i++){
		dfn[i]=low[i]=st[i]=ins[i]=vis[i]=va[i]=scc[i]=0;
		e[i].clear();f[i].clear();sc[i].clear();
	}	
	ind=tp=ans=cnt=0;
}
void tarjan(int x,int fa){
	dfn[x]=low[x]=++ind;
	st[++tp]=x;ins[x]=1;
	for(int y:e[x]){
		if(y==fa) continue;
		if(dfn[y]==0){
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
		}
		else if(ins[y]) low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x]){
		++cnt;
		while(st[tp]!=x){
			ins[st[tp]]=0;
			scc[st[tp]]=cnt,sc[cnt].push_back(st[tp]);
			--tp;
		}
		ins[x]=0,scc[x]=cnt,--tp,sc[cnt].push_back(x);
	}
}
void dfs(int x,int fa){
	vis[x]=1;
	if(va[x]==fal(fa)) va[x]='U';
	else va[x]=fa;
	for(int y:f[x]){
		if(!vis[y]) dfs(y,fa);
	}
}
void st4(){ //+-
	init();
	for(int i=1;i<=m;i++){
		if(a[i].v=='+'){
			if(a[i].x==a[i].y) continue;
			e[a[i].y].push_back(a[i].x);
			e[a[i].y+n].push_back(a[i].x+n);
		}
		else if(a[i].v=='-'){
			e[a[i].y].push_back(a[i].x+n);
			e[a[i].y+n].push_back(a[i].x);
		}
		else val[a[i].x]=a[i].v,val[a[i].x+n]=fal(a[i].v);
	}
	for(int i=1;i<=2*n;i++)
		if(!dfn[i]) tarjan(i,0);
	/*for(int i=1;i<=cnt;i++){
		for(int j:sc[i]) printf("%d ",j);
		printf("\n");
	}*/
	for(int i=1;i<=cnt;i++)
		for(int j:sc[i])
			for(int k:e[j])
				if(scc[k]!=cnt) f[cnt].push_back(scc[k]);
	for(int i=1;i<=n;i++)
		if(scc[i]==scc[i+n]) val[i]=val[i+n]='U';
	/*for(int i=1;i<=n*2;i++)
		printf("%d ",scc[i]);
	printf("\n");*/
	for(int i=1;i<=cnt;i++){
		int f1=0,f2=0;
		for(int j:sc[i]){
			if(val[j]=='T') f1=1;
			if(val[j]=='F') f2=1;
			if(val[j]=='U') f1=f2=1;
			if(f1==1&&f2==1) break;
		}
		if(f1==1&&f2==1) va[i]='U';
		else if(f1==1) va[i]='T';
		else if(f2==1) va[i]='F';
	}
	for(int i=1;i<=cnt;i++)
		if(!vis[i]) dfs(i,va[i]);
	for(int i=1;i<=n;i++)
		if(va[scc[i]]=='U') ++ans;
	printf("%d\n",ans);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1,x,y;i<=m;i++){
			scanf("%s",&s);
			if(s[0]=='+'||s[0]=='-'){
				scanf("%d%d",&x,&y);
				a[i]={s[0],x,y};
			}
			else{
				scanf("%d",&x);
				a[i]={s[0],x,0};
			}
		}
		if(c>=3&&c<=4) st2();
		else st4();
	}
	return 0;
}
/*
8 1
3 3
- 2 1
- 3 2
- 1 3
*/
