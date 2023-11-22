//WA
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{
	ll to,next,w;
};
Edge edge[100010];
ll h[100010],tot;
ll n,m;
char a[100010];
ll fa[100010][2];
ll rd[100010];
bool have[100010];
void addEdge(ll u,ll v,ll w){
	edge[++tot] = (Edge){v,h[u],w};
	h[u] = tot;
}
void dfs1(ll x){
	have[x] = true;
	for(ll i = h[x];i > 0;i = edge[i].next){
		if(a[edge[i].to] != 'A'){
			continue;
		}
		if(edge[i].w == 0){
			a[edge[i].to] = a[x];
		}
		else if(edge[i].w == 1){
			if(a[x] == 'T'){
				a[edge[i].to] = 'F';
			}
			else if(a[x] == 'F'){
				a[edge[i].to] = 'T';
			}
			else if(a[x] == 'U'){
				a[edge[i].to] = 'U';
			}
		}
		dfs1(edge[i].to);
	}
}
bool dfs2(ll x){
	bool H;
	for(ll i = h[x];i > 0;i = edge[i].next){
		if(a[edge[i].to] == 'A'){
			H = false;
		}
		else{
			H = true;
		}
		if(edge[i].w == 0){
			if(H){
				if(a[edge[i].to] != a[x]){
					return false;
				}
			}
			else{
				a[edge[i].to] = a[x];
			}
		}
		else if(edge[i].w == 1){
			if(a[x] == 'T'){
				if(H){
					if(a[edge[i].to] != 'F'){
						return false;
					}
				}
				else{
					a[edge[i].to] = 'F';
				}
			}
			else if(a[x] == 'F'){
				if(H){
					if(a[edge[i].to] != 'T'){
						return false;
					}
				}
				else{
					a[edge[i].to] = 'T';
				}
			}
		}
		bool d = true;
		if(h){
			have[edge[i].to] = true;
			d = dfs2(edge[i].to);
		}
		if(!d){
			return false;
		}
	}
	return true;
}
void cl(ll x){
	a[x] = 'A';
	have[x] = false;
	for(ll i = h[x];i > 0;i = edge[i].next){
		if(have[edge[i].to]){
			cl(edge[i].to);
		}
	}
}
bool dfs3(ll x){
	for(ll i = h[x];i > 0;i = edge[i].next){
		if(edge[i].w == 0){
			if(have[edge[i].to]){
				if(a[edge[i].to] != a[x]){
					return false;
				}
			}
			else{
				a[edge[i].to] = a[x];
			}
		}
		else if(edge[i].w == 1){
			if(a[x] == 'T'){
				if(have[edge[i].to]){
					if(a[edge[i].to] != 'F'){
						return false;
					}
				}
				else{
					a[edge[i].to] = 'F';
				}
			}
			else if(a[x] == 'F'){
				if(have[edge[i].to]){
					if(a[edge[i].to] != 'T'){
						return false;
					}
				}
				else{
					a[edge[i].to] = 'T';
				}
			}
		}
		bool d = true;
		if(!have[edge[i].to]){
			have[edge[i].to] = true;
			d = dfs3(edge[i].to);
		}
		if(!d){
			return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(ll i = 1;i <= n;i++){
			a[i] = 'A';
			fa[i][0] = fa[i][1] = 0;
		}
		if((c == 3) || (c == 4)){
			char ch;
			ll x;
			for(ll i = 1;i <= m;i++){
				cin>>ch>>x;
				a[x] = ch;
			}
			ll ans = 0;
			for(ll i = 1;i <= n;i++){
				if(a[i] == 'U'){
					++ans;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		for(ll i = 1;i <= m;i++){
			char ch;
			cin>>ch;
			ll x,y;
			switch(ch){
				case 'T':
				case 'F':
				case 'U':
					cin>>x;
					fa[x][0] = fa[x][1] = 0;
					a[x] = ch;
					break;
				case '+':
					cin>>x>>y;
					a[x] = 'A';
					fa[x][1] = 0;
					fa[x][0] = y;
					break;
				case '-':
					cin>>x>>y;
					a[x] = 'A';
					fa[x][0] = 0;
					fa[x][1] = y;
					break;
			}
		}
		memset(h,0,sizeof(h));
		tot = 0;
		for(ll i = 1;i <= n;i++){
			if(fa[i][0] != 0){
				addEdge(fa[i][0],i,0);
				++rd[i];
			}
			if(fa[i][1] != 0){
				addEdge(fa[i][1],i,1);
				++rd[i];
			}
		}
		for(ll i = 1;i <= n;i++){
			if(a[i] != 'A'){
				dfs1(i);
			}
		}
		for(ll i = 1;i <= n;i++){
			if((a[i] == 'A') && (rd[i] == 0)){
				memset(have,false,sizeof(have));
				have[i] = true;
				a[i] = 'T';
				if(dfs2(i)){
					continue;
				}
				cl(i);
				have[i] = true;
				a[i] = 'F';
				if(dfs2(i)){
					continue;
				}
				cl(i);
				a[i] = 'U';
				dfs1(i);
			}
		}
		for(ll i = 1;i <= n;i++){
			if(a[i] == 'A'){
				memset(have,false,sizeof(have));
				have[i] = true;
				a[i] = 'T';
				if(dfs3(i)){
					continue;
				}
				cl(i);
				have[i] = true;
				a[i] = 'F';
				if(dfs3(i)){
					continue;
				}
				cl(i);
				a[i] = 'U';
				dfs1(i);
			}
		}
		ll ans = 0;
		for(ll i = 1;i <= n;i++){
			if(a[i] == 'U'){
				++ans;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}