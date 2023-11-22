#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m,c,T;
bool op[N*2];
int fr[N*2];
inline int g(char p){
	if(p=='T')	return 1;
	else if(p=='F')	return 2;
	return 3;
}
int fa[N*2],siz[N*2];
int find(int w){
	if(w==fa[w])	return w;
	return fa[w]=find(fa[w]);
}
bool vis[N*2];
void merge(int u,int v){
	int fu=find(u);
	int fv=find(v);
	if(fu==fv)	return ;
	fa[fu]=fv;
	siz[fv]+=siz[fu];
}
int f(int w){
	if(vis[w])	return w;
	vis[w]=1;
	if(w==0)	return 0;
	if(w==fr[w])	return w;
	return fr[w]=f(fr[w]);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		if(c==7||c==8){
			for(int i=1;i<=n*2;i++)	fa[i]=i,op[i]=0,fr[i]=i,siz[i]=1; 
			while(m--){
				char p;
				int x,y;
				cin>>p>>x>>y;
				if(p=='+'){
					fr[x]=fr[y];
					op[x]=0;
				}
				else{
					fr[x]=fr[y];
					op[x]=1;
				}
			}
			for(int i=1;i<=n;i++){
				if(op[i]==0){
					merge(i,fr[i]);
					merge(i+n,fr[i]+n);
				}
				else{
					merge(i,fr[i]+n);
					merge(i+n,fr[i]);
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				int fx=find(i),fy=find(i+n);
				if(fx==fy)	vis[fx]=1;
			}
			for(int i=1;i<=n*2;i++){
				if(vis[i])	ans+=siz[i];
			}
			cout<<ans/2<<"\n";
		}
		else if(c==5||c==6){
			for(int i=0;i<=n;i++)	fr[i]=i,vis[i]=0;
			while(m--){
				char p;
				int x,y;
				cin>>p;
				if(p=='+'){
					scanf("%d%d",&x,&y);
					fr[x]=fr[y];
				}
				else{
					scanf("%d",&x);
					fr[x]=0;
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(!f(i))	ans++;
			}
			cout<<ans<<"\n";
		}
		else cout<<0<<"\n";
	}
	return 0;
}/*
考虑中间赋值怎么操作 
remember to clear
1 1
3 3
- 2 1
- 3 2
+ 1 3
*/
