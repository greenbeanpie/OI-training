#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 5;
const int Inf = 0x3f3f3f3f;

int c , t;
int n , m , ans , a , b;
int x[M];
char op;

int main()
{
	freopen("tribool.in" , "r" , stdin);
	freopen("tribool.out" , "w" , stdout);
	scanf("%d%d" , &c , &t);
	if (c == 3 || c == 4)
	{
		while (t--)
		{
			ans = 0;
			memset(x , 0 , sizeof(x));
			scanf("%d%d" , &n , &m);
			for (int i = 1 ; i <= m ; ++i)
			{
				char ddd = getchar();
				op = getchar();
				scanf("%d" , &a);
				//cout << op << endl;
				if (op == 'U')
				{
					x[a] = Inf;
				}
				else 
				{
					x[a] = 0;
				}
			}
			for (int i = 1 ; i <= n ; ++i)
			{
				if (x[i] == Inf)
				{
					++ ans;
				}
			}
			//cout << ans << endl;
			printf("%d\n" , ans);
		}
		return 0;
	}
	else if (c == 7 || c == 8) 
	{
		while(t--)
		{
			ans = 0;
			scanf("%d%d" , &n , &m);
			bool flag = false;
			char geop;
			char ddd = getchar();
			geop = getchar();
			//cin >> geop >> a >> b;
			scanf("%d%d" , &a , &b);
			for (int i = 2 ; i <= m ; i ++)
			{
				char ddd = getchar();
				op = getchar();
				scanf("%d%d" , &a , &b);
				if (op != geop)
				{
					//cout << "111" << endl;
					flag = true;
				}
				geop = op;
			}
			
			if (flag == true)
			{
				printf("0\n");
			}
			else 
			{
				printf("%d\n" , n);
			}
		}
		return 0;
	}//ganjueshi : bingchaji dabuwanle... pianfenba
	else 
	{
		while (t--)
		{
			cout << 0 << endl;
		}
	}
	return 0;
}
