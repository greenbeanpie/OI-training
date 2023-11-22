#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,m;
int frm[210000],col[210000],tot,hed[210000];
int fa[210000],colorr[210000];
bool vis[210000],visr[210000];
vector<int>a[210000];
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
void conect(int x,int y){
	int fx=getfa(x);
	int fy=getfa(y);
	if(fx!=fy){
		fa[fx]=fy;
		if(colorr[fy]>10)colorr[fy]=colorr[fx];
	}
}
void dfs(int x,int nowCol){
	colorr[x]=nowCol;
	vis[x]=true;
	for(int i=0;i<a[x].size();i++){
		int y=a[x][i];
		if(vis[y])continue;
		dfs(y,nowCol*-1);
	}
}
bool dfsring(int st,int x,int step){
	visr[x]=true;
	bool flag=false;
	for(int i=0;i<a[x].size();i++){
		int y=a[x][i];
		if(y==st&&step%2==0)flag=true;
		if(visr[y])continue;
		flag=flag||dfsring(st,y,step+1);
	}
	visr[x]=false;
	return flag;
}
void dfsu(int x){
	colorr[x]=0;
	vis[x]=true;
	for(int i=0;i<a[x].size();i++){
		int y=a[x][i];
		if(vis[y])continue;
		dfsu(y);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		tot=0;
		memset(frm,0,sizeof(frm));
		memset(col,0,sizeof(col));
		memset(hed,0,sizeof(hed));
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++){
			tot++;
			hed[i]=tot;
			frm[i]=i;
			col[i]=1;
			fa[i]=i;
			colorr[i]=1e8;
			a[i].clear();
		}
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch!='+'&&ch!='-'&&ch!='T'&&ch!='F'&&ch!='U'){
				ch=getchar();
			}
			int x,y;
			scanf("%d",&x);
			tot++;
			if(ch=='T'||ch=='F'||ch=='U'){
				frm[tot]=0;
				if(ch=='T')col[tot]=1;
				if(ch=='F')col[tot]=-1;
				if(ch=='U')col[tot]=0;
			}
			else{
				scanf("%d",&y);
				y=hed[y];
				frm[tot]=frm[y];
				if(ch=='+')col[tot]=col[y]*1;
				if(ch=='-')col[tot]=col[y]*-1;
			}
			hed[x]=tot;
		}
		for(int i=1;i<=n;i++){
			if(frm[hed[i]]==0){
				colorr[i]=col[hed[i]];
			}
		}
		for(int i=1;i<=n;i++){
			if(frm[hed[i]]&&col[hed[i]]==1){
				conect(i,frm[hed[i]]);
			}
		}
		for(int i=1;i<=n;i++){
			if(frm[hed[i]]&&col[hed[i]]==-1){
				int x=getfa(i);
				int y=getfa(frm[hed[i]]);
				a[x].push_back(y);
				a[y].push_back(x);
			}
		}		
		for(int i=1;i<=n;i++){
			int x=getfa(i);
			if(!vis[x]&&colorr[x]<=10){
				dfs(x,colorr[x]);
			}
		}
		for(int i=1;i<=n;i++){
			int x=getfa(i);
			if(!vis[x]){
				if(dfsring(x,x,0))dfsu(x);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(colorr[getfa(i)]==0)ans++;
		}
		printf("%d\n",ans);
	}
}
