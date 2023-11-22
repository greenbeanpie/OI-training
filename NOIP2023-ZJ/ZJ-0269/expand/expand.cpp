#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,n,m,q,a[500010],x,y,p,v,b[500010];
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	if(n==1&&m==1){
		if(a[1]>b[1])puts("1");
		else puts("0");
		while(q--){
			scanf("%lld%lld",&x,&y);
			for(int i=1;i<=x;i++){
				scanf("%lld%lld",&p,&v);
				a[p]=v;
			}
			for(int i=1;i<=y;i++){
				scanf("%lld%lld",&p,&v);
				b[p]=v;
			}
			if(a[1]>b[1])puts("1");
			else puts("0");
		}
		return 0;
	}
	if(c==2){
		if(m==2&&a[1]>=min(b[1],b[2])&&a[1]<=max(b[1],b[2]))puts("0");
		else if(n==2&&b[1]>=min(a[1],a[2])&&b[1]<=max(a[1],a[2]))puts("0");
		else{
			if(a[1]>b[1]&&a[2]>b[2]||a[1]<b[1]&&a[2]<b[2])puts("1");
			else puts("0");
		}
		while(q--){
			scanf("%lld%lld",&x,&y);
			for(int i=1;i<=x;i++){
				scanf("%lld%lld",&p,&v);
				a[p]=v;
			}
			for(int i=1;i<=y;i++){
				scanf("%lld%lld",&p,&v);
				b[p]=v;
			}
			if(m==2&&a[1]>=min(b[1],b[2])&&a[1]<=max(b[1],b[2]))puts("0");
			else if(n==2&&b[1]>=min(a[1],a[2])&&b[1]<=max(a[1],a[2]))puts("0");
			else{
				if(a[1]>b[1]&&a[2]>b[2]||a[1]<b[1]&&a[2]<b[2])puts("1");
				else puts("0");
			}
		}
	}
	return 0;
}
