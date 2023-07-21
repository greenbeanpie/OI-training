#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#define int long long
#define endl "\n"
int fa[200];
int find(int u){
	if(fa[u]==u) return u;
	return fa[u]=find(fa[u]);
}
void merge(int u,int v){
	u=find(u);
	v=find(v);
	fa[u]=fa[v];
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("UVA10129.in", "r", stdin);
	freopen("UVA10129.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		string str;
		int in[200];
		bool vis[200]={0};
		for(int i=0;i<200;i++){
			fa[i]=i;
		}
		fill(in,in+200,0);
		for(int i=1;i<=n;i++){
			cin >> str;
			in[str[0]]++;
			in[str[str.size()-1]]--;
			merge(str[str.size()-1],str[0]);
			vis[str[0]]=vis[str[str.size()-1]]=true;
		}
		bool flag=true;
		int cnt=0;
		for(int i='a';i<='z';i++){
			if(vis[i]&&find(fa[i])==i){
				cnt++;
			}
			if((in[i]!=0&&in[i]!=1&&in[i]!=-1)){
				flag=false;
				break;
			}
		}
		if(flag&&cnt==1){
			cout << "Ordering is possible." << endl;
		}
		else{
			cout << "The door cannot be opened." << endl;
		}
	}
	return 0;
}