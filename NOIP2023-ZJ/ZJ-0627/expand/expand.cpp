#include <bits/stdc++.h>
#define int long long 
using namespace std;
int c,n,m,q;
signed main(){
	freopen("expand.in","r",stdin);
  	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>q;
	if(c==1){
		int x,y;cin>>x>>y;
		if(x!=y) cout<<1;
		else cout<<0;
		while(q--){
			int k1,k2,a,b;cin>>k1>>k2;
			while(k1--){cin>>a>>b;x=b;}
			while(k2--){cin>>a>>b;y=b;}
			if(x!=y) cout<<1;
			else cout<<0;
		}
	}
	if(c==2){
		if(n==m&&n==2){
			int x1,x2,y1,y2;cin>>x1>>x2>>y1>>y2;
			if(x1>y1&&x2>y2) cout<<1;
			else if(x1<y1&&x2<y2) cout<<1;
			else cout<<0;
			while(q--){
				int k1,k2,a,b;cin>>k1>>k2;
				while(k1--){
					cin>>a>>b;
					if(a==1) x1=b;
					else x2=b;
				}
				while(k2--){
					cin>>a>>b;
					if(a==1) y1=b;
					else y2=b;
				}
				if(x1>y1&&x2>y2) cout<<1;
				else cout<<0;
			}
		}
		if(n==1&&m==2){
			int x,y1,y2;cin>>x>>y1>>y2;
			if(x>y1&&x>y2) cout<<1;
			else if(x<y1&&x<y2) cout<<1;
			else cout<<0;
			while(q--){
				int k1,k2,a,b;cin>>k1>>k2;
				while(k1--){cin>>a>>b;x=b;}
				while(k2--){
					cin>>a>>b;
					if(a==1) y1=b;
					else y2=b;
				}
				if(x>y1&&x>y2) cout<<1;
				else if(x<y1&&x<y2) cout<<1;
				else cout<<0;
			}
		}
		if(n==2&&m==1){
			int x1,x2,y;cin>>x1>>x2>>y;
			if(y>x1&&y>x2) cout<<1;
			else if(y<x1&&y<x2) cout<<1;
			else cout<<0;
			while(q--){
				int k1,k2,a,b;cin>>k1>>k2;
				while(k1--){
					cin>>a>>b;
					if(a==1) x1=b;
					else x2=b;
				}
				while(k2--){cin>>a>>b;y=b;}
				if(y>x1&&y>x2) cout<<1;
				else if(y<x1&&y<x2) cout<<1;
				else cout<<0;
			}
		}
	}
	return 0;
}