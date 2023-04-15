#include <bits/stdc++.h>
using namespace std;
#define int long long
#define map unordered_map
struct node{
    int num,cnt;
};
signed main(){
	#ifndef ONLINE_JUDGE
		freopen("P2032.in","r",stdin);
	#endif
	int n,k;
	cin >> n >> k;
	int nums[n];
	for(int i=0;i<n;i++){
		//cin >> nums[i];
        scanf("%lld",nums + i);
	}
	deque<node> d1;
	for(int i=0;i<n;i++){
		while(!d1.empty()&&d1.front().num<=nums[i]){
			d1.pop_front();
		}
		d1.push_front(node{nums[i],i});
		if(i-d1.back().cnt>=k){
			d1.pop_back();
		}
		if(i>=k-1){
			printf("%lld\n",d1.back().num);
		}
	}
	return 0;
}