#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileIO(){
	const string probname="run";
	const string suff_in ="in";
	const string suff_out="out";
	const string file_in =probname+"."+suff_in;
	const string file_out=probname+"."+suff_out;
	freopen(file_in.c_str(),"r",stdin);
	freopen(file_out.c_str(),"w",stdout);
}
void fastIO(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
unordered_map<int,vector<pair<int,int>>>chal;
int c,T,n,m,k,d;
int f[1010][1010];
signed main(){
	fileIO();fastIO();
	cin>>c>>T;
	while (T--){
		memset(f,0,sizeof(f));
		cin>>n>>m>>k>>d;
		chal.clear();
		for (int i=1;i<=m;i++){
			static int x,y,v;
			cin>>x>>y>>v;
			chal[x].emplace_back(make_pair(y,v));
		}
		for (int i=1;i<=n;i++){
			if (chal[i].size()){
				sort(chal[i].begin(),chal[i].end());
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=0;j<=min(k,i-1);j++){
				f[i][0]=max(f[i][0],f[i-1][j]);
			}
			int p=0,cnt=0;
			for (int j=1;j<=min(k,i);j++){
				while (p<(int)chal[i].size() && j>=chal[i][p].first){
					cnt+=chal[i][p++].second;
				}
				f[i][j]=f[i-1][j-1]-d+cnt;
			}
		}
		int ans=0;
		for (int i=0;i<=k;i++){
			ans=max(ans,f[n][i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
