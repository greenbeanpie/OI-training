#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#define int long long
#define endl "\n"

vector<int> e[105];
int in[105];

signed main(){
	#ifndef ONLINE_JUDGE
		freopen("B3644.in","r",stdin);
		freopen("B3644.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int son;
		while(cin >>son&&son){
			e[i].push_back(son);
			in[son]++;
		}
	}
	queue<int> q;

	for(int i=1;i<=n;i++){
		if(!in[i]){
			q.push(i);
		}
	}
	while(q.size()){
		int now=q.front();
		q.pop();
		cout << now << " ";
		for(int i:e[now]){
			in[i]--;
			if(!in[i]){
				q.push(i);
			}
		}
	}	
	return 0;
}
