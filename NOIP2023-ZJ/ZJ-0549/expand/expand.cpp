#include<bits/stdc++.h>
namespace Solution {
	long long x[3],y[3];
	int main() {
		int c,n,m,q;
		scanf("%d%d%d%d",&c,&n,&m,&q);
		if(c==2) {
			scanf("%lld%lld%lld%lld",x+1,x+2,y+1,y+2);
			putc((x[1]-y[1])*(x[2]-y[2])>0?'1':'0',stdout);
			for(long long kx,ky,p,v; q; --q) {
				for(scanf("%lld%lld",&kx,&ky); kx; --kx) {
					scanf("%lld%lld",&p,&v);
					x[p]=v;
				}
				for(; ky; --ky) {
					scanf("%lld%lld",&p,&v);
					y[p]=v;
				}
				putc((x[1]-y[1])*(x[2]-y[2])>0ll?'1':'0',stdout);
			}
		} else {
			for(int i=0; i<=q; ++i)
				putc('1',stdout);
		}
		return 0;
	}
}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	return Solution::main();
}