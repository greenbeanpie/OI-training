#include<iostream>
#include<random>
#include<ctime>

using namespace std;

mt19937 mt(time(0));

int T = 100000;

inline int rand(int l, int r) {
	return mt() % (r - l + 1) + l;
}

signed main() {
	int n = 10, m = 5;
	cout << 9 << " " << n << " " << m << " " << 0 << endl;
	cout << T/2 << " ";
	for(int i = 2;i < n;i++) cout << rand(2, T) << " ";
	cout << 1 << endl;
	cout << T/2+1 << " ";
	for(int i = 2;i < m;i++) cout << rand(2, T) << " ";
	cout << T+1 << endl;
	return 0;
}
