#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<bitset>
#include<cstdio>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<map>

//#define int long long

using namespace std;

inline int read() {
	char c = 0;
	int r = 0, f = 1;
	while(!isdigit(c)) if((c = getchar()) == '-') f = -f;
	while(isdigit(c)) r = (r << 3) + (r << 1) + (c ^ '0'), c = getchar();
	return r * f;
}
bool bg;
const int N = 3e3 + 5;

char s[2][N][N];
int n, m;

inline bool check(char *a, char *b) {
	for(int i = 1;i <= m;i++) if(a[i] != b[i]) return a[i] < b[i];
	return 0;
}

char mi[N], mi2[N];

bool ed;
signed main() {
//	cerr << (&ed - &bg) / 1048576 << endl;
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	n = read(), m = read();
	for(int i = 1;i <= n;i++) {
		scanf("%s", s[0][i] + 1);
		sort(s[0][i] + 1, s[0][i] + m + 1);
		for(int j = 1;j <= m;j++) s[1][i][j] = s[0][i][j];
		reverse(s[1][i] + 1, s[1][i] + m + 1);
	}
	for(int i = 1;i <= m;i++) mi[i] = mi2[i] = 'z';
	if(n == 1) return putchar('1'), 0;
	
	for(int i = 1;i <= n;i++) {
		if(check(s[1][i], mi)) {
			for(int j = 1;j <= m;j++) {
				mi2[j] = mi[j];
				mi[j] = s[1][i][j];
			}
		}
		else if(check(s[1][i], mi2)) for(int j = 1;j <= m;j++) mi2[j] = s[1][i][j];
	}
	
	for(int i = 1;i <= n;i++) {
		if(!check(s[1][i], mi) && !check(mi, s[1][i])) {
			if(check(s[0][i], mi2)) putchar('1');
			else putchar('0');
		}
		else if(check(s[0][i], mi)) putchar('1');
		else putchar('0');
	}
	return 0;
}//made by luogu:734497 star_of_cloud
