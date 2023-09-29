#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
#define int long long
#define double long double
#define endl "\n"
#define problemname "seg"
#define const constexpr

namespace Main{
	
	
	int main(){
		int n,m;
		cin >> n >> m;
		vector<int> v=vector<int>(1);
		for(int i=1,t;i<=n;i++){
			cin >> t;
			v.push_back(t);
		}
		for(int i=1;i<=m;i++){
			int op;
			cin >> op;
			if(op==1){
				int x,y;
				cin >> x >> y;
				v[x]=y;
			}
			else if(op==2){
				int i,k;
				cin >> i >> k;
				int begin=i*(1<<k)+1,end=(i+1)*(1<<k)+1;
				reverse(v.begin()+begin,v.begin()+end);
			}
			else if(op==3){
				int i,j,k;
				cin >> i >> j >> k;
				int start=i*(1<<k)+1,end=(i+1)*(1<<k),delta=(j*(1<<k)+1)-(i*(1<<k)+1);
				for(int i=start;i<=end;i++){
					swap(v[i],v[i+delta]);
				}
			}
			else{
				int l,r;
				cin >> l >> r;
				int sum=0;
				for(int i=l;i<=r;i++){
					sum+=v[i];
				}
				cout << sum << endl;
			}
		}
		
		return 0;
	}
};

signed main(){
#ifndef ONLINE_JUDGE
	freopen(problemname".in","r",stdin);
	freopen(problemname".out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	Main::main();
	return 0;
}