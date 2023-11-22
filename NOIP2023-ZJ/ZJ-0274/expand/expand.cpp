#include<bits/stdc++.h>
using namespace std;
const int o=5e5+5;
int n,m,a[o],T,q,b[o];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T>>n>>m>>q;
	for (int i=1;i<=n;i++)
	  cin>>a[i];
	for (int i=1;i<=m;i++)
		cin>>b[i];
	if (T<=2){
		if (a[1]-b[1]>0&&a[n]-b[m]>0||a[1]-b[1]<0&&a[n]-b[m]<0) cout<<1;
		else cout<<0;
		while (q--){
			int kx,ky,x,y;
			cin>>kx>>ky;
			for (int i=1;i<=kx;i++){
				cin>>x>>y;
				a[x]=y;
			}
			for (int i=1;i<=ky;i++){
				cin>>x>>y;
				b[x]=y;	
			}
			if (a[1]-b[1]>0&&a[n]-b[m]>0||a[1]-b[1]<0&&a[n]-b[m]<0) cout<<1;
			else cout<<0;
		}
		return 0;
	}
	if (a[1]-b[1]>0&&a[n]-b[m]>0||a[1]-b[1]<0&&a[n]-b[m]<0) cout<<1;
		else cout<<0;
	while (q--){
		int kx,ky,x,y;
		cin>>kx>>ky;
		for (int i=1;i<=kx;i++){
			cin>>x>>y;
			a[x]=y;
		}
		for (int i=1;i<=ky;i++){
			cin>>x>>y;
			b[x]=y;	
		}
		if (a[1]-b[1]>0&&a[n]-b[m]>0||a[1]-b[1]<0&&a[n]-b[m]<0) cout<<1;
		else cout<<0;
	}
	return 0;
}