#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
int fa[3*maxn],n,m,id,T,a[maxn],vis[15],ql[maxn],qr[maxn],ne[15];
int ans;
char op[maxn];
int findx(int x){
	return fa[x]==x?x:fa[x]=findx(fa[x]);
}
void mer(int x,int y){
	int fax=findx(x),fay=findx(y);
	fa[fax]=fay;
}
int check(){
	memcpy(ne,vis,sizeof(vis));
	for(int i=1;i<=m;++i){
		if(op[i]=='T')ne[ql[i]]=-3;
		else if(op[i]=='F')ne[ql[i]]=-2;
		else if(op[i]=='U')ne[ql[i]]=-1;
		else if(op[i]=='+'){
			ne[ql[i]]=ne[qr[i]];
		}
		else if(op[i]=='-'){
			if(ne[qr[i]]==-3)ne[ql[i]]=-2;
			else if(ne[qr[i]]==-2)ne[ql[i]]=-3;
			else if(ne[qr[i]]==-1)ne[ql[i]]=-1;
		}
	}
	for(int i=1;i<=n;++i){
		if(vis[i]!=ne[i])return 0;
	}
	return 1;
}
void dfs(int step=1,int cnt=0){
	if(step==n+1){
		if(check())ans=min(ans,cnt);
		return;
	}
	vis[step]=-3;
	dfs(step+1,cnt);
	vis[step]=-2;
	dfs(step+1,cnt);
	vis[step]=-1;
	dfs(step+1,cnt+1);
}
// T -3
// F -2
// U -1
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>id>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=2*n;++i){
			if(i<=n)a[i]=0;
			fa[i]=i;
		}
		for(int i=1;i<=m;++i){
			cin>>op[i];
			if(op[i]=='+'){
				cin>>ql[i]>>qr[i];
				a[ql[i]]=a[qr[i]];
			}
			else if(op[i]=='-'){
				cin>>ql[i]>>qr[i];
				a[ql[i]]=qr[i]+n;
			}
			else {
				cin>>ql[i];
				if(op[i]=='T')a[ql[i]]=-3;
				if(op[i]=='F')a[ql[i]]=-2;
				if(op[i]=='U')a[ql[i]]=-1;
			}
		}
		if(id<=2){
			ans=n;
			dfs();
			cout<<ans<<"\n";
		}
		else if(id<=4){
			ans=0;
			for(int i=1;i<=n;++i){
				if(a[i]==-1)++ans;
			}
			cout<<ans<<"\n";
		}
		else if(id<=6){
			ans=0;
			for(int i=1;i<=n;++i)a[i]=0;
			for(int i=m;i>=1;--i){
				if(op[i]=='U'){
					a[ql[i]]=-1;
				}
				else if(a[qr[i]]==-1){
					a[ql[i]]=-1;
				}
			}
			for(int i=1;i<=n;++i)if(a[i]==-1)++ans;
			cout<<ans<<"\n";		
		}
		else continue;
	}
	return 0;
}
