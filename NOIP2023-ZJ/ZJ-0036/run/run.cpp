#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;

int c,T;
int n,m,k,d;
pair<pair<int,int>,int> a[N];

namespace BF{
	ll f[N];
	int b[N<<1],btot;
	ll val[2010][2010];
	
	void solve() {
		b[++btot]=0;
		b[++btot]=n+1;
		for(int i=1;i<=m;i++) b[++btot]=a[i].first.first+1,b[++btot]=a[i].first.second-1;
		sort(b+1,b+1+btot);
		btot=unique(b+1,b+1+btot)-b-1;
		for(int i=1;i<=btot;i++) {
			int r=0;
			ll sum=0;
			for(int j=i;j<=btot;j++) {
				while(r<m && a[r+1].first.first<b[j]) {
					if(a[r+1].first.second>b[i]) sum+=a[r+1].second;
					r++;
				}
				val[i][j]=max(sum-1ll*d*(b[j]-b[i]-1),0ll);
			}
		}
		for(int i=1;i<=btot;i++) f[i]=0;
		for(int i=2;i<=btot;i++) {
			for(int j=i-1;j>=1 && b[i]-b[j]-1<=k;j--) f[i]=max(f[i],f[j]+val[j][i]);
		}
		printf("%lld\n",f[btot]);
	}
}

int main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--) {
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++) {
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			a[i]={{x,x-y+1},v};
		}
		sort(a+1,a+1+m);
		if(c<=11) {
			BF::solve();
			continue;
		}
	}
	return 0;
}

