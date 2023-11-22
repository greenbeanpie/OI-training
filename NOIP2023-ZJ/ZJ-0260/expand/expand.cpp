#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,a[2][500100],k1,k2,x[2][500100],y[2][500100],hmin[2][500100],hmax[2][500100];
void gt_s(){
	for(int i=n;i>=1;i--){
		hmin[0][i]=min(hmin[0][i+1],a[0][i]);
		hmax[0][i]=max(hmax[0][i+1],a[0][i]);
	}
	for(int i=m;i>=1;i--){
		hmin[1][i]=min(hmin[1][i+1],a[1][i]);
		hmax[1][i]=max(hmax[1][i+1],a[1][i]);
	}
	return;
}
void check(int t1,int t2){
	int l1=a[t1][0],l2=a[t2][0];
	if(a[t1][1]==a[t2][1]||a[t1][l1]>=a[t2][l2]){
		printf("0");
		return;
	}
	int lst=1,s1=1,s2=1,minn;
	while(s1<=l1&&s2<=l2){
		minn=2e9;
		while(s1<=l1&&a[t1][s1]<a[t2][s2]){
			minn=min(minn,a[t1][s1]);
			s1++;
		}
		if(s1>l1){
			break;
		}
		while(s2<=l2&&a[t2][s2]>minn){
			if(a[t2][s2]>a[t1][s1]){
				break;
			}
			s2++;
		}
		if(a[t2][s2]<=a[t1][s1]||s2>l2){
			printf("0");
			return;
		}
		lst=s1;
	}
	while(lst<l1&&s2<=l2){
		while(lst<l1&&hmin[t1][lst+1]<hmin[t2][s2]&&a[t1][lst]<a[t2][s2]){
			lst++;
		}
		if(a[t1][lst]>=a[t2][s2]){
			printf("0");
			return;
		}
		if(lst==l1){
			printf("1");
			return;
		}
		while(s2<l2&&hmin[t2][s2+1]==hmin[t2][s2]){
			s2++;
		}
		while(s2<l2&&a[t2][s2]<=a[t2][s2+1]){
			s2++;
		}
		lst++;
		if(s2==l2&&a[t2][s2]>hmax[t1][lst]){
			printf("1");
			return;
		}
	}
	printf("1");
	return;
}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	a[0][0]=n;
	a[1][0]=m;
	hmin[0][n+1]=2e9;
	hmin[1][m+1]=2e9;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[0][i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&a[1][i]);
	}
	gt_s();
	if(a[1][1]>a[0][1]){
		check(0,1);
	}
	else check(1,0);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&k1,&k2);
		for(int j=1;j<=k1;j++){
			scanf("%d%d",&x[0][j],&y[0][j]);
			int t=a[0][x[0][j]];
			a[0][x[0][j]]=y[0][j];
			y[0][j]=t;
		}
		for(int j=1;j<=k2;j++){
			scanf("%d%d",&x[1][j],&y[1][j]);
			int t=a[1][x[1][j]];
			a[1][x[1][j]]=y[1][j];
			y[1][j]=t;
		}
		gt_s();
		if(a[1][1]>a[0][1]){
			check(0,1);
		}
		else check(1,0);
		for(int j=1;j<=k1;j++){
			a[0][x[0][j]]=y[0][j];
		}
		for(int j=1;j<=k2;j++){
			a[1][x[1][j]]=y[1][j];
		}
	}
	return 0;
}
/*
1 6 6 0
9 8 11 12 2 4
7 10 1 6 5 3

*/
