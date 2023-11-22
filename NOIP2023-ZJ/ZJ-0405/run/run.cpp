#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
const int N=5e5+10;
const int inf=1e9+10;
struct node{
	int x,y,v;
}a[N];
int n,m,k,d,o,t;
int c[N],ans=-inf;
bool vis[N];
void dfs(int now){
	if(now==m+1){
		int res=0;
		memset(c,0,sizeof(c));
		for(int i=1;i<=m;i++){
			int x=a[i].x,y=a[i].y;
			if(vis[i]){
				res+=a[i].v;
				c[x-y+1]++;
				c[x+1]--;
			}
		}
		for(int i=1;i<=n;i++){
			c[i]+=c[i-1];
			if(c[i]>0) res-=d;
		}
		bool f=1;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]>0){
				cnt=1;
				while(c[i+1]>0) i++,cnt++;
			}
			if(cnt>k){
				f=0;
				break;
			}
		}
		if(f) ans=max(ans,res);
		return;
	}
	dfs(now+1);
	vis[now]=1;
	dfs(now+1);
}
void work(){
	memset(vis,0,sizeof(vis));
	ans=-inf;
	for(int i=1;i<=m;i++){
		a[i].x=read(),a[i].y=read(),a[i].v=read();
	}
	dfs(1);
	printf("%d\n",ans);
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	o=read(),t=read();
	while(t--){
		n=read(),m=read(),k=read(),d=read();
		if(o==1||o==2)work();
	}
	return 0;
}
