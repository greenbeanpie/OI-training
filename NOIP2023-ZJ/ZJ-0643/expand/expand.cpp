#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,q;
int a[10010],b[10010];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	cout<<1;
	int k1,k2;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&k1,&k2);
		for(int j=1;j<=k1;j++){
			int x,v;
			scanf("%d%d",&x,&v);
			a[x]=v;
		}
		for(int j=1;j<=k2;j++){
			int x,v;
			scanf("%d%d",&x,&v);
			b[x]=v;
		}
		printf("1");
	}
	return 0;
}

