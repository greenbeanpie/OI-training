#include<bits/stdc++.h>
typedef long long ll;
#define int ll
constexpr int maxn = 3e3 + 20;
constexpr int mod = 1e9 + 7;
using namespace std;

inline void FileIO(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int n, m;
string s[maxn], ps;
string smax[maxn], smin[maxn];

signed main() {
	
	FileIO("dict");
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
		ps = s[i];
		sort(ps.begin(), ps.end()); smin[i] = ps;
		reverse(ps.begin(), ps.end()); smax[i] = ps;
	}
	
	if(n == 1) {
		cout << "1\n";
		return 0;
	}
	
	for(int i = 1; i <= n; ++i) {
		bool flag = 1;
		for(int j = 1; j <= n; ++j) {
			if(i == j) continue;
			if(smin[i] >= smax[j]) {
				flag = 0;
			}
		}
		cout << flag;
	}
	
	
	
	return 0;
}

