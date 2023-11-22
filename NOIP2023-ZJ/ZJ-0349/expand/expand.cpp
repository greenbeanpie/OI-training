#include<bits/stdc++.h>
#define M 500005
using namespace std;
int c,n,m,q,kx,ky,a[M],b[M],oa[M],ob[M];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) scanf("%d",&oa[i]);
	for(int i=1;i<=m;i++) scanf("%d",&ob[i]);	
	if(c==1){
		while(q--){
			scanf("%d%d",&kx,&ky);
			int p,v;
			scanf("%d%d",&p,&v);
			a[p]=v;
			scanf("%d%d",&p,&v);
			b[p]=v;
			if(a[1]>b[1]) putchar('1');
			else putchar('0');
		}
	}
	if(c==2){
		while(q--){
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=2;i++) a[i]=oa[i];
			for(int i=1;i<=2;i++) b[i]=ob[i]; 
			for(int i=1;i<=kx;i++){
				int p,v;
				scanf("%d%d",&p,&v);
				a[p]=v;
			}
			for(int i=1;i<=ky;i++){
				int p,v;
				scanf("%d%d",&p,&v);
				b[p]=v;
			}
			if(a[1]>b[1]&&a[2]>b[2]) putchar('1');
			else putchar('0');
		}
	}
	return 0;
}
