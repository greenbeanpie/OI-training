#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
const int N=1e5+10;
int o=0, t=0, n=0, m=0, k=0, d=0, x=0, y=0, v=0, ans=0, pd[N];
struct df{
	int x, z, y, v, w;
}c[N];
int ci=0;
inline bool comp(df x, df y){
	return x.v < y.v;
}
signed main(){
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> o >> t;
	for(; t; t--){
		ans=0;
		memset(pd, 0, sizeof(pd));
		cin >> n >> m >> k >> d;
		for(int i=1; i<=m; i++){
			cin >> x >> y >> v;
			if(y <= k && y <= x && v > d*y){
				++ ci;
				c[ci].x=x, c[ci].z=x-y+1, c[ci].y=y, c[ci].v=v, c[ci].w=d*y;
			}
		}
		sort(c+1, c+1+m, comp);
		for(int i=1; i<=m; i++){
			int dt=0;
			for(int j=c[i].z-1; j>=1; j--){
				if(pd[j] == 1) dt ++;
				else break;
			}
			if(dt + c[i].y > k) continue;
			dt=0;
			for(int j=c[i].x+1; j<=n; j++){
				if(pd[j] == 1) dt ++;
				else break;
			}
			if(dt + c[i].y > k) continue;
			for(int j=c[i].z; j<=c[i].x; j++){
				pd[j]=1;
			}
			ans += c[ci].v;
		}
		for(int i=1; i<=n; i++){
			if(pd[i]) ans -= d;
		}
		cout << ans << endl;
	}
	return 0;
}
