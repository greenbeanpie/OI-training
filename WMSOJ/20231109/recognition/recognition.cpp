#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
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
#define const constexpr

namespace recognition
{

	char c[505][505];

	cc_hash_table<string, string> ht;
	int main()
	{
		ht["......##......."
		   ".......##......"
		   "###############"
		   "..............."
		   "..###########.."
		   "..#.........#.."
		   "..#.........#.."
		   "..#.........#.."
		   "..###########.."
		   ".......#......."
		   "...#...#...#..."
		   "..##...#...##.."
		   "..#....#....##."
		   ".#.....#.....#."
		   "#...####.....##"] = "BEA9";

		ht[".#.......#....."
		   "..##.#########."
		   "...#.....#...#."
		   ".........#...#."
		   "#...###########"
		   "##.......#...#."
		   ".##......#...#."
		   "..#..#########."
		   ".........#....."
		   "...#.#########."
		   "..#......#....."
		   "..#......#....."
		   ".##.###########"
		   ".#.......#....."
		   "##.......#....."] = "BDF2";

		ht[".....#..##..##."
		   "######..####..#"
		   "....##..#######"
		   "####.#........."
		   "..###########.."
		   "..#....#....#.."
		   "..###########.."
		   "..#....#....#.."
		   "..###########.."
		   "....#.....#...."
		   ".#############."
		   "....#.....#...."
		   "###############"
		   "...###...####.."
		   "###..........##"] = "BCBD";

		ht[".#############."
		   ".....#...#....."
		   "..#..#...#..#.."
		   "..##.#...#..#.."
		   "...#.#...#.#..."
		   ".....#...#....."
		   "###############"
		   "..............."
		   "..###########.."
		   "..#.........#.."
		   "..#.........#.."
		   "..###########.."
		   "..#.........#.."
		   "..#.........#.."
		   "..###########.."] = "BDFA";

		ht["....#.....#...."
		   "###############"
		   "....#.....#...."
		   ".#############."
		   ".#...........#."
		   ".#.#########.#."
		   "..............."
		   ".#############."
		   "....###....#..."
		   ".###..##..###.."
		   "#...##.###....."
		   "#.##..###.#...."
		   ".#...##.#..#..."
		   "..####..#...##."
		   "##....##.....##"] = "C3C9";

		ht["##............."
		   ".##..##########"
		   "..#.........##."
		   "...#.......##.."
		   "..........##..."
		   ".........##...."
		   "###......##...."
		   "..#......##...."
		   "..#......##...."
		   "..#......##...."
		   "..#......##...."
		   "..#......##...."
		   ".###...###....."
		   "##.##........##"
		   "#....######## #."] = "C1C9";

		ht[".......#......."
		   ".......#......."
		   "###############"
		   ".......#......."
		   ".......#......."
		   ".......#......."
		   ".#############."
		   "..............."
		   "..............."
		   "..###########.."
		   "..#.........#.."
		   "..#.........#.."
		   "..#.........#.."
		   "..#.........#.."
		   "..###########.."] = "BCAA";

		ht["..###########.."
		   "..#....#....#.."
		   "..#.#..#..#.#.."
		   "..#..#.#.#..#.."
		   "..#.#..#.#..#.."
		   "..###########.."
		   ".......#......."
		   ".#############."
		   ".......#......."
		   ".......#......."
		   "###############"
		   "..............."
		   "..#..#..##..##."
		   ".#...#...#...#."
		   "##...#...#....#"] = "BADA";

		ht[".#......##...."
		   "..##.....##..."
		   "...#......#..."
		   "......########"
		   "......#......#"
		   "##....#......#"
		   "..##..#......#"
		   "......########"
		   "......#......#"
		   "...#.##......."
		   "..##.##......."
		   "..#..#........"
		   ".##..#........"
		   ".#..##........"
		   "##.##........."] = "BBA6";

		ht["....#.....#...."
		   "###############"
		   "....#.....#...."
		   "....#.....#...."
		   "......#........"
		   "......#........"
		   ".###########..."
		   "......#....#..."
		   "..#...#....##.."
		   "..##.##....#.#."
		   ".##..#.....#.##"
		   "##..##.....#..#"
		   "...##.....##..."
		   "..##...#..##..."
		   "##......###...."] = "CBD5";

		ht["##....#......##"
		   "..##..#..####.."
		   "...#..#..##...."
		   "....#######...."
		   "#.....#..##...."
		   "##....#..######"
		   "..#...#..##.##."
		   "......#####.##."
		   "...#####.##.##."
		   "..#.#.#..#..##."
		   "..#...#..#..##."
		   ".##...#..#..##."
		   ".#....#..#..##."
		   "##....#.#...##."
		   "#...###.#...##."] = "D5E3";

		ht["..##.....##...."
		   "..#.......#...."
		   "..#...#########"
		   "#####.#.......#"
		   "##..#.#.......#"
		   "##..#..#######."
		   "##..#.........."
		   "#####.........."
		   "##..#.#########"
		   "##..#...##.#..."
		   "##..#...#..#..."
		   "#####...#..#..."
		   "##.....##..#..#"
		   "##....##...#..#"
		   ".....#.....####"] = "CDEE";

		ht["#...#########"
		   ".#..........#"
		   "..#.........#"
		   "......#.....#"
		   "#.....#.....#"
		   "#.#########.#"
		   "#.##..#..##.#"
		   "#.##..#..##.#"
		   "#.##..#..##.#"
		   "#.#########.#"
		   "#.....#..#..#"
		   "#.....#..#..#"
		   "#.....#####.#"
		   "#.#####...#.#"
		   "#..........##"] = "C3F6";

		ht["..##.....#....."
		   "#######.######."
		   ".#...#.###..#.."
		   ".#...#....##..."
		   "##########..###"
		   ".........#####."
		   ".######....#..."
		   ".#....#########"
		   ".######........"
		   ".#....#.######."
		   ".######.#....#."
		   "...#....#..#.#."
		   "#######.#.#..#."
		   "...#.....#####."
		   "...#...##.....#"] = "B8D3";

		ht["....##........."
		   "...#######....."
		   "..##....##....."
		   ".############.."
		   "#.#....#....#.."
		   "..###########.."
		   "..#....#....#.."
		   "###############"
		   "..............."
		   "..###########.."
		   "..##.......##.."
		   "..###########.."
		   "..##.......##.."
		   "..##.......##.."
		   "..###########.."] = "C2B3";

		ht["######..#......"
		   "....#..######.."
		   ".#.#...#...#..."
		   "####.##########"
		   "..##..#...#..##"
		   "...#..#...#..##"
		   "###############"
		   "..#.#...##....#"
		   "..#.####.##.##."
		   "..#.#.#..####.."
		   "..#....##.#.#.."
		   "..#..##..#.#.#."
		   "..#....##..#.##"
		   "..#..##...#...#"
		   "###.....###...."] = "D4A5";

		ht["####.####.#####"
		   "#..#.#..#.#..##"
		   "#..#.#..#.#..#."
		   "#..#.#..#.#..#."
		   "####.####.#.#.."
		   "..........#.#.."
		   ".#######..#.##."
		   "..........#..#."
		   "#########.#...#"
		   "..#.......#...#"
		   ".#######..#...#"
		   ".......#..#####"
		   ".......#..#...."
		   "......##..#...."
		   "...####...#...."] = "B6F5";

		ht["##....#..######"
		   ".##...#..##..##"
		   "...#..#..##..##"
		   "......#..##..##"
		   "#...#######..##"
		   "##....#..######"
		   ".##..##..##..##"
		   ".....###.##..##"
		   ".....######..##"
		   "..#.#.#.#######"
		   "..#.#.#..##..##"
		   ".#.#..#..##..##"
		   ".#.#..#..##..##"
		   "##....#..######"
		   "#.....#..##..##"] = "CFE6";

		ht["......##......."
		   "..###########.."
		   "..#.#..#..#.#.."
		   "..#..#.#.#..#.."
		   "..###########.."
		   "..#..###.#..#.."
		   "..###..#..#.#.."
		   "..###########.."
		   "..............."
		   "###############"
		   "...#..........."
		   "..###########.."
		   "............#.."
		   "...........##.."
		   "........####..."] = "D4C1";

		ht["...#.......#...."
		   "...#.......#...."
		   "...#...########."
		   ".#####.....#...."
		   "...#.......#...."
		   "...##......#...."
		   "..###.##########"
		   "..##.#.........."
		   "..##.#.....#...."
		   ".#.#.......#...."
		   "##.#...#########"
		   ".#.#.......#...."
		   "...#.......#...."
		   "...#.......#...."
		   "...#..##########"] = "B9F0";

		ht[".........##...."
		   "#####.....#...."
		   "..#...#########"
		   "..#............"
		   "..#....#######."
		   "..#....#.....#."
		   "#####..#.....#."
		   "..#....#.....#."
		   "..#....#######."
		   "..#.......#...."
		   "..#....#..#.##."
		   "..###.##..#..#."
		   "###...#...#..##"
		   ".....#.#..#...#"
		   "........###...."] = "C7ED";

		ht["##.......##...."
		   ".###....###...."
		   "...#...##.##..."
		   ".....##.....###"
		   "#..##.#######.#"
		   "##............."
		   "..#..#####.#.#."
		   ".....#..##.#.#."
		   ".....#####.#.#."
		   "..#..#..##.#.#."
		   "..#..#..##.#.#."
		   ".##..#####.#.#."
		   ".#...#..##...#."
		   "##...#..##...#."
		   "#....#.##..###."] = "D3E5";

		ht["..#..........#"
		   "..#....#.....#"
		   "..#....#.....#"
		   "..#....#.....#"
		   "..#....#.....#"
		   "..#....#.....#"
		   "..#....#.....#"
		   "..#....#.....#"
		   "..#....#.....#"
		   "..#....#.....#"
		   ".##....#.....#"
		   ".#.....#.....#"
		   ".#.....#.....#"
		   "##.....#.....#"
		   "#............#"] = "B4A8";

		ht[".......#......."
		   "..###########.."
		   "..#....#....#.."
		   "..###########.."
		   ".......#......."
		   "###############"
		   "..............."
		   "..###########.."
		   "..##.......##.."
		   "..##...#...##.."
		   "..##...#...##.."
		   "..##..##...##.."
		   ".....##.###...."
		   "...###.....####"
		   "###..........#."] = "B9F3";

		ht["..###########.."
		   "..............."
		   "..............."
		   "..............."
		   "..............."
		   "###############"
		   ".....##........"
		   ".....#........."
		   "....##....#...."
		   "....#.....##..."
		   "...##......##.."
		   "...#........#.."
		   "..##...#######."
		   ".#######.....##"] = "D4C6";

		ht["....#.....#...."
		   "###############"
		   "....#.....#.#.."
		   "..........#..#."
		   "#..############"
		   "#..#......#...."
		   "#..#.######..#."
		   ".###.#.#..##.#."
		   "...#.#####.###."
		   "####.#...#.##.."
		   ".#.#.#####.##.."
		   ".#.#.#.#...#..."
		   ".#.#.########.#"
		   "#.#..#...##.#.#"
		   "#.#.....##...##"] = "B2D8";

		ht["#####.....#...."
		   "#...#.....#...."
		   "#..#..#########"
		   "#..#......#...."
		   "#.#....#..#..#."
		   "#.##...#..#.##."
		   "#..#...#..#.#.."
		   "#...#..####.#.."
		   "#...#.#########"
		   "#...#....##...."
		   "#.##.....###..."
		   "#.......##.#..."
		   "#......##...#.."
		   "#.....##....##."
		   "#...##........#"] = "C9C2";

		ht["...#.......#..."
		   "...#.......#..."
		   "...#.......#..."
		   "###############"
		   "...#.......#..."
		   "...#.......#..."
		   "...#.......#..."
		   "...#.......#..."
		   "...#########..."
		   "...#.......#..."
		   "...#.......#..."
		   "...#.......#..."
		   "...#.......#..."
		   "...#########..."
		   "...#.......#..."] = "B8CA";

		ht[".......#......."
		   ".#############."
		   ".......#......."
		   "..###########.."
		   ".......#......."
		   "###############"
		   "..............."
		   "..###########.."
		   "..##.......##.."
		   "..###########.."
		   "..##.......##.."
		   "..###########.."
		   "..##.......##.."
		   "..##.......##.."
		   "..##.....###..."] = "C7E0";

		ht["......##......."
		   ".......##......"
		   ".#############."
		   ".#...........#."
		   ".#...........#."
		   "..............."
		   "###############"
		   ".......#......."
		   ".......#......."
		   ".......#......."
		   ".......#......."
		   ".......#......."
		   ".......#......."
		   ".......#......."
		   "....####......."] = "C4FE";

		ht["...#........###"
		   "#############.."
		   ".#...##.##....."
		   "..#..#..##....."
		   "..#..#..##....."
		   "##########....."
		   "...#....#######"
		   "...#....##..#.."
		   "##########..#.."
		   "...#....##..#.."
		   ".#.#.##.#...#.."
		   ".#.#..#.#...#.."
		   "#..#..#.#...#.."
		   "...#...##...#.."
		   "..##...#....#.."] = "D0C2";

		ht["..#####."
		   ".######."
		   "##....##"
		   "##....##"
		   "##.....#"
		   "##.....#"
		   "##.....#"
		   "##.....#"
		   "##.....#"
		   "##.....#"
		   "##.....#"
		   "##.....#"
		   "##.....#"
		   "##....##"
		   "##....##"
		   ".######."
		   "..####.."] = "0";

		ht["##"
		   "##"
		   "##"
		   "##"
		   "##"
		   "##"
		   "##"
		   "##"
		   "##"
		   "##"
		   "##"
		   "##"
		   "##"
		   "##"
		   "##"
		   "##"
		   "##"] = "1";

		ht["..#####.."
		   ".#######."
		   "##....##."
		   ".......##"
		   "......##."
		   "......##."
		   "......##."
		   ".....##.."
		   "....###.."
		   "...###..."
		   "...##...."
		   "..###...."
		   ".###....."
		   ".##......"
		   "###......"
		   "########."
		   "########."] = "2";

		ht["########"
		   "########"
		   ".....###"
		   "....###."
		   "...###.."
		   "..###..."
		   "..#####."
		   "..######"
		   "......##"
		   "......##"
		   "......##"
		   "......##"
		   "##....##"
		   "##....##"
		   "###...##"
		   ".######."
		   "..####.."] = "3";

		ht[".....##.."
		   "....###.."
		   "....###.."
		   "...####.."
		   "...####.."
		   "...####.."
		   "..#####.."
		   "..##.##.."
		   ".###.##.."
		   ".##..##.."
		   ".##..##.."
		   "##...##.."
		   "#########"
		   "#########"
		   ".....##.."
		   ".....##.."
		   ".....##.."] = "4";

		ht["########."
		   "########."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "#######.."
		   "########."
		   "......###"
		   ".......##"
		   ".......##"
		   ".......##"
		   ".......##"
		   "##.....##"
		   ".##...###"
		   ".#######."
		   "..#####.."] = "5";

		ht[".....#..."
		   "....##..."
		   "...##...."
		   "..###...."
		   "..##....."
		   ".##......"
		   ".##......"
		   ".#####..."
		   "#######.."
		   "###...##."
		   "##....##."
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "###...##."
		   ".#######."
		   "..####..."] = "6";

		ht["#########"
		   "#########"
		   ".......#."
		   "......##."
		   "......##."
		   ".....##.."
		   ".....##.."
		   ".....#..."
		   "....##..."
		   "....##..."
		   "....##..."
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."] = "7";

		ht["..#####.."
		   ".##...##."
		   "##.....#."
		   "##.....#."
		   "##.....#."
		   "##....##."
		   ".##..###."
		   "..#####.."
		   ".#######."
		   "##....##."
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "###..###."
		   ".######.."
		   "...###..."] = "8";

		ht[".######.."
		   ".##..###."
		   "##....##."
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##....##."
		   ".#######."
		   "..######."
		   ".....###."
		   ".....##.."
		   "....###.."
		   "....##..."
		   "...##...."
		   "..###...."
		   ".###....."] = "9";

		ht["...##...."
		   "...###..."
		   "...###..."
		   "..####..."
		   "..####..."
		   "..##.#..."
		   "..##.##.."
		   "..##.##.."
		   ".###.##.."
		   ".##..##.."
		   ".##...#.."
		   ".##...##."
		   ".#######."
		   "########."
		   "##....##."
		   "##....##."
		   "##.....##"] = "A";

		ht["#######."
		   "##....##"
		   "##.....#"
		   "##.....#"
		   "##.....#"
		   "##....##"
		   "########"
		   "#######."
		   "##...###"
		   "##....##"
		   "##.....#"
		   "##.....#"
		   "##.....#"
		   "##....##"
		   "##....##"
		   "#######."
		   "######.."] = "B";
		ht["..#####.."
		   ".##..###."
		   "##.....##"
		   "##.....##"
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##.....##"
		   "##.....##"
		   "###...##."
		   ".######.."
		   "...###..."] = "C";

		ht["#######.."
		   "#....###."
		   "#......#."
		   "#......##"
		   "#......##"
		   "#......##"
		   "#......##"
		   "#......##"
		   "#......##"
		   "#......##"
		   "#......##"
		   "#......##"
		   "#......##"
		   "#......#."
		   "#.....##."
		   "#######.."
		   "######..."] = "D";

		ht["########"
		   "##......"
		   "##......"
		   "##......"
		   "##......"
		   "##......"
		   "##......"
		   "#######."
		   "##......"
		   "##......"
		   "##......"
		   "##......"
		   "##......"
		   "##......"
		   "##......"
		   "########"
		   "########"] = "E";

		ht["#######"
		   "##....."
		   "##....."
		   "##....."
		   "##....."
		   "##....."
		   "##....."
		   "######."
		   "##....."
		   "##....."
		   "##....."
		   "##....."
		   "##....."
		   "##....."
		   "##....."
		   "##....."
		   "##....."] = "F";

		ht["..#####.."
		   ".##...##."
		   "##.....##"
		   "##.....##"
		   "##......."
		   "##......."
		   "##......."
		   "##.######"
		   "##.######"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "###...##."
		   ".######.."
		   "...###..."] = "G";

		ht["##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "#########"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"] = "H";
		ht[".......##"
		   ".......##"
		   ".......##"
		   ".......##"
		   ".......##"
		   ".......##"
		   ".......##"
		   ".......##"
		   ".......##"
		   ".......##"
		   ".......##"
		   ".......##"
		   "##.....##"
		   "##.....##"
		   "###...##."
		   ".######.."
		   "...###..."] = "J";

		ht["##....##."
		   "##...##.."
		   "##...##.."
		   "##..##..."
		   "##.###..."
		   "##.###..."
		   "######..."
		   "######..."
		   "###..##.."
		   "###..##.."
		   "##...##.."
		   "##....#.."
		   "##....##."
		   "##....##."
		   "##....##."
		   "##.....##"
		   "##.....##"] = "K";

		ht["##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "#########"
		   "#########"] = "L";

		ht["##....###"
		   "###...###"
		   "###..####"
		   "####.####"
		   "######.##"
		   "##.##..##"
		   "##..#..##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"] = "M";

		ht["##.....##"
		   "##.....##"
		   "###....##"
		   "###....##"
		   "####...##"
		   "####...##"
		   "##.##..##"
		   "##.##..##"
		   "##.##..##"
		   "##..##.##"
		   "##..##.##"
		   "##...####"
		   "##...####"
		   "##....###"
		   "##....###"
		   "##....###"
		   "##.....##"] = "N";

		ht["#######.."
		   "##....##."
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##....##."
		   "########."
		   "#######.."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."
		   "##......."] = "P";

		ht["..#####.."
		   ".##..###."
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##..##.##"
		   "##...####"
		   ".##..###."
		   ".#######."
		   "...#####."] = "Q";

		ht["#######.."
		   "##....##."
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##....##."
		   "########."
		   "#######.."
		   "##..##..."
		   "##..##..."
		   "##...##.."
		   "##...##.."
		   "##....##."
		   "##....##."
		   "##....##."
		   "##.....##"] = "R";

		ht["..#####.."
		   ".###.###."
		   "##....##."
		   "##.....##"
		   "##......."
		   "##......."
		   "###......"
		   ".#####..."
		   "..#####.."
		   "......##."
		   ".......##"
		   ".......##"
		   ".......##"
		   "##.....#."
		   ".##...##."
		   ".######.."
		   "...###..."] = "S";

		ht["#########"
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."
		   "...##...."] = "T";

		ht["##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "##.....##"
		   "###...##."
		   ".######.."
		   "...###..."] = "U";

		ht["##.....##"
		   "##....##."
		   ".#....##."
		   ".##...##."
		   ".##...##."
		   ".##...##."
		   ".##..##.."
		   "..#..##.."
		   "..##.##.."
		   "..##.##.."
		   "..##.##.."
		   "..####..."
		   "...###..."
		   "...###..."
		   "...###..."
		   "...##...."
		   "...##...."] = "V";

		ht["#......##"
		   "#...#..##"
		   "#...#..##"
		   "#...#..##"
		   "##.##..#."
		   "##.##..#."
		   "##.##..#."
		   ".#.#####."
		   ".#.#####."
		   ".#.#####."
		   ".#######."
		   ".###.##.."
		   ".###.##.."
		   ".###.##.."
		   "..#..##.."
		   "..#..##.."
		   "..#..##.."] = "W";

		ht["##....##."
		   "###...##."
		   ".##...##."
		   ".##..##.."
		   "..##.##.."
		   "..####..."
		   "...###..."
		   "...###..."
		   "...###..."
		   "...###..."
		   "..####..."
		   "..##.##.."
		   ".###.##.."
		   ".##...##."
		   ".##...##."
		   "##....##."
		   "##.....##"] = "X";

		ht["##....##"
		   ".##...##"
		   ".##..##."
		   "..##.##."
		   "..####.."
		   "...###.."
		   "...##..."
		   "...##..."
		   "...##..."
		   "...##..."
		   "...##..."
		   "...##..."
		   "...##..."
		   "...##..."
		   "...##..."
		   "...##..."
		   "...##..."] = "Y";

		ht["#########"
		   "......###"
		   "......##."
		   ".....###."
		   ".....##.."
		   "....###.."
		   "....##..."
		   "...###..."
		   "...##...."
		   "..###...."
		   "..##....."
		   ".###....."
		   ".##......"
		   "###......"
		   "##......."
		   "#########"
		   "#########"] = "Z";

		int up = 500, down = 1, left = 500, right = 1;

		for (int i = 1; i <= 500; i++)
		{
			for (int j = 1; j <= 500; j++)
			{
				FastIO::read(c[i][j]);
				if (c[i][j] == '#')
				{
					up = min(up, i);
					down = max(down, i);
					left = min(left, j);
					right = max(right, j);
				}
			}
		}
		int l = left, r = left + 14, u = up, d = down;
		bool flag = 0;
		while (1)
		{
			flag = 0;
			for (int i = u; i <= d; i++)
			{
				if (c[i][r] == '#')
				{
					flag = 1;
					break;
				}
			}
			if (flag)
			{
				++r;
			}
			else
			{
				break;
			}
		}
		--r;
		while (1)
		{
			flag = 0;
			for (int i = l; i <= r; i++)
			{
				if (c[u][i] == '#')
				{
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				++u;
			}
			else
			{
				break;
			}
		}
		while (1)
		{
			flag = 0;
			for (int i = l; i <= r; i++)
			{
				if (c[u][i] == '#')
				{
					flag = 1;
					break;
				}
			}
			if (flag)
			{
				--u;
			}
			else
			{
				break;
			}
		}
		++u;
		while (1)
		{
			flag = 0;
			for (int i = l; i <= r; i++)
			{
				if (c[d][i] == '#')
				{
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				--d;
			}
			else
			{
				break;
			}
		}
		while (1)
		{
			flag = 0;
			for (int i = l; i <= r; i++)
			{
				if (c[d][i] == '#')
				{
					flag = 1;
					break;
				}
			}
			if (flag)
			{
				++d;
			}
			else
			{
				break;
			}
		}
		--d;
		string temp;
		for (int i = u; i <= d; i++)
		{
			for (int j = l; j <= r; j++)
			{
				temp.push_back(c[i][j]);
				c[i][j] = '.';
			}
		}
		left = r;
		FastIO::write(ht[temp]);
		for (int l = left; l <= right; ++l)
		{
			bool flag = 0;
			for (int i = up; i <= down; i++)
			{
				if (c[i][l] == '#')
				{
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				continue;
			}
			int u = up, d = down, r = l + 1;
			while (1)
			{
				bool flag = 0;
				for (int i = u; i <= d; i++)
				{
					if (c[i][r] == '#')
					{
						flag = 1;
						break;
					}
				}
				if (flag)
				{
					++r;
				}
				else
				{
					break;
				}
			}
			--r;
			while (1)
			{
				bool flag = 0;
				for (int i = l; i <= r; i++)
				{
					if (c[u][i] == '#')
					{
						flag = 1;
						break;
					}
				}
				if (!flag)
				{
					++u;
				}
				else
				{
					break;
				}
			}
			while(1){
				bool flag = 0;
				for (int i = l; i <= r;i++){
					if(c[d][i]=='#'){
						flag = 1;
						break;
					}
				}
				if(!flag){
					--d;
				}
				else{
					break;
				}
			}
			temp.clear();
			for (int i = u; i <= d; i++)
			{
				for (int j = l; j <= r;j++){
					temp.push_back(c[i][j]);
				}
			}
			FastIO::write(ht[temp]);
			l = r + 1;
		}
		return 0;
	}
};

signed main()
{
#ifndef ONLINE_JUDGE
	FileIO("recognition");
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	recognition::main();
	FastIO::flush();
	return 0;
}