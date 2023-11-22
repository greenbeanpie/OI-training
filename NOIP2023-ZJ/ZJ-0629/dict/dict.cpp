#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)

using namespace std;

const int N = 3005;

int cnt[N][30];
int mx[N][N], mi[N][N];
int minn[N], mimx[N];
int n, m;
bool st[N];    

bool check(int mi[], int mimx[])       
{
	rep(i, 1, m)
	{
		if(mi[i] == mimx[i]) continue;
		return mi[i] < mimx[i];
	}
	return false;
}                                 
				                   
int main()       
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	rep(i, 1, n)
	{
		string s;
		cin >> s;
		rep(j, 0, m - 1) cnt[i][s[j] - 'a']++;
	}
	
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	
	rep(i, 1, n)
	{
		int tot = 0;
		per(j, 25, 0) 
		{
			int tmp = cnt[i][j];
			while(tmp)
			{
				mx[i][++tot] = j;
				tmp--;
			}	
		}
		
		tot = 0;
		rep(j, 0, 25)
		{
			int tmp = cnt[i][j];
			while(tmp)
			{
				mi[i][++tot] = j;
				tmp--;
			}
		}
	}
	
	rep(j, 1, m)
	{
		int mi = 1e9;
		rep(i, 1, n) if(!st[i]) mi = min(mx[i][j], mi);
		
		rep(i, 1, n)
		{
			if(st[i]) continue;
			if(mx[i][j] == mi) continue;
			st[i] = true;	
		}
	}
	
	rep(i, 1, n)
	{
		if(!st[i])
		{
			rep(j, 1, m) mimx[j] = mx[i][j];
			break;
		}
	}
	
	rep(i, 1, n)
	{
		if(!st[i]) cout << 1;
		else cout << check(mi[i], mimx);
	}
}

