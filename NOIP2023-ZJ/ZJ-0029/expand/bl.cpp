#include<bits/stdc++.h>
#define fi first
#define se second
#define LB lower_bound
#define UB upper_bound
#define Me(x,y) memset(x,y,sizeof x)
#define Mc(x,y) memcpy(x,y,sizeof x)
#define R(n) (rnd()%(n)+1)
using namespace std;using ll=long long;using LL=__int128;
const int N=5e5+5,M=N*4+5,K=1e7+5;mt19937 rnd(time(0));
int c,n,m,q,A[N],B[N],C[N],D[N];
int st[N],sh;
int calc(int *A,int n,int *B,int m){
	sh=0;
	for(int i=1;i<=m;i++){
		while(st[sh]^n&&B[i]>A[st[sh]+1]){
			int x=st[sh]+1;while(sh&&A[st[sh]]>=A[x]) sh--;
			st[++sh]=x;
		}
		while(sh&&B[i]<=A[st[sh]]) sh--;
		if(!sh) return 0;
	}
	return st[sh]==n;
}
int main(){
	freopen("expand.in","r",stdin);freopen("expand.out","w",stdout);
	int i,j;scanf("%d%d%d%d",&c,&n,&m,&q);
	for(i=1;i<=n;i++) scanf("%d",&A[i]);
	for(i=1;i<=m;i++) scanf("%d",&B[i]);
	printf("%d",A[1]<B[1]?calc(A,n,B,m):calc(B,m,A,n));
	while(q--){
		copy(A+1,A+n+1,C+1);
		copy(B+1,B+m+1,D+1);
		int k1,k2;scanf("%d%d",&k1,&k2);
		while(k1--) {
			int x,y;scanf("%d%d",&x,&y);C[x]=y;
		}
		while(k2--) {
			int x,y;scanf("%d%d",&x,&y);D[x]=y;
		}
		printf("%d",C[1]<D[1]?calc(C,n,D,m):calc(D,m,C,n));
	}
	printf("\n");
	cerr<<clock()*1.0/CLOCKS_PER_SEC<<'\n';
}