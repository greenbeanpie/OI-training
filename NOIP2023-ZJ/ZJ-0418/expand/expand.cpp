#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int c,n,m,q;
int ox[maxn],oy[maxn];
int x[maxn],y[maxn];
int kx,ky,p,v;
int solve1(){
	if((x[1]-y[1])*(x[n]-y[m])<=0){
		return 0;
	}
	return 1;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>ox[i];
		x[i]=ox[i];
	}
	for(int i=1;i<=m;i++){
		cin>>oy[i];
		y[i]=oy[i];
	}
	if(c<=100){
		cout<<solve1();
	}
	while(q--){
		cin>>kx>>ky;
		for(int i=1;i<=n;i++){
			x[i]=ox[i];
		}
		for(int i=1;i<=m;i++){
			y[i]=oy[i];
		}
		for(int i=1;i<=kx;i++){
			cin>>p>>v;
			x[p]=v;
		}
		for(int i=1;i<=ky;i++){
			cin>>p>>v;
			y[p]=v;
		}
		if(c<=100){
			cout<<solve1();
		}
	} 
	return 0;
}
