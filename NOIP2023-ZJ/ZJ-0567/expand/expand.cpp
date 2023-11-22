#include<bits/stdc++.h>
using namespace std;
const int MaxN=5e5+50;
int X[MaxN],Y[MaxN],ans[MaxN],px[MaxN],vx[MaxN],py[MaxN],vy[MaxN];
int c,n,m,q,kx,ky,cnt;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<n+1;i++)
		scanf("%d",&X[i]);
	for(int i=1;i<m+1;i++)
		scanf("%d",&Y[i]);
	if(1ll*(X[1]-Y[1])*(X[n]-Y[m])<=0)	
		ans[++cnt]=0;
	else
		ans[++cnt]=1;
	while(q--){
		scanf("%d%d",&kx,&ky);
		for(int i=1;i<kx+1;i++){
			scanf("%d%d",&px[i],&vx[i]);
			swap(X[px[i]],vx[i]);
		}
		for(int i=1;i<ky+1;i++){
			scanf("%d%d",&py[i],&vy[i]);
			swap(Y[py[i]],vy[i]);
		}
		if(1ll*(X[1]-Y[1])*(X[n]-Y[m])<=0)
			ans[++cnt]=0;
		else	
			ans[++cnt]=1;
		for(int i=1;i<kx+1;i++)
			swap(X[px[i]],vx[i]);
		for(int i=1;i<ky+1;i++)
			swap(Y[py[i]],vy[i]);
	}
	for(int i=1;i<cnt+1;i++)
		printf("%d",ans[i]);
	return 0;
}