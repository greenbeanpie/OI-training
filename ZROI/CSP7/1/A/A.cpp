#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "A"
#define const constexpr

namespace Main{
	const int N = 2005;
	bool mp[N][N];
	int suml[N][N],sumr[N][N];
	int query(int x1,int y1,int x2,int y2){
		return (suml[x2][y2-1]-suml[x1-1][y2-1]-suml[x2][y1-1]+suml[x1-1][y1-1])+(sumr[x2-1][y2]-sumr[x1-1][y2]-sumr[x2-1][y1-1]+sumr[x1-1][y1-1]);
	}
	int main()
	{
		// double st = clock();
		int n, m, h, w, k;
		cin >> n >> m >> h >> w >> k;
		char c;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m;j++){
				cin >> c;
				if(c=='1'){
					mp[i][j] = 1;
				}
			}
		}
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1;j<=m;j++){
				res=0;
				// if(i>1&&mp[i][j]^mp[i-1][j]){
				// 	++res;
				// }
				if(i<n&&mp[i][j]^mp[i+1][j]){
					++sumr[i][j];
				}
				// if(j>1&&mp[i][j]^mp[i][j-1]){
				// 	++res;
				// }
				if(j<m&&mp[i][j]^mp[i][j+1]){
					++suml[i][j];
				}
				// sum[i][j] = res;
			}
		}
		for (int i = 1; i <= n;i++){
			for (int j = 1; j <= m;j++){
				sumr[i][j] += sumr[i - 1][j] + sumr[i][j - 1] - sumr[i - 1][j - 1];
				suml[i][j] += suml[i - 1][j] + suml[i][j - 1] - suml[i - 1][j - 1];
			}
		}
		int ans = 0;
		for (int i = 1; i <= n - h + 1; i++)
		{
			for (int j = 1; j <= m - w + 1;j++){
				if(query(i,j,i+h-1,j+w-1)>=k){
					++ans;
				}
			}
		}
		cout << ans;
		// cerr << "This program used " << 1.0 * (clock() - st) / CLOCKS_PER_SEC << "s.";
		return 0;
	}
};

signed main(){
#ifndef ONLINE_JUDGE
	freopen(problemname"2.in","r",stdin);
	freopen(problemname".out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	Main::main();
	return 0;
}