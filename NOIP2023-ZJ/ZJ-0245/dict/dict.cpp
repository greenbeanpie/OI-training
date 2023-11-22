//I would appreciate it if CCF cound give me 1=
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(0),cout.tie(0)
#define pb push_back
//#define int long long
using namespace std;
int n,m;
string a[3005];
struct node{
	string s;
	int id;
}b[3005];
bool cmp(char a,char b){
	return a>b;
}
bool cmp1(char a,char b){
	return a<b;
}
bool cmp2(node a,node b){
	return a.s<b.s;
}
vector<int> ans;
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	IOS;TIE;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i].s=a[i];
		b[i].id=i;
		sort(b[i].s.begin(),b[i].s.end(),cmp);
	}
	if(n==1){
		cout<<"1\n";
		return 0;
	}
	sort(b+1,b+n+1,cmp2);
	for(int i=1;i<=n;i++){
		sort(a[i].begin(),a[i].end(),cmp1);
		int _1=1;
		if(b[1].id==i) _1=2;
		if(a[i]<b[_1].s) ans.pb(1);
		else ans.pb(0);
	}
	for(auto i:ans) cout<<i;
	cout<<endl;
	return 0;
}
