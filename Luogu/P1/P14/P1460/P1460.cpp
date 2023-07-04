#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int long long
#define Pii pair<int,int>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
int v,g,require[26],now[26],food[16][26];
bool vis[16];
int max_depth;
void dfs(int last,int dep){
	if(dep==max_depth){
		for(int i=1;i<=v;i++){
			if(now[i]<require[i]){
				return;
			}
		}
		cout << max_depth << " ";
		for(int i=1;i<=g;i++){
			if(vis[i]){
				cout << i << " ";
			}
		}
		exit(0);
	}
	for(int i=last+1;i<=g;i++){
		if(!vis[i]){
			for(int j=1;j<=v;j++){
				now[j]+=food[i][j];
			}
			vis[i]=true;
			dfs(i,dep+1);
			vis[i]=false;
			for(int j=1;j<=v;j++){
				now[j]-=food[i][j];
			}
		}
	}
}
signed main(){
	#ifdef CODESPACE
		freopen("P1460.in","r",stdin);
		freopen("P1460.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> v;
	for(int i=1;i<=v;i++){
		cin >> require[i];
	}
	cin >> g;
	for(int i=1;i<=g;i++){
		for(int j=1;j<=v;j++){
			cin >> food[i][j];
		}
	}
	for(max_depth=1;max_depth<=15;max_depth++){
		dfs(0,0);
	}
	return 0;
}