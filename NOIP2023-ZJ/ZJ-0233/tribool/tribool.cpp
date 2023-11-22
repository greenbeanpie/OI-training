#include <bits/stdc++.h>
using namespace std;
const int N = 4e5+20;
int f[N],a[N];
int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void uni(int x,int y) {
	x=find(x),y=find(y);
	if(x==y) return;
	f[x]=y;
}
bool check(int x,int y) {
	return find(x)==find(y);
}
void get() {
	int n,m,i;
	char op;
	int x,y;
	cin>>n>>m;
	//2*i (i) 2*i+1 (not i)    2*n+2 T   2*n+3 F   2*n+4/+5 U
	int _t=2*n+2,_f=2*n+3,_u=2*n+4;
	for(i=1;i<=n;i++) a[i]=2*i;
	for(i=0;i<=2*n+6;i++) f[i]=i;
	for(i=1;i<=m;i++) {
		cin>>op>>x;
		if(op=='T') {
			a[x]=2*n+2;
		} else if(op=='F') {
			a[x]=2*n+3;
		} else if(op=='U') {
			a[x]=2*n+4;
		} else if(op=='+') {
			cin>>y; a[x]=a[y];
		} else if(op=='-') {
			cin>>y; a[x]=(a[y]^1);
		} else assert(0);
	}
	for(i=1;i<=n;i++) uni(2*i,a[i]),uni(2*i+1,(a[i]^1));
	uni(2*n+5,2*n+4);
	for(i=1;i<=n;i++) {
		if(check(2*i,_t)||check(2*i+1,_t)) continue;
		if(check(2*i,_f)||check(2*i+1,_t)) continue;
		if(check(2*i,_u)||check(2*i+1,_t)) continue;
		if(check(2*i,2*i+1)) {
			uni(2*i,_u),uni(2*i+1,_u);
		}
	} int ans=0;
	for(i=1;i<=n;i++) if(check(2*i,_u)||check(2*i+1,_u)) ans++;
	cout<<ans<<endl;
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--) get();
	return 0;
}