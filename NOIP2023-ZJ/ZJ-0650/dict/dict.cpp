#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int n, m, k1, k2;

string s[3005], Min1, Min2, c, _c;

char t[3005], _t[3005];

bool cmp(char x, char y)
{
	return x > y;
}

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	n = read(), m = read();
	Min1 = "";
	Min2 = "";
	k1 = 0, k2 = 0;
	for(int i = 1; i <= n; ++ i )
	{
		cin >> s[i];
		for(int j = 0; j < m; ++ j ) _t[j + 1] = s[i][j];
		sort(_t + 1, _t + m + 1, cmp);
		_c = "";
		for(int j = 1; j <= m; ++ j) _c += _t[j];
		if(k1 == 0)
		{
			Min1 = _c;
			k1 = i;
		}
		else if(k2 == 0)
		{
			Min2 = _c;
			k2 = i;
		}
		else{
			if(s[i] < Min1)
			{
				Min1 = _c;
				k1 = i;
			}
			else if(s[i] < Min2)
			{
				Min2 = _c;
				k2 = i;
			}
		}
	}
//	cout << Min1 << " " << Min2 << endl;
	if(n == 1) cout << 1;
	else{
		for(int i = 1; i <= n; ++ i )
		{
			for(int j = 0; j < m; ++ j ) t[j + 1] = s[i][j];
			sort(t + 1, t + m + 1);
			c = "";
			for(int j = 1; j <= m; ++ j ) c += t[j];
			if(i == k1)
			{
				if(c < Min2) cout << 1;
					    else cout << 0;
			}
			else{
				if(c < Min1) cout << 1;
					    else cout << 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
