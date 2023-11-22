#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int c,t,n,m,ans,r[maxn][4],v[maxn],vis[maxn],rr[maxn];
char s[5];
int dfs(int x,int now){
	
	if(vis[x]==1||vis[x]==-1)return vis[x];
	if(v[x]!=0){
		if(v[x]==-x){vis[x]=-1;return -1;}
		if(v[x]==x){vis[x]=1;return 1;}
		if(rr[abs(v[x])]){
			if((now-rr[abs(v[x])]+(v[x]<0))&1)return vis[x]=-1;
			return vis[x]=1;
		}
		rr[x]=now;
		if(dfs(abs(v[x]),now+(v[x]<0))==1){rr[x]=0,vis[x]=1;return 1;}
		else{rr[x]=0,vis[x]=-1;return -1;}
	}
	if(!v[x]&&(!r[x][0]))return vis[x]=1;
	return vis[x]=-1;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)v[i]=i;
		for(int x,y,i=1;i<=m;i++){
			scanf("%s",s);
			scanf("%d",&x);
			if(s[0]=='+'){
				scanf("%d",&y);
				if(x==y)continue;
				v[x]=r[x][0]=r[x][1]=r[x][2]=0;
				if(!v[y])r[x][0]=r[y][0],r[x][1]=r[y][1],r[x][2]=r[y][2];
				else v[x]=v[y];
			}
			if(s[0]=='-'){
				scanf("%d",&y);
				if(x==y){v[x]=-v[y];continue;}
				v[x]=r[x][0]=r[x][1]=r[x][2]=0;
				if(!v[y])r[x][0]=r[y][0],r[x][1]=r[y][2],r[x][2]=r[y][1];
				else v[x]=-v[y];
			}
			if(s[0]=='T'){
				v[x]=0,r[x][0]=r[x][2]=0,r[x][1]=1;
			}
			if(s[0]=='F'){
				v[x]=0,r[x][0]=r[x][1]=0,r[x][2]=1;
			}
			if(s[0]=='U'){
				v[x]=0,r[x][1]=r[x][2]=0,r[x][0]=1;
			}
		}
		for(int i=1;i<=n;i++)
			if(!vis[i])dfs(i,1);
		for(int i=1;i<=n;i++)
			if(vis[i]==-1)ans++;
		printf("%d\n",ans);
		ans=0;
		for(int i=1;i<=n;i++)rr[i]=vis[i]=r[i][0]=r[i][1]=r[i][2]=v[i]=0;
	}
	return 0;
}
