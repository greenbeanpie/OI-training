#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int main() {
	for (;;) {
		system("data.exe");
		int st = clock();
		system("tribool.exe");
		int ed = clock();
		system("bf.exe");
		if (system("fc tribool.out ans.out")) {
			cout << "WA" << endl;
			break;
		}
		cout << "AC" <<" time: " << ed - st << endl; 
	}
	return 0;
}