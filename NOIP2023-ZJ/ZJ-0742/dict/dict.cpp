#include<bits/stdc++.h>
#define fr(s) freopen(s".in","r",stdin)
#define fw(s) freopen(s".out","w",stdout)
using namespace std;
const int N=3e3+10,M=3e3+10;
int n,m,len;
int a[N];
string maxn[N],minn[N];
string s;
//bool cmp(int x,int y){
//	return x>y;
//}
inline bool check(int id){
	for(register int i=1;i<=n;++i){
		if(id==i)continue;
		if(minn[id]>=maxn[i])return 0;
	}
	return 1;
}
signed main(){
	fr("dict");
	fw("dict");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(register int i=1;i<=n;++i){
		len=0;
		minn[i]="";
		maxn[i]="";
		cin>>s;
		for(register int j=0;j<m;++j){
			a[++len]=s[j]-'a';
		}
		sort(a+1,a+len+1);
		for(register int j=1;j<=len;++j){
			minn[i]+=(a[j]+'a');
		}
		for(int j=len;j>=1;--j){
			maxn[i]+=(a[j]+'a');
		}
//		sort(a+1,a+len+1,cmp);
//		for(int j=1;j<=len;j++){
//			maxn[i]+=(a[j]+'a');
//		}
	}
	for(register int i=1;i<=n;++i){
		cout<<check(i);
	}
//	cout<<"MINN\n";
//	for(int i=1;i<=n;i++){
//		cout<<minn[i]<<"\n";
//	}
//	cout<<"MAXN\n";
//	for(int i=1;i<=n;i++){
//		cout<<maxn[i]<<"\n";
//	}
	return 0;
}
