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
const int N = 500005;
int x[N], y[N], tmpx[N], tmpy[N];
int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	srand(time(NULL));
	int c = read(), n = read(), m = read(), q = read();
	for(int i = 1; i <= n; i++){
		x[i] = read();
		tmpx[i] = x[i];
	}
	for(int i = 1; i <= m; i++){
		y[i] = read();
		tmpy[i] = y[i];
	}
	if(c == 1){
		if(tmpx[1] != tmpy[1]){
			putchar('1');
		}
		else{
			putchar('0');
		}
	}
	else if(c == 2){
		if(tmpx[1] == tmpy[1] || (tmpx[1] > tmpy[1] && tmpx[n] < tmpy[m]) || (tmpx[1] < tmpy[1] && tmpx[n] > tmpy[m]) || tmpx[n] == tmpy[m]){
			putchar('0');
		}
		else{
			putchar('1');
		}
	}
	else{
		putchar(rand() % 2 + '0');
	}
	while(q--){
		for(int i = 1; i <= n; i++){
			tmpx[i] = x[i];
		}
		for(int i = 1; i <= m; i++){
			tmpy[i] = y[i];
		}
		int kx = read(), ky = read();
		for(int i = 1; i <= kx; i++){
			int pos = read(), val = read();
			tmpx[pos] = val;
		}
		for(int i = 1; i <= ky; i++){
			int pos = read(), val = read();
			tmpy[pos] = val;
		}
		if(c == 1){
			if(tmpx[1] != tmpy[1]){
				putchar('1');
			}
			else{
				putchar('0');
			}
		}
		else if(c == 2){
			if(tmpx[1] == tmpy[1] || (tmpx[1] > tmpy[1] && tmpx[n] < tmpy[m]) || (tmpx[1] < tmpy[1] && tmpx[n] > tmpy[m]) || tmpx[n] == tmpy[m]){
				putchar('0');
			}
			else{
				putchar('1');
			}
		}
		else{
			putchar(rand() % 2 + '0');
		}
	}
	return 0;
}