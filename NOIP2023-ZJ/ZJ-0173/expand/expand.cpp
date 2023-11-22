#include<bits/stdc++.h>
#define siz(x) int((x).size())
#define all(x) std::begin(x),std::end(x)
#define fi first
#define se second
using namespace std;
using loli=long long;
using pii=pair<int,int>;
using tiii=tuple<int,int,int>;
constexpr int N=5e5+7;
int C,n,m,q,k1,k2,a[N],b[N];
multiset<int>s1,s2;
pii d1[N],d2[N];
//bool check1(){
////	if()
//	return *s1.rbegin()<*s2.begin()||*s2.rbegin()<*s1.begin();
//}
//bool check2(){
////	return true;
//	for(int i:s1)if(s2.find(i)!=s2.end())return false;
//	for(int i:s2)if(s1.find(i)!=s1.end())return false;
//	return true;
//}
//bool solve(){return check1()&&check2();}
bool check1(){
	// let a[i]<b[i]
//	if(a[1]>=b[1]||a[n]>=b[n])return false;
	if(a[1]>=b[1])return false;
	if(n>=40000&&m>=40000)return false;
	bool f[n+2][m+2]={};
	f[1][1]=true;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(f[i][j]){
//		if(a[i]<b[j]&&a[i+1]<b[j])f[i+1][j]=true;
//		if(a[i]<b[j]&&a[i]<b[j+1])f[i][j+1]=true;
//		if(a[i+1]<b[j+1])f[i+1][j+1]=true;
		if(a[i+1]<b[j])f[i+1][j]=true;
		if(a[i]<b[j+1])f[i][j+1]=true;
		if(a[i+1]<b[j+1])f[i+1][j+1]=true;
	}
	return f[n][m];
}
bool check2(){
	// let a[i]>b[i]
//	if(a[1]<=b[1]||a[n]<=b[n])return false;
	if(a[1]<=b[1])return false;
	if(n>=40000&&m>=40000)return false;
	bool f[n+2][m+2]={};
	f[1][1]=true;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(f[i][j]){
//		cout<<i<<'~'<<j<<'\n';
//		if(a[i]>b[j]&&a[i+1]>b[j])f[i+1][j]=true;
//		if(a[i]>b[j]&&a[i]>b[j+1])f[i][j+1]=true;
//		if(a[i+1]>b[j+1])f[i+1][j+1]=true;
//		assert(a[i]>b[j]);
		if(a[i+1]>b[j])f[i+1][j]=true;
		if(a[i]>b[j+1])f[i][j+1]=true;
		if(a[i+1]>b[j+1])f[i+1][j+1]=true;
	}
//	cout<<"\n------------\n";
//	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
//		cout<<f[i][j]<<" \n"[j==m];
//	cout<<"------------\n";
	return f[n][m];
}
bool solve(){return check1()||check2();}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>C>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	cout<<solve();
//		cout<<check1()<<' '<<check2()<<'\n';
//	cerr<<"star rail\n";
	while(q--){
//		cout<<"\nyyz\n";
//		cerr<<"d "<<q<<'\n';
//		auto t1=s1,t2=s2;
		cin>>k1>>k2;
//		cerr<<"upper \n";
		for(int i=1;i<=k1;i++){
			cin>>d1[i].fi>>d1[i].se;
//			s1.insert(d1[i].se);
//			s1.erase(s1.find(a[d1[i].fi]));
			swap(a[d1[i].fi],d1[i].se);
		}
		for(int i=1;i<=k2;i++){
			cin>>d2[i].fi>>d2[i].se;
//			s2.insert(d2[i].se);
//			s2.erase(s2.find(b[d2[i].fi]));
			swap(b[d2[i].fi],d2[i].se);
		}
//		for(int i=1;i<=n;i++)
//			cout<<a[i]<<' ';
//		cout<<'\n';
//		for(int i=1;i<=m;i++)
//			cout<<b[i]<<' ';
//		cout<<'\n';
		cout<<solve();
//		cout<<check1()<<' '<<check2()<<'\n';
//		for(int i:s1)cout<<i<<' ';
//		cout<<'\n';
//		cout<<"===========\n";
//		for(int i:s2)cout<<i<<' ';
//		cout<<'\n';
//		cout<<"===========\n";
		for(int i=1;i<=k1;i++){
//			s1.insert(d1[i].se);
//			s1.erase(s1.find(a[d1[i].fi]));
			a[d1[i].fi]=d1[i].se;
		}
		for(int i=1;i<=k2;i++){
//			s2.insert(d2[i].se);
//			s2.erase(s2.find(b[d2[i].fi]));
			b[d2[i].fi]=d2[i].se;
		}
//		return 0;
//		cerr<<"solve \n";
//		cout<<solve();
//		cerr<<"back \n";
//		s1=t1,s2=t2;
	}
	return 0;
}
