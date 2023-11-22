#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mkp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
void rd(int &x) {
	x = 0; int tp = 0;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') tp = 1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	if(tp) x = -x;
}
const int N = 2010;
int csd, n, m, q, x[N], y[N];
bool f[N][N];
vector<PII>vecx, vecy;
void doit() {
//	cout<<"doit"<<endl;
//	cout<<"x: ";
//	for(int i = 1; i <= n; i++)
//		cout<<x[i]<<" ";
//	cout<<endl;
//	cout<<"y: ";
//	for(int i = 1; i <= m; i++)
//		cout<<y[i]<<" ";
//	cout<<endl;
	if((ll)(x[n] - y[m]) * (x[1] - y[1]) <= 0) {
		printf("0");
		return;
	}
	f[1][1] = 1;
	for(int s = 3; s <= n + m; s++)
		for(int i = 1; i <= min(s, n); i++) {
			int j = s - i;
			if(1 <= j && j <= m) {
				//cout<<i<<"*"<<j<<"???"<<endl;
				if((ll)(x[i] - y[j]) * (x[1] - y[1]) > 0) {
					f[i][j] |= f[i][j - 1];
					f[i][j] |= f[i - 1][j];
					f[i][j] |= f[i - 1][j - 1];
					//cout<<i<<" "<<j<<" is "<<x[i]<<" "<<y[j]<<": "<<f[i][j]<<endl;
				}
			}
		}
	if(f[n][m]) printf("1"); else printf("0");
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			f[i][j] = 0;
	return;
}
int main() {
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	rd(csd); rd(n); rd(m); rd(q); 
	for(int i = 1; i <= n; i++) rd(x[i]);
	for(int i = 1; i <= m; i++) rd(y[i]);
	doit();
	for(int i = 1; i <= q; i++) {
		int kkkx, kkky;
		rd(kkkx); rd(kkky);
		for(int j = 1, kkkp, kkkv; j <= kkkx; j++) {
			rd(kkkp); rd(kkkv);
			vecx.push_back(mkp(kkkp, x[kkkp]));
			x[kkkp] = kkkv;
		}
		for(int j = 1, kkkp, kkkv; j <= kkky; j++) {
			rd(kkkp); rd(kkkv);
			vecy.push_back(mkp(kkkp, y[kkkp]));
			y[kkkp] = kkkv;
		}
		doit();
		
		for(int j = 0; j < vecx.size(); j++)
			x[vecx[j].fi] = vecx[j].se;
		for(int j = 0; j < vecy.size(); j++)
			y[vecy[j].fi] = vecy[j].se;
		vecx.clear(); vecy.clear();
	}
	puts("");
	return 0;
}
