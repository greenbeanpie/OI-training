#include<bits/stdc++.h>
using namespace std;
int c, T;
int n, m;
pair<int, int> p[100005];
vector<int>t[100005];
int vis[100005];
int ans;
void dfs(int o){
	queue<int>q;
	q.push(o);
	while(!q.empty()){
		int pp = q.front();
		q.pop();
		ans++;
		for(auto to : t[pp]){
			if(!vis[to]){
				q.push(to);
				vis[to] = 1;
			}
		}
	}
	return;
}
void dfss(int o){
	queue<int>q;
	q.push(o);
	while(!q.empty()){
		int pp = q.front();
		q.pop();
		for(auto to : t[pp]){
			if(!vis[to]){
				q.push(to);
				vis[to] = 1;
			}
		}
	}
	return;
}
void dfs_(int o){
	queue<int>q;
	q.push(o);
	while(!q.empty()){
		int pp = q.front();
		q.pop();
		ans++;
		for(auto to : t[pp]){
			q.push(to);
			vis[to] = 1;
		}
	}
	return;
}
void dfss_(int o){
	queue<int>q;
	q.push(o);
	while(!q.empty()){
		int pp = q.front();
		q.pop();
		for(auto to : t[pp]){
			q.push(to);
			vis[to] = 1;
		}
	}
	return;
}
signed main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		ans = 0;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)p[i] = make_pair(i, 0);
		while(m--){
			string op;
			cin >> op;
			if(op[0] == 'T'){
				int i;
				scanf("%d", &i);
				p[i] = make_pair(-2, 0);	
			}
			if(op[0] == 'F'){
				int i;
				scanf("%d", &i);
				p[i] = make_pair(-1, 0);	
			}
			if(op[0] == 'U'){
				int i;
				scanf("%d", &i);
				p[i] = make_pair(0, 0);	
			}
			if(op[0] == '+'){
				int i, j;
				scanf("%d%d", &i, &j);
				p[i] = p[j];	
			}
			if(op[0] == '-'){
				int i, j;
				scanf("%d%d", &i, &j);
				p[i] = p[j];
				if(p[i].first <= 0){
					if(p[i].first < 0)p[i].first = -3 - p[i].first;
				}else{
					p[i].second ^= 1;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			t[i].clear();
		}
		for(int i = 1; i <= n; i++){	
			if(p[i].first > 0)t[p[i].first].push_back(i);
		}
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++){
			if(vis[i])continue;
			vector<int>kk;
			kk.push_back(i);
			vis[i] = 1;
			int now = i;
			while(1){
				int last = now;
				now = p[now].first;
				if(now <= 0){
					if(now == 0){
						dfs_(last);
					}else{
						dfss_(last);
					}
					break;
				}
				if(vis[now]){
					int op = 0;
					for(int i = kk.size() - 1; i >= 0; i--){
						if(p[kk[i]].second == 1)op ^= 1;
						if(kk[i] == now){
							for(int j = i - 1; j >= 0; j--){
								vis[kk[j]] = 0;
							}
							if(op == 1){
								for(int j = kk.size() - 1; j >= i; j--){
									dfs(kk[j]);
								}
							}else{
								for(int j = kk.size() - 1; j >= i; j--){
									dfss(kk[j]);
								}
							}
							break;
						}
					}
					break;
				}
				kk.push_back(now);
				vis[now] = 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
0 1
6 6
U 1
U 2
+ 3 1
+ 4 1
+ 5 2
+ 6 2
*/
