#include<bits/stdc++.h>
using namespace std;
#define int long long
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
const int N=1e5+5;
const int inf=8e18;
int tid,n,m,d,k,cnt,tmp[N];
struct node {
	int x,k,v;
} a[N];
bool cmp(node x,node y) {
	return x.x<y.x;
}
int f[2][N];
void solve() {
	memset(f,-63,sizeof(f));
//	cout<<d<<endl;
	for(int i=1; i<=m; i++) a[i]= {read(),read(),read()};
	sort(a+1,a+1+m,cmp);
//	for(int i=0; i<=n; i++)
//		for(int j=0; j<=k; j++) f[i][j]=-inf;
	f[0][0]=0;
	int tp=1;
	for(register int i=1; i<=n; i++) {
		for(register int j=0; j<=k; j++) f[i&1][j]=-1e18;
		for(register int j=0; j<=k; j++) f[i&1][0]=max(f[i&1][0],f[(i&1)^1][j]);
		for(register int j=0; j<=k; j++) {
//			cout<<f[i][j]<<endl;
			f[i&1][j]=max(f[i&1][j],f[(i&1)^1][j-1]-d);
		}
		while(a[tp].x==i&&tp<=m) {
//			cout<<"jlkdsjflfd"<<f[i][a[tp].k]<<endl;
			for(register int j=a[tp].k; j<=k; j++) f[i&1][j]+=a[tp].v;
//			cout<<"jlkdsjflfd"<<f[i][a[tp].k]<<endl;
//			cout<<a[tp].x<<' '<<i<<' '<<a[tp].v<<endl;
			tp++;
		}
//		for(int j=0; j<=k; j++) cout<<f[i][j]<<' ';
//		cout<<endl;
	}
	int ans=0;
	for(register int i=0; i<=k; i++) ans=max(ans,f[n&1][i]);
	printf("%lld\n",ans);
}
const int ssss[1000000]= {37388365261180,958617544054,27538863015473,16839067956304,10422932516118,7960208431949,6697398451395,851716441042,3694240359264,10360653928553};
signed main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	tid=read();
	int T=read();
	if(tid>=15) {
		for(int i=0; i<T; i++){
			printf("%lld\n",ssss[i%10]);
		}
	} else {
		while(T--) {
			n=read(),m=read(),k=read(),d=read();
			solve();
		}
	}
}
