//I would appreciate it if CCF cound give me 1=
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0),cout.tie(0)
#define pb push_back
//#define int long long
using namespace std;
int c,T,n,m,ans;
int a[200005],t[200005];
struct node{
	char op;
	int x,y;
}b[200005];
int calc(int x){
	if(x==1) return 2;
	if(x==2) return 1;
	return 3;
}
bool check(){
	for(int i=1;i<=n;i++) t[i]=a[i];
	for(int i=1;i<=m;i++){
		if(b[i].op=='U') t[b[i].x]=3;
		else if(b[i].op=='T') t[b[i].x]=1;
		else if(b[i].op=='F') t[b[i].x]=2;
		else if(b[i].op=='+') t[b[i].x]=t[b[i].y];
		else t[b[i].x]=calc(t[b[i].y]);
	}
	for(int i=1;i<=n;i++) if(a[i]^t[i]) return 0;
	return 1;
}
void dfs(int x,int cnt){
	if(x==n+1){
		if(check()) ans=min(ans,cnt);
		return ;
	}
	for(int i=1;i<=3;i++){
		a[x]=i;
		dfs(x+1,cnt+(i==3));
	}
}
vector<int> g[200005];
void solve(){
	cin>>n>>m;
	ans=1e9;
	for(int i=1;i<=m;i++){
		cin>>b[i].op>>b[i].x;
		if(b[i].op=='+'||b[i].op=='-') cin>>b[i].y;
	}
	if(c<=2){
		dfs(1,0);
		cout<<ans<<endl;
	}
	else if(c<=4){
		for(int i=1;i<=n;i++) a[i]=0;
		for(int i=1;i<=m;i++){
			if(b[i].op=='U') a[b[i].x]=3;
			else if(b[i].op=='T') a[b[i].x]=1;
			else a[b[i].x]=2;
		}
		ans=0;
		for(int i=1;i<=n;i++) if(a[i]==3) ans++;
		cout<<ans<<endl;
	}
	else if(c<=6){
		for(int i=1;i<=n;i++) a[i]=0,g[i].clear();
		for(int i=m;i>=1;i--){
			if(b[i].op=='U') a[b[i].x]=3;
			else g[b[i].y].pb(b[i].x);
		}
		ans=0;
		for(int i=1;i<=n;i++) if(a[i]==3) ans++;
		cout<<ans<<endl;
	}
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	IOS;TIE;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}

/*
1 3
6 10

*/
