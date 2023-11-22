#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int a[N+1],b[N+1],ta[N+1],tb[N+1];
signed main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q;
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	if(c==1) {
		cout<<(a[1]!=b[1]?1:0);
		while(q--) {
			memcpy(ta,a,sizeof(a));
			memcpy(tb,b,sizeof(b));
			int x,y;
			cin>>x>>y;
			for(int i=1;i<=x;i++) {
				int p,v;
				cin>>p>>v;
				ta[p]=v;
			}
			for(int i=1;i<=y;i++) {
				int p,v;
				cin>>p>>v;
				tb[p]=v;
			}
			cout<<(ta[1]!=tb[1]?1:0);
		}
		return 0;
	}
	if(c==2) {
		if(a[1]>b[1]&&a[n]>b[m]||a[1]<b[1]&&a[n]<b[m])
			cout<<1;
		else
			cout<<0;
		while(q--) {
		memcpy(ta,a,sizeof(a));
		memcpy(tb,b,sizeof(b));
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=x;i++) {
			int p,v;
			cin>>p>>v;
			ta[p]=v;
		}
		for(int i=1;i<=y;i++) {
			int p,v;
			cin>>p>>v;
			tb[p]=v;
		}
		if(ta[1]>tb[1]&&ta[n]>tb[m]||ta[1]<tb[1]&&ta[n]<tb[m])
			cout<<1;
		else
			cout<<0;
		}
		return 0;
	}
	if(a[1]>b[1]&&a[n]>b[m]||a[1]<b[1]&&a[n]<b[m])
		cout<<1;
	else
		cout<<0;
	while(q--) {
		memcpy(ta,a,sizeof(a));
		memcpy(tb,b,sizeof(b));
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=x;i++) {
			int p,v;
			cin>>p>>v;
			ta[p]=v;
		}
		for(int i=1;i<=y;i++) {
			int p,v;
			cin>>p>>v;
			tb[p]=v;
		}
		if(ta[1]>tb[1]&&ta[n]>tb[m]||ta[1]<tb[1]&&ta[n]<tb[m])
			cout<<1;
		else
			cout<<0;
	}
	return 0;
}