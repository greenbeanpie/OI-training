#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int c,n,m,q;
int x[500005],y[500005];
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;++i)scanf("%d",&x[i]);
	for(int i=1;i<=m;++i)scanf("%d",&y[i]);
	if(c==1){
		if(x[1]-y[1])putchar('1');
		else putchar('0');
		while(q--){
			int xx[2]={0,x[1]},yy[2]={0,y[1]};
			int k1,k2;
			scanf("%d %d",&k1,&k2);
			for(int i=1;i<=k1;++i){
				int p,v;
				scanf("%d %d",&p,&v);
				xx[p]=v;
			}
			for(int i=1;i<=k2;++i){
				int p,v;
				scanf("%d %d",&p,&v);
				yy[p]=v;
			}
			if(xx[1]-yy[1])putchar('1');
			else putchar('0');
		}
	}else if(c==2){
		if(n==2&&m==2){
			if((x[1]-y[1])*(x[2]-y[2])>0)putchar('1');
			else putchar('0');
		}else if(n==1&&m==2){
			if((x[1]-y[1])*(x[1]-y[2])>0)putchar('1');
			else putchar('0');
		}else if(n==2&&m==1){
			if((x[1]-y[1])*(x[2]-y[1])>0)putchar('1');
			else putchar('0');
		}else if(n==1&&m==1){
			if(x[1]-y[1])putchar('1');
			else putchar('0');
		}
		while(q--){
			int xx[3]={0,x[1],x[2]},yy[3]={0,y[1],y[2]};
			int k1,k2;
			scanf("%d %d",&k1,&k2);
			for(int i=1;i<=k1;++i){
				int p,v;
				scanf("%d %d",&p,&v);
				xx[p]=v;
			}
			for(int i=1;i<=k2;++i){
				int p,v;
				scanf("%d %d",&p,&v);
				yy[p]=v;
			}
			if(n==2&&m==2){
				if((xx[1]-yy[1])*(xx[2]-yy[2])>0)putchar('1');
				else putchar('0');
			}else if(n==1&&m==2){
				if((xx[1]-yy[1])*(xx[1]-yy[2])>0)putchar('1');
				else putchar('0');
			}else if(n==2&&m==1){
				if((xx[1]-yy[1])*(xx[2]-yy[1])>0)putchar('1');
				else putchar('0');
			}else if(n==1&&m==1){
				if(xx[1]-yy[1])putchar('1');
				else putchar('0');
			}
		}
	}
	return 0;
}


