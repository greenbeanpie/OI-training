#include<bits/stdc++.h>
using namespace std;

inline int read () {
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

int c , n , m ,q;
int x[500005] , y[500005]; 
int a[500005] , b[500005];
inline void fre() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
}

int main() {
	fre();
	int t,tt;
	c = read() , n = read() , m = read() , q = read();
	if(c == 1|| (n == 1 && m == 1)) {
		for(int i = 1 ; i <= n ;++i) {
			cin >> x[i];
			t=x[1];
		}
		for(int i = 1 ; i <= m ;++i){
			cin >> y[i];
			tt=y[1];	
		} 
		if(x[1] > y[1]) cout << 1;
		else cout << 0;
		while(q--) {
			x[1]=t;
			y[1] = tt;
			int kx , ky;
			kx = read() , ky = read();
			while (kx--) {
				int px , vx;
				px = read() , vx = read();
				x[1] = vx;
			}
			while (ky--) {
				int py , vy;
				py = read() , vy = read();
				y[1] = vy;
			}
			if(x[1] > y[1]) cout << 1;
			else cout << 0;
		}
		return 0;
	}
	else if(c == 2) {
		for(int i = 1 ; i <= n ;++i) {
			cin >> x[i];
			a[i] = x[i];
		}
		for(int i = 1 ; i <= m ;++i) {
			cin >> y[i];
			b[i] = y[i];
		}	
		if(x[1] > y[1]) cout << 1;
		else if(x[1] == y[1]) {
			if(x[2] > y[2]) cout << 1;
			else cout << 0; 
		}
		else cout << 0;
		
		while(q--) {
			for(int i =1 ;i <=n ;++i) {
				x[i] = a[i], y[i] = b[i];
			}
			int kx , ky;
			kx = read() , ky = read();
			while (kx--) {
				int px , vx;
				px = read() , vx = read();
				x[px] = vx;
			}
			while (ky--) {
				int py , vy;
				py = read() , vy = read();
				y[py] = vy;
			}
			if(x[1] > y[1]) cout << 1;
			else if(x[1] == y[1]) {
				if(x[2] > y[2]) cout << 1;
				else cout << 0; 
			}
			else cout << 0;
		}
		return 0;
	}
	else {
		
		for(int i = 1 ; i <= n ;++i) {
			cin >> x[i];
			a[i] = x[i];
		}
		for(int i = 1 ; i <= m ;++i) {
			cin >> y[i];
			b[i] = y[i];
		}	
		if(x[1] > x[2]) cout << 1;
		else if(x[1] == y[1]) {
			bool flag = true;
			for(int i = 2;i <= n;++i) {
				if(x[i] < y[i]) {
					cout << 0;
					flag = false;
					break;
				}
			}
			if(flag) {
				cout << 1;
			}
		}
		else cout << 0;
		
		while(q--) {
			int kx , ky;
			kx = read() , ky = read();
			for(int i =1 ;i <=n ;++i) {
				x[i] = a[i], y[i] = b[i];
			}
			while (kx--) {
				int px , vx;
				px = read() , vx = read();
				x[px] = vx;
			}
			while (ky--) {
				int py , vy;
				py = read() , vy = read();
				y[py] = vy;
			}
//			for(int i = 1 ;i <= n; ++i) {
//				cout << x[i] << " " ;
//					
//			}cout << endl;
//			for(int i = 1 ;i <= n; ++i) {
//				cout << y[i] << " " ;
//				
//			}cout << endl;
			
			 if(x[1] >= y[1]) {
				bool flag = true;
				for(int i = 2;i <= n;++i) {
					if(x[i] < y[i]) {
						cout << 0;
						flag = false;
						break;
					}
				}
				if(flag) {
					cout << 1;
				}
			}
			else cout << 0;
		}
	}
    return 0;
}
