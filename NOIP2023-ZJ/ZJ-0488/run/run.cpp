#include<bits/stdc++.h>
using namespace std;
const long long N=1010;
const int M=1010;
int c,t,n,m,k,d;
//int map[N][N]={0};
unsigned long long ans=0;
struct chall{
	int x;
	int y;
	int v;
//	int s;
//	bool f;
}a[M];
//void dfs(int time,long long power,int con){
//	if(time==n){
//		if(power>ans)ans=power;
//		return;
//	}
//	for(int i=1;i<=m;i++)
//		if(time==a[i].x&&con>=a[i].y)power+=a[i].v;
//	if(con==k){
//		dfs(n+1,power,0);
//		return;
//	}
//	dfs(n+1,power-d,con+1);
//	dfs(n+1,power,0);
//	return;
//}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	srand(time(0));
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
//			a[i].s=a[i].x-a[i].y+1;
//			if(a[i].y>a[i].x||a[i].y>k||a[i].y*d<=a[i].v)a[i].f=0;
//			else a[i].f=1;
		}
//		dfs(0,0,0);
		printf("%d\n",ans);
	}
}