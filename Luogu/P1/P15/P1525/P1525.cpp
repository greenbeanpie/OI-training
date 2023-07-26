#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define endl "\n"

struct node{
	int u,v,val;
}a[100005];

bool cmp(node a,node b){
	return a.val>b.val;
}

int fa[100005],ene[100005];

int find(int u){
	if(fa[u]==u)return u;
	return fa[u]=find(fa[u]);
}
void merge(int u,int v){
	fa[find(u)]=find(v);
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("P1525.in","r",stdin);
	freopen("P1525.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		cin >> a[i].u >> a[i].v >> a[i].val;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(find(a[i].u)==find(a[i].v)){
			cout << a[i].val;
			return 0;
		}
		else{
			if(!ene[a[i].u]){
				ene[a[i].u]=a[i].v;
			}
			else{
				merge(ene[a[i].u],a[i].v);
			}
			if(!ene[a[i].v]){
				ene[a[i].v]=a[i].u;
			}
			else{
				merge(ene[a[i].v],a[i].u);
			}
		}
	}
	cout << 0 << endl;
	return 0;
}