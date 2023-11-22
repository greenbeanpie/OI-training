#include <bits/stdc++.h>
using namespace std;
int n,m,lst;
struct node{
	char c[3005];
	bool operator < (const node b)const{
		for (int i=1;i<=m;i++) if (c[i]<b.c[i]) return 1;
			else if (c[i]>b.c[i]) return 0;return 0;
	}
}a[3005],k[3005];
bool check(int x,int y){
	if (x==y) return 1;
	return a[x]<k[y];
}
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen ("dict.in","r",stdin);
	freopen ("dict.out","w",stdout);
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",a[i].c+1);
	for (int i=1;i<=n;i++) sort(a[i].c+1,a[i].c+1+m);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		k[i].c[j]=a[i].c[m-j+1];
	for (int i=1;i<=n;i++) if (lst==0||k[i]<k[lst])
		lst=i;
	for (int i=1;i<=n;i++) if (check(i,lst))
		printf ("1");else printf ("0");
	return 0;
}