#include <bits/stdc++.h>
using namespace std;
#define int long long

int a(int b){
	int num=0;
	while(b!=0){
		num+=(b&1);
		b=b>>1;
	}
	return num;
}

signed main(){
	ios::sync_with_stdio(false);
	int n,k,answer=0;
	cin >> n >> k;
	while(a(n)>k){
		answer+=(n&-n);
		n+=(n&-n);
	}
	cout << answer;
	return 0;
}