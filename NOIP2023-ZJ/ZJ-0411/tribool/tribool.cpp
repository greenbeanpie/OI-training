#include<bits/stdc++.h>
using namespace std;
inline bool _u(char x){return x>='0'&&x<='9';}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	for(;!_u(ch);ch=='-'&&(f=-1),ch=getchar());
	for(;_u(ch);x=x*10+(ch^48),ch=getchar());
	return x*f;
}
inline void write(int num,bool flag=0){
	static int st[39],tp=0;
	num<0&&(putchar('-'),num=-num);
	do st[++tp]=num%10;while(num/=10);
	while(tp)putchar(st[tp--]|48);
	putchar(flag?'\n':' ');
	return;
}
template<typename...Args>
inline void write(int t,Args...args){
	return write(t),write(args...);
}
const int N=1e5+10;
inline int change(int x){
	if(x<=1)return x^1;
	return x;
}
tuple<int,int,int>q[N];
int n,m;
int c,t;
char op[10];
namespace pts20{
	short b[N],a[N];

	int check(){
		memcpy(b+1,a+1,n*sizeof(short));
		for(int i=1,op,x,y;i<=m;++i){
			tie(op,x,y)=q[i];
			if(op==1) b[x]=y;
				else if(op==2) b[x]=b[y];
				else if(op==3) b[x]=change(b[y]);
		}
		int sum=0;
		for(int i=1;i<=n;++i){
			if(a[i]!=b[i])return n+1;
			else sum+=(b[i]==2);
		}
		if(sum==0)
			for(int i=1;i<=n;++i)write(a[i],i==n);
		return sum;
	}
	
	int dfs(int u){
		if(u==n+1) return check();
		int sum=n+1;
		for(int i=0;i<3;++i)
			a[u]=i,sum=min(sum,dfs(u+1));
		return sum;
	}
	
	inline void _main(){
		for(;t--;){
			n=read(),m=read();
			for(int i=1,x,y;i<=m;++i){
				scanf("%s",op);
				if(op[0]=='+'){
					x=read(),y=read();
					q[i]=make_tuple(2,x,y);
				}else if(op[0]=='-'){
					x=read(),y=read();
					q[i]=make_tuple(3,x,y);
				}else{
					x=read();
					int flag;
					if(op[0]=='F') flag=0;
					else if(op[0]=='T') flag=1;
					else if(op[0]=='U') flag=2;
					q[i]=make_tuple(1,x,flag);
				}
			}
			write(dfs(1),true);
		}
		return;
	}
	
}

namespace ptso20{
	short a[N];
	inline void _main(){
		for(;t--;){
			n=read(),m=read();
			for(int i=1,x,y;i<=m;++i){
				scanf("%s",op);
				x=read();
				if(op[0]=='U') a[x]=2;
				else a[x]=(op[0]=='T');
			}
			int cnt=0;
			for(int i=1;i<=n;++i)
				if(a[i]==2) ++cnt;
			write(cnt,true);
		}
		return;
	}
	
}

namespace pts100{
	const int M=N*4;
	struct edge{
		struct node{
			int to,nxt;
		}e[M<<2];
		int head[M],tot;
		inline void init(int n){
			tot=1;
			memset(head,0,(n+1)*sizeof(int));
		}
		inline void add(int u,int v){
			e[++tot]=<%v,head[u]%>,head[u]=tot;
		}
		inline node&operator[](int x){return e[x];}
	}e;
	int scc[M],dfn[M],low[M],cnt,tot;
	int st[M],tp;
	void tarjan(int u){
		dfn[u]=low[u]=++tot;
		st[++tp]=u;
		for(int i=e.head[u],to;i;i=e[i].nxt)
			if(!dfn[to=e[i].to]){
				tarjan(to),low[u]=min(low[u],low[to]);
			}else low[u]=min(low[u],dfn[to]);
		if(low[u]==dfn[u]){
			++cnt;
			for(;st[tp]!=u;) scc[st[tp--]]=cnt;
			scc[st[tp--]]=cnt;
		}
		return;
	}
	int lst[M];
	bool vis[M];
	void dfs(int u){
		vis[u]=true;
		for(int i=e.head[u],to;i;i=e[i].nxt)
			if(!vis[to=e[i].to]) dfs(to);
	}
	
	inline void init(int n){
		cnt=tot=0;
		e.init(n*2);
		memset(dfn+1,0,n*2*sizeof(int));
		memset(vis,0,sizeof vis);
		memset(lst,0,(n+1)*sizeof(int));
	}
	inline void _main(){
		for(;t--;){
			init(n=read()),m=read();
			for(int i=1,x,y;i<=m;++i){
				scanf("%s",op);
				x=read(),y=read();
				if(op[0]=='-') e.add(y,x+n),e.add(y+n,x);
				else e.add(y,x),e.add(y+n,x+n);
				lst[x]=y;
			}
			for(int i=1;i<=n;++i) e.add(i,i+n);
			for(int i=1;i<=n*2;++i) if(!dfn[i]) tarjan(i);
			for(int i=1;i<=n;++i)
				if(scc[i]==scc[i+n]&&!vis[i])dfs(i);
			int cnt=0;
			for(int i=1;i<=n;++i) if(vis[i])++cnt;
			write(cnt,true);
		}
	}
	
}


signed main(){
	freopen("tribool.in","r",stdin),freopen("tribool.out","w",stdout);
	c=read(),t=read();
	if(c<=2) pts20::_main(),exit(0);
	if(c<=4) ptso20::_main(),exit(0);
	pts100::_main();
	return (39-39);
}
/*
7 1
5 5
- 2 1
- 3 2
- 1 3
- 4 1
- 5 4
*/
