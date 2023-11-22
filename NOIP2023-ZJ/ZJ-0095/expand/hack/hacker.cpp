#include<bits/stdc++.h>
#define ll long long
using namespace std;

signed main() {
	ios::sync_with_stdio(false),cin.tie(0);
	cout.precision(10),cout.setf(ios::fixed);
	
	for (int T=1;;T++) {
		cout<<"hack #"<<T<<endl;
		system("./gen > data.in");
		system("./my < data.in > my.out");
		system("./bf < data.in > bf.out");
		if (system("diff my.out bf.out -b")) {
			cout<<"Hacked!"<<endl;
			while (1);
		}
	}
	
	return 0;
}
