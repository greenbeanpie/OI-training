//lzy AK IOI
//lzx AK IOI
#include<bits/stdc++.H>
#define int long long
using namespace std;
const int N = 1e5+10;
int fa[N];
bool f[N];
int n,m,c,T;
char a[N];
bool vis[N];
int ans = INT_MAX,tmp;
vector <int> g[N];
queue <int> q;
bool flag = 0;
int find(int x){
	if(x == fa[x])return x;
	return fa[x] = find(fa[x]);
}
void DFS(int x,char dp,int dep){
//	cout<<x<<endl;
	vis[x] = 1;
	for(int i=0;i<g[x].size();i++){
		int u = g[x][i];
		if(vis[u])continue;
		if(dp == 'U')tmp ++;
		DFS(u,dp,dep+1);
	}
	return ;
}
void dfs(int x,char dp){
	cout<<x<<dp<<endl;
	vis[x] = 1;
	if(a[x] == 'R')a[x] = dp;
	else{
		if(a[x] != dp){
			flag = 1;
			tmp ++ ;	
		}
		vis[x] = 0;
		a[x] = 'R';
		return ;
	}
	for(int i=0;i<g[x].size();i++){
		int u = g[x][i];
		if(vis[u])continue;
		if(dp == 'T'){
			if(f[u] == 0){
				a[u] = 'T';
				dfs(u,'T');
			}
			else{
				a[u] = 'F';
				dfs(u,'F');
			}
		}else{
			if(f[u] == 0){
				a[u] = 'F';
				dfs(u,'F');
			}
			else{
				a[u] = 'T';
				dfs(u,'T');
			}
		}
	}
	vis[x] = 0;
	a[x] = 'R';
	if(flag) tmp++;
	return ;
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> m;
		for(int i=1;i<N;i++){
			fa[i] = i;
			f[i] = 0;
			g[i].clear();
			a[i] = 'R';
			vis[i] = 0;
		}
		for(int i=1;i<=n;i++){
			fa[i] = n+i;	
		}
		ans = 0;
		while(m --){
			char op;
			int x,y;
			cin >> op;
			if(op == '+'){
				scanf("%lld %lld",&x,&y);
				int by = find(y);
				fa[x] = by;
				f[x] = f[y];
			}
			else if(op == '-'){
				scanf("%lld %lld",&x,&y);
				int by = find(y);
				fa[x] = by;
				f[x] = !f[y];
			}
			else if(op == 'F'){
				scanf("%lld",&x);
				fa[x] = 2*n+1;
				f[x] = 0;
			}
			else if(op == 'T'){
				scanf("%lld",&x);
				fa[x] = 2*n+2;
				f[x] = 0;
			}
			else if(op == 'U'){
				scanf("%lld",&x);
				fa[x] = 2*n+3;
				f[x] = 0;
			}
		}
		for(int i=1;i<=3;i++){
			q.push(n+i);
		}
		for(int i=1;i<=n;i++){
			int bx = find(i);
			if(bx == n+i){
				q.push(i);
			}
			else{
				g[bx - n].push_back(i);
				g[i].push_back(bx-n);
			}
		}
		while(!q.empty()){
			tmp = 0;
			int minn = INT_MAX;
			int u = q.front();q.pop();
			if(u > n){
				if(u == n+3){
					DFS(u,'U',1);
				}
				else DFS(u,'F',1);
				minn = min(minn,tmp);
			}
			else{
				if(f[u] == 1){
					tmp++;
					DFS(u,'U',1);	
				}
				else DFS(u,'F',1);
				minn = min(minn,tmp);
			}
			ans+=minn;
		}
//		for(int i=1;i<=n;i++){
//			if(vis[i]){
//				cout<<i<<endl;
//				continue;
//			}
//			int minn = INT_MAX;
//			cout<<endl<<i<<endl;
//			for(auto u:g[i]){
//				cout<<u<<" ";
//			}
//			cout<<endl;
//			for(int j=1;j<=3;j++){
//				tmp = 0;
//				flag = 0;
//				if(j == 1){
//					dfs(i,'T');
//				}
//				else if(j == 2){
//					dfs(i,'F');
//				}
//				else{
//					tmp ++ ;
//					DFS(i,'U',1);
//				}
//				minn = min(minn,tmp);
//			}
//			ans += minn;
//			cout<<minn<<endl;
////			cout<<find(i) - n<<" "<<f[i]<<endl;
//		}
		printf("%lld\n",ans);
	}
	return 0;
}
