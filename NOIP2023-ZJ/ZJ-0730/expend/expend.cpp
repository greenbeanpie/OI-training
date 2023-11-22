#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("expend.in", "r", stdin);
	freopen("expend.out", "w", stdout);
	
	int c, n, m, q;
	scanf("%d%d%d%d", &c, &n, &m, &q);
	int n1, m1;
	scanf("%d%d", &n1, &m1);
	if(c == 1){
		if(n1 != m1) cout << 1;
		else cout << 0;
		while(q--){
			int kx, ky, px, vx, py, vy;
			scanf("%d%d", &kx, &ky);
			scanf("%d%d", &px, &vx);
			scanf("%d%d", &py, &vy);
			if(vx != vy) cout << 1;
			else cout << 0;
		}
	}
    return 0;
}
