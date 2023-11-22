#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int c,t,n,m,x[maxn],y[maxn],a[maxn],b[maxn],ans;
char v[maxn];
void dfs(int step,int mx){
	if(step==mx+1){
		int tmp=0;
		for(int i=1;i<=n;i++) b[i]=a[i],tmp+=!a[i];
		for(int i=1;i<=m;i++){
			if(v[i]=='+') b[x[i]]=b[y[i]];
			else if(v[i]=='-') b[x[i]]=-b[y[i]];
			else if(v[i]=='T') b[x[i]]=1;
			else if(v[i]=='F') b[x[i]]=-1;
			else b[x[i]]=0;
		}for(int i=1;i<=n;i++) if(b[i]!=a[i]) return ;
		ans=min(ans,tmp);
		return ;
	}for(int i=-1;i<2;i++){
		a[step]=i;
		dfs(step+1,mx);
	}
}int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t ;
	while(t--){
		cin >> n >> m ;
		for(int i=1;i<=m;i++){
			cin >> v[i] >> x[i] ;
			if(v[i]=='+' || v[i]=='-') cin >> y[i] ;
		}if(c<3){
			ans=n;
			dfs(1,n);
			cout << ans << "\n" ;
			continue;
		}else if(c<5){
			ans=0;
			memset(a,-1,sizeof(a));
			memset(b,-1,sizeof(b));
			for(int i=1;i<=m;i++){
				if(v[i]=='T') b[x[i]]=1;
				if(v[i]=='F') b[x[i]]=-1;
				if(v[i]=='U') b[x[i]]=0;
			}for(int i=1;i<=n;i++) if(b[i]!=a[i] && b[i]==0) ans++;
			cout << ans << "\n" ;
		}
	}return 0;
}