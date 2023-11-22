#include<bits/stdc++.h>
using namespace std;
const int N = 3005;
bool f1;
int n, m, a[N][N], b[N], c[N], maxn, f;
char C;
bool f2;
inline void read(int &res){
	res = 0;
	int f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		res = (res << 1) + (res << 3) + (ch - 48);
		ch = getchar();
	}
	res *= f;
}
int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
//	printf("%.2lfMB\n", (&f2 - &f1) / 1024.0 / 1024.0);
	read(n), read(m);
	memset(b, 63, sizeof(b));
	memset(c, 63, sizeof(c));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			C = getchar();
			while(C < 'a' || C > 'z') C = getchar();
			a[i][j] = C - 'a';
		}
		sort(a[i] + 1, a[i] + m + 1);
		f = 1;
		for(int j = 1; j <= m && f == 1; j++){
			if(a[i][m - j + 1] > b[j]) f = 0;
			if(a[i][m - j + 1] < b[j]) f = 2;
		}
		if(f){
			maxn = i;
			for(int j = 1; j <= m; j++) c[j] = b[j];
			for(int j = 1; j <= m; j++) b[j] = a[i][m - j + 1];
		}
		else{
			f = 1;
			for(int j = 1; j <= m && f == 1; j++){
				if(a[i][m - j + 1] > c[j]) f = 0;
				if(a[i][m - j + 1] < c[j]) f = 2;
			}
			if(f) for(int j = 1; j <= m; j++) c[j] = a[i][m - j + 1];
		}
	}
	for(int i = 1; i <= n; i++){
		f = 0;
		if(i == maxn){
			for(int j = 1; j <= m && !f; j++){
				if(a[i][j] < c[j]) f = 1;
			}
		}
		else{
			for(int j = 1; j <= m && !f; j++){
				if(a[i][j] < b[j]) f = 1;
			}
		}
		if(f) putchar('1');
		else putchar('0');
	}
	return 0;
}