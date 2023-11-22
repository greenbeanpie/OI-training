#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
bool vis[100005];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	if(c == 3 || c == 4){
		while(t--){
			cin >> n >> m;
			int ans = 0;
			char v;
			int x;
			memset(vis,0,sizeof vis);
			for(int i = 1;i <= m;i++){
				cin >> v >> x;
				if(v != 'U'){
					if(vis[x]){
						ans--;
						vis[x] = 0;
					}
				}
				if(v == 'U' && !vis[x]){
					vis[x] = 1;
					ans++;
				}
			}
			cout << ans << "\n";
		}
	}else if(c == 5 || c == 6){
		while(t--){
			cin >> n >> m;
			int ans = 0;
			char v;
			int x,y;
			memset(vis,0,sizeof vis);
			for(int i = 1;i <= m;i++){
				cin >> v;
				if(v == '+'){
					cin >> x >> y;
					if(vis[y] && !vis[x]){
						vis[x] = 1;
						ans++;
					
					}
					if(vis[x] && !vis[y]){
						vis[x] = 0;
						ans--;
					}
				}else{
					cin >> x;
					if(!vis[x]){
						ans++;
						vis[x] = 1;
					}
				}
			}
			cout << ans << "\n";
		}
	}else{
		for(int i = 1;i <= t;i++){
			cout << "0\n";
		}
	}
	return 0;
}
