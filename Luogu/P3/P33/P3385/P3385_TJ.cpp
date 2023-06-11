#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring> 
using namespace std;
int T, n, m, u, v, w;
vector <pair<int, int> > G[2001];
int dis[2001], cnt[2001];
bool in[2001];
void spfa(){
	memset(dis, 0x3f3f, sizeof(dis));
	memset(in, 0, sizeof(in));
	memset(cnt, 0, sizeof(cnt));
	queue <int> q;
	q.push(1);
	dis[1] = 0;
	in[1] = true;
	cnt[1] = 1;
	while (!q.empty()){
		u = q.front();
		q.pop();
		in[u] = false;
		for (int i = 0; i < G[u].size(); i++){
			v = G[u][i].first;
			w = G[u][i].second;
			if (dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				if (!in[v]){
					cnt[v]++;
					q.push(v);
					in[v] = true;
					if (cnt[v] >= n){
						printf("YES\n");
						return;
					} 
				}
			}
		}
	}
	printf("NO\n");
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("P3385_2.in", "r", stdin);
#endif
	scanf("%d", &T);
	for (int  t = 0; t < T; t++){
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++){
			G[i].clear();
		}
		for (int i = 0; i < m; i++){
			scanf("%d%d%d", &u, &v, &w);
			G[u].push_back(make_pair(v, w));
			if (w >= 0){
				G[v].push_back(make_pair(u, w)); 
			} 
		}
		spfa();
	}
	return 0;
}