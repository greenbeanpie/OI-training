#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int C;
int n,m,tot;
int f[N*2+10];
int a[N*2+10];

int cg(const int &x) {
	if(x==1)return 0;
	if(x==-1)return 0;
	if(x==0)return 1;
	if(x==-2)return 2;
	if(x==2)return 2;
	return -x;
}

int find(const int &x) {
	if(x==f[x])return x;
	if(x==-f[x])return 2;
	if(x<0)return cg(find(cg(x)));
	return f[x]=find(f[x]);
}

void mg(const int &x,const int &y) {
	int fa=find(x);
	if(fa>0)f[fa]=y>0?find(y):cg(find(cg(y)));
	else f[-fa]=y>0?cg(find(y)):find(cg(y));
}

void sol() {
	char ch;
	int ans=0;
	cin>>n>>m;
	tot=n+2;
	for(int i=1; i<=n+5; ++i)a[i]=i+2;
	for(int i=1; i<=n+m+5; ++i)f[i]=i;
	for(int i=1,x,y; i<=m; ++i) {
		cin>>ch;
//		cout<<i<<">>>"<<ch<<">>>";
		if(ch=='+') {
			cin>>x>>y;
			if(x==y)continue;
			a[x]=++tot;
			mg(tot,a[y]);
		} else if(ch=='-') {
			cin>>x>>y;
			a[x]=++tot;
			mg(tot,-a[y]);
		} else {
			cin>>x;
			a[x]=++tot;
			if(ch=='T') {
				f[tot]=1;
			} else if(ch=='F') {
				f[tot]=0;
			} else {
				f[tot]=2;
			}
		}
//		for(int i=0; i<=tot; ++i)cout<<f[i]<<' ';
//		cout<<endl;
//		for(int i=1; i<=n; ++i)cout<<find(a[i])<<' ';
//		cout<<endl;
	}
	
//	for(int i=0; i<=tot; ++i)cout<<f[i]<<' ';
//	cout<<endl;
//	for(int i=1; i<=n; ++i)cout<<find(a[i])<<' ';
//	cout<<endl;
	
	for(int i=1; i<=n; ++i) {
		if(find(a[i])==-i-2)f[i+2]=2;
		else f[i+2]=f[a[i]];
	}
	
//	for(int i=0; i<=tot; ++i)cout<<f[i]<<' ';
//	cout<<endl;
//	for(int i=1; i<=n; ++i)cout<<find(a[i])<<' ';
//	cout<<endl;

	for(int i=1; i<=n; ++i) {
		if(find(a[i])==2)++ans;
	}
	cout<<ans<<endl;
}

int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	int t;
	cin>>C>>t;
	while(t--) {
		sol();
	}
	return 0;
}