#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3005;
int n, m; char A[MAXN], B[MAXN];
char X[MAXN];
int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		char l = 'z', r = 'a';
		cin >> X;
		for(int j = 0; j < m; j++){
			if(X[j] < l) l = X[j];
			if(X[j] > r) r = X[j];
		}
		A[i] = l;
		B[i] = r;
	}
	for(int i = 1; i <= n; i++){
		bool vis = 1;
		for(int j = 1; j <= n; j++) if(i != j && A[i] >= B[j]) vis = 0;
		cout << vis;
	}
	cout << '\n';
	return 0;
}