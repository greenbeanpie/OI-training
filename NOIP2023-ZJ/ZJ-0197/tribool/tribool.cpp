#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int c,t,n,m,ans,s[maxn],fa[maxn],typ[maxn];
bool v[maxn];
inline int read(){
	int ret=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
int dfs(int u,int x,int top){
	if(v[u]){
		if(u==top){
			if(x==1) return 1;
			else return 0;
		}
		return s[u]*x;
	}v[u]=1;
	s[u]=dfs(fa[u],x*typ[u],top);
	return s[u]*x;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),m=read();ans=0;
		memset(v,0,sizeof v);
		for(int i=1;i<=n;i++) fa[i]=i,typ[i]=1,s[i]=3;
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch!='+'&&ch!='-'&&ch!='U'&&ch!='T'&&ch!='F') ch=getchar();
			if(ch=='-'||ch=='+'){
				int x=read(),y=read();
				if(s[y]!=3) s[x]=s[y];
				else{
					s[x]=3;fa[x]=fa[y];
					if(ch=='-') typ[x]=-typ[y];
					else typ[x]=typ[y];
				}
			}else{
				int x=read();
				if(ch=='T') s[x]=1;
				else if(ch=='F') s[x]=-1;
				else if(ch=='U') s[x]=0;
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i]!=3) v[i]=1;
		}
		for(int i=1;i<=n;i++){
			if(!v[i]) s[i]=dfs(i,1,i);
		}
		for(int i=1;i<=n;i++){
			if(s[i]==0) ans++;
		}printf("%d\n",ans);
	}
	return 0;
}