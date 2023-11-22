#include <bits/stdc++.h>
#define LL long long
#define Fcin \
	ios :: sync_with_stdio(0); \
	cin.tie(0); cout.tie(0)
using namespace std;

namespace Oxygen{
	const LL N = 5e3 + 10;
	string S1[N], S2[N];
	LL n, m;
	void main(){
		freopen("dict.in", "r", stdin);
		freopen("dict.out", "w", stdout);
		Fcin;
		cin >> n >> m;
		string S;
		for (LL i = 1; i <= n; i ++){
			cin >> S;
			sort(S.begin(), S.end());
			S1[i] = S;
			sort(S.begin(), S.end(), greater<char>());
			S2[i] = S;
		}
		for (LL i = 1; i <= n; i ++){
			bool flag = true;
			for (LL j = 1; j <= n; j ++){
				if (S2[j] < S1[i] && j != i)
					flag = false;
			}
			cout << flag;
		}

		return ;
	}
}


int main(){

	Oxygen :: main();

	return 0;
}