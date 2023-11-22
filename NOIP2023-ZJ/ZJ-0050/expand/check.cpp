#include <bits/stdc++.h>
using namespace std;
int main(){
	for(size_t i = 0; true; i++){
		if(i % 100 == 0) cerr << '#' << i << endl;
		system("python3 gen.py > expand.in");
		system("./expand");
		system("./expand-0");
		if(system("diff -w expand.out expand.ans")) break;
	}
	return 0;
}
