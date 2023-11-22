#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,kx,ky,p,v,x,y;
int a[50010],b[50010],a1[50010],b1[50010];
bool f(int l,int r,int d) {
	//return 1;
	if (l>n||r>m) {
		for (int i=l; i<=n; i++)
			if (!((a1[i]>b1[m])^d)) {
				return 0;
			}
		for (int i=r; i<=m; i++)
			if (!((a1[n]>b1[i])^d)) {
				return 0;
			}
		return 1;
	}
	if ((a1[l]>b1[r+1])^d)
		if (f(l,r+1,d))
			return 1;
	if ((a1[l+1]>b1[r])^d)
		if (f(l+1,r,d))
			return 1;
	return 0;
}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for (int i=1; i<=m; i++)
		scanf("%d",&b[i]);
	for (int k=0; k<=q; k++) {
		for (int i=1; i<=n; i++)
			a1[i]=a[i];
		for (int i=1; i<=m; i++)
			b1[i]=b[i];
		if (k>0) {
			scanf("%d%d",&kx,&ky);
			for (int i=1; i<=kx; i++) {
				scanf("%d%d",&p,&v);
				a1[p]=v;
			}
			for (int i=1; i<=ky; i++) {
				scanf("%d%d",&p,&v);
				b1[p]=v;
			}
		}
		if (a1[1]==b1[1]) {
			printf("0");
			continue;
		} else if (a1[1]>b1[1]) {
			if (a1[n]<=b1[m]) {
				printf("0");
				continue;
			}
			v=p=0;
			for (int i=1; i<=m; i++) {
				v=max(v,b1[i]);
			}
			for (int i=1; i<=n; i++) {
				if (a1[i]>v) {
					p=1;
					break;
				}
			}
			if (!p) {
				printf("0");
				continue;
			}
			if (f(1,1,0)) {
				printf("1");
			} else {
				printf("0");
			}
		} else {
			if (a1[n]>=b1[m]) {
				printf("0");
				continue;
			}
			v=p=0;
			for (int i=1; i<=n; i++) {
				v=max(v,a1[i]);
			}
			for (int i=1; i<=m; i++) {
				if (b1[i]>v) {
					p=1;
					break;
				}
			}
			if (!p) {
				printf("0");
				continue;
			}
			if (f(1,1,1)) {
				printf("1");
			} else {
				printf("0");
			}
		}
	}
	printf("\n");
	return 0;
	fclose(stdin);
	fclose(stdout);
}
