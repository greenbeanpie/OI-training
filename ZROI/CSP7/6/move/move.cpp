#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long
#define endl '\n'

const int N = 1e5 + 5;
int nowx, nowy;
int prew[N], prea[N], pres[N], pred[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("move.in", "r", stdin);
	freopen("move.out", "w", stdout);
#endif
	int n, m;
	string s;
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		prew[i + 1] = prew[i];
		prea[i + 1] = prea[i];
		pres[i + 1] = pres[i];
		pred[i + 1] = pred[i];
		if (s[i] == 'A')
		{
			++prea[i + 1];
		}
		else if (s[i] == 'W')
		{
			++prew[i + 1];
		}
		else if (s[i] == 'S')
		{
			++pres[i + 1];
		}
		else
		{
			++pred[i + 1];
		}
	}
	int l, r, movea, movew, moves, moved;
	for (int i = 1; i <= m; i++)
	{
		cin >> l >> r;
		movea = prea[r] - prea[l - 1], moves = pres[r] - pres[l - 1], movew = prew[r] - prew[l - 1], moved = pred[r] - pred[l - 1];
		if(abs(nowx+moved)>=abs(nowx-movea)){
			nowx += moved;
		}
		else{
			nowx -= movea;
		}
		if(abs(nowy+movew)>=abs(nowy-moves)){
			nowy += movew;
		}
		else{
			nowy -= moves;
		}
	}
	cout << nowx << " " << nowy;
	return 0;
}