#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 3010;
int n, m;
string s;
int ss[N][N]; 
int here[N];
bool flag;
struct Node{
	string s1, s2;
}sss[N];
void init() {
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < m; j++) {
			here[j] = ss[i][j];
		}
		sort(here, here + m);
		for(int j = 0; j < m; j++) {
			char c = here[j] + 'a';
			sss[i].s1 += c;
		}
		for(int j = 0; j < m; j++) {
			char c = here[m - 1 - j] + 'a';
			sss[i].s2 += c;
		}
	}
}
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		cin >> s;
		for(int j = 0; j < m; j++) {
			ss[i][j] = s[j] - 'a';
		}
	}
	init();
	for(int i = 1; i <= n; i++) {
		flag = 0;
		for(int j = 1; j <= n; j++) {
			if(j == i) continue;
			string a = sss[i].s1;
			string b = sss[j].s2;
			if(a >= b) {
				printf("0");
				flag = 1;
				break;
			}
		}
		if(!flag) printf("1");
	}
	return 0;
}