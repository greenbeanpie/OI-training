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
int A[N],B[N],C[N];
int main(){
	freopen("expand.in","w",stdout);
	int c=0,n=5e5,m=5e5,q=60,W=1e9+1,k=1e4;printf("%d %d %d %d\n",c,n,m,q);
	for(int i=1;i<=n;i++) printf("%d ",C[i]=R(W));printf("\n");
	for(int i=1;i<=m;i++) printf("%d ",C[i]-1);printf("\n");
	while(q--){
		printf("%d %d\n",k,k);
		iota(A+1,A+n+1,1);
		shuffle(A+1,A+n+1,rnd);
		for(int i=1;i<=k;i++) printf("%d %d\n",A[i],C[A[i]]=R(W));
		for(int i=1;i<=k;i++) printf("%d %d\n",A[i],C[A[i]]-1);
	}
}