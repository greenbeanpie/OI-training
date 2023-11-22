#include<bits/stdc++.h>
using namespace std;
long long c,n,m,q,x,y,v,kx,ky;
long long a[500010],b[500010],a2[500010],b2[500010];
long long work() {
	long long id=1;
	if(b2[1]<a2[1]) {
		for(long long i=1; i<=n; i++) {
			while(b2[id]<a2[i]) {
				id++;
				if(id==m+1) return 1;
			}
//			cout<<endl<<b2[i]<<"	"<<a2[i]<<endl;
		}
	} else if(b2[1]>a2[1]) {
		for(long long i=1; i<=n; i++) {
			if(b2[id]>a2[i]) {
				id++;
				if(id==m+1) return 1;
			}
		}
	}
//	cout<<"------"<<id<<endl;
	return 0;
}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	srand(time(NULL));
	scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
	for(long long i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	for(long long j=1; j<=m; j++) {
		scanf("%lld",&b[j]);
	}
	while(m<n) {
		b[++m]=b[m-1];
	}
	if(n==m&&m==1) {
		printf("%lld",a[1]>b[1]);
		while(q--) {
			a2[1]=a[1],b2[1]=b[1];
			scanf("%lld%lld",&kx,&ky);
			for(long long i=1; i<=kx; i++) {
				scanf("%lld%lld",&x,&y);
				a2[x]=y;
			}
			for(long long i=1; i<=ky; i++) {
				scanf("%lld%lld",&x,&y);
				b2[x]=y;
			}
			printf("%lld",a2[1]>b2[1]);
		}
	} else if(n<=2&&m<=2) {
		if((a[1]-b[1])*(a[n]-b[m])<=0) printf("0");
		else printf("1");
		while(q--) {
			scanf("%lld%lld",&kx,&ky);
			for(long long i=1; i<=n; i++) a2[i]=a[i];
			for(long long i=1; i<=m; i++) b2[i]=b[i];
			for(long long i=1; i<=kx; i++) {
				scanf("%lld%lld",&x,&y);
				a2[x]=y;
			}
			for(long long i=1; i<=ky; i++) {
				scanf("%lld%lld",&x,&y);
				b2[x]=y;
			}
			if((a2[1]-b2[1])*(a2[n]-b2[m])<=0) printf("0");
			else printf("1");
		}
	} else {
		for(long long i=1; i<=n; i++) a2[i]=a[i];
		for(long long i=1; i<=m; i++) b2[i]=b[i];
		printf("%lld",work());
		while(q--) {
			scanf("%lld%lld",&kx,&ky);
			for(long long i=1; i<=n; i++) a2[i]=a[i];
			for(long long i=1; i<=m; i++) b2[i]=b[i];
			for(long long i=1; i<=kx; i++) {
				scanf("%lld%lld",&x,&y);
				a2[x]=y;
			}
			for(long long i=1; i<=ky; i++) {
				scanf("%lld%lld",&x,&y);
				b2[x]=y;
			}
			printf("%lld",work());
		}
	}
	return 0;
}