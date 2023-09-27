#include <iostream>
#include <cstring>
using namespace std;
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
	inline int read(){
		int x=0,f=1;
		char c=gc();
		if(c=='-'){
			f=-1;
			c=gc();
		}
		while(isdigit(c)){
			x=x*10+c-'0';
			c=gc();
		}
		return x*f;
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
	inline void writeln(_Tp x) { write(x), pc(' '); }
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
using namespace FastIO;
typedef long long ll;

int n;
ll a[500005];
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	for (int T = read(); T--;)
	{
		n = read();
		for (int i = 0; i < n; i++)
			a[i] = read(), a[i] -= (i <= 1 ? 0 : a[i - 1]); //直接解出 Ci
		bool ans = 1;                                       //答案
		if (n & 1)
		{
			if (a[0] - a[n - 1] < 0 || ((a[0] - a[n - 1]) & 1))
				ans = 0; //t0<0||t0不是整数
			ll x = (a[0] - a[n - 1]) >> 1;
			for (int i = 1; i < n; i++)
				if (a[i] + ((i & 1) ? -x : x) < 0)
					ans = 0; //代入 t0 后有负数
			puts(ans ? "1" : "0");
		}
		else
		{
			if (a[0] != a[n - 1])
				ans = 0; //矛盾
			ll l = 0, r = 1e18;
			for (int i = 1; i < n; i++)
				(i & 1) ? (r = min(r, a[i])) : (l = max(l, -a[i])); //求出上下界
			ans &= (r >= l);                                        //上下界有值
			puts(ans ? "1" : "0");
		}
	}
	return 0;
}
