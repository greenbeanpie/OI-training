#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int c, n, m, q;
int x[N], y[N];
int ax[N], ay[N];

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	
	scanf("%d%d%d%d", &c, &n, &m, &q);
	for(int i = 1;i <= n; ++ i) scanf("%d", &x[i]);
	for(int i = 1;i <= m; ++ i) scanf("%d", &y[i]);
	if (c == 1){
		if (x[1] == y[1]) printf("%d", 0);
		else printf("%d", 1);
		while (q --){
			int kx, ky;
			scanf("%d%d", &kx, &ky);
			
			for (int i = 1;i <= n; ++ i) ax[i] = x[i];
			for (int i = 1;i <= m; ++ i) ay[i] = y[i];
			
			for (int i = 1;i <= kx; ++ i){
				int p, v;
				scanf("%d%d", &p, &v);
				ax[p] = v;
			}
			for (int i = 1;i <= ky; ++ i){
				int p, v;
				scanf("%d%d", &p, &v);
				ay[p] = v;
			}
			
			if (ax[1] == ay[1]) printf("%d", 0);
			else printf("%d", 1);
		}
	}
	if (c == 2){
		if (x[1] > y[1] && x[n] > y[m] || x[1] < y[1] && x[n] < y[m]) printf("%d", 1);
		else printf("%d", 0);
		while (q --){
			int kx, ky;
			scanf("%d%d", &kx, &ky);
			
			for (int i = 1;i <= n; ++ i) ax[i] = x[i];
			for (int i = 1;i <= m; ++ i) ay[i] = y[i];
			
			for (int i = 1;i <= kx; ++ i){
				int p, v;
				scanf("%d%d", &p, &v);
				ax[p] = v;
			}
			for (int i = 1;i <= ky; ++ i){
				int p, v;
				scanf("%d%d", &p, &v);
				ay[p] = v;
			}
			
			if (x[1] > y[1] && x[n] > y[m] || x[1] < y[1] && x[n] < y[m]) printf("%d", 1);
			else printf("%d", 0);
		}
	}
	return 0;
}