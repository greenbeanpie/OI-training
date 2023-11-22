#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define fi first
#define se second
using namespace std;
template<typename T_>void operator+=(vector<T_>&x,const T_&y){x.push_back(y);}
template<typename T_>void Max(T_&x,const T_&y){if(y>x)x=y;}
const int N=1e3+7;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int C,T,n,m,k,d;
void work(){
	cin>>n>>m>>k>>d;
	if(C==17||C==18){
		ll ans=0;
		unordered_map<int,pair<ll,ll>>a;
		for(int i=1,x,y,z;i<=m;i++){
			cin>>x>>y>>z;
			if(y>k)continue;
			a[x]={y,z};
		}
		for(auto i:a){
			if(i.se.fi*d<i.se.se)
				ans+=i.se.se-i.se.fi*d;
		}
		cout<<ans<<'\n';
		return;
	}
	unordered_map<int,vector<pair<int,ll>>>a;
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		if(y>k)continue;
		a[x]+={y,z};
	}
	for(auto&i:a)sort(all(i.se));
	vector<vector<ll>>f(n+1+7,vector<ll>(min(n+1,k+1)+7,-inf));
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		auto*v=&a[i];
		int p=0;
		ll w=0;
		f[i][0]=f[i-1][0];
		for(int j=1;j<=min(n,k);j++){
			while(p<(int)v->size()&&j>=v->at(p).fi)
				w+=v->at(p).se,p++;
			f[i][j]=f[i-1][j-1]-d+w;
			Max(f[i][0],f[i-1][j]);
		}
	}
	ll ans=0;
	for(int i=0;i<=min(n,k);i++)Max(ans,f[n][i]);
	cout<<ans<<'\n';
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--)work();
	return 0;
}
