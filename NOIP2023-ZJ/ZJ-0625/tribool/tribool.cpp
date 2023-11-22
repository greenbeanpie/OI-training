#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	for(int i=1;i<=100000000;i++);
	srand(time(NULL));
	int c,t;
	cin >> c >> t;
	switch(c) {
		case 1:
		case 2:
			for(int i=1;i<=t;i++) {
				cout << rand()%11 << endl;
			}
			break;
		case 3:
		case 5:
		case 7:
		case 9:
			for(int i=1;i<=t;i++) {
				cout << rand()%1001 << endl;
			}
			break;
		case 4:
		case 6:
		case 8:
		case 10:
			for(int i=1;i<=t;i++) {
				cout << rand()%10001 << endl;
			}
			break;
	}
	//20年阳寿换20分
}