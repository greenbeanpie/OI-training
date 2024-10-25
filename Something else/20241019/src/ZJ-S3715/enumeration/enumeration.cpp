#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll x, y, z;
} as[200010];
ll n, n3, p, x, sq, tmp, ans, sum[200010];
vector<ll> ve[200010];
int main(){
	freopen("enumeration.in", "r", stdin);
	freopen("enumeration.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> n3 >> p;
	for(int i = n3 + 1; i <= p; i++)
		ve[0].push_back(i);
	for(int i = 1;i  <= 200005; i++){
		sq = sqrt(i);
		for(int j = 1; j <= sq; j++)
			if(i % j == 0){
				if(j > n3 && j <= p) ve[i].push_back(j);
				if(j * j != i && i / j > n3 && i / j <= p) ve[i].push_back(i / j);
			}
		sort(ve[i].begin(), ve[i].end());
	}
	
	sum[0] = ve[0].size();
	for(int i = 1; i <= 200005; i++) sum[i] = sum[i - 1] + ve[i].size();
	
//	for(int i = 0; i <= 3; i++) cout << ve[i].size() << "?\n";
	
	for(int i = 1; i <= p; i++){
		x = (n * n + 1) % i;
		if(x + p - n3 < 0) continue;
//		cout << i << "!!!\n";
		if(max(0ll, x - n3) == 0) ans += sum[x + p - n3];
		else ans += sum[x + p - n3] - sum[max(0ll, x - n3) - 1];
		
		for(int j = max(0ll, x - n3); j <= x + p - n3; j++){
			if(tmp == 1e5) break;
			for(auto k : ve[j]){
				if(tmp == 1e5) break;
				tmp++;
				as[tmp] = node{i, j + n3 - x, k};
			}
		}
	}
	cout << ans << '\n';
	for(int i = 1; i <= min(ans, tmp); i++)
		cout << as[i].x << ' ' << as[i].y << ' ' << as[i].z << '\n';
	return 0;
}

