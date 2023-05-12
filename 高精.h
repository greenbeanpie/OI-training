#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
#define bimax 20000
const double Pi = acos(-1);
#define int long long
#define double long double
#define fft fast_fast_tle
#define ceil ceilf64x
struct bigint {
	bool positive=true;
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
		if(!positive){
			putchar('-');
		}
		for(int i=len-1; i>=0; i--) {
			putchar('0'+num[i]);
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
			if(num[i]<0){
				num[i+1]+=num[i]/10;
				num[i]=10-abs(num[i])%10;
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
struct complex {
	double real=0, imag=0;
	inline complex(double r = 0, double i = 0) {
		real = r;
		imag = i;
	}
};
const complex I(0, 1);
complex operator+(complex a, complex b) {
	complex c(a.real + b.real, a.imag + b.imag);
	return c;
}
complex operator-(complex a, complex b) {
	complex c(a.real - b.real, a.imag - b.imag);
	return c;
}
complex operator*(complex a, complex b) {
	complex c(a.real * b.real, a.imag * b.imag);
	return complex(a.real * b.real-a.imag*b.imag, a.real*b.imag + a.imag*b.real);
}

void change(complex y[], int len) {
	int k;
	for (int i = 1, j = len / 2; i < len - 1; i++) {
		if (i < j) {
			swap(y[i], y[j]);
		}
		k = len / 2;
		while (j >= k) {
			j = j - k;
			k>>=1;
		}
		if (j < k) {
			j += k;
		}
	}
}

void fast_fast_tle(complex y[], int len, int op) {
  change(y, len);
  for (int h = 2; h <= len; h <<= 1) {
    complex wn(cos(2 * Pi / h), sin(op * 2 * Pi / h));
    for (int j = 0; j < len; j += h) {
      complex w(1,0);
      for (int k = j; k < j + h / 2; k++) {
        complex u = y[k];
        complex t = w * y[k + h / 2];
        y[k] = u + t;
        y[k + h / 2] = u - t;
        w = w * wn;
      }
    }
  }
  if (op == -1) {
    for (int i = 0; i < len; i++) {
      y[i].real /= len;
    }
  }
}
extern bigint operator+(bigint a,bigint b);
extern bigint operator-(bigint a,bigint b);
extern bigint operator*(bigint a,bigint b);
extern bigint operator/(bigint a,bigint b);

bigint operator+(bigint a,bigint b)
{
	if(a.positive^b.positive){
		if(!a.positive){
			a.positive=true;
			return b-a;
		}
		else{
			b.positive=true;
			return a-b;
		}
	}
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
bool operator<(bigint a,bigint b){
	if(a.positive&&!b.positive){
		return false;
	}
	else if(!a.positive&&b.positive){
		return true;
	}
	bool flag=a.positive;
	if(a.len>b.len){
		return !flag;
	}
	else if(a.len<b.len){
		return flag;
	}
	else{
		for(int i=0;i<a.len;i++){
			if(a[i]-'0'<b[i]-'0'){
				return flag;
			}
			else if(a[i]-'0'>b[i]-'0'){
				return !flag;
			}
		}
	}
	return false;
}
bigint operator-(bigint a,bigint b){
	bigint c=0;
	if(a<b){
		bigint temp;
		temp=a;
		b=a;
		temp=b;
		c.positive=false;
	}
	for(int i=0; i<max(a.len,b.len); i++) {
		c[i]+=a[i]-b[i];
	}
	c.flatten(max(a.len,b.len)+1);
	return c;
}

bigint operator*(bigint a, bigint b)
{
	complex x1[bimax], x2[bimax];
	int len = 1ll << (int)max(ceil(log2(a.len*2)), ceil(log2(b.len*2)));
	for (int i = 0; i < a.len; i++) {
		x1[i] = complex(a[i], 0);
	}
	for (int i = 0; i < b.len; i++) {
		x2[i] = complex(b[i], 0);
	}
	fft(x1, len, 1);
	fft(x2, len, 1);
	for (int i = 0; i < len; i++) {
		x1[i] = x1[i] * x2[i];
	}
	fft(x1, len, -1);
	bigint c;
	for (int i = 0; i < len; i++) {
		c[i] = (int)(x1[i].real + 0.5);
	}
	for (int i = 0; i < len; i++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	c.len = a.len + b.len - 1;
	while (c.len >= 0 && !c[c.len]) {
		c.len--;
	}
	c.len++;
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

