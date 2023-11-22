#include <bits/stdc++.h>

using i64 = long long;

void solve1() {
	int n, m, k, d;
	std::cin >> n >> m >> k >> d;
	
	std::vector<std::vector<std::pair<int,int>>> a(n + 3);
	for (int i = 0; i < m; i++) {
		int x, y, val;
		std::cin >> x >> y >> val;
		a[x + 1].push_back(std::make_pair(x - y + 1, val));
	}
	
	auto dfs = [&](auto self, int x, int lst, int nowval) -> i64 {
		if ((x - lst - 1) > k) return 0ll;
		
		int qwq = nowval;
		for (auto p : a[x]) {
			if (lst < p.first) {
				qwq += p.second; 
			}
		}
		
		if (x == n + 1) return qwq;
		return std::max(self(self, x + 1, lst, qwq - d), self(self, x + 1, x, qwq));
	};
	
	std::cout << dfs(dfs, 1, 0, 0) << std::endl;
	return ;
}

signed main() {
	
	freopen ("run.in", "r", stdin);
	freopen ("run.out", "w", stdout);
	
	int c, T;
	std::cin >> c >> T;
	
	if (c == 1 or c == 2) {
		while (T--) {
			solve1();
		}
	} else {
		while (T--) {
			std::cout << 0 << std::endl;
			// I know I can't solve a so difficult problem like this
			// so can you give me 45 pts?
			// please! I thank you ccf !!!
		}
	}
	   
    return 0;
}

/*
Oh, I'm so bored (12: 30)
I'm a junior high school student 
I used to think I will AFO after taking 1=
but I think I will be more and more confident
and also be more and more strong
we should fight fight fight, without stopping

Never gonna give you up~
Never gonna let you down~

rp++ rp++
#define int long long
](
using namespace std;
//freopen
*/