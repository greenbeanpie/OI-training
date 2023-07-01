#include <bits/stdc++.h>
using namespace std;
#define int long long
int tim[1000005];
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i=1;i<=2*n;i++){
		tim[i]++;
	}
	if (k % 2 == 1)
	{
		int tot=n-1;
		cout << "Yes" << endl;
		bool flag = false;
			for (int i = 2; i <= 2 * n; i++)
			{
				if (i == k)
				{
					continue;
				}
				cout << i;
				tim[i]--;
				if (!flag)
				{
					flag = true;
					cout << " ";
				}
				else
				{
					flag = false;
					cout << "\n";
					tim[1]++;
				}
			}
			tim[1]--;
			tim[2]++;
			cout << "2 1" << endl << "1 1" << endl;
			tot+=2;
			tim[1]--;
			tim[2]--;
			tim[0]++;
				while(tim[1]--,tim[1]--){
					cout << "1 1" << endl;
					tim[0]++;
				}
				while(tim[0]--){
					cout << k << " 0" << endl;
				}
			
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}