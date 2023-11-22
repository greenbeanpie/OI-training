#include <bits/stdc++.h>
using namespace std;
int t,n,m,cnt,a[1000005],opt[1000005],ans,size[1000005],lst[1000005];
int lnk[1000005],son[2000005],nxt[2000005],w[2000005],fa[1000005];
bool vis[1000005],s[1000005];
struct node{
	char key;
	int pos,val;
}c[1000005],que[400005];
int read(){
	int ret=0;bool f=true;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=false;ch=getchar();}
	while (isdigit(ch)) ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return f?ret:-ret;
}
void add_e(int x,int y,int z){w[++cnt]=z,son[cnt]=y,nxt[cnt]=lnk[x],lnk[x]=cnt;}
int Get(char x){return x=='T'?1:(x=='F'?-1:0);}
int Fa(int x){return x==fa[x]?x:fa[x]=Fa(fa[x]);}
bool check(int u,int val){
	if (opt[u]!=0) return opt[u]==val;
	bool ret=1;opt[u]=val;
	for (int j=lnk[u];j;j=nxt[j]) ret=check(son[j],val*w[j])&ret;
	return ret;
}
int work(){int ret=0;
	for (int j=m;j;j--){
		int u=c[j].pos,v=c[j].val;
		if (c[j].key=='T'||c[j].key=='F'||c[j].key=='U'){
			if (vis[u]&&!s[abs(a[u])]){s[abs(a[u])]=1,vis[u]=0;
				opt[abs(a[u])]=a[u]<0?-Get(c[j].key):Get(c[j].key);
			}
		}else{
			if (v==u){
				if (vis[u]){
					if (lst[v]==j){
						if (c[j].key=='+'){
							add_e(abs(a[u]),abs(v),a[u]*v<0?-1:1);
							add_e(abs(v),abs(a[u]),a[u]*v<0?-1:1);
						}else{
							add_e(abs(a[u]),abs(v),a[u]*v<0?1:-1);
							add_e(abs(v),abs(a[u]),a[u]*v<0?1:-1);
						}
					}else{
						if (c[j].key=='+') vis[v]=1,a[v]=a[u];
						else vis[v]=1,a[v]=-a[u];
					}
				}
			}else if (c[j].key=='+'){
				if (vis[u]){
					if (!vis[v]) vis[v]=1,a[v]=a[u];
					else{
						add_e(abs(a[u]),abs(a[v]),a[u]*a[v]<0?-1:1);
						add_e(abs(a[v]),abs(a[u]),a[u]*a[v]<0?-1:1);
					}
				}vis[u]=0;
			}else if (c[j].key=='-'){
				if (vis[u]){
					if (!vis[v]) vis[v]=1,a[v]=-a[u];
					else{
						add_e(abs(a[u]),abs(a[v]),a[u]*a[v]<0?1:-1);
						add_e(abs(a[v]),abs(a[u]),a[u]*a[v]<0?1:-1);
					}
				}vis[u]=0;
			}
		}if (lst[u]==j) vis[u]=1,a[u]=u;
	}
	for (int i=1;i<=n;i++)
	for (int j=lnk[i];j;j=nxt[j]) if (Fa(i)!=Fa(son[j])){
		int xo=fa[i],yo=fa[son[j]];
		size[xo]+=size[yo],fa[yo]=xo,s[xo]|=s[yo],opt[xo]=opt[xo]?opt[xo]:opt[yo];
	}
	for (int i=1;i<=n;i++) if (Fa(i)==i){
		if (s[i]) ret+=opt[i]?0:size[i];
		else ret+=check(i,1)?0:size[i];
	}return ret;
}
int main(){
	freopen ("tribool.in","r",stdin);
	freopen ("tribool.out","w",stdout);
	read(),t=read();
	while (t--){
		n=read(),m=read();
		char ch=getchar();
		for (int i=1;i<=n;i++)
			vis[i]=1,a[i]=i,s[i]=0,opt[i]=0,lnk[i]=0,fa[i]=i,size[i]=1,lst[i]=0;
		for (int i=1;i<=m;i++){
			while (ch!='-'&&ch!='+'&&ch!='T'&&ch!='F'&&ch!='U') ch=getchar();
			c[i].key=ch;
			if (c[i].key=='+'||c[i].key=='-') c[i].pos=read(),c[i].val=read();
			else c[i].pos=read();if (i<m) ch=getchar();
			if (lst[c[i].pos]==0) lst[c[i].pos]=i;
		}ans=n,cnt=0;
		printf ("%d\n",work());
	}return 0;
}