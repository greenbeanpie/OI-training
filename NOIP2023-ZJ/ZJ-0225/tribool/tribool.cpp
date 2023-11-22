#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
using LL=long long;
const int N=2e5+9;
int fa[N],n,m,x[N]; //UTF
inline int rever(int u) {
	if(u==2*n+2) return 2*n+3;
	if(u==2*n+3) return 2*n+2;
	if(u==2*n+1) return u;
	if(u>n) return u-n;
	return u+n;
}
int find(int u) {
	if(fa[u]==u) return u;
	return fa[u]=find(fa[u]);
}
void merge(int a,int b) {
	a=find(a),b=find(b);
	fa[a]=b;
}
char getc() {
	char ch=getchar();
	while(ch!='+' && ch!='-' && ch!='U' && ch!='T' && ch!='F')
		ch=getchar();
	return ch;
}
bool is[N];
void solve() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=2*n+3; i++) fa[i]=i,x[i]=i,is[i]=0;
	char op;
	int i,j;
	for(int o=1; o<=m; o++) {
		op=getc();
		if(op=='+') {
			scanf("%d%d",&i,&j);
			x[i]=x[j];
		} else if(op=='-') {
			scanf("%d%d",&i,&j);
			x[i]=rever(x[j]);
		} else {
			scanf("%d",&i);
			if(op=='U') x[i]=2*n+1;
			if(op=='T') x[i]=2*n+2;
			if(op=='F') x[i]=2*n+3;
		}
	}
	for(int i=1; i<=n*2+3; i++)
		merge(i,x[i]),merge(rever(i),rever(x[i]));
	int ans=0;
	for(int i=1; i<=n; i++) {
		if(find(i)==find(i+n) || find(i)==find(2*n+1)) is[find(i)]=1;
	}
	for(int i=1; i<=n; i++) {
		if(is[find(i)]) ++ans;
	}
	printf("%d\n",ans);
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int IDX,_;
	scanf("%d%d",&IDX,&_);
	while(_--)
		solve();
	return 0;
}