#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1E5+5;
int c,t;
int n,m,k,d;
long long f[2][MAXN]= {0}; // <first> day, with <second> day(s) of consecutive running
struct Challenge {
	Challenge() {
	}
	Challenge(int iy,int iv) {
		y=iy,v=iv;
	}
	long long y;
	long long v;
};
//map<int, vector<Challenge> > ch; //map too slow bro
vector<Challenge> ch[MAXN];

long long get_reward(long long x, long long y) {
	int ret=0;
	for(auto i : ch[x]) {
		if (i.y<=y)
			ret+=i.v;
	}
	return ret;
}

int main() {

	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> c >> t;
	while(t--) {
		cin >> n >> m >> k >> d;
		for(int i=0; i<m; i++) {
			long long x1,x2,x3;
			cin >> x1 >> x2 >> x3;
			ch[x1].push_back(Challenge(x2,x3));
		}

		for(int i=0; i<=k; i++) {
			f[0][i]=f[1][i]=0;
		}
		//Dp with flipping array
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=min(i+1,k); j++) {
				long long reward=get_reward(i,j);
				if (j==0) {
					for(int j1=0; j1<=min(i+1,k); j1++)
						f[i&1][j]=max(f[i&1][j],f[(i-1)&1][j1]);
				} else {
					f[i&1][j]=f[(i-1)&1][j-1]-d;
					f[i&1][j]=max(f[i&1][j],f[(i-1)&1][j-1]);
					reward-=d;
				}
				f[i&1][j]+=reward;
			}
		}

		long long mx=-0x3f3f3f3f;
		for(int i=0; i<=k; i++) mx=max(f[n&1][i],mx);
		cout<<mx<<endl;

		for(int i=0; i<=n; i++) {
			ch[i].clear();
		}
	}


	fclose(stdin);
	fclose(stdout);
}
