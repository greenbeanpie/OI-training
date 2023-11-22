#include <bits/stdc++.h>
using namespace std;

int c, n, m, q, a[500005], A[500005], B[500005], b[500005], ka[65], kb[65];
vector<int> pa[65], pb[65], va[65], vb[65];
bool flag;

void init(){
	for (int i = 1; i <= n; i++)
		a[i] = A[i];
	for (int i = 1; i <= m; i++)
		b[i] = B[i];
}

void solve1(){
	init();
	printf(a[1] != b[1] ? "1" : "0");
	for (int i = 1; i <= q; i++){
		init();
		for (int j = 0; j < ka[i]; j++)
			a[pa[i][j]] = va[i][j];
		for (int j = 0; j < kb[i]; j++)
			b[pb[i][j]] = vb[i][j];
		printf(a[1] != b[1] ? "1" : "0");
	}
}

void solve2(){
	init();
	if (n == 1)
		a[2] = a[1];
	if (m == 1)
		b[2] = b[1];
	printf((a[1] - b[1]) * (a[2] - b[2]) > 0 ? "1" : "0");
	for (int i = 1; i <= q; i++){
		init();
		for (int j = 0; j < ka[i]; j++)
			a[pa[i][j]] = va[i][j];
		for (int j = 0; j < kb[i]; j++)
			b[pb[i][j]] = vb[i][j];
		printf((a[1] - b[1]) * (a[2] - b[2]) > 0 ? "1" : "0");
	}
}
//vector<int> arra, arrb;

void dfs3(int p_a, int p_b){
	//printf("%d %d\n", p_a, p_b);
	//Sleep(100);
	//arra.push_back(a[p_a]);
	//arrb.push_back(b[p_b]);
	if (flag){
		//arra.pop_back();
		//arrb.pop_back();
		return;
	}
	if (a[1] - b[1] >= 0)
		if (a[p_a] <= b[p_b]){
			//arra.pop_back();
			//arrb.pop_back();
			return;
		}
	if (a[1] - b[1] <= 0)
		if (a[p_a] >= b[p_b]){			
			//arra.pop_back();
			//arrb.pop_back();
			return;
		}
	if (p_a == n && p_b == m){
		/*for (int i = 0; i < arra.size(); i++)
			printf("%d ", arra[i]);
		printf("\n");
		for (int i = 0; i < arrb.size(); i++)
			printf("%d ", arrb[i]);*/
		flag = 1;
		//arra.pop_back();
		//arrb.pop_back();
		return;
	}
	if (p_a < n)
		dfs3(p_a + 1, p_b);
	if (p_b < m)
		dfs3(p_a, p_b + 1);
	if (p_a < n && p_b < m)
		dfs3(p_a + 1, p_b + 1);
	//arra.pop_back();
	//arrb.pop_back();
}
void solve3(){
	init();
	flag = 0;
	dfs3(1, 1);
	printf(flag ? "1" : "0");
	for (int i = 1; i <= q; i++){
		init();
		flag = 0;
		for (int j = 0; j < ka[i]; j++)
			a[pa[i][j]] = va[i][j];
		for (int j = 0; j < kb[i]; j++)
			b[pb[i][j]] = vb[i][j];
		dfs3(1, 1);
		printf(flag ? "1" : "0");
	}
}

int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	scanf("%d%d%d%d", &c, &n, &m, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &B[i]);
	for (int i = 1; i <= q; i++){
		scanf ("%d%d", &ka[i], &kb[i]);
		for (int j = 1; j <= ka[i]; j++){
			int x, y;
			scanf("%d%d", &x, &y);
			pa[i].push_back(x);
			va[i].push_back(y);
		}
		for (int j = 1; j <= kb[i]; j++){
			int x, y;
			scanf("%d%d", &x, &y);
			pb[i].push_back(x);
			vb[i].push_back(y);
		}
	}
	if (c == 1)
		solve1();
	if (c == 2)
		solve2();
	if (c > 2)
		solve3();

	return 0;
}

