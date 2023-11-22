#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=500005;
int c,n,m,q,mx,mn;
int kx,ky,p,v;
int x[N],y[N],a[N],b[N];
void IO(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
void check(){
	if(n==1 && m==1){
		if(a[1]>b[1])	cout<<1;
		else	cout<<0;
	}
	if(n==1 && m==2){
		if(a[1]>b[1] && a[1]>a[2])	cout<<1;
		else cout<<0;
	}
	if(n==2 && m==1){
		if(a[1]>b[1] && a[2]>b[1])	cout<<1;
		else cout<<0;
	}
	if(n==2 && m==2){
		if(a[2]<b[2] || a[1]<b[1])	cout<<0;
		else cout<<1;
	}
}
signed main(){
	IO("expand");
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>q;
	mn=LONG_LONG_MAX;
	for(int i=1;i<=n;i++){
		cin>>x[i];	
	}
	for(int i=1;i<=m;i++){
		cin>>y[i];	
	}
	while(q--){
		for(int i=1;i<=n;i++)	a[i]=x[i];
		for(int i=1;i<=m;i++)	b[i]=y[i];
		cin>>kx>>ky;
		while(kx--){
			cin>>p>>v;
			a[p]=v;
		}
		while(ky--){
			cin>>p>>v;
			b[p]=v;
		}
		check();
	}
	return 0;
}

