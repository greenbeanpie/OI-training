#include<bits/stdc++.h>
using namespace std;
constexpr int N=3000;
char ch[N+10],c[N+10][N+10],b[N+10];
struct _{
	int cnt[26],id;
	bool operator<(const _ &ob)const{
		int i;
		for(i=25;i>=0;--i) if(cnt[i]!=ob.cnt[i]) return cnt[i]<ob.cnt[i];
		return 0;
	}
}a[N+10];
int ans[N+10];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int i,j;
	for(i=1;i<=n;++i){
		cin>>ch+1;
		for(j=1;j<=m;++j) ++a[i].cnt[ch[j]-'a'];
		a[i].id=i;
	}
	if(n==1){
		cout<<"1\n";
		return 0;
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;++i){
		int ctop=0;
		for(j=25;j>=0;--j) for(int k=0;k<a[i].cnt[j];++k) c[i][++ctop]='a'+j;
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j) b[j]=c[i][j];
		reverse(b+1,b+1+m);
		int id=1;
		if(i==1) id=2;
		for(j=1;j<=m;++j){
			if(b[j]!=c[id][j]) break;
		}
		if(j<=m&&b[j]<c[id][j]) ans[a[i].id]=1;
	}
	for(i=1;i<=n;++i) cout<<ans[i];
	cout<<'\n';
	return 0;
}
