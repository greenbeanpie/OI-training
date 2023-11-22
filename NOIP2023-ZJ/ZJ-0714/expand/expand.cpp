#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 57, M = 2e5 + 57;
int read(){
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -f; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
	return x * f;
}

bool _u;

int c, n[2], q, t1, t2, pre, now = 1;
int a[2][N], b[2][N], l[N], r[N];
bool v1[N], v2[N];

void solve(){
	for(int i = 1; i <= n[0]; ++i) b[0][i] = a[0][i];
	for(int i = 1; i <= n[1]; ++i) b[1][i] = a[1][i]; 
	if(b[0][1] == b[1][1]){
		printf("0");
	}else{
		if(b[0][1] < b[1][1]) t1 = 1, t2 = 0;
		else t1 = 0, t2 = 1;
		for(int i = 1; i <= n[t2]; ++i) v1[i] = v2[i] = 0;
		for(int i = 1; i <= n[t2]; ++i){
			if(b[t2][i] >= b[t1][1]) break;
			v1[i] = 1;
		}
		for(int i = 2; i <= n[t1]; ++i){
			for(int j = 1; j <= n[t2]; ++j){
				if(v1[j]) while(j <= n[t2] && b[t2][j] < b[t1][i]) v2[j] = 1, ++j;
			}
			for(int j = 1; j <= n[t2]; ++j) v1[j] = v2[j], v2[j] = 0;
		}
		printf("%d", v1[n[t2]]);
	} 
	while(q--){
		int kx = read(), ky = read();
		for(int i = 1; i <= n[0]; ++i) b[0][i] = a[0][i];
		for(int i = 1; i <= n[1]; ++i) b[1][i] = a[1][i]; 
		for(int i = 1; i <= kx; ++i){
			int p = read(), v = read();
			b[0][p] = v;
		}
		for(int i = 1; i <= ky; ++i){
			int p = read(), v = read();
			b[1][p] = v;
		}
		if(b[0][1] == b[1][1]){
			printf("0"); continue;
		}else if(b[0][1] < b[1][1]) t1 = 1, t2 = 0;
		else t1 = 0, t2 = 1;
		for(int i = 1; i <= n[t2]; ++i) v1[i] = v2[i] = 0;
		for(int i = 1; i <= n[t2]; ++i){
			if(b[t2][i] >= b[t1][1]) break;
			v1[i] = 1;
		}
		for(int i = 2; i <= n[t1]; ++i){
			for(int j = 1; j <= n[t2]; ++j){
				if(v1[j]) while(j <= n[t2] && b[t2][j] < b[t1][i]) v2[j] = 1, ++j;
			}
			for(int j = 1; j <= n[t2]; ++j) v1[j] = v2[j], v2[j] = 0;
		}
		printf("%d", v1[n[t2]]);
	}
	printf("\n");
}

bool _v;

int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	
	cerr << abs(&_u - &_v) / 1048576.0 << " MB\n";
	
	c = read(), n[0] = read(), n[1] = read(), q = read();
	for(int i = 1; i <= n[0]; ++i) a[0][i] = read();
	for(int i = 1; i <= n[1]; ++i) a[1][i] = read();
	
	if(n[0] <= 2000 && n[1] <= 2000) solve(), exit(0);
	while(q--){
		int kx = read(), ky = read();
		for(int i = 1; i <= n[0]; ++i) b[0][i] = a[0][i];
		for(int i = 1; i <= n[1]; ++i) b[1][i] = a[1][i]; 
		for(int i = 1; i <= kx; ++i){
			int p = read(), v = read();
			b[0][p] = v;
		}
		for(int i = 1; i <= ky; ++i){
			int p = read(), v = read();
			b[1][p] = v;
		}
		if(b[0][1] == b[1][1]){
			printf("0"); continue;
		}else if(b[0][1] < b[1][1]) t1 = 1, t2 = 0;
		else t1 = 0, t2 = 1; l[1] = 1;
	}
	return 0;
}
