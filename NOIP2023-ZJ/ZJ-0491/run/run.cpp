#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	ll x,y,v;
};
ll n,m,k,d;
Node cha[100010];
bool sx(Node x,Node y){
	return x.x < y.x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		for(ll i = 1;i <= m;i++){
			cin>>cha[i].x>>cha[i].y>>cha[i].v;
		}
		sort(cha + 1,cha + m + 1,sx);
		if((c == 17) || (c == 18)){//ypa!
			ll ans = 0;
			for(ll i = 1;i <= m;i++){
				if(cha[i].y <= k){
					if(cha[i].x - cha[i].y == cha[i - 1].x){
						if(cha[i - 1].y + cha[i].y <= k){
							ans += max(0ll,cha[i].v - cha[i].y * d);
						}
					}
					else{
						ans += max(0ll,cha[i].v - cha[i].y * d);
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}