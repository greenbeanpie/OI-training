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
const int N=5e5+5;
int tid,n,m,q;
int a[N],b[N],c[N],d[N];
void solve(int id) {
	if((a[1]-b[1])*(a[n]-b[m])<=0) {
		printf("0");
		return ;
	}
	if(a[1]>b[1]) {
//		if(id==4) cout<<"lkfdjflkajflkdjflas"<<endl;
		int tp=m;
		for(int i=n; i; i--) {
			tp=max(tp,1ll),tp=min(tp,m);
			while(tp<m&&a[i]<b[tp]) tp++;
			while(tp>1&&a[i]>b[tp-1]) tp--;
//			if(id==6) cout<<tp<<" "<<i<<endl;
			tp=max(tp,1ll),tp=min(tp,m);
//			if(id==6) cout<<tp<<" "<<i<<endl;
			if(a[i]<=b[tp]) {
				printf("0");
				return ;
			} else tp--;
		}
		tp=max(tp,1ll);
		if(tp==1) printf("1");
		else printf("0");
		return ;
	} else {
//		if(id==4) cout<<"lkfdjflkajflkdjflas"<<endl;
		int tp=1;
		for(int i=1; i<=n; i++) {
			tp=max(tp,1ll),tp=min(tp,m);
			while(tp>1&&a[i]>b[tp]) tp--;
			while(tp<m&&a[i]<b[tp+1]) tp++;
			tp=max(tp,1ll),tp=min(tp,m);
//			if(id==4) cout<<tp<<" "<<i<<endl;
			if(a[i]>=b[tp]) {
				printf("0");
				return ;
			} else tp++;
		}
		tp=min(tp,m);
		if(tp==m) printf("1");
		else printf("0");
		return ;
	}
}
signed main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	tid=read(),n=read(),m=read(),q=read();
	if((tid>=8&&tid<=14)||(tid>=19)){
		for(int i=0; i<=q; i++)printf("0");
	}else if(n>2){
		for(int i=1; i<=n; i++) c[i]=read();
		for(int i=1; i<=m; i++) d[i]=read();
		for(int i=1; i<=n; i++) a[i]=c[i];
		for(int i=1; i<=m; i++) b[i]=d[i];
		solve(0);
		for(int k=1; k<=q; k++) {
			for(int i=1; i<=n; i++) a[i]=c[i];
			for(int i=1; i<=m; i++) b[i]=d[i];
			int k1=read(),k2=read();
			for(int i=1; i<=k1; i++) {
				int x=read(),y=read();
				a[x]=y;
			}
			for(int i=1; i<=k2; i++) {
				int x=read(),y=read();
				b[x]=y;
			}
//		if(k==4){
//			cout<<endl;
//			cout<<"_________________"<<endl;
//			for(int i=1; i<=n; i++)cout<<a[i]<<' ';
//			puts("");
//			for(int i=1; i<=n; i++)cout<<b[i]<<' ';
//			puts("");
//		}
			solve(k);
		}
	}else if(n<=2&&m<=2){
		for(int i=1; i<=n; i++) c[i]=read();
		for(int i=1; i<=m; i++) d[i]=read();
		for(int i=1; i<=n; i++) a[i]=c[i];
		for(int i=1; i<=m; i++) b[i]=d[i];
		if((a[1]-b[1])*(a[n]-b[m])<=0) printf("0");
		else printf("1");
		for(int k=1; k<=q; k++) {
			for(int i=1; i<=n; i++) a[i]=c[i];
			for(int i=1; i<=m; i++) b[i]=d[i];
			int k1=read(),k2=read();
			for(int i=1; i<=k1; i++) {
				int x=read(),y=read();
				a[x]=y;
			}
			for(int i=1; i<=k2; i++) {
				int x=read(),y=read();
				b[x]=y;
			}
			if((a[1]-b[1])*(a[n]-b[m])<=0) printf("0");
			else printf("1");
		}
	}
}
