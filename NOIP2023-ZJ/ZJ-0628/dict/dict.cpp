#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=3005;
string str[N],mininum;
bool ans[N];
int minpos;

signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> str[i];
	}
	mininum = str[1];
	minpos = 1;
	for(int i=2;i<=n;i++){
		if(str[i]<mininum){
			mininum = str[i];
			minpos = i;
		}
	}
	ans[minpos] = 1;
	sort(mininum.rbegin(),mininum.rend());
	for(int i=1;i<=n;i++){
		sort(str[i].begin(),str[i].end());
		if(str[i]<mininum){
			ans[i] = 1;
		}
	}
	for(int i=1;i<=n;i++){
		cout << ans[i];
	}
	cout << endl;
	return 0;
}