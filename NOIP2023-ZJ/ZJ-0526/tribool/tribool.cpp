#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
const int MAXN=1e5+5;
int c,t,n,m,tnt,now[MAXN],fa[MAXN],gen[MAXN];
struct edge{
	int op,u,v,t;
}a[MAXN];
int find(int x){
	return fa[x]==x ? x : fa[x]=find(fa[x]); 
}
void merage(int x,int y,int op){
	int fx=find(x),fy=find(y);
	if(fx==fy){
		gen[fx]*=op;
		if(gen[fx]==-1){
			for(int i=1;i<=n;i++){
				if(fa[i]==fx){
					now[i]=0;
					fa[i]=i;
				}
			}
		}
		return ;
	}
	fa[fy]=fx;
	gen[fx]*=gen[fy]*op;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&m); tnt=1;
		now[n+1]=1; now[n+2]=-1; now[n+3]=0;
		for(int i=1;i<=n;i++){now[i]=2; fa[i]=i; gen[i]=1;}
		for(int i=1;i<=m;i++){
			char c;
			cin>>c;
			if(c=='T'||c=='F'||c=='U'){
				a[i].op=1;
				if(c=='T')a[i].u=n+1;
				else if(c=='F')a[i].u=n+2;
				else a[i].u=n+3;
				scanf("%d",&a[i].v);
			}else {
				if(c=='+')a[i].op=1;
				else a[i].op=-1;
				scanf("%d%d",&a[i].u,&a[i].v);
			}
		}
		int ans=0;
		for(int i=1;i<=m;i++){
			int op=a[i].op,u=a[i].u,v=a[i].v;
			if(op==1){
				if(now[u]==2)merage(u,v,1);
				else {
					now[v]=now[u];
					fa[v]=v; 
					gen[v]=1;
				}
			}else {
				if(now[u]==2)merage(u,v,-1);
				else {
					now[v]=now[u]*-1;
					fa[v]=v; 
					gen[v]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			//cout<<find(i)<<" "<<now[find(i)]<<endl;
			if(now[find(i)]==0)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}