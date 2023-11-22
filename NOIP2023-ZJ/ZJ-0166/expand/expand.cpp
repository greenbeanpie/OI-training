#include<bits/stdc++.h>
using namespace std;
void fileIO(){
	const string probname="expand";
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
int astore[500010],bstore[500010];
int c,n,m,q,a[500010],b[500010];
void solve(){
	if (n==1 && m==1){
		cout<<(a[1]==b[1]? "0":"1");
		return;
	}
	if (n==1 && m==2){
		if (b[1]==a[1] || b[2]==a[1]){
			cout<<"0";
			return;
		}
		if (b[1]>a[1] && b[2]<a[1]){
			cout<<"0";
			return;
		}
		if (b[2]>a[1] && b[1]<a[1]){
			cout<<"0";
			return;
		}
		cout<<"1";
		return;
	}
	if (n==2 && m==1){
		if (a[1]==b[1] || a[2]==b[1]){
			cout<<"0";
			return;
		}
		if (a[1]>b[1] && a[2]<b[1]){
			cout<<"0";
			return;
		}
		if (a[2]>b[1] && a[1]<b[1]){
			cout<<"0";
			return;
		}
		cout<<"1";
		return;
	}
	if (n==2 && m==2){
		if (a[1]<b[1] && a[2]<b[2]){
			cout<<"1";
			return;
		}
		if (a[1]>b[1] && a[2]>b[2]){
			cout<<"1";
			return;
		}
		cout<<"0";
		return;
	}
}
int main(){
	fileIO();fastIO();
	cin>>c>>n>>m>>q;
	for (int i=1;i<=n;i++) cin>>astore[i];
	for (int i=1;i<=m;i++) cin>>bstore[i];
	for (int i=1;i<=n;i++) a[i]=astore[i];
	for (int i=1;i<=m;i++) b[i]=bstore[i];
	solve();
	while (q--){
		for (int i=1;i<=n;i++) a[i]=astore[i];
		for (int i=1;i<=m;i++) b[i]=bstore[i];
		static int kx,ky;
		cin>>kx>>ky;
		while (kx--){
			static int px,vx;
			cin>>px>>vx;
			a[px]=vx;
		}
		while (ky--){
			static int py,vy;
			cin>>py>>vy;
			b[py]=vy;
		}
		solve();
	}
	return 0;
}
