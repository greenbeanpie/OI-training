#include<iostream>

using namespace std;

signed main() {
	while(1) {
		system("sm > sj.txt");
		system("expand < sj.txt > myo.txt");
		system("dp < sj.txt > dpo.txt");
		if(system("fc myo.txt dpo.txt")) break;
	}
}
