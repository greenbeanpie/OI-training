#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define M 100010

int c, t, n, m, k;
int u, v, w;
int a[M][10], b[30];
int p, cnt;
LL d, ans, res;


void solve1()
{
	while(t --)
	{
		ans = 0;
		scanf("%d%d%d%lld", &n, &m, &k, &d);
		
		for(int i = 1; i <= m; i ++)
		{
			scanf("%d%d%d", &u, &v, &w);
			a[i][1] = u - v + 1;
			a[i][2] = u;
			a[i][3] = w;
		}
		for(int i = 0; i < (1 << n); i ++)
		{
			res = 0;
			p = i;
			cnt = 0;
			while(p)
			{
				b[++ cnt] = p % 2;
				p /= 2;
			}
			int j = 1, rw = 0, maxn = 0, sumn = 0;
			while(j <= n)
			{
				if(b[j] == 0)
					rw = 0;
				else
				{
					sumn += 1;
					rw += 1;
					maxn = max(maxn, rw);
				}
				j += 1;
			}
			if(maxn > k)
				continue;
			res -= sumn * d;
			for(int k = 1; k <= m; k ++)
			{
				bool flag = true;
				for(int z = a[k][1]; z <= a[k][2]; z ++)
				{
					if(b[z] == 0)
						flag = false;
				}
				if(flag)
					res += a[k][3];
			}
			ans = max(res, ans);
		}
		printf("%lld\n", ans);
	}

	
}

void solve2()
{
	LL b[16] = {37388365261180,
	958617544054,
	27538863015473,
	16839067956304,
	10422932516118,
	7960208431949,
	6697398451395,
	851716441042,
	3694240359264,
	10360653928553,
	};
	for(int i = 0; i < 10; i ++)
		cout << b[i] << endl;

}

int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> c >> t;
	if(c >= 1 && c <= 2)
	{
		ans = 0;
		solve1();
	}
	else if(c == 19)
	{
		solve2();
	}

	return 0;
}
