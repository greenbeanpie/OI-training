#include<bits/stdc++.h>
using namespace std;
#define lL long long
#define max(x,y) ((x)>(y)?(x):(y))
struct data_1{
	int l,r,v;
}a[100086];
int n,m,k,d;
bool vis[100086];
lL ans;
bool cmp(data_1 x,data_1 y){
	if(x.l==y.l){
		return x.r<y.r;
	}
	return x.l<y.l;
}
void dfs(int now_x,lL now_v,int stp){
	lL cnt=0;
	if(now_x==n){
		ans=max(ans,now_v);
		return;
	}
	dfs(now_x+1,now_v,0);
	if(stp==k){
		return;
	}
	vis[now_x+1]=true;
	for(int i=1;i<=m;i++){
		bool flag=true;
		if(a[i].r>now_x+1){
			break;
		}
		if(a[i].r==now_x+1){
			for(int j=a[i].l;j<=a[i].r;j++){
				if(!vis[j]){
					flag=false;
					break;
				}
			}
			if(flag){
				cnt+=a[i].v;
			}
		}
	}
	dfs(now_x+1,now_v-d+cnt,stp+1);
	vis[now_x+1]=false;
}
void sub1(){
	ans=0;
	scanf("%d%d%d%d",&n,&m,&k,&d);
	for(int i=1;i<=m;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		a[i].l=x-y+1;
		a[i].r=x;
		a[i].v=v;
	}
	for(int i=1;i<=n;i++){
		vis[i]=false;
	}
	sort(a+1,a+m+1,cmp);
	dfs(0,0,0);
	printf("%lld\n",ans);
}
void sub2(){
	ans=0;
	scanf("%d%d%d%d",&n,&m,&k,&d);
	for(int i=1;i<=m;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		a[i].l=x-y+1;
		a[i].r=x;
		a[i].v=v;
		if(a[i].v-y*d>0){
			ans+=(a[i].v-y*d);
		}
	}
	printf("%lld\n",ans);
//	sort(a+1,a+m+1,cmp);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	if(c==1||c==2){
		while(T--){
			sub1();
		}
	}
	else if(c==17||c==18){
		while(T--){
			sub2();
		}
	}
	else{
		while(T--){
			sub2();
		}
	}
}