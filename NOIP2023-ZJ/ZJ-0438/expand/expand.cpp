#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int c,n,m,q;
int a[N],b[N],tot;
bool ans[N];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	if (c==1||(n==1&&m==1)){
		if (a[1]==b[1]) ans[++tot]=0;else ans[++tot]=1;
		while(q--){
			int kx,ky,x=a[1],y=b[1],wei;
			scanf("%d%d",&kx,&ky);
			for (int i=1;i<=kx;i++)
				scanf("%d%d",&wei,&x);
			for (int i=1;i<=ky;i++)
				scanf("%d%d",&wei,&y);
			if (x==y) ans[++tot]=0;else ans[++tot]=1;
			
		}
		for (int i=1;i<=tot;i++)
			cout<<ans[i];
	}else if (c==2&&n==2&m==2){
		if ((a[1]-b[1])*(a[2]-b[2])>0) ans[++tot]=1;else ans[++tot]=0;
		while(q--){
			int kx,ky,x1=a[1],y1=a[2],x2=b[1],y2=b[2],wei,zhi;
			scanf("%d%d",&kx,&ky);
			for (int i=1;i<=kx;i++){
				scanf("%d%d",&wei,&zhi);
				if (wei==1) x1=zhi;else y1=zhi;
			}
			for (int i=1;i<=ky;i++){
				scanf("%d%d",&wei,&zhi);
				if (wei==1) x2=zhi;else y2=zhi;
			}
			if ((x1-x2)*(y1-y2)>0) ans[++tot]=1;else ans[++tot]=0;
		}
		for (int i=1;i<=tot;i++)
			cout<<ans[i];
	}else if (c==2&&n==2&&m==1){
		if (b[1]>max(a[1],a[2])||b[1]<min(a[1],a[2])) ans[++tot]=1;else ans[++tot]=0;
		while(q--){
			int kx,ky,x1=a[1],y1=a[2],x2=b[1],y2=b[2],wei,zhi;
			scanf("%d%d",&kx,&ky);
			for (int i=1;i<=kx;i++){
				scanf("%d%d",&wei,&zhi);
				if (wei==1) x1=zhi;else y1=zhi;
			}
			for (int i=1;i<=ky;i++){
				scanf("%d%d",&wei,&zhi);
				if (wei==1) x2=zhi;else y2=zhi;
			}
			if (x2>max(x1,y1)||x2<min(x1,y1)) ans[++tot]=1;else ans[++tot]=0;
		}
		for (int i=1;i<=tot;i++)
			cout<<ans[i];
	}else if (c==2&&n==1&&m==2){
		if (a[1]>max(b[1],b[2])||a[1]<min(b[1],b[2])) ans[++tot]=1;else ans[++tot]=0;
		while(q--){
			int kx,ky,x1=a[1],y1=a[2],x2=b[1],y2=b[2],wei,zhi;
			scanf("%d%d",&kx,&ky);
			for (int i=1;i<=kx;i++){
				scanf("%d%d",&wei,&zhi);
				if (wei==1) x1=zhi;else y1=zhi;
			}
			for (int i=1;i<=ky;i++){
				scanf("%d%d",&wei,&zhi);
				if (wei==1) x2=zhi;else y2=zhi;
			}
			if (x1>max(x2,y2)||x1<min(x2,y2)) ans[++tot]=1;else ans[++tot]=0;
		}
		for (int i=1;i<=tot;i++)
			cout<<ans[i];
	}
	return 0;
}
