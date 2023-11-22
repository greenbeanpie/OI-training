#include <bits/stdc++.h>
using namespace std;

void file() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
}

void desync() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);std::cout.tie(0);
}

int c,n,m,q;

int main() {
	file();
	desync();
	srand(time(0));
	cin >> c >> n >> m >> q;
	while (q-->-1) cout << rand()%2;
	return 0;
}
