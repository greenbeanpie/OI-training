#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6+5;
int num[N];

deque<pair<int,int> > q;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n;i++){
		cin >> num[i];
		while (!q.empty() && q.back().first >= num[i])
		{
			q.pop_back();
		}
		q.push_back({num[i],i});
		if(i-q.front().second>=k){
			q.pop_front();
		}
		if(i>=k){
			cout << q.front().first << " ";
		}
	}
	cout << endl;
	q.clear();
	for (int i = 1; i <= n; i++)
	{
		// cin >> num[i];
		while (!q.empty() && q.back().first <= num[i])
		{
			q.pop_back();
		}
		q.push_back({num[i], i});
		if (i - q.front().second >= k)
		{
			q.pop_front();
		}
		if (i >= k)
		{
			cout << q.front().first << " ";
		}
	}
	return 0;
}