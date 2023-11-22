#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int x[500005],y[500005];
int main(){
	#ifndef LOCAL
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin >> c >> n >> m >> q;
	for(int i = 1;i <= n;i++){
		cin >> x[i];
	}
	for(int j = 1;j <= m;j++){
		cin >> y[j];
	}
	if(n==1&&m==1){
		if(x[1]!=y[1]) cout << 1;
		else cout << 0;
		while(q--){
			int kx,ky;
			cin >> kx >> ky;
			int newx=x[1],newy=y[1];
			for(int i = 1;i <= kx;i++){
				int px,vx;
				cin >> px >> vx;
				newx = vx;
			}
			for(int i = 1;i <= ky;i++){
				int py,vy;
				cin >> py >> vy;
				newy = vy;
			}
			if(newx!=newy) cout << 1;
			else cout << 0;
		}
		return 0;
	}
	
}