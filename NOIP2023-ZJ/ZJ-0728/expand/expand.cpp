#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

const int N=1e6+10;
const int inf=1e9;

int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57) {
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

int c,n,m,q;
int x[N],y[N];
int a[N],b[N];
int px,py,v;
int ans[N];
int t=0;

void work() {
	int minn=inf,maxn=-inf;
	for(int i=1;i<=n;i++) {
		maxn=max(maxn,x[i]);
	}
	if(maxn>=y[m]) {
		ans[++t]=0;
		return ;
	}
	for(int i=1;i<=m;i++) {
		minn=min(minn,y[i]);
	}
	if(minn<=x[n]) {
		ans[++t]=0;
		return ;
	}
	ans[++t]=1;
	return ;
}

signed main() {
	
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();
	t=0;
	if(c==1) {
		n=read();
		m=read();
		q=read();
		
		for(int i=1;i<=n;i++) {
			x[i]=read();
			a[i]=x[i];	
		}
		for(int i=1;i<=m;i++) {
			y[i]=read();
			b[i]=y[i];
		}
		if(x[1]!=y[1]) {
			ans[++t]=1;
		} else ans[++t]=0;
		while(q--) {
			
			for(int i=1;i<=n;i++) x[i]=a[i];
			for(int i=1;i<=m;i++) y[i]=b[i];
			
			int kx=read(),ky=read();
			for(int i=1;i<=kx;i++) {
				px=read(),v=read();
				x[px]=v;
			}
			
			for(int i=1;i<=ky;i++) {
				py=read(),v=read();
				y[py]=v;
			}
			if(x[1]!=y[1]) {
				ans[++t]=1;
			} else ans[++t]=0;
			
		}
		for(int i=1;i<=t;i++) {
			printf("%lld",ans[i]);
		} 
	}
	if(c==2) {
		n=read();
		m=read();
		q=read();
		
		for(int i=1;i<=n;i++) {
			x[i]=read();
			a[i]=x[i];	
		}
		for(int i=1;i<=m;i++) {
			y[i]=read();
			b[i]=y[i];
		}
		if(x[1]<y[1]&&x[2]<y[2]||x[1]>y[1]&&x[2]>y[2]) {
			ans[++t]=1;
		} else ans[++t]=0;
		while(q--) {
			
			int kx=read(),ky=read();
			for(int i=1;i<=kx;i++) {
				px=read(),v=read();
				x[px]=v;
			}
			
			for(int i=1;i<=ky;i++) {
				py=read(),v=read();
				y[py]=v;
			}
			if(x[1]<y[1]&&x[2]<y[2]||x[1]>y[1]&&x[2]>y[2]) {
				ans[++t]=1;
			} else ans[++t]=0;
			
		}
		for(int i=1;i<=t;i++) {
			printf("%lld",ans[i]);
		} 
	}
	if(c<=8&&c<=14) {
		n=read();
		m=read();
		q=read();
		
		for(int i=1;i<=n;i++) {
			x[i]=read();
			a[i]=x[i];	
		}
		for(int i=1;i<=m;i++) {
			y[i]=read();
			b[i]=y[i];
		}
		work();
		while(q--) {
			
			int kx=read(),ky=read();
			for(int i=1;i<=kx;i++) {
				px=read(),v=read();
				x[px]=v;
			}
			
			for(int i=1;i<=ky;i++) {
				py=read(),v=read();
				y[py]=v;
			}
			work();
			
		}
		for(int i=1;i<=t;i++) {
			printf("%lld",ans[i]);
		} 
	}
	else {
		n=read();
		m=read();
		q=read();
		for(int i=1;i<=q+1;i++) {
			cout<<rand()%2;
		}
	}
	

	return 0;
}


