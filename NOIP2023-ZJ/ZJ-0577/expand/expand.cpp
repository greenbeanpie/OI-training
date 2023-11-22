#include<iostream>
#include<cstdio>
using namespace std;
int c,n,m,q,kx,ky,p,i;
long long x[500003],y[500003],tree[2000003][2],v;
int main(){
	freopen("expand.in","r",stdin),freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(i=1;i<=n;i++)  scanf("%lld",&x[i]);
	for(i=1;i<=m;i++)  scanf("%lld",&y[i]);
	if(x[1]!=y[1])  puts("1");
	else  puts("0");
	while(q--){
		scanf("%d%d",&kx,&ky);
		if(x[1]!=y[1])  puts("1");
		else  puts("0");
	}
	return 0;
}
