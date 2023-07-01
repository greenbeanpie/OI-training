#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<int> s;
	s.insert(1);
	s.insert(3);
	cout << *s.erase(s.end());
    return 0;
}