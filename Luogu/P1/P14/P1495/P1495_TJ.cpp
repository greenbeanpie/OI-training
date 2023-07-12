#include<algorithm>
//会用到一个很神奇滴函数，加着
#include<iostream>
using namespace std;
long long n,a[11],b[11],i,ans,c;
//用long long定义
long long zxgbs(long long a,long long b){
	return a*b/ __gcd(a,b);
    //__gcd(a,b):求最大公因数，要algorithm
}
//求最小公倍数
int main(){
	#ifndef ONLINE_JUDGE
		freopen("P1495.in","r",stdin);
		freopen("P1495_TJ.out","w",stdout);
	#endif
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i]>>b[i];
    //输入部分，不说了
	c=a[1];ans=b[1];
    //第一次建立不用循环，直接写进去
	for(i=2;i<=n;i++)
	{
		for(;ans%a[i]!=b[i];) ans+=c;
        //ans暴力往上加，加到符合这次的标准
		c=zxgbs(c,a[i]);
        //用函数把a[i]加进去，后面每次加的都要是这次的倍数
	}
	cout<<ans;
    //输出结果
	return 0;
} 
