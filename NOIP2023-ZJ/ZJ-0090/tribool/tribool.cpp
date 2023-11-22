#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int w=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) w=w*10+ch-'0',ch=getchar();
	return w;
}
inline char getop(){
	char ch=getchar();
	while(ch!='T'&&ch!='U'&&ch!='F'&&ch!='-'&&ch!='+') ch=getchar();
	return ch;
}
int t,c;
int n,m;
int s[100015],w[100015],vis[100015],sunzh[100015],sz[100015];
vector<int> tr[100015],val[100015];
int flag;
int findsz(int x,int col){
	vis[x]=1;
	sz[x]=1;
	for(int i=0;i<tr[x].size();i++){
		if(!vis[tr[x][i]]){
			sz[x]+=findsz(tr[x][i],col^(val[x][i]));
		}else{
			flag=(col^(val[x][i]));
		}
	}
	return sz[x];
}
int findcir(int x){
	while(!sunzh[x]){
		sunzh[x]=1;
		x=s[x];
	}
	return x;
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read(),m=read();
		for(int i=0;i<=n+2;i++) s[i]=i,w[i]=0,tr[i].clear(),val[i].clear(),vis[i]=sz[i]=0,sunzh[i]=0;
		for(int i=1;i<=m;i++){
			char op=getop();
			if(op=='T'){
				int id=read();
				s[id]=-1;w[id]=0;
			}
			if(op=='F'){
				int id=read();
				s[id]=-2;w[id]=0;
			}
			if(op=='U'){
				int id=read();
				s[id]=0;w[id]=0;
			}
			if(op=='+'){
				int u=read(),v=read();
				s[u]=s[v];
				w[u]=w[v];
			}
			if(op=='-'){
				int u=read(),v=read();
				s[u]=s[v];
				w[u]=w[v]^1;
				if(s[u]<=0) w[u]=0,s[u]=(s[u]==0?0:-3-s[u]);
			}
		}
		for(int i=1;i<=n;i++) if(s[i]==-1) s[i]=n+1;
		for(int i=1;i<=n;i++) if(s[i]==-2) s[i]=n+2;
		for(int i=1;i<=n;i++) tr[s[i]].push_back(i),val[s[i]].push_back(w[i]);
		int ans=findsz(0,0)-1;findsz(n+1,0);findsz(n+2,0);
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			int x=findcir(i);
//			printf("%d %d\n",i,x);
			int sz=findsz(x,0);
//			printf("%d\n",sz);
			if(flag) ans+=sz;
		}
//		for(int i=1;i<=n;i++) printf("%d %d\n",s[i],w[i]);
		printf("%d\n",ans);
	}
	return 0;
}