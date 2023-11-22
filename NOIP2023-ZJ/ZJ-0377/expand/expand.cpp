#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;bool flag,flag1;
int C,n,m,q,i,j,p,v,nn,mm,kx,ky,maxx,maxp,a[N],b[N],aa[N],bb[N],pre[N];
signed main(){
	freopen("expand.in","r",stdin);freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&C,&n,&m,&q);q++;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	while(q--){
		if(flag){
			scanf("%d%d",&kx,&ky);
			for(i=1;i<=kx;i++){
				scanf("%d%d",&p,&v);
				a[p]=v;
			}
			for(i=1;i<=ky;i++){
				scanf("%d%d",&p,&v);
				b[p]=v;
			}
		}else flag=1;
		if(a[1]==b[1]){
			putchar('0');
			continue;
		}
		if(a[1]>b[1]){
			nn=n;mm=m;
			for(i=1;i<=n;i++) aa[i]=a[i];
			for(i=1;i<=m;i++) bb[i]=b[i];
		}
		if(a[1]<b[1]){
			nn=m;mm=n;
			for(i=1;i<=m;i++) aa[i]=b[i];
			for(i=1;i<=n;i++) bb[i]=a[i];
		}
		maxx=0;flag1=0;
		for(i=1;i<=nn;i++){
			maxx=max(maxx,aa[i]);
			if(maxx<=bb[i]){
				putchar('0');
				flag1=1;
				break;
			}
		}
		if(flag1) continue;
		/*
		for(i=1;i<=mm;i++){
			for(j=i;j>=1;j--)
				if(a[i]>b[j]){
					pre[j]=i;
					break;
				}
		}
		maxp=0;
		for(i=1;i<=mm;i++) maxp=max(maxp,i-pre[i]+1);
		for(i=1;i<=nn;i++)
			if(a[i+maxp]<=b[i]){
				putchar('0');
				flag1=1;
				break;
			}
		if(!flag1) putchar('1');
		*/
		putchar('1');
	}
	return 0;
}
