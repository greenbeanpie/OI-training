#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
int temp[N],temp2[N];
map<int, int> num;

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

int res,n,k,maxans;

int dfs(bool flag = 1){
	if(flag){
		for (int i = 1; i <= n;i++){
			for (int j = i + 1; j <= n;j++){
				res -= abs(temp[i] - temp2[i]);
				res -= abs(temp[j] - temp2[j]);
				swap(temp[i], temp[j]);
				res += abs(temp[i] - temp2[i]);
				res += abs(temp[j] - temp2[j]);
				dfs(0);
				res -= abs(temp[i] - temp2[i]);
				res -= abs(temp[j] - temp2[j]);
				swap(temp[i], temp[j]);
				res += abs(temp[i] - temp2[i]);
				res += abs(temp[j] - temp2[j]);
			}
		}
		return maxans;
	}
	else{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				res -= abs(temp[i] - temp2[i]);
				res -= abs(temp[j] - temp2[j]);
				swap(temp[i], temp[j]);
				res += abs(temp[i] - temp2[i]);
				res += abs(temp[j] - temp2[j]);
				maxans = max(maxans, res);
				res -= abs(temp[i] - temp2[i]);
				res -= abs(temp[j] - temp2[j]);
				swap(temp[i], temp[j]);
				res += abs(temp[i] - temp2[i]);
				res += abs(temp[j] - temp2[j]);
			}
		}
	}
	return 0;
}

signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		num.clear();
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> temp[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> temp2[i];
			num[temp2[i]] = temp[i];
		}
		if(k>=n-1){
			sort(temp + 1, temp + 1 + n);
			sort(temp2 + 1, temp2 + 1 + n, greater<int>());
			int res = 0;
			for (int i = 1; i <= n;i++){
				res += abs(temp2[i] - temp[i]);
			}
			FastIO::writeln(res);
		}
		else if(k==0){
			for (int i = 1; i <= n; i++)
			{
				res += abs(temp2[i] - temp[i]);
			}
			FastIO::writeln(res);
		}
		else if(k==2){
			for (int i = 1; i <= n; i++)
			{
				res += abs(temp2[i] - temp[i]);
			}
			FastIO::writeln(dfs());
		}
		else if(k==1){
			for (int i = 1; i <= n; i++)
			{
				res += abs(temp2[i] - temp[i]);
			}
			FastIO::writeln(dfs(0));
		}
	}

	FastIO::flush();
	return 0;
}
