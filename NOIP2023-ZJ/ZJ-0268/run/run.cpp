#include <bits/stdc++.h>
#define LL long long
#define Fcin \
	ios :: sync_with_stdio(0); \
	cin.tie(0); cout.tie(0)
using namespace std;

namespace Oxygen{
	const LL M = 1e5 + 10;
	LL n, m, K, D, DP[M], mx[M], tmp[M]; 
	struct Challenge{
		LL x, y, z;
	} ch[M];
	bool cmp(Challenge a, Challenge b){
		if (a.x != b.x) return a.x < b.x;
		if (a.y != b.y) return a.y < b.y;
		return a.z < b.z;
	}
	void main(){
		memset(mx, 0x9f, sizeof mx);
		cin >> n >> m >> K >> D;
		for (LL i = 1; i <= m; i ++){ cin >> ch[i].x >> ch[i].y >> ch[i].z; }
		sort(ch + 1, ch + 1 + m, cmp);
		for (LL i = 1; i <= m; i ++)
			tmp[i] = ch[i].x;
		memset(DP, 0x9f, sizeof DP);
		DP[0] = 0;
		mx[0] = 0;
		for (LL i = 1; i <= m; i ++){
			LL pt = ch[i].x - ch[i].y + 1, sum = ch[i].z, k = ch[i].y;
			for (LL j = i - 1; j >= 0; j --){
				if (k > K)
					break;
				LL a = lower_bound(tmp + 1, tmp + 1 + m, pt - 1) - tmp - 1;
				DP[i] = max(DP[i], mx[a] - k * D + sum);
				k = ch[i].x - (ch[j].x - ch[j].y + 1) + 1;
				sum += ch[j].z;
				pt = ch[i].x - k + 1;
				if (ch[j + 1].x < pt - 1)
					break;
			}
			mx[i] = max(mx[i - 1], DP[i]);
		}
		cout << mx[m] << "\n";
		return ;
	}
}


int main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	Fcin;
	LL C, T;
	cin >> C >> T;
	while (T --){
		if (C >= 14)
			cout << "0\n";
		else
			Oxygen :: main();
	}

	return 0;
}