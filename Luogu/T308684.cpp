#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
    int n,m,k;
long long quickpower(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }
    long long answer = 1;
    while (b)
    {
        if (b & 1)
        {
            answer = answer * a;
        }
        a = a * a;
        b >>= 1;
    }
    return answer;
}
int sqrt1(int x,int y){//x结果，y指数 
	int a=1;
	int l=2,r=sqrt(x);
	while(l!=r){
		int mid=(l+r)/2;
		int a=quickpower(mid,y);
		if(a>x){
			r=mid; 
		}
		else if(a<x){
			l=mid+1;
		}
		else{
			break;
		}
	}
	return a;
}
int f(int x){
	int temp=log(x);
	int c=1;
	if(x==1){
		return 1;
	}
	if(x<4){
		return x;
	}
    for(int i=2;i<sqrt(x);i+=c){
    	if(temp/log(i)==floor(temp/log(i))){
    		c=i;
		}
	}
	return sqrt1(x,c)*__gcd(c,k);
}

signed main(){

    cin >> n >> m >> k;
    int sum=0;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		sum+=f(i*j)%mod;
		}
	}
	cout << sum;
}