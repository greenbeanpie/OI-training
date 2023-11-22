#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 5e5 + 10;
int c, n, m, q;
int x[MAXN], y[MAXN], x1[MAXN], y2[MAXN];
int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%d %d %d %d", &c, &n, &m, &q);
	for(int i = 0; i < n; i++){
		scanf("%d", &x[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &y[i]);
	}
	
	
	
	if(n == 1 && m == 1){
		if(x[0] > y[0]){
			printf("1");
		}
		else{
			printf("0");
		}
		while(q--){
			for(int i = 0; i < n; i++){
				x1[i] = x[i];
			}
			for(int i = 0; i < m; i++){
				y2[i] = y[i];
			}
			int kx, ky;
			scanf("%d %d", &kx, &ky);
			for(int i = 0; i < kx; i++){
				int px, vx;
				scanf("%d %d", &px, &vx);
				x1[px - 1] = vx;
			}
			for(int i = 0; i < ky; i++){
				int py, vy;
				scanf("%d %d", &py, &vy);
				y2[py - 1] = vy;
			}
			if(x1[0] > y2[0]){
				printf("1");
			}
			else{
				printf("0");
			}
		}
		
	}
	if(n == 1 && m == 2){
		int maxn = max(y[0], y[1]);
		int minn = min(y[0], y[1]);
		if((x[0] > y[0] && x[0] > y[1]) || (x[0] < y[0] && x[0] < y[1])){
			cout << 1;
		}
		else{
			cout << 0;
		}
		while(q--){
			for(int i = 0; i < n; i++){
				x1[i] = x[i];
			}
			for(int i = 0; i < m; i++){
				y2[i] = y[i];
			}
			int kx, ky;
			scanf("%d %d", &kx, &ky);
			for(int i = 0; i < kx; i++){
				int px, vx;
				scanf("%d %d", &px, &vx);
				x1[px - 1] = vx;
			}
			for(int i = 0; i < ky; i++){
				int py, vy;
				scanf("%d %d", &py, &vy);
				y2[py - 1] = vy;
			}
			if((x1[0] > y2[0] && x1[0] > y2[1]) || (x1[0] < y2[0] && x1[0] < y2[1])){
				cout << 1;
			}
			else{
				cout << 0;
			}
		}
	}
	if(n == 2 && m == 1){
		int maxn = max(y[0], y[1]);
		int minn = min(y[0], y[1]);
		if((y[0] > x[0] && y[0] > x[1]) || (y[0] < x[0] && y[0] < x[1])){
			cout << 1;
		}
		else{
			cout << 0;
		}
		while(q--){
			for(int i = 0; i < n; i++){
				x1[i] = x[i];
			}
			for(int i = 0; i < m; i++){
				y2[i] = y[i];
			}
			int kx, ky;
			scanf("%d %d", &kx, &ky);
			for(int i = 0; i < kx; i++){
				int px, vx;
				scanf("%d %d", &px, &vx);
				x1[px - 1] = vx;
			}
			for(int i = 0; i < ky; i++){
				int py, vy;
				scanf("%d %d", &py, &vy);
				y2[py - 1] = vy;
			}
			if((y2[0] > x1[0] && y2[0] > x1[1]) || (y2[0] < x1[0] && y2[0] < x1[1])){
				cout << 1;
			}
			else{
				cout << 0;
			}
		}
	}
	if(n == 2 && m == 2){
		if((x[0] - y[0]) * (x[1] - y[1]) > 0){
			cout << 1;
		}
		else{
			cout << 0;
		}
		while(q--){
			for(int i = 0; i < n; i++){
				x1[i] = x[i];
			}
			for(int i = 0; i < m; i++){
				y2[i] = y[i];
			}
			int kx, ky;
			scanf("%d %d", &kx, &ky);
			for(int i = 0; i < kx; i++){
				int px, vx;
				scanf("%d %d", &px, &vx);
				x1[px - 1] = vx;
			}
			for(int i = 0; i < ky; i++){
				int py, vy;
				scanf("%d %d", &py, &vy);
				y2[py - 1] = vy;
			}
			if((x[0] - y[0]) * (x[1] - y[1]) > 0){
				cout << 1;
			}
			else{
				cout << 0;
			}
		}
	}
	
	
	
	
	
	if(x[0] < y[0] && x[n - 1] < y[m - 1]){
		int a = 0, flag1 = 1;
		for(int i = 0; i < n; i++){//up->down   x->y    x<y  forward
			if(flag1 == 0){
				break;
			}
		    int b = a;
		    while(x[i] >= y[b] && b < m){
		    	b++;
		    	if(b == m){
		    		flag1 = 0;
				}
			}
			a = b;
		}
		for(int i = a; i < m; i++){
			if(x[n - 1] >= y[i]){
				flag1 = 0;
				break;
			}
		}
		a = 0;
		for(int i = 0; i < m; i++){// y->x   x < y  forward
			if(flag1 == 0){
				break;
			}
		    int b = a;
		    while(y[i] <= x[b] && b < n){
		    	b++;
		    	if(b == n){
		    		flag1 = 0;
				}
			}
			a = b;
		}
		for(int i = a; i < n; i++){
			if(x[i] >= y[m - 1]){
				flag1 = 0;
				break;
			}
		}
		a = m - 1;
		for(int i = n - 1; i >= 0; i--){//x->y x<y backward
			if(flag1 == 0){
				break;
			}
		    int b = a;
		    while(x[i] >= y[b] && b >= 0){
		    	b--;
		    	if(b == -1){
		    		flag1 = 0;
				}
			}
			a = b;
		}
		for(int i = a; i >= 0; i--){
			if(x[n - 1] >= y[i]){
				flag1 = 0;
				break;
			}
		}
		a = n - 1;
		for(int i = m - 1; i > 0; i--){//y->x x < y backward
			if(flag1 == 0){
				break;
			}
		    int b = a;
		    while(y[i] <= x[b] && b >= 0){
		    	b--;
		    	if(b == -1){
		    		flag1 = 0;
				}
			}
			a = b;
		}
		for(int i = a; i >= 0; i--){
			if(x[i] >= y[m - 1]){
				flag1 = 0;
				break;
			}
		}
		printf("%d", flag1);
	}
	else if(x[0] > y[0] && x[n - 1] > y[m - 1]){
		int a = 0, flag2 = 1;
		for(int i = 0; i < n; i++){//up->down   x->y    x>y forward
			if(flag2 == 0){
				break;
			}
		    int b = a;
		    while(x[i] <= y[b] && b < m){
		    	b++;
		    	if(b == m){
		    		flag2 = 0;
				}
			}
			a = b;
		}
		for(int i = a; i < m; i++){
			if(x[n - 1] <= y[i]){
				flag2 = 0;
				break;
			}
		}
		//printf("1:%d\n", flag2);
		a = 0;
		for(int i = 0; i < m; i++){//y->x  x > y forward
			if(flag2 == 0){
				break;
			}
		    int b = a;
		    while(y[i] >= x[b] && b < n){
		    	b++;
		    	if(b == n){
		    		flag2 = 0;
				}
			}
			a = b;
		}
		for(int i = a; i < n; i++){
			if(x[i] <= y[m - 1]){
				flag2 = 0;
				break;
			}
		}
		//printf("2:%d\n", flag2);
		a = n - 1;
		for(int i = m - 1; i > 0; i--){//y->x x > y backward
			if(flag2 == 0){
				break;
			}
		    int b = a;
		    while(y[i] >= x[b] && b >= 0){
		    	b--;
		    	if(b == -1){
		    		flag2 = 0;
				}
			}
			a = b;
		}
		for(int i = a; i >= 0; i--){
			if(x[n - 1] <= y[i]){
				flag2 = 0;
				break;
			}
		}
		//printf("3:%d\n", flag2);
		a = m - 1;
		for(int i = n - 1; i >= 0; i--){//x->y x > y backward
			if(flag2 == 0){
				break;
			}
		    int b = a;
		    while(x[i] <= y[b] && b >= 0){
		    	b--;
		    	if(b == -1){
		    		flag2 = 0;
				}
			}
			a = b;
		}
		for(int i = a; i >= 0; i--){
			if(x[i] <= y[m - 1]){
				flag2 = 0;
				break;
			}
		}
		//printf("4:%d\n", flag2);
		printf("%d", flag2);
	}
	else{
		printf("0");
	}
	
	
	while(q--){
		for(int i = 0; i < n; i++){
			x1[i] = x[i];
		}
		for(int i = 0; i < m; i++){
			y2[i] = y[i];
		}
		int kx, ky;
		scanf("%d %d", &kx, &ky);
		for(int i = 0; i < kx; i++){
			int px, vx;
			scanf("%d %d", &px, &vx);
			x1[px - 1] = vx;
		}
		for(int i = 0; i < ky; i++){
			int py, vy;
			scanf("%d %d", &py, &vy);
			y2[py - 1] = vy;
		}
		
		
		if(x1[0] < y2[0] && x1[n - 1] < y2[m - 1]){
			int a = 0, flag1 = 1;
			for(int i = 0; i < n; i++){//up->down   x->y    x<y  forward
				if(flag1 == 0){
					break;
				}
			    int b = a;
			    while(x1[i] >= y2[b] && b < m){
			    	b++;
			    	if(b == m){
			    		flag1 = 0;
					}
				}
				a = b;
			}
			for(int i = a; i < m; i++){
				if(x1[n - 1] >= y2[i]){
					flag1 = 0;
					break;
				}
			}
			a = 0;
			for(int i = 0; i < m; i++){// y->x   x < y  forward
				if(flag1 == 0){
					break;
				}
			    int b = a;
			    while(y2[i] <= x1[b] && b < n){
			    	b++;
			    	if(b == n){
			    		flag1 = 0;
					}
				}
				a = b;
			}
			for(int i = a; i < n; i++){
				if(x1[i] >= y2[m - 1]){
					flag1 = 0;
					break;
				}
			}
			a = m - 1;
			for(int i = n - 1; i >= 0; i--){//x->y x<y backward
				if(flag1 == 0){
					break;
				}
			    int b = a;
			    while(x1[i] >= y2[b] && b >= 0){
			    	b--;
			    	if(b == -1){
			    		flag1 = 0;
					}
				}
				a = b;
			}
			for(int i = a; i >= 0; i--){
				if(x1[n - 1] >= y2[i]){
					flag1 = 0;
					break;
				}
			}
			a = n - 1;
			for(int i = m - 1; i > 0; i--){//y->x x < y backward
				if(flag1 == 0){
					break;
				}
			    int b = a;
			    while(y2[i] <= x1[b] && b >= 0){
			    	b--;
			    	if(b == -1){
			    		flag1 = 0;
					}
				}
				a = b;
			}
			for(int i = a; i >= 0; i--){
				if(x1[i] >= y2[m - 1]){
					flag1 = 0;
					break;
				}
			}
			printf("%d", flag1);
		}
		else if(x1[0] > y2[0] && x1[n - 1] > y2[m - 1]){
			int a = 0, flag2 = 1;
			for(int i = 0; i < n; i++){//up->down   x->y    x>y forward
				if(flag2 == 0){
					break;
				}
			    int b = a;
			    while(x1[i] <= y2[b] && b < m){
			    	b++;
			    	if(b == m){
			    		flag2 = 0;
					}
				}
				a = b;
			}
			for(int i = a; i < m; i++){
				if(x1[n - 1] <= y2[i]){
					flag2 = 0;
					break;
				}
			}
			//printf("1:%d\n", flag2);
			a = 0;
			for(int i = 0; i < m; i++){//y->x  x > y forward
				if(flag2 == 0){
					break;
				}
			    int b = a;
			    while(y2[i] >= x1[b] && b < n){
			    	b++;
			    	if(b == n){
			    		flag2 = 0;
					}
				}
				a = b;
			}
			for(int i = a; i < n; i++){
				if(x1[i] <= y2[m - 1]){
					flag2 = 0;
					break;
				}
			}
			//printf("2:%d\n", flag2);
			a = n - 1;
			for(int i = m - 1; i > 0; i--){//y->x x > y backward
				if(flag2 == 0){
					break;
				}
			    int b = a;
			    while(y2[i] >= x1[b] && b >= 0){
			    	b--;
			    	if(b == -1){
			    		flag2 = 0;
					}
				}
				a = b;
			}
			for(int i = a; i >= 0; i--){
				if(x1[n - 1] <= y2[i]){
					flag2 = 0;
					break;
				}
			}
			//printf("3:%d\n", flag2);
			a = m - 1;
			for(int i = n - 1; i >= 0; i--){//x->y x > y backward
				if(flag2 == 0){
					break;
				}
			    int b = a;
			    while(x1[i] <= y2[b] && b >= 0){
			    	b--;
			    	if(b == -1){
			    		flag2 = 0;
					}
				}
				a = b;
			}
			for(int i = a; i >= 0; i--){
				if(x1[i] <= y2[m - 1]){
					flag2 = 0;
					break;
				}
			}
			//printf("4:%d\n", flag2);
			printf("%d", flag2);
		}
		else{
			printf("0");
		}
	}
	
	
	
	
	return 0;                  
}