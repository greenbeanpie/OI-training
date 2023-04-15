#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
signed main(){
	int n;
	cin >> n;
	int sum=0;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		sum+=min(a,b);
	}
	cout << sum;
	return 0;
}

