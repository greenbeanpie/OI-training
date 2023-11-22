#include<bits/stdc++.h>
#define LL long long
#define IL inline
using namespace std;
const int N = 5e5 + 10;
bool _u;
int id,n,m,q,x[N],y[N],X[N],Y[N],ans[N];
bool _v;
IL int read() {
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {if(c == '-')	f = -1;c = getchar();}
	while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + (c ^ 48);c = getchar();}
	return x * f;
}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	//cerr << abs(&_u - &_v) / 1048576.0 << "MB" << endl;
	id = read(),n = read(),m = read(),q = read();
	for(int i = 1;i <= n;i ++)	X[i] = x[i] = read();
	for(int i = 1;i <= m;i ++)	Y[i] = y[i] = read();
	if(id == 1) {
		if(X[1] != Y[1])	ans[1] = 1;
		for(int j = 1;j <= q;j ++) {
			for(int i = 1;i <= n;i ++)	X[i] = x[i];
			for(int i = 1;i <= m;i ++)	Y[i] = y[i];
			int kx = read(),ky = read();
			for(int i = 1;i <= kx;i ++) {int p = read(),v = read();X[p] = v;}
			for(int i = 1;i <= ky;i ++) {int p = read(),v = read();Y[p] = v;}
			if(X[1] != Y[1])	ans[j + 1] = 1;
		}
		for(int i = 1;i <= q + 1;i ++)	printf("%d",ans[i]);
		printf("\n");return 0;
	}
	if(id == 2) {
		if((X[1] < Y[1] && X[2] < Y[2]) || (X[1] > Y[1] && X[2] > Y[2]))	ans[1] = 1;
		for(int j = 1;j <= q;j ++) {
			for(int i = 1;i <= n;i ++)	X[i] = x[i];
			for(int i = 1;i <= m;i ++)	Y[i] = y[i];
			int kx = read(),ky = read();
			for(int i = 1;i <= kx;i ++) {int p = read(),v = read();X[p] = v;}
			for(int i = 1;i <= ky;i ++) {int p = read(),v = read();Y[p] = v;}
			if((X[1] < Y[1] && X[2] < Y[2]) || (X[1] > Y[1] && X[2] > Y[2]))	ans[j + 1] = 1;
		}
		for(int i = 1;i <= q + 1;i ++)	printf("%d",ans[i]);
		printf("\n");return 0;
	}
	if(id >= 3 && id <= 4) {
		
	}
	if(id >= 8 && id <= 14) {
		
	}
	return 0;
}
