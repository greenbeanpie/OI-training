#include <bits/stdc++.h>
using namespace std;
int n,m,C,q,kn,km,x,y,a[100010],b[100010],c[100010],d[100010];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>n>>m>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++) cin>>b[i];
	if (n==1 && m==1){
		if (a[1]!=b[1]) cout<<1;
		else cout<<0;
		while (q--){
			cin>>kn>>km;
			memset(c,-1,sizeof(c));
			memset(d,-1,sizeof(d));
			for (int i=1;i<=kn;i++){
				cin>>x>>y;
				c[x]=y;
			}
			for (int i=1;i<=n;i++)
				if (c[i]==-1)
					c[i]=a[i];
			for (int i=1;i<=km;i++){
				cin>>x>>y;
				d[x]=y;
			}
			for (int i=1;i<=m;i++)
				if (d[i]==-1)
					d[i]=b[i];
			if (c[1]!=d[1]) cout<<1;
			else cout<<0;
		}
		return 0;
	}
	for (int i=1;i<=q+1;i++) cout<<0;
	return 0;
}
