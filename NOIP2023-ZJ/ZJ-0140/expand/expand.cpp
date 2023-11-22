#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int mn[N],mn1[N],mx[N],mx1[N],x[N],y[N],a[N],b[N],n,m,ans[105];
int work(){
	int l=1,r=1,u=x[1]-y[1];
	if(1ll*u*(x[n]-y[m])<=0)return 0;
	for (int i=n;i>=1;i--)
		mn[i]=min(mn[i+1],x[i]),mx[i]=max(mx[i+1],x[i]);
	for (int i=m;i>=1;i--)
		mn1[i]=min(mn1[i+1],y[i]),mx1[i]=max(mx1[i+1],y[i]);
	int i=1,j=1;
	while(i<=n&&j<=m){
//	printf("%d %d %lld %lld %lld p\n",i,j,u,x[i]-y[j],1ll*u*(x[i]-y[h]));
		if(1ll*u*(mn[i]-mn1[j])<=0||1ll*u*(mx[i]-mx1[j])<=0)return 0;
		if(1ll*u*(x[i]-y[j])>0)j++;
		else i++;
	}
	return 1;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int t,q,u,v,z,p;
	scanf("%d%d%d%d",&t,&n,&m,&q);mn[n+1]=1e9,mn1[m+1]=1e9;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),x[i]=a[i];
	for (int i=1;i<=m;i++)scanf("%d",&b[i]),y[i]=b[i];
	ans[0]=work();
	for (int j=1;j<=q;j++){
		scanf("%d%d",&u,&v);
		for (int i=1;i<=n;i++)x[i]=a[i];
		for (int i=1;i<=m;i++)y[i]=b[i];
		for (int i=1;i<=u;i++){
			scanf("%d%d",&p,&z);
			x[p]=z;
		}
		for (int i=1;i<=v;i++){
			scanf("%d%d",&p,&z);
			y[p]=z;
		}
		ans[j]=work();
	}
	for (int i=0;i<=q;i++)printf("%d",ans[i]);
}
