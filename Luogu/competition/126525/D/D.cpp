#include <bits/stdc++.h>
#define int long long
#define INF 2147483647
using namespace std;
int t;
int v[100005],w[100005];
int n;
struct node{
	int v,w;
};
bool cmp1(node x,node y){
	return x.w > y.w;
}
bool cmp2(node x,node y){
	return x.w + x.v > y.w + y.v;
} 
bool check(int val){
	vector <node> need,give;
	for(int i = 1;i <= n;i++){
		if(v[i] < val) need.push_back({v[i],w[i]});
		else give.push_back({v[i],w[i]});
	}
	sort(need.begin(),need.end(),cmp1);
	sort(give.begin(),give.end(),cmp2);
	if(need.size() > give.size()) return 0;
	for(int i = 0;i < need.size();i++){
		if(need[i].w <= give[i].w) continue;
		int v1 = give[i].v - (need[i].w - give[i].w);
		if(v1 < val) return 0;
	}
	return 1;
}
signed main(){
	#ifndef ONLINE_JUDGE
		freopen("D.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> t;
	while(t--){
		int mx=0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> v[i] >> w[i];
			mx=max(mx,v[i]);
		}
		int r=mx,l=0;
		while(r-l>1){
			int mid = (l+r)/2;
			if(check(mid)){
				r=mid-1;
			}else{
				l=mid;
				
			}
		}
		cout << l << endl;
	}
	return 0;
}
