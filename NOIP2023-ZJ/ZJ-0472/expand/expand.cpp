#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int i,j,c,n,m,q,n1,m1,x,y,p1,p2,mi,a[N],b[N],a1[N],b1[N];
void dfs1(int x,int y){
	if(p1==1)return;
	if(x==n+1&&y==m+1){p1=1;return;}
	if(x>n||y>m)return;
	if(a1[x]<=b1[y])return;
	int k=y;
	while(a1[x]>b1[k]&&k<=m)dfs1(x+1,k++);
	dfs1(x+1,k);
}
void dfs2(int x,int y){
	if(p2==1)return;
	if(x==n+1&&y==m+1){p2=1;return;}
	if(x>n||y>m)return;
	if(a1[x]>=b1[y])return;
	int k=y;
	while(a1[x]<b1[k])dfs2(x+1,k++);
	dfs2(x+1,k);
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(i=1;i<=n;i++)scanf("%d",&a[i]),a1[i]=a[i];
	for(i=1;i<=m;i++)scanf("%d",&b[i]),b1[i]=b[i];
	p1=p2=0;
	dfs1(1,1);dfs2(1,1);
	printf("%d",p1|p2);
	while(q--){
		for(i=1;i<=n;i++)a1[i]=a[i];
		for(i=1;i<=m;i++)b1[i]=b[i];
		scanf("%d%d",&n1,&m1);
		for(i=1;i<=n1;i++)scanf("%d%d",&x,&y),a1[x]=y;
		for(i=1;i<=m1;i++)scanf("%d%d",&x,&y),b1[x]=y;
		p1=p2=0;
		dfs1(1,1);dfs2(1,1);
		printf("%d",p1|p2);
	}
	return 0;
}
