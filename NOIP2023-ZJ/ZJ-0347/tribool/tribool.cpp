#include<iostream>
#include<cstdio>
#define maxn 100050
using namespace std;
inline int read(){
	int res=0,neg=1; char ch=getchar(); while(!isdigit(ch)){if(ch=='-') neg=-1; ch=getchar();}
	while(isdigit(ch)){res=(res<<1)+(res<<3)+(ch-'0'); ch=getchar();} return res*neg;
}
int id,T,n,m,x,y,ans[maxn],num=0; char opt;
int typ[maxn],rev[maxn],vis[maxn]; bool cir[maxn];
struct edge{int to,nex,rev;}g[maxn]; int head[maxn],cnt=0;
void init(){for(int i=1;i<=n+5;i++) typ[i]=i,rev[i]=ans[i]=head[i]=vis[i]=cir[i]=0; num=cnt=0;}
void add(int from,int to,int rev){g[++cnt]=(edge){to,head[from],rev}; head[from]=cnt;}
void dfs(int p){
	for(int i=head[p];i;i=g[i].nex) if(!cir[g[i].to]){
		if(g[i].rev){if(ans[p]==n+3) ans[g[i].to]=n+3; else ans[g[i].to]=2*n+3-ans[p];}
		else ans[g[i].to]=ans[p]; dfs(g[i].to);
	}
}
int main(){
	freopen("tribool.in","r",stdin); freopen("tribool.out","w",stdout);
	id=read(); T=read(); while(T--){
		n=read(); m=read(); init(); while(m--){
			scanf("%c",&opt); while(opt!='+'&&opt!='-'&&opt!='T'&&opt!='F'&&opt!='U') scanf("%c",&opt);
			if(opt=='+'){
				x=read(); y=read(); // y -> x
				if(typ[y]>n) typ[x]=typ[y],rev[x]=0; else typ[x]=typ[y],rev[x]=rev[y];
			}else if(opt=='-'){
				x=read(); y=read(); // !y -> x
				if(typ[y]>n){
					if(typ[y]==n+1) typ[x]=n+2,rev[x]=0;
					else if(typ[y]==n+2) typ[x]=n+1,rev[x]=0; else typ[x]=n+3,rev[x]=0;
				}else typ[x]=typ[y],rev[x]=rev[y]^1;
			}else if(opt=='T'){x=read(); typ[x]=n+1; rev[x]=0;} // T -> x
			else if(opt=='F'){x=read(); typ[x]=n+2; rev[x]=0;}  // F -> x
			else if(opt=='U'){x=read(); typ[x]=n+3; rev[x]=0;}  // U -> x
		} for(int i=1;i<=n;i++){add(typ[i],i,rev[i]); if(typ[i]>n) ans[i]=typ[i];}
		for(int i=1;i<=n;i++) if(!vis[i]){
			int pos=i; while(!vis[pos]) vis[pos]=i,pos=typ[pos];
			if(vis[pos]==i) while(!cir[pos]) cir[pos]=1,pos=typ[pos];
		} for(int i=1;i<=n;i++) if(ans[i]>n) dfs(i);
		for(int i=1;i<=n;i++) if(cir[i]&&ans[i]<=n){
			int pos=typ[i],val=n+1; ans[i]=val; if(rev[i]) val=2*n+3-val;
			while(pos!=i){ans[pos]=val; if(rev[pos]) val=2*n+3-val; pos=typ[pos];}
			if(ans[i]!=val){ans[i]=n+3; pos=typ[pos]; while(pos!=i) ans[pos]=n+3,pos=typ[pos];}
			pos=typ[i]; dfs(i); while(pos!=i) dfs(pos),pos=typ[pos];
		} for(int i=1;i<=n;i++) if(ans[i]==n+3) num++; printf("%d\n",num);
	}
	return 0;
}
// Finished 10:07
