#include <iostream>
#include <stdio.h>
using namespace std;

const int maxN = 2010;
const int maxQ = 70;
const int INF = 1e9 + 10;

int c, n, m, q;
int nums1[maxN], nums2[maxN], temp1[maxN], temp2[maxN];
bool dp[maxN][maxN];
int ans[maxQ];

int main(void) {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	scanf("%d%d%d%d", &c, &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &nums1[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &nums2[i]);
	}
	
	int kx, ky, p, v;
	/*if (n == 1 && m == 1) {
		if (nums1[1] != nums2[1]) {
			ans[1] = 1;
		}
		else {
			ans[1] = 0;
		}
		for (int i = 2; i <= q + 1; i++) {
			scanf("%d%d", &kx, &ky);
			for (int j = 1; j <= kx; j++) {
				scanf("%d%d", &p, &v);
				nums1[p] = v;
			}
			for (int j = 1; j <= ky; j++) {
				scanf("%d%d", &p, &v);
				nums2[p] = v;
			}
			if (nums1[1] != nums2[1]) {
				ans[i] = 1;
			}
			else {
				ans[i] = 0;
			}
		}
	}
	if (n == 1 && m == 2) {
		if (nums1[1] < nums2[1] && nums1[1] < nums2[2]) {
			ans[1] = 1;
		}
		else if (nums1[1] > nums2[1] && nums1[1] > nums2[2]) {
			ans[1] = 1;
		}
		else {
			ans[1] = 0;
		}
		for (int i = 2; i <= q + 1; i++) {
			scanf("%d%d", &kx, &ky);
			for (int j = 1; j <= kx; j++) {
				scanf("%d%d", &p, &v);
				nums1[p] = v;
			}
			for (int j = 1; j <= ky; j++) {
				scanf("%d%d", &p, &v);
				nums2[p] = v;
			}
			if (nums1[1] < nums2[1] && nums1[1] < nums2[2]) {
				ans[i] = 1;
			}
			else if (nums1[1] > nums2[1] && nums1[1] > nums2[2]) {
				ans[i] = 1;
			}
			else {
				ans[i] = 0;
			}
		}
	}
	if (n == 2 && m == 1) {
		if (nums2[1] < nums1[1] && nums2[1] < nums1[2]) {
			ans[1] = 1;
		}
		else if (nums2[1] > nums1[1] && nums2[1] > nums1[2]) {
			ans[1] = 1;
		}
		else {
			ans[1] = 0;
		}
		for (int i = 2; i <= q + 1; i++) {
			scanf("%d%d", &kx, &ky);
			for (int j = 1; j <= kx; j++) {
				scanf("%d%d", &p, &v);
				nums1[p] = v;
			}
			for (int j = 1; j <= ky; j++) {
				scanf("%d%d", &p, &v);
				nums2[p] = v;
			}
			if (nums2[1] < nums1[1] && nums2[1] < nums1[2]) {
				ans[1] = 1;
			}
			else if (nums2[1] > nums1[1] && nums2[1] > nums1[2]) {
				ans[1] = 1;
			}
			else {
				ans[1] = 0;
			}
		}
	}
	if (n == 2 && m == 2) {
		if (nums2[1] < nums1[1] && nums2[2] < nums1[2]) {
			ans[1] = 1;
		}
		else if (nums2[1] > nums1[1] && nums2[2] > nums1[2]) {
			ans[1] = 1;
		}
		else {
			ans[1] = 0;
		}
		for (int i = 2; i <= q + 1; i++) {
			scanf("%d%d", &kx, &ky);
			for (int j = 1; j <= kx; j++) {
				scanf("%d%d", &p, &v);
				nums1[p] = v;
			}
			for (int j = 1; j <= ky; j++) {
				scanf("%d%d", &p, &v);
				nums2[p] = v;
			}
			if (nums2[1] < nums1[1] && nums2[2] < nums1[2]) {
				ans[1] = 1;
			}
			else if (nums2[1] > nums1[1] && nums2[2] > nums1[2]) {
				ans[1] = 1;
			}
			else {
				ans[1] = 0;
			}
		}
	}*/
	if (nums1[1] == nums2[1]) {
		ans[1] = 0;
	}
	else if (nums1[1] > nums2[1]){
		int mn = INF, mx = 0;
		for (int i = 1; i <= n; i++) {
			mn = min(mn, nums1[i]);
			if (mn > nums2[1]) dp[i][1] = 1;
			else dp[i][1] = 0;
		}
		for (int i = 1; i <= m; i++) {
			mx = max(mx, nums2[i]);
			if (nums1[1] > mx) dp[1][i] = 1;
			else dp[1][i] = 0;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 2; j <= m; j++) {
				if (nums1[i] <= nums2[j]) {
					dp[i][j] = 0;
				}
				else if (dp[i][j - 1] || dp[i - 1][j]) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = dp[i - 1][j - 1];
				}
			}
		}
		ans[1] = dp[n][m];
	}
	else {
		int mn = INF, mx = 0;
		for (int i = 1; i <= n; i++) {
			mx = max(mx, nums1[i]);
			if (mx < nums2[1]) dp[i][1] = 1;
			else dp[i][1] = 0;
		}
		for (int i = 1; i <= m; i++) {
			mn = min(mn, nums2[i]);
			if (nums1[1] < mn) dp[1][i] = 1;
			else dp[1][i] = 0;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 2; j <= m; j++) {
				if (nums1[i] >= nums2[j]) {
					dp[i][j] = 0;
				}
				else if (dp[i][j - 1] || dp[i - 1][j]) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = dp[i - 1][j - 1];
				}
			}
		}
		ans[1] = dp[n][m];
	}
	for (int i = 1; i <= n; i++) temp1[i] = nums1[i];
	for (int i = 1; i <= m; i++) temp2[i] = nums2[i];
	for (int qi = 2; qi <= q + 1; qi++) {
		scanf("%d%d", &kx, &ky);
		for (int j = 1; j <= kx; j++) {
			scanf("%d%d", &p, &v);
			nums1[p] = v;
		}
		for (int j = 1; j <= ky; j++) {
			scanf("%d%d", &p, &v);
			nums2[p] = v;
		}
		if (nums1[1] == nums2[1]) {
			ans[qi] = 0;
		}
		else if (nums1[1] > nums2[1]){
			int mn = INF, mx = 0;
			for (int i = 1; i <= n; i++) {
				mn = min(mn, nums1[i]);
				if (mn > nums2[1]) dp[i][1] = 1;
				else dp[i][1] = 0;
			}
			for (int i = 1; i <= m; i++) {
				mx = max(mx, nums2[i]);
				if (nums1[1] > mx) dp[1][i] = 1;
				else dp[1][i] = 0;
			}
			for (int i = 2; i <= n; i++) {
				for (int j = 2; j <= m; j++) {
					if (nums1[i] <= nums2[j]) {
						dp[i][j] = 0;
					}
					else if (dp[i][j - 1] || dp[i - 1][j]) {
						dp[i][j] = 1;
					}
					else {
						dp[i][j] = dp[i - 1][j - 1];
					}
				}
			}
			ans[qi] = dp[n][m];
		}
		else {
			int mn = INF, mx = 0;
			for (int i = 1; i <= n; i++) {
				mx = max(mx, nums1[i]);
				if (mx < nums2[1]) dp[i][1] = 1;
				else dp[i][1] = 0;
			}
			for (int i = 1; i <= m; i++) {
				mn = min(mn, nums2[i]);
				if (nums1[1] < mn) dp[1][i] = 1;
				else dp[1][i] = 0;
			}
			for (int i = 2; i <= n; i++) {
				for (int j = 2; j <= m; j++) {
					if (nums1[i] >= nums2[j]) {
						dp[i][j] = 0;
					}
					else if (dp[i][j - 1] || dp[i - 1][j]) {
						dp[i][j] = 1;
					}
					else {
						dp[i][j] = dp[i - 1][j - 1];
					}
				}
			}
			ans[qi] = dp[n][m];
		}
		
		for (int i = 1; i <= n; i++) nums1[i] = temp1[i];
		for (int i = 1; i <= m; i++) nums2[i] = temp2[i];
	}
	
	for (int i = 1; i <= q + 1; i++) {
		printf("%d", ans[i]);
	}
	putchar('\n');
	return 0;
}