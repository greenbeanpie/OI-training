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

int C, t, n, m, x, y, ans, tot = 0, Min;

int au[100005];

char op;



int a[105], b[105], c[105], jl[105], _jl[105];

inline void check()
{
	
	for(int i = 1; i <= n; ++ i ) _jl[i] = jl[i];
	for(int i = 1; i <= m; ++ i )
	{
		if(c[i] == 3)
		{
			_jl[a[i]] = b[i];
		}
		else if(c[i] == 1)
		{
			_jl[a[i]] = _jl[b[i]];
		}
		else if(c[i] == 2)
		{
			if(_jl[b[i]] == 1)
			{
				_jl[a[i]] = 2;
			}
			else if(_jl[b[i]] == 2)
			{
				_jl[a[i]] = 1;
			}
			else if(_jl[b[i]] == 3)
			{
				_jl[a[i]] = 3;
			}
		}
	}
	
	
	bool f = 1;
	int ans = 0;
	for(int i = 1; i <= n; ++ i )
	{
		
		if(_jl[i] != jl[i])
		{
			f = 0;
			break;
		}
		else{
			if(jl[i] == 3) ++ ans;
		}
	}
	
	if(!f)
	{
		return;
	}
	else{
		Min = min(Min, ans);
	}
}

inline void dfs(int k)
{
	if(k == n + 1)
	{
		check();
		return;
	}
	jl[k] = 1;
	dfs(k + 1);
	jl[k] = 2;
	dfs(k + 1);
	jl[k] = 3;
	dfs(k + 1);
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	C = read(), t = read();
	while(t --)
	{
		n = read(), m = read();

		//clear
		
		if(C == 1 || C == 2)
		{
			memset(a, 0, sizeof(a));
			memset(b, 0, sizeof(b));
			memset(c, 0, sizeof(c));
			for(int i = 1; i <= m; ++ i )
			{
				cin >> op;
				if(op == '+')
				{
					cin >> x >> y;
					c[i] = 1;
					a[i] = x;
					b[i] = y;
				}
				else if(op == '-')
				{
					cin >> x >> y;
					c[i] = 2;
					a[i] = x;
					b[i] = y;
				}
				else {
					cin >> x;
					c[i] = 3;
					a[i] = x;
					if(op == 'T') b[i] = 1;
					else if(op == 'F') b[i] = 2;
					else if(op == 'U') b[i] = 3;
				}
			}	
			Min = 0x7fffffff;
			dfs(1);
			cout << Min << endl;			
		}
		else if(C == 3 || C == 4)
		{
			ans = 0;
			for(int i = 1; i <= m; ++ i )
			{
				cin >> op;
				cin >> x;
				if(op == 'U') ++ ans;
			}
			cout << ans << endl;
		}
		else if(C == 5 || C == 6)
		{
			tot = 0;
			memset(au, 0, sizeof(au));
	
			for(int i = 1; i <= m; ++ i )
			{
				cin >> op;
				if(op == 'U')
				{
					cin >> x;
					au[x] = 1;
				}
				else{
					cin >> x >> y;
					au[x] = au[y];
				}
			}
//			for(int i = 1; i <= n; ++ i ) cout << au[i] << " ";
//			cout << endl;
			int answer = 0;
			for(int i = 1; i <= n; ++ i ) answer += au[i];
			cout << answer << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Goodbye, OI
If I have opportunity again,
I will treat you with all my might.
But now,
I can't.
Go back to whk,
especially history, geography, and so on..
Even I can't choose you--Technology,
sorry, bye.
*/
