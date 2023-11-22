#include<bits/stdc++.h>
using namespace std;
int c,T,n,m,k;
long long d,v[1010][1010],f[1010][1010];
void solve1(){
	scanf("%d%d%d%lld",&n,&m,&k,&d);
	memset(v,0,sizeof(v));
	memset(f,0,sizeof(f));
	for(int i=1;i<=m;i++){
		int x,y;
		long long w;
		scanf("%d%d%lld",&x,&y,&w);
		v[x][x-y+1]+=w;
	}
	for(int i=1;i<=n+1;i++){
		long long sum=0;
		for(int j=1;j<=min(i,k);j++){
		    sum+=v[i][i-j+1];
			f[i][j]=f[i-1][j-1]+sum-d;
		}
		for(int j=0;j<=k;j++)f[i][0]=max(f[i][0],f[i-1][j]);
	}
	printf("%lld\n",f[n+1][0]);
}
void solve2(){
	scanf("%d%d%d%lld",&n,&m,&k,&d);
	long long ans=0;
	for(int i=1;i<=m;i++){
		int x,y;
		long long w;
		scanf("%d%d%lld",&x,&y,&w);
		if(y<=k)ans+=max(0ll,w-d*y);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		if(c<=9)solve1();
		else solve2();
	}
}