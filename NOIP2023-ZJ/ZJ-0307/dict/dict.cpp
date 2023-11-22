#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 3e3 + 5;
const unsigned long long MOD = 1331;

int n, m, T[30];
unsigned long long h1[N][N], h2[N][N];
string s[N], t[N];

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();};
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	n = read(), m = read();
	if(n == 1) {
		puts("1");
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		s[i] = "";
		char c = getchar();
		while(c < 'a' || c > 'z') c = getchar();
		while(c >= 'a' && c <= 'z') s[i] += c, c = getchar();
		for(int j = 0; j < 26; j++) T[j] = 0;
		for(int j = 0; j < m; j++) T[s[i][j] - 'a']++;
		s[i] = t[i] = "";
		for(int j = 0; j < 26; j++)
			for(int k = 1; k <= T[j]; k++)
				s[i] += 'a' + j;
		for(int j = 25; j >= 0; j--)
			for(int k = 1; k <= T[j]; k++)
				t[i] += 'a' + j;
		for(int j = 1; j <= m; j++) {
			h1[i][j] = h1[i][j - 1] * MOD + s[i][j - 1];
			h2[i][j] = h2[i][j - 1] * MOD + t[i][j - 1];
		}
	}
	for(int i = 1; i <= n; i++) {
		bool f = 1;
		for(int j = 1; j <= n; j++) {
			if(i == j) continue;
			int l = 0, r = m, pos;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(h1[i][mid] != h2[j][mid]) r = mid - 1;
				else l = mid + 1, pos = mid;
			}
			if(pos == m || s[i][pos] >= t[j][pos]) f = 0;
		}
		if(f) putchar('1');
		else putchar('0');
	}
	puts("");
	return 0;
}