#include<bits/stdc++.h>
#define For(i,l,r) for(int i=l,i##end=r;i<=i##end;++i)
#define rFor(i,r,l) for(int i=r,i##end=l;i>=i##end;--i)
#define all(a) a.begin(),a.end()
using namespace std;
using ll=long long;
using pii=array<int,2>;
const int BS=1e8;
char buf[BS];
int read() {
	static char *p;
	if(!p) fread(buf,BS,1,stdin),p=buf;
	int x=0;
	while(!isdigit(*p)) ++p;
	while(isdigit(*p)) x=x*10+(*(p++)&15);
	return x;
}
const int N=5e5+10,INF=2e9;
int n,m,a[N],b[N],la[N],lb[N];
bool work(int n,int m,int *a,int *b) {
	if(a[1]==b[1]) return 0;
	if(a[1]>b[1]) swap(n,m),swap(a,b);
	if(a[n]>=b[m]) return 0;
	For(i,1,m) b[i]=-b[i];
	int p=min_element(a+1,a+n+1)-a,q=min_element(b+1,b+m+1)-b;
	auto solve=[&](int n,int m)->bool {
		int i=1,j=1,x=1,y=1;
		while(1) {
			if(j<n && a[j+1]+b[x]<0) {
				++j;
				if(a[j]<a[i]) i=j;
				continue;
			}
			if(y<m && b[y+1]+a[i]<0) {
				++y;
				if(b[y]<b[x]) x=y;
				continue;
			}
			break;
		}
		return j==n && y==m;
	};
	if(!solve(p,q)) return 0;
	reverse(a+1,a+n+1); reverse(b+1,b+m+1);
	if(!solve(n-p+1,m-q+1)) return 0;
	return 1;
}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	read(); n=read(); m=read(); int q=read();
	For(i,1,n) la[i]=read();
	For(i,1,m) lb[i]=read();
	memcpy(a,la,sizeof(a)); memcpy(b,lb,sizeof(b));
	cout<<work(n,m,a,b);
	while(q--) {
		int kx=read(),ky=read();
		memcpy(a,la,sizeof(a)); memcpy(b,lb,sizeof(b));
		while(kx--) {
			int p=read(),x=read();
			a[p]=x;
		}
		while(ky--) {
			int p=read(),x=read();
			b[p]=x;
		}
		cout<<work(n,m,a,b);
	}
}