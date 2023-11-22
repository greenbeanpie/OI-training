#include<bits/stdc++.h>
#define Gc() getchar()
#define fi first
#define se second
#define LB lower_bound
#define UB upper_bound
#define Me(x,y) memset(x,y,sizeof x)
#define Mc(x,y) memcpy(x,y,sizeof x)
#define R(n) (rnd()%(n)+1)
using namespace std;using ll=long long;using LL=__int128;
const int N=5e5+5,M=N*4+5,K=1e7+5;mt19937 rnd(time(0));

void read(int &x){
	char c=Gc();x=0;
	while(c<'0'||c>'9') c=Gc();
	while(c>='0'&&c<='9') x=x*10+c-48,c=Gc();
}

int c,n,m,q,A[N],B[N],C[N],D[N];
int S1[N],S2[N],S3[N],S4[N];
int MIN(int x,int y,int *A){return A[x]<A[y]?x:y;}
int MAX(int x,int y,int *A){return A[x]>A[y]?x:y;}
int st[N],sh;
int calc(int *A,int n,int *B,int m){
	int i,j;
	S1[1]=1;for(i=2;i<=n;i++) S1[i]=MIN(S1[i-1],i,A);
	int R=1;
	for(int i=1;i<=m;i++){
		while(R<=n&&B[i]>A[R]) R++;
		if(R==1||B[i]<=A[S1[R-1]]) return 0;
	}
	if(R!=n+1) return 0;
	S2[n]=n;for(int i=n-1;i;i--) S2[i]=MAX(S2[i+1],i,A);
	S3[m]=S4[m]=m;for(int i=m-1;i;i--) S3[i]=MAX(S3[i+1],i,B),S4[i]=MIN(S4[i+1],i,B);
	sh=0;for(i=1;i<=n;i++){
		while(sh&&A[st[sh]]>A[i]) sh--;
		st[++sh]=i;
	}
	int pt=1;
	R=1;
	for(int i=1;R<=m;i++){
		if(i&1){
			R=S3[R];
			if(st[pt-1]^n&&B[R]<=A[S2[st[pt-1]+1]]) return 0; 
			if(R==m) return 1;
		}else{
			R=S4[R];
			while(pt<=sh&&A[st[pt]]<B[R]) pt++;
			if(R==m) return pt>sh;
		}
		R++;
	}
	return 1;
}
int main(){
	freopen("expand.in","r",stdin);freopen("expand.out","w",stdout);
	int i,j;scanf("%d%d%d%d",&c,&n,&m,&q);
	for(i=1;i<=n;i++) read(A[i]);
	for(i=1;i<=m;i++) read(B[i]);
	printf("%d",A[1]<B[1]?calc(A,n,B,m):calc(B,m,A,n));
	while(q--){
		copy(A+1,A+n+1,C+1);
		copy(B+1,B+m+1,D+1);
		int k1,k2;read(k1);read(k2);
		while(k1--) {
			int x,y;read(x);read(y);C[x]=y;
		}
		while(k2--) {
			int x,y;read(x);read(y);D[x]=y;
		}
		printf("%d",C[1]<D[1]?calc(C,n,D,m):calc(D,m,C,n));
	}
	printf("\n");
	cerr<<clock()*1.0/CLOCKS_PER_SEC<<'\n';
}