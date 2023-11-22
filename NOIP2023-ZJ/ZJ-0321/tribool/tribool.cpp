#include<bits/stdc++.h>
using namespace std;
int num[100010], a[100010];
bool flag[100010];
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c, T;
	cin >> c >> T;
	while (T--)
	{
		memset(a, 0, sizeof(a));
		memset(num, 1, sizeof(num));
		memset(flag, 0, sizeof(flag));
		int m, n, ans = 0;
		cin >> n >> m;
		while (m--)
		{
			string v;
			scanf("%d", &v);
//			cin >> v;
			if (v == "+")
			{
				int x, y;
//				cin >> x >> y;
				scanf("%d%d", &x, &y);
				a[x] = y;
				flag[x] = 0;
				num[x] = 1; 
			}
			else if (v == "-")
			{
				int x, y;
//				cin >> x >> y;
				scanf("%d%d", &x, &y);
				a[x] = -1 * y;
				flag[x] = 0;
				num[x] = 1;
			}
			else if (v == "U")
			{
				int x;
//				cin >> x;
				scanf("%d", &x);
				num[x] = 0;
				flag[x] = 1;
				a[x] = 0;
			}
			else if (v == "T")
			{
				int x;
				scanf("%d", &x);
//				cin >> x;
				num[x] = 1;
				flag[x] = 1;
				a[x] = 0;
			}
			else if (v == "F")
			{
				int x;
				scanf("%d", &x);
//				cin >> x;
				num[x] = -1;
				flag[x] = 1;
				a[x] = 0;
			}
		}
		if (c == 3 || c == 4)
		{
			for (int i = 1; i <= n; i++)
			{
				if(num[i] == 0) ans++;
			}
			cout << ans << endl;
			continue;
		}
		if (c == 5 || c == 6)
		{
			for(int i = 1; i <= n; i++)
			{
				if(num[i] == 0) 
				{
					ans++;
					continue;
				}
				int x = a[i];
				while (x != 0 && x != i)
				{
					if(flag[a[i]] == 1 && num[a[i]] == 0) 
					{
						ans++;
						break;
					}
					x = a[x];
				}
			}
			cout << ans << endl;
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			if (flag[i] == 1 && num[i] == 0) 
			{
				ans++;
				continue;
			}
			if (flag[i] == 1) continue;
			int x = a[i];
			if (x == 0) continue;
			int f = 1;
			while(abs(x) != i)
			{
				if (flag[abs(x)] == 1)
				{
					flag[i] = 1;
					num[i] = num[x] * f;
					break;
				}
				if(a[abs(x)] == 0) break;
				else if(x < 0) f = -1 * f;
				x = a[abs(x)];
			}
			if (x < 0) f = -1 * f;
			if (f == -1) ans++;
			else if (flag[i] == 1 && num[i] == 0) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
