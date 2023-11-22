#include<bits/stdc++.h>
#define xrain depression
#define maxn 100005
#define inf 0x3fff
using namespace std;

int id, t;
int n, m, k, d;
int y, z;
int ans;
struct node{
	int l, r, w;
}a[maxn];

//inline void read(int &x){
//	x=0; bool sgn; char s=getchar();
//	while(!dagisit(s)) sgn|=s=='-', s=getchar();
//	while(dagisit(s)) x=(x<<1)+(x<<3)+(s^48), s=getchar();
//	sgn?x=-x:x;
//}

bool cmp(node x, node y){
	return x.r<y.r;
}

inline void solve(){
	scanf("%d%d%d%d", &n, &m, &k, &d);
	for(int i=1; i<=m; i++) scanf("%d%d%d", &a[i].r, &y, &z), a[i].l=a[i].r-y, a[i].w-=y*d;
	sort(a+1, a+m+1, cmp);
	
	ans=a[1].w;
	for(int i=2; i<=m; i++){
		if(a[i].r-a[i].l>k) continue;
		if(a[i].l<a[i-1].r) ans=max(ans, ans-a[i-1].w-a[i].w);
	}
	
	printf("%d\n", ans);
}

signed main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);

	scanf("%d%d", &id, &t);
	while(t--) solve();

	return 0;
}
