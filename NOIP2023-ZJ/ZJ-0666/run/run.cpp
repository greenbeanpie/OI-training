#include <bits/stdc++.h>
using namespace std;
#define M int(1e5+1)
#define ll long long

void file() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
}

void desync() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);std::cout.tie(0);
}

struct query{ll x,y,z;} q[M];

int C,T;
ll n,m,k,d;
int ans;

bool cmp(query a, query b) {
	if (a.x-a.y+1 == b.x-b.y+1) return a.y < b.y;
	return a.x-a.y+1 < b.x-b.y+1;
}

void solve() {
	ans = 0;
	cin >> n >> m >> k >> d;
	for (int i = 1; i <= m; i++) cin >> q[i].x >> q[i].y >> q[i].z;
	sort(q+1,q+1+m,cmp);
	for (int i = 1; i <= m; i++) {
		if (q[i].z>q[i].y*d) {
			if (i==1) ans+=q[i].z-q[i].y*d;
			else {
				if (q[i-1].x>=q[i].x-q[i].y+1) {
					if (q[i].x-q[i-1].x+q[i-1].y<=k) ans+=q[i].z-(q[i].x-q[i-1].x)*d;
					else {
						if (q[i].z-q[i].y*d>q[i-1].z-q[i-1].y*d) {
							ans-=q[i-1].z-q[i-1].y*d;
							ans+=q[i].z-q[i].y*d;
						} else {
							continue;
						}
					}
				} else {
					ans+=q[i].z-q[i].y*d;
				}
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	file();
	desync();
	cin >> C >> T;
	while (T--) solve();
	return 0;
}
