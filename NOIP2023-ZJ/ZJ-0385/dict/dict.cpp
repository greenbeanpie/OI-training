#include<bits/stdc++.h>
using namespace std; constexpr int maxn(3010);
int n,m,idm[maxn],idb[maxn];
string sm[maxn],sb[maxn],s; 
vector<string> vec;
signed main(){ freopen("dict.in","r",stdin),freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin >> n >> m;
	for(int i=1;i<=n;i++){ cin >> s;
		sort(s.begin(),s.end()),sm[i]=s;
		sort(s.begin(),s.end(),[&](char a,char b){return a>b;}),sb[i]=s;
		vec.push_back(sm[i]),vec.push_back(sb[i]);
	} sort(vec.begin(),vec.end()),vec.resize(unique(vec.begin(),vec.end())-vec.begin());
	for(int i=1;i<=n;i++){
		idm[i]=lower_bound(vec.begin(),vec.end(),sm[i])-vec.begin();
		idb[i]=lower_bound(vec.begin(),vec.end(),sb[i])-vec.begin();
	}
	for(int i=1;i<=n;i++){ bool fl=true; int id1=idm[i];
		for(int j=1;j<=n;j++) if(i^j){ int id2=idb[j];
			if(id1>=id2){ fl=false; goto loop; }
		} loop:; cout << fl;
	}
	return 0;
}