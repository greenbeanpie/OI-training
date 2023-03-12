#include <bits/stdc++.h>
using namespace std;
#define int long long

int xorsum(int a,int b){
	if(b>a){
		swap(a,b);
	}
	int sum=0,temp=b*(b+1)/2;
	if(a%2==1){
		temp--;
		sum+=(temp*2-b+1)*b/2;
		for(int i=1;i<=b;i++){
			temp+=b^(b+1);
		}
		sum+=temp*(a-b);
	}
	else{
		sum+=temp*(b-1);
		temp=0;
		for(int i=1;i<=b;i++){
			temp+=b^i;
		}
		sum+=temp*(a-b+1);
	}
	return sum;
}

signed main(){
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	cin >> t;
	int n,m;
	for(int a=0;a<t;a++){
		cin >> n >> m;

		cout << xorsum(n,m) << endl;
	}
	return 0;
}