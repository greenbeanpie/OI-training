#include <bits/stdc++.h>

const int maxn = (int) 1e5 + 7;
int bl[maxn], chushi[maxn];

struct Sub1
{
	int n, m;
	char op[15];
	int x[15], y[15];
	void mian()
	{
		std::cin >> n >> m;
		for(int i = 0; i < m; i++)
		{
			std::cin >> op[i];
			if(op[i] == 'T' || op[i] == 'F' || op[i] == 'U') scanf("%d", &x[i]);
			else std::cin >> x[i] >> y[i];
			x[i]--; y[i]--;
		}
		int posib = 1;
		for(int i = 0; i < n; i++) posib *= 3;
		int ans = -1;
		for(int i = 0; i < posib; i++)
		{
			int i1 = i;
			for(int j = n - 1; j >= 0; j--)
			{
				chushi[j] = i1 % 3;
				bl[j] = i1 % 3;
				i1 /= 3;
			}
			//T2U1F0
			for(int j = 0; j < m; j++)
			{
				if(op[j] == 'T') bl[x[j]] = 2;
				if(op[j] == 'U') bl[x[j]] = 1;
				if(op[j] == 'F') bl[x[j]] = 0;
				if(op[j] == '+') bl[x[j]] = bl[y[j]];
				if(op[j] == '-') bl[x[j]] = 2 - bl[y[j]];
			}
			int totu = 0; bool ok = true;
			for(int j = 0; j < n; j++)
			{
				if(bl[j] != chushi[j]) ok = false;
				if(bl[j] == 1) totu++;
			}
			if(ok)
			{
				if(ans == -1 || totu < ans) ans = totu;
//				for(int k = 0; k < n; k++) std::cerr << chushi[k] << " ";
//				std::cerr << i <<" "<<totu << std::endl;
			} 
		}
		std::cout << ans << std::endl;
		return;
	}
}sub1;

struct Sub2
{
	void mian()
	{
		int n, m;
		std::cin >> n >> m;
		for(int i = 0; i <= n; i++) bl[i] = 3;
		char op;
		int x;
		for(int i = 0; i < m; i++)
		{
			std::cin >> op >> x;
			//std::cerr << op;
			if(op == 'T') bl[x] = 2;
			if(op == 'U') bl[x] = 1;
			if(op == 'F') bl[x] = 0;
		}
		int ans = 0;
//		for(int i = 1; i <= n; i++) std::cerr << bl[i] << " ";
		for(int i = 1; i <= n; i++) if(bl[i] != 1) ans++;
		std::cout << ans << std::endl;
		return;
	}
}sub2;
//
//struct Sub3
//{
//	void mian()
//	{
//		int n, m;
//		std::cin >> n >> m;
//		for(int i = 0; i <= n; i++) bl[i] = 3;
//		char op;
//		int x, y;
//		for(int i = 0; i < m; i++)
//		{
//			std::cin >> op >> x;
//			//std::cerr << op;
//			if(op == 'U') bl[x] = 1;
//			if(op == '+') 
//			{
//				std::cin >> y;
//				bl[x] = bl[y];
//			}
//		}
//		int ans = 0;
////		for(int i = 1; i <= n; i++) std::cerr << bl[i] << " ";
//		for(int i = 1; i <= n; i++) if(bl[i] != 1) ans++;
//		std::cout << ans << std::endl;
//		return;
//	}
//}sub3;


int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	//freopen("dict.out", "w", stdout);
	int	c, t;
//	scanf("%d%d", &c, &t);
	std::cin >> c >> t;
	if(c <= 2)
	{
		while(t--) sub1.mian();
	}
	if(c == 3 || c == 4)
	{
		while(t--) sub2.mian();
	}
//	if(c == 5 || c == 6)
//	{
//		while(t--) sub3.mian();
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}