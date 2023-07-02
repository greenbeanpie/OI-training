#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
tree<std::pair<int,int>,null_type,std::less<std::pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> bt;

int main()
{
	bt.insert({1,1});
	std::cout << (*bt.find_by_order(std::min((int)bt.size()-1,2))).first;
	return 0;
}