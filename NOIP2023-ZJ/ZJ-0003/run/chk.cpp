#include <bits/stdc++.h>
#define rep(i, l, r) for(int i=l, _=r; i<=_; ++i)
using namespace std;
typedef long long ll;

int main() {
	for(int cnt=0; ; ++cnt) {
		printf("----------------\ntest %d\n", cnt);
		if(system("./build > tribool.in")
		|| system("./bf < tribool.in > 2.out")
		|| system("./tribool")
		|| system("diff tribool.out 2.out -sb")) {
			return 0;
		}
	}
	return 0;
}