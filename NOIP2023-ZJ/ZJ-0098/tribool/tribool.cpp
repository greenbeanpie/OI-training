#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
inline int Read(){
	int c;
	while((c=getchar())<48);
	int R=c^48;
	while((c=getchar())>47)R=(R<<1)+(R<<3)+(c^48);
	return R;
}
typedef long long ll;
inline int zz(char c){
	if(c=='T')return -1;
	if(c=='F')return -2;
	if(c=='U')return -3;
}
char s[5];
vector<int> to[100005],ct[100005];
int ans,n,m;
int dis[100005];
int f[100005],fs[100005],vl[100005],bl[100005];
void ori(int N){
	ans=0;
	for(int i=1;i<=N;i++){
		to[i].clear();
		ct[i].clear();
		vl[i]=f[i]=i;
		fs[i]=1;
		bl[i]=0;
		dis[i]=-1;
	}
}
int Find(int x){
	if(x!=f[x])return f[x]=Find(f[x]);
	return x;
}
void bin(int x,int y){
	x=Find(x);y=Find(y);
	if(x==y)return;
	if(fs[x]<fs[y])swap(x,y);
	f[y]=x;
	fs[x]+=fs[y];
}
int dfs(int u){
	if(vl[u]<0&&vl[u]==-3)return 1;
	int si=to[u].size(),v;
	for(int i=0;i<si;i++)if(dis[v=to[u][i]]>-1){
		if(dis[u]!=(dis[v]^ct[u][i]))return 1;
	}
	for(int i=0;i<si;i++)if(dis[v=to[u][i]]<0){
		dis[v]=dis[u]^ct[u][i];
		if(dfs(v))return 1;
	}
	return 0;
}
void sol(int u){
	dis[u]=0;
	if(dfs(u))ans+=fs[u];
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int ccc,T;
	scanf("%d%d",&ccc,&T);
	while(T--){
		n=Read();m=Read();
		ori(n);
		for(int i=1;i<=m;i++){
			int x,y;
			while((s[0]=getchar())<43);
			x=Read();
			if(s[0]=='+'){
				y=Read();
				vl[x]=vl[y];
				bl[x]=bl[y];
			}	
			else
			if(s[0]=='-'){
				y=Read();
				vl[x]=vl[y];
				bl[x]=!bl[y];
			}
			else{
				bl[x]=0;
				vl[x]=zz(s[0]);
			}
		}
		for(int i=1;i<=n;i++){
			if(vl[i]>-1){
				bin(i,vl[i]);
				to[i].push_back(vl[i]);
				to[vl[i]].push_back(i);
				ct[i].push_back(bl[i]);
				ct[vl[i]].push_back(bl[i]);
			}
		}
		for(int i=1;i<=n;i++){
			if(dis[Find(i)]<0)sol(Find(i));
		}
		printf("%d\n",ans);
	}
	return 0;
}