#include <iostream>
#include <cstdio>
using namespace std;
int c, t;
int n, m, k, d;
int main(){
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin>>c>>t;
	int x, y, v;
	int ans = 0;
	while (t--){
		cin>>n>>m>>k>>d;
		for (int i=0;i<m;i++){
			cin>>x>>y>>v;
			ans += v;
			ans -= y*d;
		}
		cout<<ans<<endl;
	}
	return 0;
}
// Have no time.
// I love you.
// AFO.