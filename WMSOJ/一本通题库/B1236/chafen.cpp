#include <bits/stdc++.h>
using namespace std;
#define int long long
int chafen[10005];
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("problem10.in","r",stdin);
    #endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int mininum=INT_MAX,maxinum=INT_MIN;
  for(int i=0;i<n;i++){
  	int s,e;
  	cin >> s >> e;
  	chafen[s]++;
  	chafen[e]--;
  	mininum=min(mininum,s);
  	maxinum=max(maxinum,e);
  }
  int temp=0;
  for(int i=mininum;i<maxinum;i++){
  	temp+=chafen[i];
  	if(temp<=0){
  		cout << "no";
  		return 0;
	  }
  }
  cout << mininum << " " << maxinum;
  return 0;
}