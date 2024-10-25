#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace Main{
	const int N=1e5+5;
	int a[N],b[N],c[N];
	int check(int n,int k){
		int rnk=0;
		for(int i=1;i<=n;i++){
			rnk+=upper_bound(c+1,c+1+n,(k-a[i])/b[i])-c-1;
		}
		return rnk;
	}
	int main(){
		int n,k;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int i=1;i<=n;i++){
			cin >> b[i];
		}
		for(int i=1;i<=n;i++){
			cin >> c[i];
		}
		sort(c+1,c+n+1);
		cin >> k;
		int l=1,r=1e18;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(n,mid)>=k){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		cout << r;
		return 0;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	Main::main();
	return 0;
}
