#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	auto c=a.begin()+1;
	a.erase(a.begin());
	cout << *c;
	return 0;
}