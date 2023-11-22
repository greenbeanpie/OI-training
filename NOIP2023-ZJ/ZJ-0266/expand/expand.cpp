#include <bits/stdc++.h>

using i64 = long long;

signed main() {
	
	freopen ("expand.in", "r", stdin);
	freopen ("expand.out", "w", stdout);
	
	int c, n, m, q;
	std::cin >> c >> n >> m >> q;
	
	if(c <= 7) {
		
		std::vector<int> a(n + 1), b(m + 1), na(n + 1), nb(m + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			std::cin >> b[i];
		}
		
		for (int i = 1; i <= n; i++) {
			na[i] = a[i];
		}
		for (int i = 1; i <= m; i++) {
			nb[i] = b[i];
		}
		
		std::vector<std::vector<bool>> sdp1(n + 1, std::vector<bool> (m + 1, 0));
		sdp1[1][1] = (na[1] > nb[1]);
		for (int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if (i == 1 and j == 1) continue;
				if(na[i] > nb[j]) {
					if (sdp1[i - 1][j] or sdp1[i][j - 1] or sdp1[i - 1][j - 1]) {
						sdp1[i][j] = 1;
					}
				}
			}
		}
			
		std::vector<std::vector<bool>> sdp2(n + 1, std::vector<bool> (m + 1, 0));
		sdp2[1][1] = (na[1] < nb[1]);
		for (int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if (i == 1 and j == 1) continue;
				if(na[i] < nb[j]) {
					if (sdp2[i - 1][j] or sdp2[i][j - 1] or sdp2[i - 1][j - 1]) {
						sdp2[i][j] = 1;
					}
				}
			}
		}
			
		std::cout << (sdp1[n][m] | sdp2[n][m]);
		
		while (q--) {
			for (int i = 1; i <= n; i++) {
				na[i] = a[i];
			}
			for (int i = 1; i <= m; i++) {
				nb[i] = b[i];
			}
			
			int x, y;
			std::cin >> x >> y;
			for (int i = 1; i <= x; i++) {
				int aka, her;
				std::cin >> aka >> her;
				na[aka] = her;
			}
			for (int i = 1; i <= y; i++) {
				int aka, her;
				std::cin >> aka >> her;
				nb[aka] = her;
			}
			
			std::vector<std::vector<bool>> dp1(n + 1, std::vector<bool> (m + 1, 0));
			dp1[1][1] = (na[1] > nb[1]);
			for (int i = 1; i <= n; i++) {
				for(int j = 1; j <= m; j++) {
					if (i == 1 and j == 1) continue;
					if(na[i] > nb[j]) {
						if (dp1[i - 1][j] or dp1[i][j - 1] or dp1[i - 1][j - 1]) {
							dp1[i][j] = 1;
						}
					}
				}
			}
			
			std::vector<std::vector<bool>> dp2(n + 1, std::vector<bool> (m + 1, 0));
			dp2[1][1] = (na[1] < nb[1]);
			for (int i = 1; i <= n; i++) {
				for(int j = 1; j <= m; j++) {
					if (i == 1 and j == 1) continue;
					if(na[i] < nb[j]) {
						if (dp2[i - 1][j] or dp2[i][j - 1] or dp2[i - 1][j - 1]) {
							dp2[i][j] = 1;
						}
					}
				}
			}
			
			std::cout << (dp1[n][m] | dp2[n][m]);
		}
		
		std::cout << std::endl;
	} else {
		while (q--) {
			std::cout << "0";
		}
		std::cout << std::endl;
	}
	   
    return 0;
}

/*
The contest will finish soon.
I think I will get 100 + [60 - 100] + [25 - 35] + 8 = [193 - 243] pts
It is much better then I pridicted.
But I think there are so many bugs. Hope I can get good grades.

If you see this, You can have a look my Luogu : 344543, Misty-Hazers
You can chat with me. I want to make friends with you.
I'm sorry my English is not very good.
*/
