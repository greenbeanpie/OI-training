#include<bits/stdc++.h>
using namespace std;
string s[3005];
int M[3005][2];
bool F[3005];
struct MAXS {
	string S;
	int Num;
} MaxS[3005];
//0 最小    1 最大 
string Swap(int x, int to) {
	string S = s[x];
	char ch = S[0];
	S[0] = S[to];
	S[to] = ch;
	return S;
}
inline bool cmp(MAXS a, MAXS b) {
	return a.S < b.S;
}
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int n, m;
	memset(F, true, sizeof(F));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) {
		cin >> s[i];
		char Max = s[i][m - 1], Min = s[i][m - 1];
		M[i][0] = m - 1, M[i][1] = m - 1;
		for (int j = m - 2; j >= 0; -- j) {
			if (Max < s[i][j]) {
				Max = s[i][j];
				M[i][1] = j;
			}
			if (Min > s[i][j]) {
				Min = s[i][j];
				M[i][0] = j;
			}
		}
		MaxS[i].S = Swap(i, M[i][1]), MaxS[i].Num = i;
	}
	sort(MaxS + 1, MaxS + 1 + n, cmp);
	for (int i = 1; i <= n; ++ i) {
		string Now = Swap(i, M[i][0]);
		int j = 1;
		if (MaxS[j].Num == i) {
			++ j;
		}
		if (Now <= MaxS[j].S)
			printf("1");
		else
			printf("0");
	}
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/
