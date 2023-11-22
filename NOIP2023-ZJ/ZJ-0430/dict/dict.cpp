#include <bits/stdc++.h>
using namespace std;
const int N = 3010;

int n, m, tot;
string S, minn[N];

int trie[N * 3000][27], endcnt[N * 3000];

void insert(string S) {
	int p = 0;
	for (char c : S) {
		int x = c - 'a';
		if (!trie[p][x]) trie[p][x] = ++tot;
		p = trie[p][x];
	}
	++endcnt[p];
}

int check(string s) {
	int p = 0;
	for (char c : s) {
		int x = c - 'a';
		for (int j = 0; j < x; j++)
			if (trie[p][j]) return 0;
		if (!trie[p][x]) return 1;
		p = trie[p][x];
	}
	return (endcnt[p] <= 1 ? 1 : 0);
}


int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> S;
		sort(S.begin(), S.end());
		minn[i] = S;
		sort(S.begin(), S.end(), [](char a, char b){ return a > b; });
		insert(S);
	}
	for (int i = 1; i <= n; i++) {
		cout << check(minn[i]);
	}
	cout << "\n";
	return 0;
}
