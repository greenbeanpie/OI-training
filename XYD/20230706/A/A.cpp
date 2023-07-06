#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=1e5+5;
int l[1005],r[1005];
bool vis[1005];
signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("A.in","r",stdin);
		freopen("A.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> l[i] >> r[i];
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		for(int j=1;j<=n;j++){
			if(i==j||vis[j]){
				continue;
			}
			if(l[j]<=l[i]&&r[j]>=r[i]){
				vis[i]=true;
				break;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			sum++;
		}
	}
	cout << sum;
	return 0;
}