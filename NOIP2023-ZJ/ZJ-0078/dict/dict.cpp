#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x; scanf("%lld",&x); return x;
}
ll maxx(ll a,ll b){return a>b?a:b;}
ll minn(ll a,ll b){return a<b?a:b;}
ll n,m; char str[3005][3005];
ll mx[3005], mn[3005], hv[26], tt[26], all=26, cnt;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(), m=read();
	for(ll i=1;i<=n;i++){
		scanf("%s",(str[i]+1));
		mn[i]=26;
		for(ll j=1;j<=m;j++){
			if(str[i][j]-'a'>=mx[i]) mx[i]=str[i][j]-'a';
			if(str[i][j]-'a'<=mn[i]) mn[i]=str[i][j]-'a';
		}
		if(mn[i] == mx[i]) hv[mn[i]] ++;
		
		if(mx[i] < all){
			all = mx[i]; cnt = 1;
		}else if(mx[i] == all) ++cnt;
	}
	for(ll i=1;i<=n;i++){
		if(mn[i]<all || (mn[i]==all && cnt==1)) printf("1");
		else printf("0");
	}
	return 0;
}