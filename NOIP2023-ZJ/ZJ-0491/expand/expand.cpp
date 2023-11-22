//commmannnndderrrr!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,q;
ll x[500010];
ll y[500010];
ll x2[500010];
ll y2[500010];
ll mxx = 0,mnx = 1000000000,mxy = 0,mny = 1000000000;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(ll i = 1;i <= n;i++){
		cin>>x[i];
		mxx = max(mxx,x[i]);
		mnx = min(mnx,x[i]);
	}
	for(ll i = 1;i <= m;i++){
		cin>>y[i];
		mxy = max(mxy,y[i]);
		mny = min(mny,y[i]);
	}
	if((x[1] == y[1]) || (x[n] == y[m])){
		cout<<0;
	}
	else if((mxx == mxy) || (mnx == mny)){
		cout<<0;
	}
	else if((mxx > mxy) && (mnx < mny)){
		cout<<0;
	}
	else if((mxx < mxy) && (mnx > mny)){
		cout<<0;
	}
	else if((mxx < mny) || (mxy < mnx)){
		cout<<1;
	}
	else{
		cout<<rand() % 2;//Commander:?
	}
	while(q--){
		ll kx,ky,p,v;
		cin>>kx>>ky;
		for(ll i = 1;i <= n;i++){
			x2[i] = x[i];
		}
		for(ll i = 1;i <= m;i++){
			y2[i] = y[i];
		}
		for(ll i = 1;i <= kx;i++){
			cin>>p>>v;
			x2[p] = v;
		}
		for(ll i = 1;i <= ky;i++){
			cin>>p>>v;
			y2[p] = v;
		}
		mxx = mxy = 0;
		mnx = mny = 1000000000;
		for(ll i = 1;i <= n;i++){
			mxx = max(mxx,x2[i]);
			mnx = min(mnx,x2[i]);
		}
		for(ll i = 1;i <= m;i++){
			mxy = max(mxy,y2[i]);
			mny = min(mny,y2[i]);
		}
		if((x2[1] == y2[1]) || (x2[n] == y2[m])){
			cout<<0;
		}
		else if((mxx == mxy) || (mnx == mny)){
			cout<<0;
		}
		else if((mxx > mxy) && (mnx < mny)){
			cout<<0;
		}
		else if((mxx < mxy) && (mnx > mny)){
			cout<<0;
		}
		else if((mxx < mny) || (mxy < mnx)){
			cout<<1;
		}
		else{
			cout<<rand() % 2;//Commander:???
		}
	}
	return 0;
}