#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int C,n,m,q,tot;
int a[N],b[N];
int t[N*2];

void sol(){
	if(1ll*(a[n]-b[m])*(a[1]-b[1])<0){
		cout<<0;
		return ;
	}
	cout<<1;
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>C>>n>>m>>q;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)cin>>b[i];
	sol();
	for(int i=1,kx,ky;i<=q;++i){
		cin>>kx>>ky;
		int x,y;
		for(int j=1;j<=kx;++j){
			cin>>x>>y;
			a[x]=y;
		}
		for(int j=1;j<=ky;++j){
			cin>>x>>y;
			b[x]=y;
		}
		sol();
	}
	return 0;
}