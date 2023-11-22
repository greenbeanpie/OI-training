#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,m,k,d;
struct node{
	int l,r,w;
}x[100005];
bool vis1[100005];
bool vis[100005];
bool cmp(node p,node q){
	if((double)((double)p.w / (double)(p.r - p.l +1)) > (double)((double)q.w / (double)(q.r - q.l +1))) return 1;
	else if((double)((double)p.w / (double)(p.r - p.l +1)) == (double)((double)q.w / (double)(q.r - q.l +1))){
		return p.r - p.l + 1 <= q.r - q.l + 1;
	}else{
		return 0;
	}
}
void solve(){
	cin >> n >> m >> k >> d;
	memset(vis,0,sizeof vis);
	memset(vis1,0,sizeof vis1);
	for(int i = 1,u,v;i <= m;i++){
		cin >> u >> v >> x[i].w;
		x[i].l = u-v+1;
		x[i].r = u;
	}
	sort(x+1,x+1+m,cmp);
	int ans = 0;
	for(int i = 1;i <= m;i++){
		if(x[i].r - x[i].l + 1 > k) continue;
		if(x[i].w <= (x[i].r - x[i].l + 1) * d) break;
		int sum = 0;
		int mx = 0;
		for(int j = x[i].l;j <= x[i].r;j++){
			vis[j] = 1;
//			cout << j  << "\n";
		}
		for(int j = 1;j <= n;j++){
			if(vis[j]){
				sum++;
				if(sum > mx) mx = sum;
			}else{
				sum=0;
			}
		}
		if(mx > k){
			for(int j = x[i].l;j <= x[i].r;j++){
				if(!vis1[j]) vis[j] = 0;
			}
		}else{
			for(int j = x[i].l;j <= x[i].r;j++){
				vis1[j] = 1;
			}
			ans += x[i].w;
//			cout << x[i].r <<  "\n";
		}
	}
	for(int i = 1;i <= n;i++){
		if(vis1[i]) ans-=d;
	}
	cout << ans << "\n";
}
void solve1(){
	cin >> n >> m >> k >> d;
	memset(vis,0,sizeof vis);
	for(int i = 1,u,v;i <= m;i++){
		cin >> u >> v >> x[i].w;
		x[i].l = u-v+1;
		x[i].r = u;
	}
	sort(x+1,x+1+m,cmp);
	int ans = 0;
	for(int i = 1;i <= m;i++){
		if(x[i].r - x[i].l + 1 > k) continue;
		if(x[i].w <= (x[i].r - x[i].l + 1) * d) break;
		int sum = 0;
		int mx = 0;	
		for(int j = x[i].l;j <= x[i].r;j++){
			vis[j] = 1;
		}
		ans += x[i].w;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i]) ans-=d;
	}
	cout << ans << "\n";
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin >> c >> t;
	if(c >= 1 && c <= 4){
		while(t--){
			solve();
		}
	}else{
		while(t--){
			solve1();
		}
	}
	return 0;	
}
