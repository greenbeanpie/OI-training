#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#define LL long long
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

const string EOR = "Invalid command";

struct piece
{
	string name;
	string col;
	LL n, pn;
	LL dir[20][2];
	LL pd1[8][2];
	LL pd2[8][2];
};

struct point
{
	LL x, y;
};

const piece null = {"", "", 0, 0};
const piece pc[15] = {
	// 0:NULL   1~7:red   8~14:blue
	null,
	{"captain", "red", 4, 0, {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}},
	{"guard", "red", 4, 0, {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}},
	{"elephant", "red", 4, 1, {{2, 2}, {2, -2}, {-2, 2}, {-2, -2}}, {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}},
	{"horse", "red", 8, 1, {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}}, {{0, 1}, {0, -1}, {-0, 1}, {-0, -1}, {1, 0}, {1, -0}, {-1, 0}, {-1, -0}}},
	{"car", "red"},
	{"duck", "red", 8, 2, {{2, 3}, {2, -3}, {-2, 3}, {-2, -3}, {3, 2}, {3, -2}, {-3, 2}, {-3, -2}}, {{0, 1}, {0, -1}, {-0, 1}, {-0, -1}, {1, 0}, {1, -0}, {-1, 0}, {-1, -0}}, {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}}},
	{"soldier", "red", 8, 0, {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}},

	{"captain", "blue", 4, 0, {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}},
	{"guard", "blue", 4, 0, {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}},
	{"elephant", "blue", 4, 1, {{2, 2}, {2, -2}, {-2, 2}, {-2, -2}}, {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}},
	{"horse", "blue", 8, 1, {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}}, {{0, 1}, {0, -1}, {-0, 1}, {-0, -1}, {1, 0}, {1, -0}, {-1, 0}, {-1, -0}}},
	{"car", "blue"},
	{"duck", "blue", 8, 2, {{2, 3}, {2, -3}, {-2, 3}, {-2, -3}, {3, 2}, {3, -2}, {-3, 2}, {-3, -2}}, {{0, 1}, {0, -1}, {-0, 1}, {-0, -1}, {1, 0}, {1, -0}, {-1, 0}, {-1, -0}}, {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}}},
	{"soldier", "blue", 8, 0, {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}},
};

struct game
{
	LL chess[10][9] = {
		{12, 11, 10, 9, 8, 9, 10, 11, 12},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{13, 0, 0, 0, 0, 0, 0, 0, 13},
		{14, 0, 14, 0, 14, 0, 14, 0, 14},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{7, 0, 7, 0, 7, 0, 7, 0, 7},
		{6, 0, 0, 0, 0, 0, 0, 0, 6},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{5, 4, 3, 2, 1, 2, 3, 4, 5}};
	LL B = 0;
	bool ifover()
	{
		point redcap = find(1), blackcap = find(8);
		if (redcap.x + redcap.y == -2 || blackcap.x + blackcap.y == -2)
			return true;
		return false;
	}
	bool ifmove(LL x, point pos, point vec)
	{
		piece p = pc[x];
		point to = {pos.x + vec.x, pos.y + vec.y};
		piece p_to = pc[chess[to.x][to.y]];
		if (to.x < 0 || to.x > 9 || to.y < 0 || to.y > 8)
			return false; // 是否出界
		if (p_to.col == p.col)
			return false;	 // 不能吃己方子
		if (p.name == "car") // 车要特判
		{
			LL dx = (vec.x > 0 ? 1 : -1), dy = (vec.y > 0 ? 1 : -1);
			if (vec.x == 0)
				dx = 0;
			else if (vec.y == 0)
				dy = 0;
			else
				return false;
			for (LL i = 1; i < abs(vec.x + vec.y); i++)
				if (chess[pos.x + dx * i][pos.y + dy * i])
					return false;
		}
		else
		{
			LL d = -1;
			for (LL i = 0; i < p.n; i++)
				if (vec.x == p.dir[i][0] && vec.y == p.dir[i][1])
					d = i;
			if (d == -1)
				return false; // 移动方式是否存在
			if (p.pn > 0 && chess[pos.x + p.pd1[d][0]][pos.y + p.pd1[d][1]])
				return false; // 限制1
			if (p.pn > 1 && chess[pos.x + p.pd2[d][0]][pos.y + p.pd2[d][1]])
				return false; // 限制2
		}
		return true;
	}
	bool ifmove(point x, point y, bool pB)
	{
		if (ifover())
			return false;
		LL id = chess[x.x][x.y];
		if (!id)
			return false;
		if (pB && pc[id].col != (B == 0 ? "red" : "blue"))
			return false;
		if (!ifmove(id, x, (point){y.x - x.x, y.y - x.y}))
			return false;
		return true;
	}
	void move(point x, point y, LL &M, LL &O)
	{
		if (!ifmove(x, y, 1))
			return;
		M = chess[x.x][x.y];
		O = chess[y.x][y.y];
		chess[y.x][y.y] = M;
		chess[x.x][x.y] = 0;
		B ^= 1;
	}
	point find(LL id)
	{
		for (LL i = 0; i < 10; i++)
		{
			for (LL j = 0; j < 9; j++)
			{
				if (chess[i][j] == id)
					return (point){i, j};
			}
		}
		return (point){-1, -1};
	}
	bool ifkilling()
	{
		if (ifover())
			return false;
		point redcap = find(1), blackcap = find(8);
		for (LL i = 0; i < 10; i++)
		{
			for (LL j = 0; j < 9; j++)
			{
				LL id = chess[i][j];
				if (pc[id].col == "blue" && ifmove((point){i, j}, redcap, 0))
					return true;
				if (pc[id].col == "red" && ifmove((point){i, j}, blackcap, 0))
					return true;
			}
		}
		return false;
	}
} G;

void print(LL id)
{
	if (id)
		cout << pc[id].col << " " << pc[id].name << ";";
	else
		cout << "NA;";
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("P5380.in", "r", stdin);
	freopen("P5380_TJ.out", "w", stdout);
#endif
	LL Q;
	cin >> Q;
	for (LL i = 1; i <= Q; i++)
	{
		point u, v;
		cin >> u.x >> u.y >> v.x >> v.y;
		u.x = 9 - u.x;
		v.x = 9 - v.x;
		if (!G.ifmove(u, v, 1))
			cout << EOR << endl;
		else
		{
			LL M, O;
			G.move(u, v, M, O);
			print(M);
			print(O);
			cout << (G.ifkilling() ? "yes" : "no") << ";" << (G.ifover() ? "yes" : "no") << endl;
		}
	}
	return 0;
}
