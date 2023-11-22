#include <bits/stdc++.h>
#define gc() (iS == iT && (iT = (iS = buf) + fread(buf, 1, 1 << 20, stdin), iS == iT) ? EOF : *iS++)
char buf[1 << 20], *iS = buf, *iT = buf;
template <typename _Tp> inline void read(_Tp& x) {
	x = 0; char c = gc(); bool f = 0;
	for(; !std::isdigit(c); c = gc()) f |= c == '-';
	for(; std::isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48);
	f ? x = ~x + 1 : 1;
}
template <> inline void read(std::string& x) {
	x.clear(); char c = gc();
	for(; !std::isgraph(c); c = gc());
	for(; std::isgraph(c); c = gc()) x += c;
}
template <typename _Tp, typename ...Args>
inline void read(_Tp& x, Args& ...args) {
	read(x), read(args...);
}
inline void FileIO(std::string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

typedef long long i64;
constexpr int N = 3e3 + 5;
std::string w[N], a[N], b[N], min;
int n, m, cnt;

inline bool check(int i) {
	for(int j = 1; j <= n; j++) {
		if(i == j) continue;
		if(b[i] < a[j]) continue;
		return 0;
	}
	return 1;
}

bool chk[N];
inline bool check2(int i) {
	return b[i] < min || ((b[i] == min && chk[i] && cnt == 1));
}

int buc[26];
inline std::string sort(std::string s) {
	std::string res; res.clear();
	memset(buc, 0, sizeof(buc));
	for(auto& c : s) buc[c - 'a']++;
	for(int c = 0; c < 26; c++) {
		while(buc[c]--) res.push_back(c + 'a');
	}
	return res;
}

inline std::string isort(std::string s) {
	std::string res; res.clear();
	memset(buc, 0, sizeof(buc));
	for(auto& c : s) buc[c - 'a']++;
	for(int c = 25; c >= 0; c--) {
		while(buc[c]--) res.push_back(c + 'a');
	}
	return res;
}

signed main() {
	FileIO("dict");
	read(n, m);
	if(n <= 300 && m <= 300) {
		for(int i = 1; i <= n; i++) read(w[i]);
		for(int i = 1; i <= n; i++) {
			a[i] = w[i], b[i] = w[i];
			std::sort(a[i].begin(), a[i].end(), std::greater<char>()); // down
			std::sort(b[i].begin(), b[i].end(), std::less<char>()); // up
		}
		for(int i = 1; i <= n; i++) putchar(check(i) ? '1' : '0');
		putchar('\n');
	} else {
		for(int i = 1; i <= n; i++) read(w[i]);
		for(int i = 1; i <= n; i++) {
			a[i] = isort(w[i]), b[i] = sort(w[i]);
			if(i == 1) min = a[i];
			else if(a[i] < min) min = a[i];
		}
		for(int i = 1; i <= n; i++) if(a[i] == min) chk[i] = 1, cnt++;
		for(int i = 1; i <= n; i++) putchar(check2(i) ? '1' : '0');
		putchar('\n');
	}
	return 0;
}
/*
11:13 100pts
2h left
*/
