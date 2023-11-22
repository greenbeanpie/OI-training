#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to,nt,val;
}a[400005];
int flag[400005];
int val[400005],nxt[400005],depth[400005],num[400005];
int n,i,j,k,m,x,useless,ans=0,cnt=0,t,y;
char ch;
bool vis[400005],flag1[400005];
void pu(int x){
	ans++;
	vis[x]=true;
	for(int i=nxt[x];i;i=a[i].nt)
	  if(vis[a[i].to]==false) pu(a[i].to);
}
void dfs(int x){
	//printf("%d ",x);
	flag1[x]=vis[x]=true;
	for(int i=nxt[x];i;i=a[i].nt){
		if(flag1[a[i].to]==true){
			//printf("%d %d %d %d %d\n",x,a[i].to,num[x],num[a[i].to],a[i].val);
			if(((num[a[i].to]^num[x])^a[i].val)==1){
				val[a[i].to]=n+2;
			}
		}
		else if(vis[a[i].to]==true) continue;
		else{
			depth[a[i].to]=depth[x]+1;
			num[a[i].to]=num[x]^a[i].val;
			dfs(a[i].to);
		}
	}
}
void cl(int x){
	flag1[x]=false;
	for(int i=nxt[x];i;i=a[i].nt)
	  if(flag1[a[i].to]==true) cl(a[i].to);
}
void add(int x,int y,int z){
	a[++cnt].to=y;a[cnt].nt=nxt[x];nxt[x]=cnt;a[cnt].val=z;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&useless,&t);
	while(t--){
		//printf("%d ",t);
		ans=0;cnt=0;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			val[i]=i;
			num[i]=0;
			flag[i]=0;
			depth[i]=0;
			nxt[i]=0;
			vis[i]=false;flag1[i]=false;
		}
		for(i=1;i<=m;i++){
			cin>>ch;
			if(ch=='U' || ch=='T' || ch=='F'){
				scanf("%d",&x);
				if(ch=='U') val[x]=n+2;
				else val[x]=n+1;
				flag[x]=0;
				continue;
			}
			else{
				scanf("%d%d",&x,&y);
				val[x]=val[y];
				if(ch=='+') flag[x]=flag[y];
				else flag[x]=flag[y]^1;
			}
		}
		for(i=1;i<=n;i++)
		  if(val[i]<=n) add(val[i],i,flag[i]);
		//for(i=1;i<=n;i++)
		  //printf("%d %d\n",val[i],flag[i]);
		for(i=1;i<=n;i++)
		  if(vis[i]==false){
		  	num[i]=0;
		  	depth[i]=0;
		  	dfs(i);
		  	cl(i);
		  }
		for(i=1;i<=n;i++)
		  vis[i]=false;
		for(i=1;i<=n;i++)
		  if(vis[i]==false && val[i]==n+2){
		  	pu(i);
		  }
		  
		printf("%d\n",ans);
	}
	return 0;
}
