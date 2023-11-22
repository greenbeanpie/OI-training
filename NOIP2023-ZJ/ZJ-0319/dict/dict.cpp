#include <bits/stdc++.h>
#define FL(i, a, b) for(register int i = (a); i <= (b); ++i)
#define FR(i, a, b) for(register int i = (a); i >= (b); --i)
using namespace std;
constexpr int N = 3010;
int n, m, w[N];
struct Str{
	char s[N];
	bool operator < (const Str &cmp) const{
		FL(i, 1, m) if(s[i] != cmp.s[i]) return s[i] < cmp.s[i];
		return 0;
	}
} s[N], t[N];
int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%d%d", &n, &m);
	FL(i, 1, n){
		scanf("%s", s[i].s + 1);
		sort(s[i].s + 1, s[i].s + m + 1);
		FL(j, 1, m) t[i].s[j] = s[i].s[m - j + 1];
		w[i] = s[i].s[1] < t[i].s[1];
	}
	sort(t + 1, t + n + 1);
	FL(i, 1, n){
		int ans = upper_bound(t + 1, t + n + 1, s[i]) - t;
		putchar('0' + (ans + w[i] == 2));
	}
	putchar('\n');
	return 0;
}