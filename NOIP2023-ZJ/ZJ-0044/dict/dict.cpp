#include<bits/stdc++.h>
using namespace std; using ll = long long;
#define For(i, j, k) for ( int i = (j) ; i <= (k) ; i++ )
#define Fol(i, j, k) for ( int i = (j) ; i >= (k) ; i-- )
int n, m, mn[3009], mx[3009], tot[26]; char c; multiset < int > st;
int main()
{
	freopen("dict.in", "r", stdin), freopen("dict.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> m;
	For(i, 1, n)
	{
		mx[i] = -1, mn[i] = 26;
		For(j, 1, m)
		{
			cin >> c;
			mn[i] = min(mn[i], c - 'a'), mx[i] = max(mx[i], c - 'a');
		}
		st.insert(mx[i]);
	}
	For(i, 1, n)
	{
		st.erase(st.find(mx[i]));
		if ( st.empty() || *st.begin() > mn[i] ) cout << '1';
		else cout << '0';
		st.insert(mx[i]);
	}
	return cout << '\n', 0;
}
/*
clear && g++ dict.cpp -o dict -Wno-unused-result -std=c++14 -O2 -fsanitize=address,undefined -g && /usr/bin/time -f "%Us %MKB" ./dict < dict1.in > dict.out && diff dict.out dict1.ans -Z
*/