#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m,k,d;
int ans;
struct nod{
	int x,y,v;
}a[100010];
int ef(int k){
	int l=1,r=m;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid].x<k){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	return l;
}
void dfs(int day,int e,int lx){
	int s=ef(day);
	while(day==a[s].x){
		if(lx>=a[s].y){
			e+=a[s].v;
		}
		s++;
	}
	if(day==n){
		ans=max(e,ans);
		return;
	}
	if(lx==k){
		dfs(day+1,e,0);
	}
	else{
		dfs(day+1,e,0);
		dfs(day+1,e-d,lx+1);
	}
}
bool cmp(nod p,nod q){
	return p.x<=q.x;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
		}
		sort(a+1,a+n+1,cmp);
		dfs(0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
