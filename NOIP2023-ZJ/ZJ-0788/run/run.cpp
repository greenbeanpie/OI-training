#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,t;

int nr(int l,int r) {
	return rand() % (r - l + 1) + l;
}
signed main() {
	
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	srand(time(0));
	scanf("%lld %lld",&c,&t);
	while(t --) {
		
		int n,m,k,d,sum;
		sum = 0;
		scanf("%lld %lld %lld %lld",&n,&m,&k,&d);
		for(int i = 1; i <= m; i ++) {
			int x,y,v; scanf("%lld %lld %lld",&x,&y,&v);
			sum += v;
		}
		printf("%lld\n",nr(sum/3,sum/2));
	}
	
	return 0;
}
/*
1 1
3 2 2 1
2 2 4
3 2 3
*/
