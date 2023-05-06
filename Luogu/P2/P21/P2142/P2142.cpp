#include <bits/stdc++.h>
using namespace std;
#define bimax 20000

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
            puts("-");
        }
		for(int i=len-1; i>=0; i--) {
			printf("%d",num[i]);
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
		while(len>=0&&!num[len]){
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
bool operator<(bigint a,bigint b){
	if(a.len>b.len){
		return false;
	}
	else if(a.len<b.len){
		return true;
	}
	else{
		for(int i=0;i<a.len;i++){
			if(a[i]-'0'<b[i]-'0'){
				return true;
			}
			else if(a[i]-'0'>b[i]-'0'){
				return false;
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
bigint stob(string x)
{
    bigint a;
	for(int i=x.length()-1; i>=0; i--) {
		a[i]=x[x.length()-1-i]-'0';
		a.len++;
	}
    return a;
}
#define int long long
signed main(){
    bigint a,b;
    string t;
    cin >> t;
    a=stob(t);
    cin >> t;
    b=stob(t);
    bigint c=a-b;
    c.print();
    return 0;
}