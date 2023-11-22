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
const int N = 100005;
int cnt[N];
char s[5];
int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int c = read(), _ = read();
	srand(time(NULL));
	while(_--){
		int n = read(), m = read();
		if(c == 3 || c == 4){
			int ans = 0;
			for(int i = 1; i <= m; i++){
				scanf("%s", s + 1);
				int pos = read();
				if(s[1] == 'U'){
					if(!cnt[pos]){
						cnt[pos] = 1;
						ans++;
					}
				}
				else{
					if(cnt[pos]){
						cnt[pos] = 0;
						ans--;
					}
				}
			}
			write(ans);
			puts("");
		}
		else{
			write(rand() % n);
			puts("");
		}
	}
	return 0;
}