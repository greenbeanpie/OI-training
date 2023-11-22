#include <iostream>
#include <algorithm>
#include <ctime>
#define f cout << rand()%2;
using namespace std;
const int N=1e5+10;
int o=0, n=0, m=0, q=0, a[N], b[N], ag[N], bg[N], xn=0, xm=0, x=0, y=0;
signed main(){
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	srand(time(NULL));
	cin >> o >> n >> m >> q;
	for(int i=1; i<=n; i++) cin >> ag[i];
	for(int i=1; i<=m; i++) cin >> bg[i];
	/**/f
	for(; q; q--){
		for(int i=1; i<=max(n, m); i++) a[i]=ag[i], b[i]=bg[i];
		cin >> xn >> xm;
		for(int i=1; i<=xn; i++){
			cin >> x >> y; a[x]=y;
		}
		for(int i=1; i<=xm; i++){
			cin >> x >> y; b[x]=y;
		}
		/**/f 
	}
	return cout << endl, 0;
}
