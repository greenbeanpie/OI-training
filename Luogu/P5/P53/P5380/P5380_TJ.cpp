#include <bits/stdc++.h>
// #include <windows.h>																//////////////
using namespace std;
#define out                      \
	{                            \
		flagout = 1;             \
		puts("Invalid command"); \
		return;                  \
	}
#define bounce (a >= 0 && a <= 9 && b >= 0 && b <= 8 && c >= 0 && c <= 9 && d >= 0 && d <= 8)
#define checkok    \
	{              \
		jiang = 1; \
		return;    \
	}

int Q;
int a, b, c, d;
// 全局变量区

int mapp[12][12]; // 列 行 : 如 mapp[4][3]表红方第二个兵
bool turn = 0;	  // 红0 蓝1		//王1 士2 象3 马4 车5 鸭6 兵7  红单位，蓝双位

int checkturn;				  // 记录check的时候对方的王
int hong = 16, lan = 16, gai; // 总兵数  被吃兵
							  //  红蓝变量区

bool flagout;				 // 判断是否被out掉
bool capture = 0, jiang = 0; // 1为被抓/将军
int extra, checkextra;		 // move的时候结果是什么兵的修改
int which;					 // move的时候调用的什么兵
							 // 特殊辅助区

inline void init() // 初始化棋盘
{
	mapp[0][4] = 1, mapp[9][4] = 11;
	mapp[0][3] = 2, mapp[0][5] = 2, mapp[9][3] = 12, mapp[9][5] = 12;
	mapp[0][2] = 3, mapp[0][6] = 3, mapp[9][2] = 13, mapp[9][6] = 13;
	mapp[0][1] = 4, mapp[0][7] = 4, mapp[9][1] = 14, mapp[9][7] = 14;
	mapp[0][0] = 5, mapp[0][8] = 5, mapp[9][0] = 15, mapp[9][8] = 15;
	mapp[2][0] = 6, mapp[2][8] = 6, mapp[7][0] = 16, mapp[7][8] = 16;
	mapp[3][0] = 7, mapp[3][2] = 7, mapp[3][4] = 7, mapp[3][6] = 7, mapp[3][8] = 7;
	mapp[6][0] = 17, mapp[6][2] = 17, mapp[6][4] = 17, mapp[6][6] = 17, mapp[6][8] = 17;
}

void lose(int c, int d) // 判断吞兵
{
	if (mapp[c][d] == 1)
		capture = 1, gai = 1;
	else if (mapp[c][d] == 11)
		capture = 2, gai = 11;
	else if (mapp[c][d] > 10)
		gai = mapp[c][d], lan--;
	else if (mapp[c][d] > 0)
		gai = mapp[c][d], hong--;
}

bool fang(bool turn) // 是哪一方在动 & bounce
{
	if (turn == 0)
		return (mapp[c][d] == 0 || mapp[c][d] > 10);
	else
		return (mapp[c][d] == 0 || mapp[c][d] < 10);
}

void exchange(int e, int extra)
{
	mapp[a][b] = 0, mapp[c][d] = e + extra;
	which = e + extra;
}

inline void move()
{
	// 条件 ：符合该棋的移动 路上||终点无棋 终点敌方？ 没越界

	if (turn == 1)
		extra = 10;

	if (mapp[a][b] == 1 + extra)
	{
		if (bounce == 0)
			out if (c - a == 1 && b == d && fang(turn))
			{
				lose(c, d);
				exchange(1, extra);
				return;
			}
		if (a - c == 1 && b == d && fang(turn))
		{
			lose(c, d);
			exchange(1, extra);
			return;
		}
		if (a == c && b - d == 1 && fang(turn))
		{
			lose(c, d);
			exchange(1, extra);
			return;
		}
		if (a == c && d - b == 1 && fang(turn))
		{
			lose(c, d);
			exchange(1, extra);
			return;
		}
		out
	}

	if (mapp[a][b] == 2 + extra)
	{
		if (bounce == 0)
			out if (c - a == 1 && b - d == 1 && fang(turn))
			{
				lose(c, d);
				exchange(2, extra);
				return;
			}
		if (a - c == 1 && b - d == 1 && fang(turn))
		{
			lose(c, d);
			exchange(2, extra);
			return;
		}
		if (c - a == 1 && d - b == 1 && fang(turn))
		{
			lose(c, d);
			exchange(2, extra);
			return;
		}
		if (a - c == 1 && d - b == 1 && fang(turn))
		{
			lose(c, d);
			exchange(2, extra);
			return;
		}
		out
	}

	if (mapp[a][b] == 3 + extra)
	{
		if (bounce == 0)
			out if (c == a + 2 && d == b + 2 && fang(turn) && mapp[a + 1][b + 1] == 0)
			{
				lose(c, d);
				exchange(3, extra);
				return;
			}
		if (c == a + 2 && d == b - 2 && fang(turn) && mapp[a + 1][b - 1] == 0)
		{
			lose(c, d);
			exchange(3, extra);
			return;
		}
		if (c == a - 2 && d == b + 2 && fang(turn) && mapp[a - 1][b + 1] == 0)
		{
			lose(c, d);
			exchange(3, extra);
			return;
		}
		if (c == a - 2 && d == b - 2 && fang(turn) && mapp[a - 1][b - 1] == 0)
		{
			lose(c, d);
			exchange(3, extra);
			return;
		}
		out
	}

	if (mapp[a][b] == 4 + extra)
	{
		if (bounce == 0)
			out if (c - a == 2 && d - b == 1 && fang(turn) && mapp[a + 1][b] == 0)
			{
				lose(c, d);
				exchange(4, extra);
				return;
			}
		if (c - a == 1 && d - b == 2 && fang(turn) && mapp[a][b + 1] == 0)
		{
			lose(c, d);
			exchange(4, extra);
			return;
		}
		if (c - a == -1 && d - b == 2 && fang(turn) && mapp[a][b + 1] == 0)
		{
			lose(c, d);
			exchange(4, extra);
			return;
		}
		if (c - a == -2 && d - b == 1 && fang(turn) && mapp[a - 1][b] == 0)
		{
			lose(c, d);
			exchange(4, extra);
			return;
		}
		if (c - a == -2 && d - b == -1 && fang(turn) && mapp[a - 1][b] == 0)
		{
			lose(c, d);
			exchange(4, extra);
			return;
		}
		if (c - a == -1 && d - b == -2 && fang(turn) && mapp[a][b - 1] == 0)
		{
			lose(c, d);
			exchange(4, extra);
			return;
		}
		if (c - a == 1 && d - b == -2 && fang(turn) && mapp[a][b - 1] == 0)
		{
			lose(c, d);
			exchange(4, extra);
			return;
		}
		if (c - a == 2 && d - b == -1 && fang(turn) && mapp[a + 1][b] == 0)
		{
			lose(c, d);
			exchange(4, extra);
			return;
		}
		out
	}

	if (mapp[a][b] == 5 + extra)
	{
		if (bounce == 0)
			out if (a == c)
			{
				if (d > b)
				{
					for (register int i = b + 1; i < d; i++)
						if (mapp[a][i])
							out // 有障碍
								if (fang(turn))
							{
								lose(c, d);
								exchange(5, extra);
								return;
							} // 判断吃，更新
				}

				else if (d < b)
				{
					for (register int i = b - 1; i > d; i--)
						if (mapp[a][i])
							out if (fang(turn))
							{
								lose(c, d);
								exchange(5, extra);
								return;
							}
				}

				else
					out
			}

		else if (b == d)
		{
			if (c > a)
			{
				for (register int i = a + 1; i < c; i++)
					if (mapp[i][b])
						out if (fang(turn))
						{
							lose(c, d);
							exchange(5, extra);
							return;
						}
			}

			else if (c < a)
			{
				for (register int i = a - 1; i > c + 1; i--)
					if (mapp[i][b])
						out if (fang(turn))
						{
							lose(c, d);
							exchange(5, extra);
							return;
						}
			}

			else
				out
		}

		else
			out
	}

	if (mapp[a][b] == 6 + extra)
	{
		if (bounce == 0)
			out if (c - a == 2 && d - b == 3 && fang(turn) && mapp[a][b + 1] == 0 && mapp[a + 1][b + 2] == 0)
			{
				lose(c, d);
				exchange(6, extra);
				return;
			}
		if (c - a == 3 && d - b == 2 && fang(turn) && mapp[a + 1][b] == 0 && mapp[a + 2][b + 1] == 0)
		{
			lose(c, d);
			exchange(6, extra);
			return;
		}
		if (c - a == -2 && d - b == 3 && fang(turn) && mapp[a][b + 1] == 0 && mapp[a - 1][b + 2] == 0)
		{
			lose(c, d);
			exchange(6, extra);
			return;
		}
		if (c - a == -3 && d - b == 2 && fang(turn) && mapp[a - 1][b] == 0 && mapp[a - 2][b + 1] == 0)
		{
			lose(c, d);
			exchange(6, extra);
			return;
		}
		if (c - a == 2 && d - b == -3 && fang(turn) && mapp[a][b - 1] == 0 && mapp[a + 1][b - 2] == 0)
		{
			lose(c, d);
			exchange(6, extra);
			return;
		}
		if (c - a == 3 && d - b == -2 && fang(turn) && mapp[a + 1][b] == 0 && mapp[a + 2][b - 1] == 0)
		{
			lose(c, d);
			exchange(6, extra);
			return;
		}
		if (c - a == -2 && d - b == -3 && fang(turn) && mapp[a][b - 1] == 0 && mapp[a - 1][b - 2] == 0)
		{
			lose(c, d);
			exchange(6, extra);
			return;
		}
		if (c - a == -3 && d - b == -2 && fang(turn) && mapp[a - 1][b] == 0 && mapp[a - 2][b - 1] == 0)
		{
			lose(c, d);
			exchange(6, extra);
			return;
		}
		out
	}

	if (mapp[a][b] == 7 + extra)
	{
		if (bounce == 0)
			out if (c - a == 1 && b == d && fang(turn))
			{
				lose(c, d);
				exchange(7, extra);
				return;
			}
		if (a - c == 1 && b == d && fang(turn))
		{
			lose(c, d);
			exchange(7, extra);
			return;
		}
		if (a == c && b - d == 1 && fang(turn))
		{
			lose(c, d);
			exchange(7, extra);
			return;
		}
		if (a == c && d - b == 1 && fang(turn))
		{
			lose(c, d);
			exchange(7, extra);
			return;
		}
		if (c - a == 1 && b - d == 1 && fang(turn))
		{
			lose(c, d);
			exchange(7, extra);
			return;
		}
		if (a - c == 1 && b - d == 1 && fang(turn))
		{
			lose(c, d);
			exchange(7, extra);
			return;
		}
		if (c - a == 1 && d - b == 1 && fang(turn))
		{
			lose(c, d);
			exchange(7, extra);
			return;
		}
		if (a - c == 1 && d - b == 1 && fang(turn))
		{
			lose(c, d);
			exchange(7, extra);
			return;
		}
		out
	}

	out
}

inline void initmove() // 初始化 move()
{
	gai = 0;
	flagout = 0;
	extra = 0;
	capture = 0;
	jiang = 0;
}

inline void checkmate(int p, int q)
{
	if (mapp[p][q] > 10)
		checkturn = 1, checkextra = 10;
	else
		checkturn = 11, checkextra = 0;

	if (mapp[p][q] == 1 + checkextra)
	{
		if (mapp[p + 1][q] == checkturn && 0 <= p + 1 && p + 1 <= 9 && 0 <= q && q <= 8)
			checkok if (mapp[p - 1][q] == checkturn && 0 <= p - 1 && p - 1 <= 9 && 0 <= q && q <= 8) checkok if (mapp[p][q + 1] == checkturn && 0 <= p && p <= 9 && 0 <= q + 1 && q + 1 <= 8) checkok if (mapp[p][q - 1] == checkturn && 0 <= p && p <= 9 && 0 <= q - 1 && q - 1 <= 8) checkok
	}

	if (mapp[p][q] == 2 + checkextra)
	{
		if (mapp[p + 1][q + 1] == checkturn && 0 <= p + 1 && p + 1 <= 9 && 0 <= q + 1 && q + 1 <= 8)
			checkok if (mapp[p - 1][q + 1] == checkturn && 0 <= p - 1 && p - 1 <= 9 && 0 <= q + 1 && q + 1 <= 8) checkok if (mapp[p + 1][q - 1] == checkturn && 0 <= p + 1 && p + 1 <= 9 && 0 <= q - 1 && q - 1 <= 8) checkok if (mapp[p - 1][q - 1] == checkturn && 0 <= p - 1 && p - 1 <= 9 && 0 <= q - 1 && q - 1 <= 8) checkok
	}

	if (mapp[p][q] == 3 + checkextra)
	{
		if (mapp[p + 2][q + 2] == checkturn && mapp[p + 1][q + 1] == 0 && 0 <= p + 2 && p + 2 <= 9 && 0 <= q + 2 && q + 2 <= 8)
			checkok if (mapp[p - 2][q + 2] == checkturn && mapp[p - 1][q + 1] == 0 && 0 <= p - 2 && p - 2 <= 9 && 0 <= q + 2 && q + 2 <= 8) checkok if (mapp[p + 2][q - 2] == checkturn && mapp[p + 1][q - 1] == 0 && 0 <= p + 2 && p + 2 <= 9 && 0 <= q - 2 && q - 2 <= 8) checkok if (mapp[p - 2][q - 2] == checkturn && mapp[p - 1][q - 1] == 0 && 0 <= p - 2 && p - 2 <= 9 && 0 <= q - 2 && q - 2 <= 8) checkok
	}

	if (mapp[p][q] == 4 + checkextra)
	{
		if (mapp[p + 1][q + 2] == checkturn && mapp[p][q + 1] == 0 && 0 <= p + 1 && p + 1 <= 9 && 0 <= q + 2 && q + 2 <= 8)
			checkok if (mapp[p + 2][q + 1] == checkturn && mapp[p + 1][q] == 0 && 0 <= p + 2 && p + 2 <= 9 && 0 <= q + 1 && q + 1 <= 8) checkok if (mapp[p + 2][q - 1] == checkturn && mapp[p + 1][q] == 0 && 0 <= p + 2 && p + 2 <= 9 && 0 <= q - 1 && q - 1 <= 8) checkok if (mapp[p + 1][q - 2] == checkturn && mapp[p][q - 1] == 0 && 0 <= p + 1 && p + 1 <= 9 && 0 <= q - 2 && q - 2 <= 8) checkok if (mapp[p - 1][q - 2] == checkturn && mapp[p][q - 1] == 0 && 0 <= p - 1 && p - 1 <= 9 && 0 <= q - 2 && q - 2 <= 8) checkok if (mapp[p - 2][q - 1] == checkturn && mapp[p - 1][q] == 0 && 0 <= p - 2 && p - 2 <= 9 && 0 <= q - 1 && q - 1 <= 8) checkok if (mapp[p - 2][q + 1] == checkturn && mapp[p - 1][q] == 0 && 0 <= p - 2 && p - 2 <= 9 && 0 <= q + 1 && q + 1 <= 8) checkok if (mapp[p - 1][q + 2] == checkturn && mapp[p][q + 1] == 0 && 0 <= p - 1 && p - 1 <= 9 && 0 <= q + 2 && q + 2 <= 8) checkok
	}

	if (mapp[p][q] == 5 + checkextra)
	{
		for (register int i = p + 1; i <= 9; i++)
		{
			if (mapp[i][q] == checkturn)
				checkok if (mapp[i][q] != 0) return;
		}

		for (register int i = p - 1; i >= 0; i--)
		{
			if (mapp[i][q] == checkturn)
				checkok if (mapp[i][q] != 0) return;
		}

		for (register int i = q + 1; i <= 8; i++)
		{
			if (mapp[p][i] == checkturn)
				checkok if (mapp[p][i] != 0) return;
		}

		for (register int i = q - 1; i >= 0; i--)
		{
			if (mapp[p][i] == checkturn)
				checkok if (mapp[p][i] != 0) return;
		}
	}

	if (mapp[p][q] == 6 + checkextra)
	{
		if (mapp[p + 2][q + 3] == checkturn && mapp[p][q + 1] == 0 && mapp[p + 1][q + 2] == 0 && 0 <= p + 2 && p + 2 <= 9 && 0 <= q + 3 && q + 3 <= 8)
			checkok if (mapp[p + 3][q + 2] == checkturn && mapp[p + 1][q] == 0 && mapp[p + 2][q + 1] == 0 && 0 <= p + 3 && p + 3 <= 9 && 0 <= q + 2 && q + 2 <= 8) checkok if (mapp[p + 3][q - 2] == checkturn && mapp[p + 1][q] == 0 && mapp[p + 2][q - 1] == 0 && 0 <= p + 3 && p + 3 <= 9 && 0 <= q - 2 && q - 2 <= 8) checkok if (mapp[p + 2][q - 3] == checkturn && mapp[p][q - 1] == 0 && mapp[p + 1][q - 2] == 0 && 0 <= p + 2 && p + 2 <= 9 && 0 <= q - 3 && q - 3 <= 8) checkok if (mapp[p - 2][q - 3] == checkturn && mapp[p][q - 1] == 0 && mapp[p - 1][q - 2] == 0 && 0 <= p - 2 && p - 2 <= 9 && 0 <= q - 3 && q - 3 <= 8) checkok if (mapp[p - 3][q - 2] == checkturn && mapp[p - 1][q] == 0 && mapp[p - 2][q - 1] == 0 && 0 <= p - 3 && p - 3 <= 9 && 0 <= q - 2 && q - 2 <= 8) checkok if (mapp[p - 3][q + 2] == checkturn && mapp[p - 1][q] == 0 && mapp[p - 2][q + 1] == 0 && 0 <= p - 3 && p - 3 <= 9 && 0 <= q + 2 && q + 2 <= 8) checkok if (mapp[p - 2][q + 3] == checkturn && mapp[p][q + 1] == 0 && mapp[p - 1][q + 2] == 0 && 0 <= p - 2 && p - 2 <= 9 && 0 <= q + 3 && q + 3 <= 8) checkok
	}

	if (mapp[p][q] == 7 + checkextra)
	{
		if (mapp[p + 1][q] == checkturn && 0 <= p + 1 && p + 1 <= 9 && 0 <= q && q <= 8)
			checkok if (mapp[p - 1][q] == checkturn && 0 <= p - 1 && p - 1 <= 9 && 0 <= q && q <= 8) checkok if (mapp[p][q + 1] == checkturn && 0 <= p && p <= 9 && 0 <= q + 1 && q + 1 <= 8) checkok if (mapp[p][q - 1] == checkturn && 0 <= p && p <= 9 && 0 <= q - 1 && q - 1 <= 8) checkok if (mapp[p + 1][q + 1] == checkturn && 0 <= p + 1 && p + 1 <= 9 && 0 <= q + 1 && q + 1 <= 8) checkok if (mapp[p - 1][q + 1] == checkturn && 0 <= p - 1 && p - 1 <= 9 && 0 <= q + 1 && q + 1 <= 8) checkok if (mapp[p + 1][q - 1] == checkturn && 0 <= p + 1 && p + 1 <= 9 && 0 <= q - 1 && q - 1 <= 8) checkok if (mapp[p - 1][q - 1] == checkturn && 0 <= p - 1 && p - 1 <= 9 && 0 <= q - 1 && q - 1 <= 8) checkok
	}
}

inline void check() // 检查将军
{
	for (register int i = 0; i <= 9; i++)
	{
		for (register int j = 0; j <= 8; j++)
		{
			if (mapp[i][j] == 0)
				continue;

			checkmate(i, j);

			if (jiang)
				return;
		}
	}
}

inline void print() // 输出
{
	if (mapp[c][d] == 1)
		printf("red captain;");
	else if (mapp[c][d] == 2)
		printf("red guard;");
	else if (mapp[c][d] == 3)
		printf("red elephant;");
	else if (mapp[c][d] == 4)
		printf("red horse;");
	else if (mapp[c][d] == 5)
		printf("red car;");
	else if (mapp[c][d] == 6)
		printf("red duck;");
	else if (mapp[c][d] == 7)
		printf("red soldier;");
	else if (mapp[c][d] == 11)
		printf("blue captain;");
	else if (mapp[c][d] == 12)
		printf("blue guard;");
	else if (mapp[c][d] == 13)
		printf("blue elephant;");
	else if (mapp[c][d] == 14)
		printf("blue horse;");
	else if (mapp[c][d] == 15)
		printf("blue car;");
	else if (mapp[c][d] == 16)
		printf("blue duck;");
	else if (mapp[c][d] == 17)
		printf("blue soldier;");

	if (gai == 1)
		printf("red captain;");
	else if (gai == 2)
		printf("red guard;");
	else if (gai == 3)
		printf("red elephant;");
	else if (gai == 4)
		printf("red horse;");
	else if (gai == 5)
		printf("red car;");
	else if (gai == 6)
		printf("red duck;");
	else if (gai == 7)
		printf("red soldier;");
	else if (gai == 11)
		printf("blue captain;");
	else if (gai == 12)
		printf("blue guard;");
	else if (gai == 13)
		printf("blue elephant;");
	else if (gai == 14)
		printf("blue horse;");
	else if (gai == 15)
		printf("blue car;");
	else if (gai == 16)
		printf("blue duck;");
	else if (gai == 17)
		printf("blue soldier;");
	else
		printf("NA;");

	if (capture == 0 && jiang)
		printf("yes;");
	else
		printf("no;");

	if (capture)
		puts("yes");
	else
		puts("no");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("P5380.in", "r", stdin);
	freopen("P5380_TJ.out", "w", stdout);
#endif

	init();
	scanf("%d", &Q);

	for (register int i = 1; i <= Q; i++)
	{

		scanf("%d%d%d%d", &a, &b, &c, &d);

		if (capture)
		{
			puts("Invalid command");
			continue;
		}

		initmove();
		move();

		if (flagout)
			continue;
		check();

		print();

		if (turn == 0)
			turn = 1;
		else
			turn = 0;
	}

	return 0;
}
