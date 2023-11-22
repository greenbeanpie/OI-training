#include<bits/stdc++.h>
using namespace std;
const int tru = 114514;
const int fal = 1919810;
const int unk = 19800307;
int c, t;
int n, m;
char v; int I, J;
long long ans;

int zhong[100010][2], guo[100010][2];

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; i++)
		{
			cin >> v;
			if(v == 'T' || v == 'F' || v == 'U')
			{
				cin >> I;
				if(v == 'T') guo[I][0] = tru;
				else if(v == 'F') guo[I][0] = fal;
				else guo[I][0] = unk;
			}
			else if(v == '+')
			{
				cin >> I >> J;
				if(guo[J][0]) {guo[I][0] = guo[J][0], guo[I][1] = guo[J][1];}
				else {guo[I][0] = J;}
			}
			else
			{
				cin >> I >> J;
				if(guo[J][0]) {guo[I][0] = guo[J][0], guo[I][1] = 1 ^ guo[J][1];}
				else {guo[I][0] = J; guo[I][1] = 1;}
			}
		}
		for(int i = 1; i <= n; i++)
		{
			if(guo[i][0] > n)
			{
				zhong[i][0] = guo[i][0];
				zhong[i][1] = guo[i][1];
				if(guo[i][0] == unk) ans++;
			}
			else if(guo[i][0] > 0 && guo[i][0] != i)
			{
				if(guo[guo[i][0]][0] > 0)
				{
					if(zhong[guo[i][0]][0] > n)
					{
						zhong[i][0] = zhong[guo[i][0]][0];
						zhong[i][1] = zhong[guo[i][0]][1] ^ guo[i][1];
						if(zhong[i][0] == unk) ans++;
					}
					else if(guo[guo[i][0]][0] > n)
					{
						 zhong[i][0] = guo[guo[i][0]][0];
						 zhong[i][1] = guo[guo[i][0]][1] ^ guo[i][1];
						 if(zhong[i][0] == unk) ans++;
					}
					else if((guo[guo[i][0]][0] == guo[i][0] && guo[guo[i][0]][1] == 1) || (guo[guo[i][0]][0] == i && guo[i][1] == 1))
					{
						zhong[i][0] = unk;
						ans++;
					}
				}
			}
			else
			{
				if(guo[i][1] == 1)
				{
					ans++;
					zhong[i][0] = unk;
				}
			}
		}
		printf("%lld\n", ans);
		ans = 0;
		memset(zhong, 0, sizeof(zhong));
		memset(guo, 0, sizeof(guo));
	}
	return 0;
}
