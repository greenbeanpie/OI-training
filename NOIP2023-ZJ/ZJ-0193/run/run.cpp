#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=20,maxm=1e5+5,maxk=1e3+5;
int c,t,n,k,m,d,s[maxn],sum[maxn],ans,f[maxk][maxk],Sum[maxk];
struct point{
	int x,y,v;
}p[maxm];
int read(){
	int ret=0,y=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') y=-y;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*y;
}
void check(){
	memset(sum,0,sizeof sum);
	int now=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0) sum[i]=0;
		else sum[i]=sum[i-1]+1,now-=d;
		if(sum[i]>k) return;
	}
	for(int i=1;i<=m;i++)
	  if(sum[p[i].x]>=p[i].y) now+=p[i].v;
	ans=max(ans,now);
	return;
}
void dfs(int i){
	if(i==n+1){check();return;}
	s[i]=1;
	dfs(i+1);
	s[i]=0;
	dfs(i+1);
	return;
}
void solve(){
	t=read();
	while(t--){
		n=read();m=read();k=read();d=read();ans=0;
		for(int i=1;i<=m;i++) p[i].x=read(),p[i].y=read(),p[i].v=read();
		dfs(1);
		printf("%lld\n",ans);
	}
	return;
}
void solve1(){
	t=read();
	while(t--){
		n=read();m=read();k=read();d=read();ans=0;
		for(int i=1;i<=m;i++) p[i].x=read(),p[i].y=read(),p[i].v=read();
		for(int i=1;i<=m;i++){
			if(p[i].y>k) continue;
			if(p[i].v>p[i].y*d) ans+=p[i].v-p[i].y*d;
		}
		printf("%lld\n",ans);
	}
	return;
}
bool cmp(point a,point b){return a.x<b.x||a.x==b.x&&a.y<b.y;}
void solve2(){
	t=read();
	while(t--){
		memset(f,0,sizeof f);
		n=read();m=read();k=read();d=read();ans=0;int num=1,cnt=0;
		for(int i=1;i<=m;i++){
			int x=read(),y=read(),v=read();
			if(y>k) continue;
			p[++cnt].x=x;p[cnt].y=y;p[cnt].v=v;
		}
		sort(p+1,p+1+cnt,cmp);
		for(int i=1;i<=cnt;i++) Sum[i]=Sum[i-1]+p[i].v;
		for(int i=1;i<=n;i++) f[i][0]=0;
		for(int i=1;i<=n;i++){
			int lst=num-1;
			for(int j=1;j<=min(i,k);j++){
				f[i][j]=f[i-1][j-1]-d;
				while(num<=cnt&&p[num].x==i&&p[num].y<=j) num++;
				f[i][j]+=Sum[num-1]-Sum[lst];
				f[i+1][0]=max(f[i+1][0],f[i][j]);
			}
			f[i+1][0]=max(f[i+1][0],f[i][0]);
		}
		for(int j=0;j<=k;j++) ans=max(ans,f[n][j]);
		printf("%lld\n",ans);
	}
	return;
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();
	if(c<=2) solve();
	if(c>=3&&c<=9) solve2();
	if(c==17||c==18) solve1();
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/