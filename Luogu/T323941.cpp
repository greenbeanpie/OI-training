#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("T323941.in","r",stdin);
    #endif
	int sx,sy,ex,ey;
	cin >> sx >> sy >> ex >> ey;
	if((abs(sx-ex)+abs(sy-ey))%2==1){
		cout << -1 << endl;
		return 0;
	}
	else{
		if(abs(sx-ex)%2==1){
			
			cout << (abs(sx-ex)+abs(sy-ey))+1;
		}
		else{
			cout << (abs(sx-ex)+abs(sy-ey));
		}
	}
	return 0;
}