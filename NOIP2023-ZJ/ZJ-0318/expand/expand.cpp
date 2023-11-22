#include<bits/stdc++.h>
using namespace std;
int c,n,m,kx,ky,x,y,q,pa[500005],pb[500005],a[500005],b[500005];
bool solve(){
	if(n==1&&m==1){
		if(a[1]!=b[1]) return true;
		else return false; 
	}else if(n==1&&m==2){
		if((b[1]>a[1]&&b[2]>a[1])||(b[1]<a[1]&&b[2]<a[1])) return true;
		else return false;	
	}else if(n==2&&m==1){
		if((a[1]>b[1]&&a[2]>b[1])||(a[1]<b[1]&&a[2]<b[1])) return true;
		else return false;	
	}else if(n==2&&m==2){
		if((a[1]>b[1]&&a[2]>b[2])||(a[1]<b[1]&&a[2]<b[2])) return true;
		else return false;
	}else{
		int mina=1e9,maxa=-1e9,minb=1e9,maxb=-1e9;
		for(int i=1;i<=n;i++){
			mina=min(mina,a[i]);
			maxa=max(maxa,a[i]);
		}
		for(int i=1;i<=m;i++){
			minb=min(minb,b[i]);
			maxb=max(maxb,b[i]);
		}
		if(mina>maxb||minb>maxa) return true;
		else return false;
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>pa[i];
		a[i]=pa[i];
	}
	for(int i=1;i<=m;i++){
		cin>>pb[i];
		b[i]=pb[i];
	}
	cout<<solve();
	while(q--){
		cin>>kx>>ky;
		for(int i=1;i<=n;i++){
			a[i]=pa[i];
		}
		for(int i=1;i<=m;i++){
			b[i]=pb[i];
		}
		for(int i=1;i<=kx;i++){
			cin>>x>>y;
			a[x]=y;
		}
		for(int i=1;i<=ky;i++){
			cin>>x>>y;
			b[x]=y;
		}
		cout<<solve();
	}
	
	return 0;
}//9:51 choclate 10:14 10pts
