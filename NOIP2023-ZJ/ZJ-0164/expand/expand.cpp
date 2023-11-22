#include<bits/stdc++.h>
using namespace std;
int vis[2005],linker[2005],mp[2005][2005],c,n,m,q,a[2005],b[2005];
int ya[2005],yb[2005];
bool dfs(int u){	
	for(int v=1;v<=m;++v){
		if(!vis[v]&&mp[u][v]){
			vis[v]=1;
			if(!linker[v]||dfs(linker[v])){
				linker[v]=u;
				return true;
			}
			vis[v]=0;
		}
	}
	return false;
}
int cal(){
	if(a[1]==b[1])return 0;
	if(a[1]<b[1]){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i]<b[j])mp[i][j]=1;
				else mp[i][j]=0;
			}
		}
	}		
	else{
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i]>b[j])mp[i][j]=1;
				else mp[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;++i){
		memset(vis,0,sizeof(vis));
		if(!dfs(i)){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;++i)cin>>ya[i];
	for(int i=1;i<=m;++i)cin>>yb[i];
	memcpy(a,ya,sizeof(ya));
	memcpy(b,yb,sizeof(yb));
	cout<<cal();
	for(int i=1;i<=q;++i){
		memset(linker,0,sizeof(linker));
		memcpy(a,ya,sizeof(ya));
		memcpy(b,yb,sizeof(yb));
		int kx,ky;
		cin>>kx>>ky;
		for(int j=1,x,y;j<=kx;++j){
			cin>>x>>y;
			a[x]=y;
		}
		for(int j=1,x,y;j<=ky;++j){
			cin>>x>>y;
			b[x]=y;
		}
		cout<<cal();
	}
}
