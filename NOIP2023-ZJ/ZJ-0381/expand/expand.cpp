#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
const int N=5e5+5;
int x[N];
int y[N];
int a[N];
int b[N];
int l[N];
int r[N];
bool f[2005][2005];
bool FLAG;
inline bool cmp(int a,int b) {
	/*
	if(FLAG){
		if(a>b) return true;
		return false;
	}
	if(a<b) return true;
	return false;
	*/
	if(FLAG) return a>b ? true:false;
	return a<b? true:false;
}
inline read() {
	char c=getchar();
	int ans=0;
	while(c<'0'||c>'9') {
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		ans=ans*10+(c-'0');
		c=getchar();
	}
	return ans;
}
inline void print() {
	for(int i=1; i<=n; ++i) {
		cout<<l[i]<<"# ";
	}
	cout<<"\n";
	for(int i=1; i<=n; ++i) {
		cout<<r[i]<<"# ";
	}
}
int main() {

	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1; i<=n; ++i) scanf("%d",&x[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&y[i]);
	for(int var=0; var<=q; ++var) {
//		cout<<q<<" ";
		for(register int i=1; i<=n; ++i) a[i]=x[i],l[i]=r[i]=0;
		for(register int i=1; i<=m; ++i) b[i]=y[i];
		if(var!=0) {
			int kx,ky;
			scanf("%d %d",&kx,&ky);
			for(register int i=1; i<=kx; ++i) {
				int px,vx;
				scanf("%d %d",&px,&vx);
				a[px]=vx;
			}
			for(register int i=1; i<=ky; ++i) {
				int py,vy;
				scanf("%d %d",&py,&vy);
				b[py]=vy;
			}
		}
//		for(int i=1;i<=n;++i) cout<<b[i]<<" ";
//		cout<<"\n";
		if(a[1]==b[1]) {
			cout<<'0';
			continue;
		}
		if(a[1]>b[1]) FLAG=1;
		else FLAG=0;
		l[0]=1;
		r[0]=1;
		/*
		bool fail=0;
		for(int i=1; i<=n; ++i) {
		//			cout<<i<<" ";
			int j=l[i-1];
			while(j<=m) {
				if(cmp(a[i],b[j])) break;
				++j;
			}
			if(j>m||j>r[i-1]) {
				fail=1;
				break;
			}
			l[i]=j;
			while(j<=m) {
				if(!cmp(a[i],b[j])) break;
				++j;
			}
			r[i]=j-1;
		}
		print();
		if(fail) cout<<'0';
		else cout<<'1';
		*/
		/*
		int now=1;
		while(now<=m) {
			if(!cmp(a[1],b[now])) break;
			++now;
		}
		--now;
		for(int i=2; i<=n; ++i) {
			if(a[i]==a[i-1]) continue;
			if(cmp(a[i],a[i-1])) {
				while(now<=m) {
					if(!cmp(a[i],b[now])) break;
					++now;
				}
				--now;
			} else {
						
			}
		}*/
		f[1][1]=1;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(!cmp(a[i],b[j])) continue;
				if(f[i-1][j]||f[i][j-1]) f[i][j]=1;
			}
		}
		cout<<f[n][m];
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				f[i][j]=0;
			}
		}
	}
	return 0;
}
/*

*/
