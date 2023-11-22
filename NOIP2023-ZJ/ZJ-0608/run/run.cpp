#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sgn=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')sgn=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}
	return x*sgn;
}
struct act{
	ll start,end,v;
}a[100010];
ll c,t;
bool cmp(act a,act b){
	if(a.v==b.v) return a.end<b.end;
	else return a.v>b.v;
}
bool vis[100010];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		ll n=read(),m=read(),k=read(),d=read(),ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;i++){
			a[i].start=read();a[i].end=read();a[i].v=read();
			a[i].v=a[i].v-a[i].end*d;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++){
			bool flag=1;
			for(int j=a[i].start-a[i].end+1;j<=a[i].start;j++){
				if(vis[j]==1) flag=0;
			}
			if(a[i].end<=k&&flag==1){
				ans+=a[i].v;
				for(int j=a[i].start-a[i].end+1;j<=a[i].start;j++) vis[j]=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
// maybe AFO.......
// less than 100+20+10+0
// I have no time to slove it   QaQ
// super(fake) tanxin!