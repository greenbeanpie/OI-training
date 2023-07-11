#include <bits/stdc++.h>
using namespace std;
#define int long long
#define map unordered_map

signed main(){
	ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("P1886.in","r",stdin);
	#endif
	int n,k;
	cin >> n >> k;
	deque<int> d;
	map<int,int> m;
	int nums[n];
	for(int i=0;i<n;i++){
		cin >> nums[i];
	}
	for(int i=0;i<n;i++){
		while(!d.empty()&&d.front()>=nums[i]){
			d.pop_front();
		}
		d.push_front(nums[i]);
		m[nums[i]]=i;
		if(i-m[d.back()]>=k){
			d.pop_back();
		}
		if(i>=k-1){
			cout << d.back() << " ";
		}
	}
	deque<int> d1;
	map<int,int> m1;
	cout << endl;
	for(int i=0;i<n;i++){
		while(!d1.empty()&&d1.front()<=nums[i]){
			d1.pop_front();
		}
		d1.push_front(nums[i]);
		m1[nums[i]]=i;
		if(i-m1[d1.back()]>=k){
			d1.pop_back();
		}
		if(i>=k-1){
			cout << d1.back() << " ";
		}
	}
	return 0;
}