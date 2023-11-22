#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
int a[N];
int b[N];
int ta[N],tb[N];
int n,m,q;

int mina=2e9,minb=2e9;
int maxa=0,maxb=0;

void init(){
	int C;
	cin>>C>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=m;j++)
		cin>>b[j];
	for(int i=1;i<=n;i++)
		ta[i]=a[i];
	for(int j=1;j<=m;j++)
		tb[j]=b[j];
	
	return;
}

int pos[N];



bool check(){
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=m;i++)
//		cout<<b[i]<<' ';
//	cout<<endl;
	if( (a[1]-b[1]) *  (a[n]-b[m])<=0) return false;
	
	mina=minb=2e9;
	maxa=maxb=0;
	for(int i=1;i<=n;i++){
		mina=min(mina,a[i]);
		maxa=max(maxa,a[i]);
	}
	for(int i=1;i<=m;i++){
		minb=min(minb,b[i]);
		maxb=max(maxb,b[i]);
	}
	
	if(a[1]>b[1] && a[n]>b[m]){
		if(maxa<maxb) return false;
	}
	else{
		if(maxa>maxb) return false;
	}
	return true;
}

void solve(){
	if(check()) cout<<1;
	else cout<<0;
	while(q--){
		for(int i=1;i<=n;i++){
			a[i]=ta[i];
		}
		for(int i=1;i<=m;i++)
			b[i]=tb[i];
		int kx,ky;
		cin>>kx>>ky;
		for(int i=1;i<=kx;i++){
			int p,v;
			cin>>p>>v;
			a[p]=v;
		}
		for(int i=1;i<=ky;i++){
			int p,v;
			cin>>p>>v;
			b[p]=v;
		}
		if(check()) cout<<1;
		else cout<<0;
	}
	return;
}

signed main(){
	
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	solve();
	return 0;
}
