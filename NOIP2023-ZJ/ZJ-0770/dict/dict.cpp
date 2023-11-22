#include<bits/stdc++.h>
using namespace std;
#define il inline

il int read () {
    int x = 0, f = 1;
    char c = getchar();
    while (c<'0' || c>'9') {
        if(c =='-') f=-f;
        c=getchar();
    }
    while (c>='0'&& c<='9') {
        x = (x << 3) + (x << 1) + (c & 15);
        c= getchar();
    }
    return x * f;
}

il void print(int x) {
    if(x < 0) {
        x = -x;
        putchar('-');
    }
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

il void fre() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
}

int n ,m;
char a[3005];
char c[3005][3005];
int main() {
	fre();
    n = read();
    m = read();
    if(n == 1 && m == 1){
    	cin >> a[1];
    	cout << 1;
    	return 0;
	}
	else if(m == 1) {
		for(int i = 1 ;i <= n; ++i) cin >> a[i];
		for(int i = 1; i <= n ;++i){
			int cnt = 0;
			for(int j = 1; j <= n; ++j) {
				if(j == i) continue;
				if(a[i] < a[j]) cnt++;
			}			
			if(cnt == n-1) print(1);
			else print(0); 
		}
		return 0;
	}
	else if(m == 2){
		for(int i = 1; i <= n;++i) 
			for(int j = 1; j <= m;++j) 
				cin >> c[i][j];
		for(int i = 1; i <= n;++i) {
			char now = c[i][1];
			bool flag = true;
			for(int j = 1; j <= n;++j) {
				if(i == j) continue;
				if(now >= c[j][1]){
					if(now >= c[j][2] && c[i][2] >= c[j][1] && c[i][2] >= c[j][2]){
						flag = false;
						break;
					}
				}
			}
			if(flag) print(1);
			else print(0);
		}
		return 0;
	}
	else {
		for(int i = 1; i <= n;++i) 
			for(int j = 1; j <= m;++j) 
				cin >> c[i][j];
		for(int i = 1; i <= n; ++i){
			bool flag = false;
			bool is = false;
			int cnt = 0;
			for(int h = 1;h <= n ;++h) {
				if(h == i) continue;
				for(int j = 1;j <= m;++j) {
					for(int k = 1;k <= m;++k) {
						if(c[i][j] < c[h][k]) {
							cnt++;
							//cout << c[i][j] << " " << c[h][k] << " " << h << " " << cnt << " ";
							flag = true;
							is = true;
							break;
						}
					}
					if(is) break;
				}
				//if(is) break;
			}
			if(flag && cnt == n-1) print(1);
			else print(0);
		}
	}
    return 0;
}
