#include<bits/stdc++.h>
#define fi first
#define se second
#define LB lower_bound
#define UB upper_bound
#define Me(x,y) memset(x,y,sizeof x)
#define Mc(x,y) memcpy(x,y,sizeof x)
#define R(n) (rnd()%(n)+1)
using namespace std;using ll=long long;using LL=__int128;
const int N=2e5+5,M=N*4+5,K=1e7+5;mt19937 rnd(time(0));
int n,m,k,fa[N*2];
int op[N],val[N];
int GF(int x){return fa[x]^x?fa[x]=GF(fa[x]):x;}
void merge(int x,int y){
	fa[GF(x)]=GF(y);
}
void Solve(){
	int i,j;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) op[i]=1,val[i]=i;
	while(m--){
		char c;c=getchar();
		while(c^'+'&&c^'-'&&c^'T'&&c^'F'&&c^'U') c=getchar();
		int x,y;scanf("%d",&x);
		if(c=='T') {
			op[x]=-1;val[x]=1;
		}else if(c=='F'){
			op[x]=-1;val[x]=-1;
		}else if(c=='U'){
			op[x]=-1;val[x]=0;
		}else if(c=='+'){
			scanf("%d",&y);
			op[x]=op[y];val[x]=val[y];
		}else{
			scanf("%d",&y);
			op[x]=op[y];val[x]=-val[y];
		}
	}
	iota(fa+1,fa+2*n+4,1);
	int tr=2*n+1,fl=2*n+2,un=2*n+3;
	for(i=1;i<=n;i++){
		if(op[i]==-1) {
			if(val[i]==1) merge(i,tr),merge(i+n,fl);
			else if(val[i]==0) merge(i,un),merge(i+n,un);
			else merge(i,fl),merge(i+n,tr);
		}else{
			if(val[i]>0) merge(i,val[i]),merge(i+n,val[i]+n);
			else merge(i,-val[i]+n),merge(i+n,-val[i]);
		}
	}
	for(i=1;i<=n;i++) if(GF(i)==GF(i+n)) merge(i,un),merge(i+n,un);
	int cnt=0;
	for(i=1;i<=n;i++) if(GF(i)==GF(un)) cnt++;
	printf("%d\n",cnt);
}
int main(){
	freopen("tribool.in","r",stdin);freopen("tribool.out","w",stdout);
	int c,t;scanf("%d%d",&c,&t);
	while(t--) Solve();
	cerr<<clock()*1.0/CLOCKS_PER_SEC<<'\n';
}