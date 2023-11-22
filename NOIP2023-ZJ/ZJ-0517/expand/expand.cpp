#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int x[500010],y[500010],x1[500010],y1[500010];
int c,n,m,q,maxn,maxni,maxm,maxmi,minn,minni,minm,minmi;
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i = 1; i <= n; i++) {
		scanf("%d",&x[i]);
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d",&y[i]);
	}
	if(c == 1) {
		if(x[1] != y[1]) printf("1");
		else printf("0");
		while(q--) {
			int kx,ky;
			scanf("%d%d",&kx,&ky);
			for(int i = 1; i <= kx; i++) {
				int px,vx;
				scanf("%d%d",&px,&vx);
				x[px] = vx;
			}
			for(int i = 1; i <= ky; i++) {
				int py,vy;
				scanf("%d%d",&py,&vy);
				y[py] = vy;
			}
			if(x[1] != y[1]) printf("1");
			else printf("0");
		}
		return 0;
	}
	if(c == 2) {
		if(n == 2&& m == 2) {
			if((x[1] < y[1] && x[2] < y[2]) || (x[1] > y[1] && x[2] > y[2])) printf("1");
			else printf("0");
			while(q--) {
				int kx,ky;
				scanf("%d%d",&kx,&ky);
				for(int i = 1; i <= kx; i++) {
					int px,vx;
					scanf("%d%d",&px,&vx);
					x[px] = vx;
				}
				for(int i = 1; i <= ky; i++) {
					int py,vy;
					scanf("%d%d",&py,&vy);
					y[py] = vy;
				}
				if((x[1] < y[1] && x[2] < y[2]) || (x[1] > y[1] && x[2] > y[2])) printf("1");
				else printf("0");
			}
			return 0;
		} else {
			if(n == 1 && m == 2) {
				if((x[1] < y[1] && x[1] < y[2]) || (x[1] > y[1] && x[1] > y[2])) printf("1");
				else printf("0");
				while(q--) {
					int kx,ky;
					scanf("%d%d",&kx,&ky);
					for(int i = 1; i <= kx; i++) {
						int px,vx;
						scanf("%d%d",&px,&vx);
						x[px] = vx;
					}
					for(int i = 1; i <= ky; i++) {
						int py,vy;
						scanf("%d%d",&py,&vy);
						y[py] = vy;
					}
					if((x[1] < y[1] && x[1] < y[2]) || (x[1] > y[1] && x[1] > y[2])) printf("1");
					else printf("0");
				}
				return 0;
			} else {
				if(n == 2 && m == 1) {
					if((x[1] < y[1] && x[2] < y[1]) || (x[1] > y[1] && x[2] > y[1])) printf("1");
					else printf("0");
					while(q--) {
						int kx,ky;
						scanf("%d%d",&kx,&ky);
						for(int i = 1; i <= kx; i++) {
							int px,vx;
							scanf("%d%d",&px,&vx);
							x[px] = vx;
						}
						for(int i = 1; i <= ky; i++) {
							int py,vy;
							scanf("%d%d",&py,&vy);
							y[py] = vy;
						}
						if((x[1] < y[1] && x[2] < y[1]) || (x[1] > y[1] && x[2] > y[1])) printf("1");
						else printf("0");
					}
					return 0;
				}
			}

		}
	}
	if(c>=8&&c <= 14) {
		if(x[n] < y[m]) printf("1");
		else printf("0");
		while(q--) {
			int kx,ky;
			scanf("%d%d",&kx,&ky);
			for(int i = 1; i <= kx; i++) {
				int px,vx;
				scanf("%d%d",&px,&vx);
				x[px] = vx;
			}
			for(int i = 1; i <= ky; i++) {
				int py,vy;
				scanf("%d%d",&py,&vy);
				y[py] = vy;
			}
			if(x[n] < y[m]) printf("1");
			else printf("0");
		}
		return 0;
	}
	if((x[1] != y[1])&&(x[n] != y[m])||((x[1] < y[1] && x[2] < y[2]) || (x[1] > y[1] && x[2] > y[2]))) printf("1");
	else printf("0");
	while(q--) {
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		for(int i = 1; i <= kx; i++) {
			int px,vx;
			scanf("%d%d",&px,&vx);
			x[px] = vx;
		}
		for(int i = 1; i <= ky; i++) {
			int py,vy;
			scanf("%d%d",&py,&vy);
			y[py] = vy;
		}
		if((x[1] != y[1])&&(x[n] != y[m])&&((x[1] < y[1] && x[2] < y[2]) || (x[1] > y[1] && x[2] > y[2]))) printf("1");
		else printf("0");
	}
	return 0;
}