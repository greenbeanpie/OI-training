#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
long long C,T,n,m,K,d;
long long Ans;
//long long f[2][5005][5005];
bool vis[maxn];
struct yxy{
	long long x,y,z;
	bool operator<(const yxy b)const{return x<b.x;}
}a[maxn];
long long read(){
	long long ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
void dfs(int x,int lst,long long v){
	if(x>n){
		for(int i=1;i<=m;i++){
			bool flg=1;
			for(int j=a[i].x-a[i].y+1;j<=a[i].x;j++)if(!vis[j]){flg=0;break;}
			if(flg)v+=a[i].z;
		}
		Ans=max(Ans,v);
		return ;
	}
	vis[x]=0;
	dfs(x+1,0,v);
	if(lst+1<=K){
		vis[x]=1;
		dfs(x+1,lst+1,v-d);
	}
}
void solve1(){
	while(T--){
		n=read();m=read();K=read();d=read();
		Ans=0;
		for(int i=1;i<=m;i++)a[i].x=read(),a[i].y=read(),a[i].z=read();
		sort(a+1,a+1+m);
		dfs(1,0,0);
		printf("%lld\n",Ans);
	}
}
void solve2(){
	while(T--){
		n=read();m=read();K=read();d=read();
		Ans=0;
		for(int i=1;i<=m;i++)a[i].x=read(),a[i].y=read(),a[i].z=read();
		sort(a+1,a+1+m);
		for(int i=1;i<=m;i++)if(a[i].y<=K&&a[i].z-a[i].y*d>0){
			Ans+=a[i].z-a[i].y*d;
		}
		printf("%lld\n",Ans);
	}
	exit(0);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	C=read();T=read();
	if(C==1||C==2)solve1();
	else if(C==17||C==18)solve2();
	return 0;
}//f[i] stan