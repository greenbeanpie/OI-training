#include<bits/stdc++.h>
using namespace std;
int n,m,k,l,ans;
char c[3009];
int a[3009][3009],b[3009][3009],mini;
bool check(int i,int j){
	for (int k=1;k<=m;k++){
		if (b[i][k]!=a[j][k]){
			if (b[i][k]<a[j][k]) return 1;else return 0;
		}
	}
	return 0;
}
bool cmp(int x,int y){
	return x>y;
}
bool check1(int i,int mini){
	if (mini==0) return 1;
	for (int j=1;j<=m;j++){
		if (a[i][j]!=a[mini][j]){
			if (a[i][j]<a[mini][j]) return 1;else return 0; 
		}
	}
	return 1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",c+1);
		for (int j=1;j<=m;j++)
			a[i][j]=b[i][j]=c[j]-'a';
		sort(b[i]+1,b[i]+1+m);
		sort(a[i]+1,a[i]+1+m,cmp);
	}
	for (int i=1;i<=n;i++){
		if (check1(i,mini)) mini=i;
	}
	for (int i=1;i<=n;i++){
		bool flag1=1;
		for (int j=1;j<=m;j++){
			if (a[i][j]!=a[mini][j]) {
				flag1=0;break;
			}
		}
		if (flag1==0){
			bool flag=1;
			if (check(i,mini)||n==1) printf("1");else printf("0");
		}else	printf("1");
	}
	return 0;
}
