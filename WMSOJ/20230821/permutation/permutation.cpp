#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#define int long long
#define double long double
#define endl "\n"
#define problemname "permutation"
#define const constexpr
#define max_matrix 105
#define mod 1000000007

namespace Main
{
	int n, k, ans;
	bool used[100];
	vector<int> num;
	struct matrix
	{
		long long mat[max_matrix + 1][max_matrix + 1];
		int *operator[](int &x) { return mat[x]; }
		matrix()
		{
			memset(mat, 0, sizeof(mat));
		}
		void init()
		{
			for (int i = 0; i < max_matrix; i++)
			{
				mat[i][i] = 1;
			}
		}
	} a;
	matrix operator*(matrix a, matrix b)
	{
		matrix c;
		for (int k = 1; k <= max_matrix; k++)
		{
			for (int i = 1; i <= max_matrix; i++)
			{
				for (int j = 1; j <= max_matrix; j++)
				{
					c.mat[i][j] += a.mat[i][k] * b.mat[k][j] % mod;
				}
			}
		}
		return c;
	}
	matrix operator%(matrix a, int b)
	{
		for (int i = 1; i <= max_matrix; i++)
		{
			for (int j = 1; j <= max_matrix; j++)
			{
				a.mat[i][j] %= b;
			}
		}
		return a;
	}

	matrix mquickpower(matrix a, int b)
	{
		matrix answer;
		answer.init();
		do
		{
			if (b & 1)
			{
				answer = answer * a % mod;
			}
			a = a * a;
			b >>= 1;
		} while (b);
		return answer;
	}
	int fibonacci(int x)
	{
		matrix a;
		a.mat[1][1] = a.mat[1][2] = a.mat[2][2] = a.mat[2][3] = a.mat[3][2] = 1;
		return mquickpower(a, x).mat[3][2] % mod;
	}
	void dfs(int now)
	{
		if (now == n + 1)
		{
			++ans;
			// for(int i:num){
			// 	cerr << i << " ";
			// }
			// cerr << endl;
			return;
		}
		for (int i = now - k; i <= now + k; i++)
		{
			if (i > 0 && i <= n && !used[i])
			{
				used[i] = 1;
				// num.push_back(i);
				dfs(now + 1);
				// num.pop_back();
				used[i] = 0;
			}
		}
	}
	int main()
	{
		cin >> n >> k;
		if (k == 0)
		{
			cout << 1;
		}
		else if (k == 1)
		{
			cout << fibonacci(n + 1)%mod;
		}
		else if(k>=n-1){
			int sum=1;
			for(int i=1;i<=n;i++){
				sum*=i;
			}
			cout << sum;
		}
		else
		{
			dfs(1);
			cout << ans % mod << endl;
		}
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	freopen(problemname ".in", "r", stdin);
	freopen(problemname ".out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Main::main();
	return 0;
}

