#include <bits/stdc++.h>
using namespace std;
#define int long long
namespace IO {
	template<typename _Tp>inline void read(_Tp& x) {
		#define gc() getchar()
		x = 0; char c = gc(); bool f = 0;
		while(!std::isdigit(c)) f |= c == 45, c = gc();
		while(std::isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
		return (void)(f ? x = -x : 1);
	}
	
	template<typename _Tp>inline void write(_Tp x) {
		static char stk[20]; int top = 0;
		if(!x) return putchar(48), void();
		if(x < 0) putchar(45), x = -x;
		while(x) stk[top++] = x % 10, x /= 10;
		while(top) putchar(stk[--top] + 48);
	}
	
	template<typename _Tp, typename ...Args>
	inline void read(_Tp& x, Args& ...args) {
        read(x), read(args...);
    }
};
using namespace IO;
signed main(){
    ios::sync_with_stdio(false);

    return 0;
}