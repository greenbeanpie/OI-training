#include <iostream>
using namespace std;

int c,t,a[100010],b[100010],n,m,cnt,ans[100010],temp[100010];
char op[100010],tmp;

bool sure[100010];

void dfs(int x,int value)
{
	if(x == n + 1)
	{
		for(int i = 1;i <= n;i++) temp[i] = ans[i];
		for(int i = 1;i <= m;i++)
		{
			if(op[i] == '+') temp[a[i]] = temp[b[i]];
			else if(op[i] == '-') temp[a[i]] = -1 * temp[b[i]];
			else if(op[i] == 'U') temp[a[i]] = 0;
			else if(op[i] == 'T') temp[a[i]] = 1;
			else temp[a[i]] = -1;
		}
		for(int i = 1;i <= n;i++) if(temp[i] != ans[i]) return;
		int tmpcnt = 0;
		for(int i = 1;i <= n;i++) if(ans[i] == 0) tmpcnt++;
		if(cnt > tmpcnt) cnt = tmpcnt;
		return;
	}
	ans[x] = value;
	dfs(x + 1,1);
	dfs(x + 1,-1);
	dfs(x + 1,0);
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		//Input
		cin >> n >> m;
		for(int i = 1;i <= n;i++) sure[i] = false,ans[i] = 1;
		for(int i = 1;i <= m;i++)
		{
			cin >> tmp >> a[i];
			op[i] = tmp;
			if(op[i] == '+' || op[i] == '-') cin >> b[i];
		}
		cnt = 0;
		//Point 3,4
		if(c == 3 || c == 4)
		{
			for(int i = 1;i <= m;i++)
			{
				if(op[m] == 'T') ans[a[i]] = 1;
				else if(op[m] == 'F') ans[a[i]] = -1;
				else ans[a[i]] = 0;
			}
			for(int i = 1;i <= n;i++) if(ans[i] == 0) cnt++;
			cout << cnt << endl;
		}
		//Point 5,6
		else if(c == 5 || c == 6)
		{
			for(int iii = 1;iii < 666;iii++)
			for(int i = 1;i <= m;i++)
			{
				if(op[i] == 'U')
				{
					sure[a[i]] = true;
					ans[a[i]] = 0;
				}
				else
				{
					if(sure[b[i]])
					{
						sure[a[i]] = true;
						ans[a[i]] = ans[b[i]];
					}
					else
					{
						sure[a[i]] = false;
						ans[a[i]] = 1;
					}
				}
			}
			for(int i = 1;i <= n;i++) if(ans[i] == 0) cnt++;
			cout << cnt << endl;
		}
		//Point 1,2
		else
		{
			cnt = 1e9;
			dfs(1,1);
			dfs(1,-1);
			dfs(1,0);
			cout << cnt << endl;
		}
	}
	return 0;
}