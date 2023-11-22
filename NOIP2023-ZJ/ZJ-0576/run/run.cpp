#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,v;
};
int c,t,n,m,k,d,ans;
node a[10010];
void tryy(int l,int u,int s){
	if (l==n){
		if (s>ans)
			ans=s;
		return;
	}
	int kk=0;
	for (int i=1;i<=m;i++)
		if (a[i].x==l&&a[i].y<=u)
			kk+=a[i].v;
	if (u<k){
		tryy(l+1,u+1,s-d+kk);
	}
	tryy(l+1,0,s+kk);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	for (int i=1;i<=t;i++){
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for (int j=1;j<=m;j++){
			scanf("%d%d%d",&a[j].x,&a[j].y,&a[j].v);
		}
		ans=-100000;
		tryy(0,0,0);
		printf("%d\n",ans);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
