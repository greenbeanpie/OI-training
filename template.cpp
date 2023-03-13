#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bimax 20000
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


struct bigint {
	int len=0;
	int num[bimax]= {0};
	bigint(int x=0) {
		for(int i=0; x; i++) {
			num[i]=x%10;
			x/=10;
			len++;
		}
		if(num[len]!=0) {
			len++;
		}
	}
	int &operator[](int a) {
		return num[a];
	}
	void print() {
		for(int i=len-1; i>=0; i--) {
			cout << num[i];
		}
	}
	void flatten(int L){
		len=L;
		for(int i=0;i<L;i++)
		{
			if(num[i]>=10)
			{
				num[i+1]+=num[i]/10;
				num[i]%=10;
			}

		}
		while(!num[len]){
			len--;
		} 
		len++;
		if(len==0){
			len++;
		}
	} 

};
bigint operator+(bigint a,bigint b)
{
	bigint c=0;
	for(int i=0; i<max(a.len,b.len); i++) {
		c[i]+=a[i]+b[i];
		if(c[i]>=10) {
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	}
	c.flatten(max(a.len,b.len)+1);
	return c;
}
bigint operator*(bigint a,bigint b)
{
	bigint c=0;
	for(int i=0; i<a.len; i++) {
		for(int j=0;j<b.len;j++)
		{
			c[i+j]+=a[i]*b[j];
		}
	}
	c.flatten(a.len+b.len+1);
	return c;
}
bigint stb(string x,bigint a)
{
	for(int i=x.length()-1; i>=0; i--) {
		a[i]=x[x.length()-1-i]-'0';
		a.len++;
	}
	return a;
}
using namespace IO;
signed main(){
    ios::sync_with_stdio(false);

    return 0;
}