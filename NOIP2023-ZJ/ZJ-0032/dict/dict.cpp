#include <bits/stdc++.h>
using namespace std;
int n, m, c[26], fmn, smn; string s[3005], FMN, SMN; char t[3005];
int main() {
	freopen ("dict.in", "r", stdin);
	freopen ("dict.out", "w", stdout);
	cin >> n >> m;
	if (n == 1) return puts ("1"), 0;
	for (int i=1; i<=n; i++) {
		scanf ("%s", t);
		for (int j=0; j<m; j++)
			c[t[j]-'a'] ++;
		for (int j=0; j<26; c[j++]=0)
			while (c[j] --)
				s[i] += j + 'a';
		reverse (s[i]. begin(), s[i]. end());
		if (! fmn || s[fmn] >= s[i])
			smn = fmn, fmn = i;
		else if (! smn || s[smn] > s[i])
			smn = i;
	}
	FMN = s[fmn], SMN = s[smn];
	for (int i=1; i<=n; i++)
		reverse (s[i]. begin(), s[i]. end()), 
		putchar((s[i] < (i == fmn ? SMN : FMN)) + '0');
}