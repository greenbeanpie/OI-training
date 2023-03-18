#include <bits/stdc++.h>
using namespace std;
#define bimax 20000

//freopen("std.in","r",stdin);
//freopen("std.out","w",stdout);

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
int main()
{
	
	bigint a(0),b(0);
	string x,y;
	cin >> x >> y;
	a=stb(x,a);
	b=stb(y,b);
	bigint c=0;
	c=a*b;
	c.print();
	return 0;
}