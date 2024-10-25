#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace Main{
	const int N=1e5+5;
	int a[N],b[N];
	int cnt[N];
	int main(){
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int i=1;i<=n;i++){
			cin >> b[i];
		}
		int ans=-1;
		for(int i=1;i<=n;i++){
			cnt[i]=1;
			for(int j=i-1;j>=1;j--){
				if(a[j]<a[i] && b[j]<b[i]){
					cnt[i]=max(cnt[i],cnt[j]+1);
				}
			}
			ans=max(ans,cnt[i]);
		}
		cout << ans;
		return 0;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("factor.in","r",stdin);
	freopen("factor.out","w",stdout);
	Main::main();
	return 0;
}
