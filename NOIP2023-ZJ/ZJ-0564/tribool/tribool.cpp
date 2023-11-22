#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(!(c^'-')) f^=1;c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^'0');c=getchar();}
	return (f?s:~(s-1));
}
const int N=1e5+10;
//const int N=1e3+10;
typedef pair<int,int> pii;
int a[N],t[N];
int vis[N];
pii f[N];
int C,T;
int n,m;
pii find(int u){
	vis[u]=1;
	if(f[u].fi==u) return f[u];
	else{
		pii v=find(f[u].fi);
		if(t[v.fi]){
			t[f[u].fi]=1;
			f[u]={-1,0};
		}
		else{
			if(f[u].se==-1&&v.se==-1||f[u].se==1&&v.se==1){
				f[u]={v.fi,1};
			}
			else if(f[u].se==1&&v.se==-1||f[u].se==-1||v.se==1){
				f[u]={v.fi,-1};
			}
			else{
				if(f[u].se==1) f[u]={v.se,0};
				else f[u]={!v.se,0};
			}
		}
		return f[u];
	}
}
void solve(){
	memset(f,0,sizeof f);
	memset(t,0,sizeof t);
	n=read(),m=read();
	int cnt=0;
	for(int i=1;i<=n;i++) f[i]={-1,0};
	for(int i=1;i<=m;i++){
		char c;int x,y;
		cin>>c;
		if(c=='T'){
			x=read();
			f[x]={x,1};
		}
		else if(c=='F'){
			x=read();
			f[x]={x,0};
		}
		else if(c=='U'){
			x=read();
			t[x]=1;
			cnt++;
		}
		else{
			x=read(),y=read();
//			pii v=find(y);
//			if(c=='-'){
//				if(v.se==-1) f[x]={y,1};
//				else if(v.se==1) f[x]={y,-1};
//				else{
//					if(t[v.fi]){
//						t[f[x].fi]=1;
//						
//					}
//				}
//			}
//			else{
//				f[x]={y,1};
//			}
		}
	}
//	for(int i=1;i<=n;i++){
//		if(f[i].se!=0&&!vis[i]) f[i]=find(f[i].fi);
//	}
	printf("%d\n",n);
}
void solve1(){
	memset(f,0,sizeof f);
	memset(t,0,sizeof t);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		char c;int x;
		cin>>c;x=read();
		if(t[x]) continue;
		if(c=='T'){
			if(a[x]==-1) t[x]=1;
			else a[x]=1;
		}
		else if(c=='F'){
			if(a[x]==1) t[x]=1;
			else a[x]=-1;
		}
		else t[x]=1;
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(t[i]) cnt++;
	printf("%d\n",cnt);
}
void solve2(){
	memset(f,0,sizeof f);
	memset(t,0,sizeof t);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		char c;int x,y;
		cin>>c;
		if(c=='U'){
			x=read();
			t[x]=1;
		}
		else{
			x=read(),y=read();
			if(t[y]==1) t[x]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(t[i]) cnt++;
	printf("%d\n",cnt);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	C=read(),T=read();
	if(C==3||C==4) while(T--) solve1();
	else if(C==5||C==6) while(T--) solve2();
	else while(T--) solve();
	return 0;
}