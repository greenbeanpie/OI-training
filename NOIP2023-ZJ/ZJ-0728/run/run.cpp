#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=3e3+10;

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

int n,m;
int c,t;
bool ans[N];
int k,d;
int x[N],y[N],v[N];

void work() {
	n=read();
	m=read();
	k=read();
	d=read();
	int ans=0;
	for(int i=1;i<=m;i++) {
		x[i]=read();
		y[i]=read();
		v[i]=read();
		ans+=v[i];
	}
	printf("%lld\n",ans);
	
}

signed main() {
	
//	freopen("run.in","r",stdin);
//	freopen("run.out","w",stdout);
	c=read();
	t=read();
	
	while(t--) {
//		clean();
		work();
	}

	return 0;
}

