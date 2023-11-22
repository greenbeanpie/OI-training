#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct xx{
	long long x,y,v;
}a[N];
int c,t,n,m,k,i,j;
long long d,ans,f[1005][1005];
bool cmp(xx x,xx y){
	return x.x<y.x||x.x==y.x&&x.y<y.y;
}
long long dfs(int u,int x,int y,long long s){
	if(x>m)return s;
	if(f[x][y])return f[x][y];
	long long ans=0;
	for(int i=u;i<=m;i++)
		if(a[i].x>=x)
			if(a[i].x-a[i].y+1<=x){
				if(a[i].x-x+y<=k&&a[i].x<=n)ans=max(ans,dfs(i+1,a[i].x,a[i].x-x+y,s+a[i].v-d*(a[i].x-x+y)));
			}else{
				if(a[i].y<=k&&a[i].x<=n)ans=max(ans,dfs(i+1,a[i].x,a[i].y,s+a[i].v-d*a[i].y));
			}
	return f[x][y]=ans;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;memset(f,0,sizeof(f));
		scanf("%d%d%d%lld",&n,&m,&k,&d);
		for(i=1;i<=m;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
		sort(a+1,a+m+1,cmp);
		dfs(1,0,0,0);
		for(i=1;i<=n;i++)
			for(j=0;j<=n;j++)
				ans=max(ans,f[i][j]);
		printf("%lld\n",ans);
	}
	return 0;
}
