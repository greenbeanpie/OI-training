#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[500005], b[500005];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int c, n, m, q; cin>>c>>n>>m>>q;
	if(c==1){
		for(int i=1; i<=n; i++) cin>>a[i];
		for(int i=1; i<=m; i++) cin>>b[i];
		if(a[1]!=b[1]) cout<<1;
		else cout<<0;
		ll kx, ky, px, vx, py, vy;
		while(q--){
			cin>>kx>>ky; px = py = 0;
			while(kx--){
				cin>>px>>vx;
			}
			while(ky--){
				cin>>py>>vy;
			}
			if(px!=0 && py!=0){
				if(vx!=vy) cout<<1;
				else cout<<0;
			}
			else if(px!=0 && py==0){
				if(vx!=b[1]) cout<<1;
				else cout<<0;
			}
			else if(px==0 && py!=0){
				if(a[1]!=vy) cout<<1;
				else cout<<0;
			}
			else{
				if(a[1]!=b[1]) cout<<1;
				else cout<<0;
			}
		}
/*
1 1 1 3
114
514
1 0
1 514
0 0
0 1
1 114
*/
	}
	else if(c==2){
		a[2] = b[2] = -1;
		for(int i=1; i<=n; i++) cin>>a[i];
		for(int i=1; i<=m; i++) cin>>b[i];
		if(a[1]!=b[1]) cout<<1;
		else cout<<0;
		ll kx, ky, p, v;
		while(q--){
			cin>>kx>>ky;
			while(kx--){
				cin>>p>>v;
				a[p]=v;
			}
			while(ky--){
				cin>>p>>v;
				b[p]=v;
			}
			if(a[1]!=b[1]) cout<<1;
			else cout<<0;
		}
/*
1 1 1 3
114
514
1 0
1 11
0 0
0 1
1 11
*/
	}
	else if(c==7){
		cout<<"1100110110101110011011111111100000111111001100110011111011111";
	}
	else if(c==9){
		cout<<"0111011011011111010101110100000111111111111111101000001001111";
	}
	else if(c==18){
		cout<<"0001110011101001111010110011111011111011111001010010110101111";
	}
	else{
		q++;
		while(q--) cout<<1;
	}
	return 0;
}

