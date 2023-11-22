#include<bits/stdc++.h>
using namespace std;
#define fq(i,l,r) for(int i=(l);i<=(r);i++)
#define ffq(i,r,l) for(int i=(r);i>=(l);i--)
#define int long long
const int N=2e5+10,M=N*2+30;
int id,T,n,m,t[N],a,b,col[M],ans;
bool pd[M];
char u;
vector<int> c[M];
bool P(int x){
	if(x<=1&&x>=-1) return 1;
	return 0;
}
namespace F{
	int fa[M];
	void init(){fq(i,1,M-10) fa[i]=i;}
	inline int f(int x){
		assert(x>=0&&x<=M);
		return x==fa[x]?x:fa[x]=f(fa[x]);
	}
	inline void mg(int x,int y){
		int u=f(x),v=f(y);
		if(u!=v) fa[u]=v;	
	}
}
using namespace F;
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);	
	cin>>id>>T;
	while(T--){
		cin>>n>>m;++n;
		memset(col,-1,sizeof(col));
		memset(pd,0,sizeof(pd));
		fq(i,0,M-10) c[i].clear();
		init(),ans=0;
		fq(i,2,n) t[i]=i;
		fq(i,1,m){
			cin>>u>>a;a++;
			if(u=='+') cin>>b,++b,t[a]=t[b];
			else if(u=='-') cin>>b,++b,t[a]=-t[b];
			else if(u=='T') t[a]=1;
			else if(u=='F') t[a]=-1;
			else t[a]=0;
		}
		fq(i,2,n) if(!P(t[i])){
			mg(t[i]+N,i+N);
			mg(N-t[i],N-i);
		}
		fq(i,-n,n){
			if(P(i)) continue;
			c[f(i+N)].push_back(i+N);
		}
		fq(i,2,n) if(P(t[i])){
			int u=f(i+N);
			for(int v:c[u]) col[f(N-(v-N))]=-t[i];
			col[u]=t[i];
			col[f(N-(N-i))]=-t[i];
		}
		fq(i,2,n) if(col[f(i+N)]==-1){
			if(f(i+N)==f(N-i)) col[f(i+N)]=0;
		}
		fq(i,-n,n) if(col[i+N]==0){
			for(int u:c[i+N]) pd[u]=1;
		}
		fq(i,2,n) if(pd[i+N]==1||pd[N-i]==1) ans++;
		cout<<ans<<endl;
	}
	return 0;
}