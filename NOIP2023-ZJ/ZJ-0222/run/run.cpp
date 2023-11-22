#include<bits/stdc++.h>
using namespace std;
int id;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int T;
	cin >> id >> T;
	while(T--){
		long long N,M,K,D,ANS = 0;
		cin >> N >> M >> K >> D;
		while(M--){
			long long X,Y,V;
			cin >> X >> Y >> V;
			if(Y > K) continue;
			ANS += max(0ll ,V-Y*D);
		}
		cout << ANS <<"\n";
	}
	return 0;
}
//rp+=inf;
//rp+=inf;
//rp+=inf;
//rp+=inf;
//rp+=inf;
//rp+=inf;
