#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 57;
int read(){
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -f; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
	return x * f;
}

bool _u;

int n, m;
char s[N][N];
int cnt[N][27];
int mn[N], mx[N];

bool _v;

int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	cerr << abs(&_u - &_v) / 1048576.0 << " MB\n";
	n = read(), m = read();
	for(int i = 1; i <= n; ++i){
		scanf("%s", s[i] + 1); 
		mn[i] = 27, mx[i] = 0;
		for(int j = 1; j <= m; ++j){
			int tmp = s[i][j] - 'a';
			++cnt[i][tmp];
			mn[i] = min(mn[i], tmp), mx[i] = max(mx[i], tmp);
		} 
	}
	for(int i = 1; i <= n; ++i){
		bool flag = 1;
		for(int j = 1; j <= n; ++j){
			if(i == j) continue;
			if(mx[j] <= mn[i]){
				flag = 0; break;
			}
		}
		printf("%d", flag);
	}
	printf("\n");
	return 0;
}
