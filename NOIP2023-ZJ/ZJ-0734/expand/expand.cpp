#include<bits/stdc++.h>
#define xrain depression
#define maxn 50005
#define inf 0x3fff
using namespace std;

int id, n, m, q;
int x[maxn], y[maxn];
int k1, k2;

//inline void read(int &x){	
//	x=0; bool sgn; char s=getchar();
//	while(!dagist(s)) sgn|=s=='-', s=getchar();
//	while(dagist(s)) x=(x<<1)+(x<<3)+(s^48), s=getchar();
//	sgn?x=-x:x;
//}

inline void solve1(){
	int x1=-1, x2=-1, k;
	for(int i=1; i<=k1; i++) scanf("%d%d", &k, &x1);
	for(int i=1; i<=k2; i++) scanf("%d%d", &k, &x2);
	x1==-1?x1=x[1]:x1;
	x2==-1?x2=y[1]:x2;
	if(x1>x2) printf("1");
	else printf("0");
}

inline void solve2(){
	int x1=-1, x2=-1, x3=-1, x4=-1, k;
	for(int i=1; i<=k1; i++) scanf("%d", &k), k==1?scanf("%d", &x1):scanf("%d", &x2);
	for(int i=1; i<=k2; i++) scanf("%d", &k), k==1?scanf("%d", &x3):scanf("%d", &x4);
	x1==-1?x1=x[1]:x1;
	x2==-1?x2=x[2]:x2;
	x3==-1?x3=y[1]:x3;
	x4==-1?x4=y[2]:x4;
	if(x1>x3&&x2>x4) printf("1");
	else printf("0");
}

inline void solve(){
	int x1=-1, x2=-1, x3=-1, x4=-1, k;
	for(int i=1; i<=k1; i++) scanf("%d%d", &k, &x1);
	for(int i=1; i<=k2; i++) scanf("%d%d", &k, &x3);
}

signed main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);

	scanf("%d%d%d%d", &id, &n, &m, &q);
	for(int i(1); i<=n; i++) scanf("%d", &x[i]);
	for(int i(1); i<=m; i++) scanf("%d", &y[i]);
	scanf("%d%d", &k1, &k2);
	
	if(n==1&&m==1){ x[1]>y[1]?printf("1"):printf("0"); while(q--) solve1(); }
	else if(n==2&&m==2){ x[1]>y[1]&&x[2]>y[2]?printf("1"):printf("0"); while(q--) solve2(); }
	else{ x[1]>y[1]&&x[n]>y[m]?printf("1"):printf("0"); while(q--) solve(); }
	
	return 0;
}
