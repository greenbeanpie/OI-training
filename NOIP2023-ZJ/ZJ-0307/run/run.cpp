#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 1e5 + 5;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();};
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	
	return 0;
}
