#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mpr make_pair
const int SIZE = 3003;
const int mod = 998244353;
int n, m, tot;
char a[SIZE][SIZE];
vector<pair<char, int> > t[SIZE*SIZE];
int cnt[SIZE*SIZE], siz[SIZE*SIZE];
bool ans[SIZE];

inline int rd(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x<<1)+(x<<3)+(ch^48);
		ch = getchar();
	}
	return x*f;
}

void insert(int id){
	int now = 1;
	for(int i = m; i >= 1; i--){
		int nx = a[id][i]-'a'; bool ff = 0; int jl = 0;
		for(int j = 0; j < t[now].size(); j++){
			if(t[now][j].first == nx){
				ff = 1; jl = t[now][j].second;
				break;
			}
		}
		if(!ff) t[now].push_back(mpr(nx, ++tot)), jl = tot;
		now = jl;
	}	
	cnt[now]++;
}

void dfs(int x){
	siz[x] = cnt[x];
	sort(t[x].begin(), t[x].end());
	for(int i = 0; i < t[x].size(); i++){
		dfs(t[x][i].second);
		siz[x] += siz[t[x][i].second];
	}
}

bool ask(int id){
	int now = 1;
	for(int i = 1; i <= m; i++){
		int jl = 0;
		for(int j = 0; j < t[now].size(); j++){
			if(t[now][j].first == a[id][i]-'a') jl = t[now][j].second;
			if(t[now][j].first >= a[id][i]-'a') break;
			if(siz[t[now][j].second]) return 0;
		}
		if(!jl) return 1;
		now = jl;
	}
	return 1;
}

int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	n = rd(), m = rd(); tot = 1;
	for(int i = 1; i <= n; i++){
		cin >> (a[i]+1);
		sort(a[i]+1, a[i]+m+1);
		insert(i);
	}
	if(n == 1){
		printf("1");
		return 0;
	}
	dfs(1);
	for(int i = 1; i <= n; i++){
		ans[i] = ask(i);
	}
	for(int i = 1; i <= n; i++){
		printf("%d", ans[i]);
	}
	return 0;
}
