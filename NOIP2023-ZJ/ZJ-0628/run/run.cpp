#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int,int> dp,tim;

const int N=1e5+5;

struct node{
	int x,y,v;
}cha[N];

bool cmp(node a,node b){
	return a.x-a.y<b.x-b.y;
}

signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,m,k,d;
		cin >> n >> m >> k >> d;
		for(int i=1;i<=m;i++){
			cin >> cha[i].x >> cha[i].y >> cha[i].v;
		}
		dp.clear();
		sort(cha+1,cha+1+m,cmp);
		dp[0] = 0;
		tim[0] = 0;
		int maxinum = 0;
		for(int i=1;i<=m;i++){
			if(cha[i].x-cha[i].y+1 <= 0){
				continue;
			}
			if(cha[i].y>n){
				continue;
			}
			if(cha[i].y>k){
				continue;
			}
			auto last = tim.rbegin();
			// cerr << last->first << endl;
			if(last->first < cha[i].x-cha[i].y){
				auto temp=dp.upper_bound(cha[i].x-cha[i].y);
				--temp;
				dp[cha[i].x] = dp[temp->first] + cha[i].v - cha[i].y;
				tim[cha[i].x] = cha[i].y;	
			}
			else if(cha[i].x-last->first+last->second > k){
				auto temp = dp.lower_bound(cha[i].x-k);
				--temp;
				dp[cha[i].x] = dp[temp->first] + cha[i].v - (cha[i].x-last->first);
				tim[cha[i].x] = cha[i].x-last->first;
			}
			else{
				auto temp = dp.end();
				--temp;
				dp[cha[i].x] = dp[temp->first] + cha[i].v - (cha[i].x-last->first);
				tim[cha[i].x] = cha[i].x-last->first+last->second;				
			}
			// auto tempt = tim.upper_bound(cha[i].x-cha[i].y);
			// --tempt;
			// if(cha[i].x-tempt->first+tempt->second > k){
			// 	--tempt;
			// }
			// dp[cha[i].x] = dp[tempt->first]+cha[i].v-(cha[i].x-);
			maxinum = max(maxinum,dp[cha[i].x]);
		}
		cout << maxinum << endl;
	}
	return 0;
}