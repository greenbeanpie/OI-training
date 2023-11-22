#include<bits/stdc++.h>
using namespace std;
long long c,n,m,q;
long long x[500005]={0},y[500005]={0};
long long xz[500005],yz[500005];
bool check(){
	long long i,j;
	if(x[1]<=y[1] || x[n]<=y[m]){
		//cout<<"&&";
		return 0;
	}
	for(j=1;j<=m;j++){
		while(x[i]<=y[j] && i<=n) i++;
		if(i>j || i>n){
			//cout<<"||";
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	memset(x,0,sizeof(x));
	memset(xz,0,sizeof(xz));
	memset(y,0,sizeof(y));
	memset(yz,0,sizeof(yz));
	cin>>c>>n>>m>>q;
	long long i,j;
	for(i=1;i<=n;i++){
		cin>>xz[i];
		x[i]=xz[i];
	}	
	for(i=1;i<=m;i++){
		cin>>yz[i];
		y[i]=yz[i];
	}
	if(check()==1){
		cout<<1;
	}
	else{
		for(i=1;i<=max(n,m);i++){
			long long t;
			t=x[i];
			x[i]=y[i];
			y[i]=t;
		}
		long long e=n;
		n=m;
		m=e;
		//swap(n,m);
		cout<<check();
		//swap(n,m);
		e=n;
		n=m;
		m=e;
	}
	for(i=1;i<=q;i++){
		for(j=1;j<=n;j++){
			x[j]=xz[j];
		}
		for(j=1;j<=m;j++){
			y[j]=yz[j];
		}
		long long qx,qy;cin>>qx>>qy;
		for(j=1;j<=qx;j++){
			long long u,v;cin>>u>>v;
			x[u]=v;
		}
		for(j=1;j<=qy;j++){
			long long u,v;cin>>u>>v;
			y[u]=v;
		}
		if(check()==1){
			cout<<1;
		}
		else{
			for(j=1;j<=max(n,m);j++){
				long long t;
				t=x[j];
				x[j]=y[j];
				y[j]=t;
			}
			long long e=n;
			n=m;
			m=e;
			//swap(n,m);
			cout<<check();
			//swap(n,m);
			e=n;
			n=m;
			m=e;
		}
	}
	return 0;
}
