#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define gc() (p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)

namespace FastIO
{
	static constexpr int SIZE = 1 << 21;
	char ibuf[SIZE], obuf[SIZE], *p1 = ibuf, *p2 = ibuf, *p3 = obuf;
	inline void read(char &c)
	{
		for (c = gc(); !std::isgraph(c); c = gc())
			;
	}
	inline void read(char *s)
	{
		char c = gc();
		for (; !std::isgraph(c); c = gc())
			;
		for (; std::isgraph(c); c = gc())
			*s++ = c;
		*s = 0;
	}
	inline void read(std::string &s)
	{
		s.clear();
		char c = gc();
		for (; !std::isgraph(c); c = gc())
			;
		for (; std::isgraph(c); c = gc())
			s.push_back(c);
	}
	inline void pc(char c)
	{
		if (p3 - obuf == SIZE)
			fwrite(obuf, 1, SIZE, stdout), p3 = obuf;
		*p3++ = c;
	}
	inline void write(char c) { pc(c); }
	inline void write(const char *s)
	{
		while (*s)
			pc(*s), ++s;
	}
	inline void write(std::string s)
	{
		for (const char c : s)
			pc(c);
	}
	template <typename _Tp>
	inline void read(_Tp &x)
	{
		x = 0;
		char c = gc();
		int f = 0;
		for (; !std::isdigit(c); c = gc())
			f |= c == '-';
		for (; std::isdigit(c); c = gc())
			x = (x << 1) + (x << 3) + (c ^ 48);
		return f ? x = ~x + 1 : 1, void();
	}
	template <typename _Tp>
	inline void write(_Tp x)
	{
		static int stk[40];
		int tp = 0;
		if (!x)
			return pc('0'), void();
		if (x < 0)
			pc('-'), x = ~x + 1;
		while (x)
			stk[++tp] = x % 10, x /= 10;
		while (tp)
			pc(stk[tp--] + '0');
	}
	template <typename _Tp>
	inline void writesp(_Tp x)
	{
		write(x);
		pc(' ');
	}
	template <typename _Tp>
	inline void writeln(_Tp x) { write(x), pc('\n'); }
	template <typename _Tp, typename... Args>
	inline void read(_Tp &x, Args &...args) { read(x), read(args...); }
	template <typename _Tp, typename... Args>
	inline void write(_Tp x, Args... args) { write(x), write(args...); }
	template <typename _Tp, typename... Args>
	inline void writesp(_Tp x, Args... args) { writesp(x), writesp(args...); }
	template <typename _Tp, typename... Args>
	inline void writeln(_Tp x, Args... args) { writeln(x), writeln(args...); }
	inline void flush() { fwrite(obuf, p3 - obuf, 1, stdout); }
}
void FileIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
// #define const constexpr

namespace P3580
{

	bool end;

	struct node
	{
		bool color; // red:0 blue:1
		int typ;	// 1:captain 2:guard 3:elephant 4:horse 5:car 6:duck 7:soldier
		node()
		{
			color = -1, typ = -1;
		}
		node(bool a, int b)
		{
			color = a, typ = b;
		}
	};
	random_device rd;
	sfmt19937_64 rand(rd());
	int k1 = rand(), k2 = rand();
	struct pt
	{
		int x, y;
		pt(int a, int b) { x = a, y = b; }
	};

	struct myhash
	{
		size_t operator()(const pt &a) const noexcept
		{
			return a.x * k1 + a.y * k2;
		}
		size_t operator()(const pair<int, int> &a) const noexcept
		{
			return a.first * k1 + a.second * k2;
		}
	};

	bool operator==(pt a, pt b)
	{
		return a.x == b.x && a.y == b.y;
	}
	bool operator!=(pt a, pt b)
	{
		return !(a == b);
	}
	unordered_map<pt, node, myhash> mp;

	unordered_map<int, string> name, color;

	void init() // 初始化棋盘
	{
		mp[{0, 0}] = mp[{8, 0}] = {0, 5};
		mp[{1, 0}] = mp[{7, 0}] = {0, 4};
		mp[{2, 0}] = mp[{6, 0}] = {0, 3};
		mp[{3, 0}] = mp[{5, 0}] = {0, 2};
		mp[{4, 0}] = {0, 1};
		mp[{0, 2}] = mp[{8, 2}] = {0, 6};
		mp[{0, 3}] = mp[{2, 3}] = mp[{4, 3}] = mp[{6, 3}] = mp[{8, 3}] = {0, 7};
		mp[{0, 6}] = mp[{2, 6}] = mp[{4, 6}] = mp[{6, 6}] = mp[{8, 6}] = {1, 7};
		mp[{0, 7}] = mp[{8, 7}] = {1, 6};
		mp[{0, 9}] = mp[{8, 9}] = {1, 5};
		mp[{1, 9}] = mp[{7, 9}] = {1, 4};
		mp[{2, 9}] = mp[{6, 9}] = {1, 3};
		mp[{3, 9}] = mp[{5, 9}] = {1, 2};
		mp[{4, 9}] = {1, 1};
		color[0] = "red";
		color[1] = "blue";
		name[-1] = name[0] = "NA";
		name[1] = "captain";
		name[2] = "guard";
		name[3] = "elephant";
		name[4] = "horse";
		name[5] = "car";
		name[6] = "duck";
		name[7] = "soldier";
	}

	node find(pt pos)
	{
		if (mp.find(pos) == mp.end())
		{
			return node();
		}
		return mp[pos];
	}

	node find(int x, int y)
	{
		return find(pt(x, y));
	}

	bool check(pt pos)
	{ // 检查是否出现将军情况
		for (int i = -1; i <= 1; i++)
		{
			if (i == 0)
			{
				for (int j = -1; j <= 1; j += 2)
				{
					auto res = find((pt){pos.x + i, pos.y + j});
					if ((res.typ == 1 || res.typ == 7) && res.color != mp[pos].color)
					{
						return 1;
					}
				}
				auto res = find((pt){pos.x + i, pos.y});
				if ((res.typ == 1 || res.typ == 7) && res.color != mp[pos].color)
				{
					return 1;
				}
			}
		} // 判断王、兵
		for (int i = -1; i <= 1; i += 2)
		{
			for (int j = -1; j <= 1; j += 2)
			{
				auto res = find((pt){pos.x + i, pos.y + j});
				if ((res.typ == 7 || res.typ == 2) && res.color != mp[pos].color)
				{
					return 1;
				}
			}
		} // 判断士、兵

		for (int i = pos.x - 1; i >= 0; i--)
		{
			auto res = find((pt){i, pos.y});
			if (res.typ == 5 && res.color != mp[pos].color)
			{
				return 1;
			}
			else if (res.typ != -1)
			{
				break;
			}
		}
		for (int i = pos.y - 1; i >= 0; i--)
		{
			auto res = find((pt){pos.x, i});
			if (res.typ == 5 && res.color != mp[pos].color)
			{
				return 1;
			}
			else if (res.typ != -1)
			{
				break;
			}
		}
		for (int i = pos.x + 1; i <= 8; i++)
		{
			auto res = find((pt){i, pos.y});
			if (res.typ == 5 && res.color != mp[pos].color)
			{
				return 1;
			}
			else if (res.typ != -1)
			{
				break;
			}
		}
		for (int i = pos.y + 1; i <= 9; i++)
		{
			auto res = find((pt){pos.x, i});
			if (res.typ == 5 && res.color != mp[pos].color)
			{
				return 1;
			}
			else if (res.typ != -1)
			{
				break;
			}
		} // 判断车
		for (int i = -1; i <= 1; i += 2)
		{
			for (int j = -1; j <= 1; j += 2)
			{
				auto res1 = find((pt){pos.x - i, pos.y - j}), res2 = find((pt){pos.x - 2 * i, pos.y - 2 * j}), res = find((pt){pos.x - 3 * i, pos.y - 2 * j});
				if (res1.typ == -1 && res2.typ == -1 && res.typ == 6 && res.color != mp[pos].color)
				{
					return 1;
				}
			}
		}
		for (int i = -1; i <= 1; i += 2)
		{
			for (int j = -1; j <= 1; j += 2)
			{
				auto res1 = find((pt){pos.x - i, pos.y - j}), res2 = find((pt){pos.x - 2 * i, pos.y - 2 * j}), res = find((pt){pos.x - 2 * i, pos.y - 3 * j});
				if (res1.typ == -1 && res2.typ == -1 && res.typ == 6 && res.color != mp[pos].color)
				{
					return 1;
				}
			}
		} // 判断鸭
		for (int i = -1; i <= 1; i += 2)
		{
			for (int j = -1; j <= 1; j += 2)
			{
				auto res1 = find((pt){pos.x - i, pos.y - j}), res = find((pt){pos.x - i, pos.y - 2 * j});
				if (res1.typ == -1 && res.typ == 4 && res.color != mp[pos].color)
				{
					return 1;
				}
			}
		}
		for (int i = -1; i <= 1; i += 2)
		{
			for (int j = -1; j <= 1; j += 2)
			{
				auto res1 = find((pt){pos.x - i, pos.y - j}), res = find((pt){pos.x - 2 * i, pos.y - j});
				if (res1.typ == -1 && res.typ == 4 && res.color != mp[pos].color)
				{
					return 1;
				}
			}
		} // 判断马
		for (int i = -1; i <= 1; i += 2)
		{
			for (int j = -1; j <= 1; j += 2)
			{
				auto res1 = find((pt){pos.x - i, pos.y - j}), res = find((pt){pos.x - 2 * i, pos.y - 2 * j});
				if (res1.typ == -1 && res.typ == 3 && res.color != mp[pos].color)
				{
					return 1;
				}
			}
		} // 判断象
		return 0;
	}

	struct ans
	{
		node chess, moveout;
		bool valid, warning, end;
		ans()
		{
			chess = moveout = node();
			valid = 1;
			warning = end = 0;
		}
	};

	ans move(pt from, pt to, bool last)
	{
		ans res;
		if (!(find(from).color ^ last))
		{
			res.valid = 0;
			return res;
		}
		if (mp.find(from) == mp.end() || end || (find(to).typ != -1 && find(to).color == mp[from].color))
		{
			res.valid = 0;
			return res;
		}
		auto chess = mp[from];
		res.chess = chess;
		int xmove, ymove;
		switch (chess.typ)
		{
		case 1:
			if (abs(to.x - from.x) + abs(to.y - from.y) != 1)
			{
				res.valid = 0;
				return res;
			}
			res.warning = check(to);
			break;
		case 2:
			if (abs(to.x - from.x) != 1 && abs(to.y - from.y) != 1)
			{
				res.valid = 0;
				return res;
			}
			for (int i = -1; i <= 1; i += 2)
			{
				for (int j = -1; j <= 1; j += 2)
				{
					if (find((pt){to.x + i, to.y + j}).typ == 1)
					{
						res.warning = 1;
						break;
					}
				}
			}
			break;
		case 3:
			xmove = (to.x - from.x) / 2, ymove = (to.y - from.y) / 2;
			if (find((pt){from.x + xmove, from.y + ymove}).typ != -1 || (abs(to.x - from.x) != 2 || abs(to.y - from.y) != 2))
			{
				res.valid = 0;
				return res;
			}
			for (int i = -1; i <= 1; i += 2)
			{
				for (int j = -1; j <= 1; j += 2)
				{
					if (find((pt){to.x + i, to.y + j}).typ == -1 && find((pt){to.x + 2 * i, to.y + 2 * j}).typ == 1)
					{
						res.warning = 1;
						break;
					}
				}
			}
			break;
		case 4:
			xmove = to.x - from.x, ymove = to.y - from.y;
			if (abs(xmove) > abs(ymove))
			{
				xmove /= abs(xmove), ymove /= abs(ymove);
				if (find((pt){from.x + xmove, from.y}).typ != -1)
				{
					res.valid = 0;
					return res;
				}
			}
			else
			{
				xmove /= abs(xmove), ymove /= abs(ymove);
				if (find((pt){from.x, from.y + ymove}).typ != -1)
				{
					res.valid = 0;
					return res;
				}
			}
			for (int i = -1; i <= 1; i += 2)
			{
				for (int j = -1; j <= 1; j += 2)
				{
					auto res1 = find((pt){to.x, to.y + j}), res2 = find((pt){to.x + i, to.y + 2 * j});
					if (res1.typ == -1 && res2.typ == 4)
					{
						res.warning = 1;
						break;
					}
				}
			}
			for (int i = -1; i <= 1; i += 2)
			{
				for (int j = -1; j <= 1; j += 2)
				{
					auto res1 = find((pt){to.x + i, to.y}), res2 = find((pt){to.x + 2 * i, to.y + j});
					if (res1.typ == -1 && res2.typ == 4)
					{
						res.warning = 1;
						break;
					}
				}
			}
			break;
		case 5:
			if (from != to && (from.x == to.x || from.y == to.y))
			{
				if (from.x != to.x)
				{
					for (int i = min(from.x, to.x) + 1; i <= max(from.x, to.x) - 1; i++)
					{
						if (find((pt){i, from.y}).typ != -1)
						{
							res.valid = 0;
							break;
						}
					}
				}
				else
				{
					for (int i = min(from.y, to.y) + 1; i <= max(from.y, to.y) - 1; i++)
					{
						if (find((pt){from.x, i}).typ != -1)
						{
							res.valid = 0;
							break;
						}
					}
				}
				if (res.valid)
				{
					for (int i = to.x - 1; i >= 0; i--)
					{
						auto res1 = find((pt){i, to.y});
						if (res1.typ == 1)
						{
							res.warning = 1;
						}
						else if (res1.typ != -1)
						{
							break;
						}
					}
					for (int i = to.y - 1; i >= 0; i--)
					{
						auto res1 = find((pt){to.x, i});
						if (res1.typ == 1)
						{
							res.warning = 1;
						}
						else if (res1.typ != -1)
						{
							break;
						}
					}
					for (int i = to.x + 1; i <= 8; i++)
					{
						auto res1 = find((pt){i, to.y});
						if (res1.typ == 1)
						{
							res.warning = 1;
						}
						else if (res1.typ != -1)
						{
							break;
						}
					}
					for (int i = to.y + 1; i <= 9; i++)
					{
						auto res1 = find((pt){i, to.y});
						if (res1.typ == 1)
						{
							res.warning = 1;
						}
						else if (res1.typ != -1)
						{
							break;
						}
					}
				}
			}
			else
			{
				res.valid = 0;
				break;
			}
			break;
		case 6:
			xmove = to.x - from.x, ymove = to.y - from.y;
			if (abs(xmove) > abs(ymove))
			{
				xmove /= abs(xmove), ymove /= abs(ymove);
				if (find((pt){from.x + xmove * 2, from.y + ymove}).typ == -1 && find((pt){from.x + xmove, from.y}).typ == -1)
				{
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							if (find(pt(to.x + i, to.y)).typ == -1 && find(pt(to.x + 2 * i, to.y + j)).typ == -1 && find(pt(to.x + 3 * i, to.y + 2 * j)).typ == 1)
							{
								res.warning = 1;
								break;
							}
							if (find(pt(to.x, to.y+j)).typ == -1 && find(pt(to.x + i, to.y + 2 * j)).typ == -1 && find(pt(to.x + 2 * i, to.y + 3 * j)).typ == 1)
							{
								res.warning = 1;
								break;
							}
						}
					}
				}
				else
				{
					res.valid = 0;
					break;
				}
			}
			else
			{
				xmove /= abs(xmove), ymove /= abs(ymove);
				if (find((pt){from.x + xmove, from.y + ymove*2}).typ == -1 && find((pt){from.x , from.y+ymove}).typ == -1)
				{
					for (int i = -1; i <= 1; i++)
					{
						for (int j = -1; j <= 1; j++)
						{
							if (find(pt(to.x , to.y+j)).typ == -1 && find(pt(to.x +  i, to.y + 2*j)).typ == -1 && find(pt(to.x + 2 * i, to.y + 3 * j)).typ == 1)
							{
								res.warning = 1;
								break;
							}
							if (find(pt(to.x, to.y + j)).typ == -1 && find(pt(to.x + i, to.y + 2 * j)).typ == -1 && find(pt(to.x + 2 * i, to.y + 3 * j)).typ == 1)
							{
								res.warning = 1;
								break;
							}
						}
					}
				}
				else
				{
					res.valid = 0;
					break;
				}
			}
			break;
		case 7:
			if (abs(to.x - from.x) < 2 && abs(to.y - from.y) < 2 && abs(to.x - from.x) + abs(to.y - from.y) <= 2)
			{
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -1; j <= 1; j++)
					{
						if (j || i)
						{
							if (find(pt(to.x + i, to.y + j)).typ == 1)
							{
								res.warning = 1;
								break;
							}
						}
					}
				}
			}
			else
			{
				res.valid = 0;
			}
		}
		mp.erase(from);
		auto temp = find(to.x, to.y);
		if (temp.typ != -1)
		{
			res.moveout = find(to.x, to.y);
		}
		if (temp.typ == 1)
		{
			res.end = end = 1;
		}
		return res;
	}

	int main()
	{
		init();
		int Q;
		FastIO::read(Q);
		int last = 1;
		for (int i = 1; i <= Q; i++)
		{
			int xs, xt, ys, yt;
			FastIO::read(ys, xs, yt, xt);
			if (end)
			{
				FastIO::writeln("Invalid command");
			}
			else
			{
				auto res = move(pt(xs, ys), pt(xt, yt), last);
				if (!res.valid)
				{
					FastIO::writeln("Invalid command");
				}
				else
				{
					FastIO::write(color[res.chess.color], " ", name[res.chess.typ], ";");
					if (res.moveout.typ != -1)
					{
						FastIO::write(color[res.moveout.color], " ", name[res.moveout.typ], ";");
					}
					else
					{
						FastIO::write(name[res.moveout.typ], ";");
					}
					FastIO::write((res.warning ? "Yes" : "No"), ";", (res.end ? "Yes" : "No"));
					FastIO::pc('\n');
					last ^= 1;
				}
			}
		}
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	FileIO("P5380");
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	P3580::main();
	FastIO::flush();
	return 0;
}
