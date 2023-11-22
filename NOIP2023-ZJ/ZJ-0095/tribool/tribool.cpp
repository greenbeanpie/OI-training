#include<bits/stdc++.h>
#define ll long long
using namespace std;

void work() {
	int n,m;
	cin>>n>>m;
	vector<int>tp(n+1,3),id(n+1);
	for (int i=1;i<=n;i++) {
		id[i]=i;
	}
	for (int i=1;i<=m;i++) {
		char c;
		int x,y;
		cin>>c;
		if (c=='F') {
			cin>>x;
			tp[x]=0;
		}
		if (c=='T') {
			cin>>x;
			tp[x]=1;
		}
		if (c=='U') {
			cin>>x;
			tp[x]=2;
		}
		if (c=='+') {
			cin>>x>>y;
			tp[x]=tp[y];
			id[x]=id[y];
		}
		if (c=='-') {
			cin>>x>>y;
			tp[x]=tp[y];
			id[x]=id[y];
			if (tp[x]==0||tp[x]==1) {
				tp[x]^=1;
			}
			if (tp[x]==3||tp[x]==4) {
				if (tp[x]==3) {
					tp[x]=4;
				} else {
					tp[x]=3;
				}
			}
		}
	}
	vector<int>fa(n+1),val(n+1);
	for (int i=1;i<=n;i++) {
		fa[i]=i;
	}
	auto find=[&](auto &self,int x) {
		if (x==fa[x]) {
			return x;
		}
		int res=self(self,fa[x]);
		val[x]^=val[fa[x]];
		return fa[x]=res;
	};
	auto link=[&](int x,int y,int w) {
		int u=find(find,x),v=find(find,y);
		if (u==v) {
			return (val[x]^val[y])==w;
		}
		fa[u]=v;
		val[u]=val[x]^val[y]^w;
		return true;
	};
	vector<int>mark(n+1);
	for (int i=1;i<=n;i++) {
		if (tp[i]>=3) {
			if (!link(i,id[i],tp[i]==4)) {
				mark[i]=1;
			}
		}
	}
	vector<int>a(n+1,-1),siz(n+1);
	for (int i=1;i<=n;i++) {
		siz[find(find,i)]++;
		if (tp[i]<2) {
			if (a[fa[i]]<0) {
				a[fa[i]]=tp[i]^val[i];
			} else {
				mark[fa[i]]|=a[fa[i]]!=(tp[i]^val[i]);
			}
		}
		if (tp[i]==2) {
			a[fa[i]]=tp[i];
		}
		if (mark[i]) {
			mark[fa[i]]=1;
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++) {
		if (fa[i]==i) {
			if (a[i]==2||mark[i]) {
				ans+=siz[i];
			}
		}
	}
	cout<<ans<<"\n";
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0);
	cout.precision(10),cout.setf(ios::fixed);
	
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	int C,T;
	cin>>C>>T;
	while (T--) {
		work();
	}
	
	return 0;
}
