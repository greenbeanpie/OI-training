#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct Node{
	int x , y , v;
};

int c , t;
int n , m , k , d;
Node a[N];
long long ans = 0;

bool cmp(Node a , Node b)
{
	return a.x < b.x;
}

inline int my_find(int d , int st)
{
	int l = st, r = m;
	int mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (a[mid].x == d)
		{
			return mid;
		}
		else if (a[mid].x < d)
		{
			l = mid + 1;
		}
		else 
		{
			r = mid - 1;
		}
	}
	return 0;
}

void dfs(int day , long long fen , int lian)
{
	
	if (day > n)
		return;
	
	if (lian > k)
		return;
	
	if (fen > ans)
	{
		ans = fen;
	}

	int s = my_find(day , 1);
	while (s != 0)
	{
		if (lian >= a[s].y)
		{
			fen += a[s].v;
		}
		int s_pos = s;
		s = my_find(day , s_pos + 1);
	}
	
	
	dfs(day + 1 , fen - d, lian + 1);
	dfs(day + 1 , fen , 0);
	
}

int main()
{
	freopen("run.in" , "r" , stdin);
	freopen("run.out" , "w" , stdout);
	scanf("%d%d" , &c , &t);
	while (t--)
	{
		
		ans = 0;
		for (int i = 1 ; i <= m ; i++)
		{
			a[i].x = 0;
			a[i].y = 0;
			a[i].v = 0;
		}
		
		scanf("%d%d%d%d" , &n , &m , &k , &d);
		
		for (int i = 1 ; i <= m ; i++)
		{
			scanf("%d%d%d" , &a[i].x , &a[i].y , &a[i].v);
		}
		
		sort(a + 1 , a + m + 1 , cmp);
		
		dfs(0 , 0 , 0);
		
		cout << ans;
	
	}
	return 0;
}
/*#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int c , t;
int n , m , k , d;
int x[N] , y[N] , v[N];
long long ans = 0;


void dfs(int day , long long fen , int lian)
{
	
	if (day > n)
		return;
	
	if (lian > k)
		return;
	
	if (fen > ans)
	{
		ans = fen;
	}
	
	for (int i = 1 ; i <= m ; i++)
	{
		if (x[i] == day)
		{
			if (lian >= y[i])
			{
				//cout  << day << " "<< fen <<" " << v[i] << " ";
				fen += v[i];
				//cout << fen << endl;
			}
		}
	} 
	
	
	dfs(day + 1 , fen - d, lian + 1);
	dfs(day + 1 , fen , 0);
	
}

int main()
{
	//freopen("run.in" , "r" , stdin);
	//freopen("run.out" , "w" , stdout);
	scanf("%d%d" , &c , &t);
	while (t--)
	{
		
		ans = 0;
		memset(x , 0 , sizeof(x));
		memset(y , 0 , sizeof(x));
		memset(v , 0 , sizeof(x));
		
		scanf("%d%d%d%d" , &n , &m , &k , &d);
		
		for (int i = 1 ; i <= m ; i++)
		{
			scanf("%d%d%d" , &x[i] , &y[i] , &v[i]);
		}
		
		dfs(0 , 0 , 0);
		cout << ans;
	
	}
	return 0;
}
*/
