// Think twice, code once.
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define eputchar(c) putc(c, stderr)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(str) fputs(str, stderr), putc('\n', stderr)
using namespace std;

int n, m, b[26];
string s[3005];
int mn1, mn2;

int main() {
	freopen("dict.in", "r",stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		for (char c : s[i]) b[c - 'a']++;
		s[i] = "";
		for (int j = 25; j >= 0; j--)
			for (int k = 1; k <= b[j]; k++) s[i].push_back(j + 'a');
		for (char c : s[i]) b[c - 'a']--;
		if (mn1 == 0 || s[mn1] > s[i]) mn2 = mn1, mn1 = i;
		else if (mn2 == 0 || s[mn2] > s[i]) mn2 = i;
	}
	for (int i = 1; i <= n; i++) {
		reverse(s[i].begin(), s[i].end());
		if (i != mn1) cout << (s[i] < s[mn1] ? '1' : '0');
		else cout << (s[i] < s[mn2] ? '1' : '0');
		reverse(s[i].begin(), s[i].end());
	}
	cout << '\n';
	return 0;
}