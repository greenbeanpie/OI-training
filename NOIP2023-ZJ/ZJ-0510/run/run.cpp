#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=1e5+5;
int C,T;
int n,m,k,d;
ll f[2][N];
ll cnt[N];
struct VS{
	int x,y,v;
}a[M];
inline void sol(){
	scanf("%d%d%d%d",&n,&m,&k,&d);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
	}
	sort(a+1,a+m+1,[](VS a,VS b){return a.x^b.x?a.x<b.x:a.y<b.y;});
	int now=1;
	for(int j=0;j<=k;j++)f[0][j]=-1e18;
	f[0][0]=0;
	bool cur=1;
	for(int i=1;i<=n;i++,cur^=1){
		for(int j=0;j<=k;j++) cnt[j]=0;
		while(now<=m&&a[now].x==i){
			cnt[a[now].y]+=a[now].v;
			++now;
		}
		for(int j=1;j<=k;j++) cnt[j]+=cnt[j-1];
		bool lst=cur^1;
//		for(int j=0;j<=k;j++) f[cur][j]=-1e18;
		for(int j=1;j<=min(i,k);j++){
			f[cur][j]=f[lst][j-1]-d+cnt[j];
		}
		f[cur][0]=-1e18;
		for(int j=0;j<=min(i-1,k);j++){
			f[cur][0]=max(f[cur][0],f[lst][j]+cnt[0]);
		}
		
//		for(int j=0;j<=k;j++) printf("%lld ",cnt[j]);puts("");
	}
	ll ans=-1e18;
	for(int i=0;i<=k;i++) ans=max(ans,f[cur^1][i]);
	
//	for(int i=1;i<=n;i++,puts("")){
//		for(int j=0;j<=k;j++) printf("%lld ",f[i][j]);
//	}
	
	printf("%lld\n",ans);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);


//	freopen("run3.in","r",stdin);
//	freopen("my.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--) sol();
	return 0;
}
/*
24142462716
33146218618
84564337193
111722966249
37609621895
0
19229533734
38648265802
13657195549
104692775606


*/