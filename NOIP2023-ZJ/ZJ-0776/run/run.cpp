#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gc getchar()
#define il inline
#define int ll
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
const int M = 100005;
struct node{
	int x, y, v;
	// bool operator < (const node &a) const {
	// 	return v > a.v;
	// }
}clg[M];
bool can[M];
bool cmp(const node &lhs, const node &rhs)
{
	return lhs.x < rhs.x;
}
signed main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c = read(), _ = read();
	while(_--){
		int n = read(), m = read(), k = read(), d = read();
		int sav = k;
		int tot = 0;
		for(int i = 1; i <= m; i++){
			int x = read(), y = read(), v = read();
			if(y <= k && v > y * d){
				clg[++tot] = {x, y, v - y * d};
			}
		}
		if(c == 17 || c == 18){
			int ans = 0;
			for(int i = 1; i <= tot; i++){
				// if(clg[i].v - clg[i].y * d > 0){
				ans += clg[i].v;
				// }
			}
			write(ans);
			puts("");
		}
		else{
			sort(clg + 1, clg + 1 + tot, cmp);
			int tmp = 1;
			int ans = 0;
			for(int i = 1; i <= n; i++){
				if(i == clg[tmp].x){
					if(k >= clg[tmp].y){
						ans += clg[tmp].v;
						can[tmp] = true;
						k = 0;
					}
				}
				if(k != sav){
					k++;
				}
			}
			write(ans);
			puts("");
			// cerr << q.top().v << endl;
		}
	}
	return 0;
}