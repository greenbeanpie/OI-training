#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gc getchar()
#define il inline
il int read()
{
	int ret = 0;
	bool neg = false;
	char ch = gc;
	while(!isdigit(ch)){
		neg = ch == '-';
		ch = gc;
	}
	while(isdigit(ch)){
		ret = ret * 10 + ch - '0';
		ch = gc;
	}
	return neg ? -ret : ret;
}
il void write(int x)
{
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x % 10 + '0');
}
const int M = 3005;
const int N = 3005;
char s[M];
int mp[N][M];
// int ans[N];
int mn[N];
int mx[N];
int cnt[N][30];
bool cmp(const int &lhs, const int &rhs)
{
	return lhs > rhs;
}
int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int n = read(), m = read();
	for(int i = 1; i <= n; i++){
		mx[i] = -1;
		mn[i] = 1000;
	}
	for(int i = 1; i <= n; i++){
		scanf("%s", s + 1);
		for(int j = 1; j <= m; j++){
			mp[i][j] = s[j] - 'a';
			cnt[i][s[j] - 'a']++;
			mn[i] = min(mn[i], mp[i][j]);
			mx[i] = max(mx[i], mp[i][j]);
			// cerr << mn[i] << " " << mx[i] << cnt[i][s[j] - 'a'] << endl;
		}
	}
	for(int i = 1; i <= n; i++){
		bool flag = true;
		for(int j = 1; j <= n; j++){
			if(i == j){
				continue;
			}
			if(mn[i] < mx[j]){
				continue;
			}
			else{
				// if(cnt[i][mn[i]] != cnt[j][mx[j]]){
				flag = false;
				break;
				// }
				// else{
				// 	continue;
				// }
			}
			// else if(mn[i] > mx[j]){
			// 	flag = false;
			// 	break;
			// }
		}
		if(flag){
			putchar('1');
		}
		else{
			putchar('0');
		}
	}
	return 0;
}