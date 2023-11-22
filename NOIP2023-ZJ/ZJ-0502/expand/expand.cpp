#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
namespace Sub1{
	int x,y,ans[500100],cnt,kx,ky;
	int keepx,keepy;
	signed work(){
		scanf("%d ",&x);
		scanf("%d ",&y);
		if(x-y)ans[++cnt]=1;
		else ans[++cnt]=0;
		keepx=x,keepy=y;
		while(q--){
			int p,v;
			scanf("%d %d ",&kx,&ky);
			while(kx--){
				scanf("%d %d ",&p,&v);
				x=v;
			}
			while(ky--){
				scanf("%d %d ",&p,&v);
				y=v;
			}
			if(x-y)ans[++cnt]=1;
			else ans[++cnt]=0;
			x=keepx,y=keepy;
		}
		for(int i=1;i<=cnt;++i)printf("%d",ans[i]);
		return 0;
	}
}
namespace Sub2{
	int x[100],y[100],ans[500010],cnt,kx,ky,keepx[100],keepy[100];
	inline void judge1(){
		if(x[1]-y[1]>0&&x[2]-y[2]>0) ans[++cnt]=1;
		else if(x[1]-y[1]<0&&x[2]-y[2]<0) ans[++cnt]=1;
		else ans[++cnt]=0;
	}
	inline void judge2(){
		if(x[1]-y[1]>0&&x[2]-y[1]>0) ans[++cnt]=1;
		else if(x[1]-y[1]<0&&x[2]-y[1]<0) ans[++cnt]=1;
		else ans[++cnt]=0;
	}
	inline void judge3(){
		if(x[1]-y[1]>0&&x[1]-y[2]>0) ans[++cnt]=1;
		else if(x[1]-y[1]<0&&x[1]-y[2]<0) ans[++cnt]=1;
		else ans[++cnt]=0;
	}
	signed work(){
		for(int i=1;i<=n;++i)scanf("%d ",&x[i]);
		for(int i=1;i<=m;++i)scanf("%d ",&y[i]);
		for(int i=1;i<=n;++i)keepx[i]=x[i];
		for(int i=1;i<=m;++i)keepy[i]=y[i];
		if(n==2&&m==2){
			judge1();
			while(q--){
				int p,v;
				scanf("%d %d ",&kx,&ky);
				while(kx--){
					scanf("%d %d ",&p,&v);
					x[p]=v;
				}
				while(ky--){
					scanf("%d %d ",&p,&v);
					y[p]=v;
				}
				judge1();
				for(int i=1;i<=n;++i)x[i]=keepx[i];
				for(int i=1;i<=m;++i)y[i]=keepy[i];
			}
		}else if(n==2){
			judge2();
			while(q--){
				int p,v;
				scanf("%d %d ",&kx,&ky);
				while(kx--){
					scanf("%d %d ",&p,&v);
					x[p]=v;
				}
				while(ky--){
					scanf("%d %d ",&p,&v);
					y[p]=v;
				}
				judge2();
				for(int i=1;i<=n;++i)x[i]=keepx[i];
				for(int i=1;i<=m;++i)y[i]=keepy[i];
			}
		}else{
			judge3();
			while(q--){
				int p,v;
				scanf("%d %d ",&kx,&ky);
				while(kx--){
					scanf("%d %d ",&p,&v);
					x[p]=v;
				}
				while(ky--){
					scanf("%d %d ",&p,&v);
					y[p]=v;
				}
				judge3();
				for(int i=1;i<=n;++i)x[i]=keepx[i];
				for(int i=1;i<=m;++i)y[i]=keepy[i];
			}
		}
		for(int i=1;i<=cnt;++i)printf("%d",ans[i]);
		return 0;
	}
}
namespace Sub3{
	int x[2023],y[2023],keepx[2023],keepy[2023],kx,ky,ans[500010],cnt;
	signed work(){
		for(int i=1;i<=n;++i)scanf("%d ",&x[i]);
		for(int i=1;i<=m;++i)scanf("%d ",&y[i]);
		for(int i=1;i<=n;++i)keepx[i]=x[i];
		for(int i=1;i<=m;++i)keepy[i]=y[i];
		if(x[1]>y[1])ans[++cnt]=1;
		else ans[++cnt]=0;
		while(q--){
			int p,v;
			scanf("%d %d ",&kx,&ky);
			while(kx--){
				scanf("%d %d ",&p,&v);
				x[p]=v;
			}
			while(ky--){
				scanf("%d %d ",&p,&v);
				y[p]=v;
			}
			if(x[1]>y[1])ans[++cnt]=1;
			else ans[++cnt]=0;
			for(int i=1;i<=n;++i)x[i]=keepx[i];
			for(int i=1;i<=m;++i)y[i]=keepy[i];
		}
		for(int i=1;i<=cnt;++i)printf("%d",ans[i]);
		return 0;
	}
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d %d %d %d ",&c,&n,&m,&q);
	if(c==1||(n==1&&m==1))Sub1::work();
	else if(c==2)Sub2::work();
	return 0;
}
/*
3 3 3 3
8 6 9
1 7 4
1 0
3 0
0 2
1 8
3 5
1 1
2 8
1 7

*/