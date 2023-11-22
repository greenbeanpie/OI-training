#include<bits/stdc++.h>
using namespace std;
int n ,m;
int main() {
	freopen("run.in" , "r",stdin);
	freopen("run.out","w" ,stdout);
	cin >> n >>m;
	
	srand(time(0));
	srand(rand());
	while(m--)
		cout << rand()%200805;
    return 0;
}
