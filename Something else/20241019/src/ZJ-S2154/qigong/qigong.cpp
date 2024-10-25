#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace Main {
	const int N=105;
	struct wall {
		int strg=0,eg=0,broken=0;
		wall() {
			return;
		}
		wall(int a) {
			strg=a;
		}
	};
	wall a[N];
	deque<int> res;
	const int st=clock();
	int dfs(int n,int cost) {
		wall tmp[N];
		bool flag=0;
		int res=INT_MAX;
		for(int i=1; i<=n; i++) {
			if(!a[i].broken) {
				flag=1;
				memcpy(tmp,a,sizeof(a));
				a[i].broken=1;
				int energy=a[i].strg/2;
				for(int j=i+1; j<=n; j++) {
					while(a[j].broken) {
						++j;
					}
					energy+=a[j].eg;
					if(a[j].strg<energy) {
						a[j].broken=1;
						energy/=2;
					} else {
						a[j].eg=energy;
						break;
					}
				}
				res=min(res,dfs(n,cost+a[i].strg-a[i].eg));
				memcpy(a,tmp,sizeof(a));
			}
		}
		if(!flag) {
			return cost;
		}
		return res;
	}
	int Sub1(int n) {
		return dfs(n,0);
	}
	int main() {
		int n;
		cin >> n;
		bool flag=1;
		for(int i=1,tmp; i<=n; i++) {
			cin >> a[i].strg;
			flag&=(a[i].strg<=2);
		}
		if(flag) {
			int res=0;
			for(int i=1; i<=n; i++) {
				if(a[i-1].strg==2 && a[i].strg==1) {
				} else if((a[i-1].strg!=2 && a[i].strg==1)||(a[i-1].strg==2 && a[i].strg==2)){
					res+=1;
				}
				else{
					res+=2;
				}
				cout << res << " ";
			}
			return 0;
		}
		for(int i=1; i<=n; i++) {
			cout << dfs(i,0) << " ";
		}
		return 0;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("qigong.in","r",stdin);
	freopen("qigong.out","w",stdout);
	Main::main();
	return 0;
}
