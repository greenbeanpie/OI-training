#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 100005;
int _, T, Cnt, n, m, A[MAXN], Tag[MAXN], F[MAXN], Ans, X[MAXN];
void DFS(int id){
	Tag[id] = Cnt;
	if(A[id] ==  n + 1){X[id] =  1; return;}
	if(A[id] == -n - 1){X[id] = -1; return;}
	if(A[id] ==      0){X[id] =  0; return;}
	int nxt = abs(A[id]), f = A[id] < 0? -1: 1;
	if(Tag[nxt] == Cnt){X[id] = F[id] * f == F[nxt]; return;}
	if(!Tag[nxt]) F[nxt] = F[id] * f, DFS(nxt);
	X[id] = X[nxt] * f;
}
int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	for(cin >> _ >> T; T--;){
		cin >> n >> m, Ans = Cnt = 0;
		for(int i = 1; i <= n; i++) X[A[i] = i] = Tag[i] = 0;
		while(m--){
			char c; cin >> c;
			if(c == 'T'){int x; cin >> x, A[x] =  n + 1;}
			if(c == 'F'){int x; cin >> x, A[x] = -n - 1;}
			if(c == 'U'){int x; cin >> x, A[x] =      0;}
			if(c == '+'){int x, y; cin >> x >> y, A[x] =  A[y];}
			if(c == '-'){int x, y; cin >> x >> y, A[x] = -A[y];}
		}
		for(int i = 1; i <= n; i++) if(!Tag[i]) F[i] = 1, Cnt++, DFS(i);
		for(int i = 1; i <= n; i++) Ans += !X[i];
		cout << Ans << '\n';
	}
	return 0;
}