#include<bits/stdc++.h>
using namespace std;
string ans;
int c,n,m,q;
int x[500005],y[500005],a[500005],b[500005];
char cmp(int a[],int b[]){
	if(a[1]==b[1]||a[n]==b[m]) return '0';
	if(a[1]>b[1]) {
		if(a[n]<b[m]) return '0';
		else{
			bool k=0;
			for(int i=2;i<=n-1;i++){
				k=0;
				for(int j=1;j<=m;j++){
					if(a[i]>b[j]) {
						k=1;
						break;	
					}
				}
				if(!k) return '0';
			}
			return '1';
		}
	}
	if(a[1]<b[1]) {
		if(a[n]>b[m]) return '0';
		else{
			bool kk=0;
			for(int i=2;i<=n-1;i++){
				kk=0;
				for(int j=1;j<=m;j++){
					if(a[i]<b[j]) {
						kk=1;
						break;
					}
				}
				if(!kk) return '0';
			}
			return '1';
		}
	}
}
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=m;i++) cin>>y[i];
	ans+=cmp(x,y);
	while(q--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++) a[i]=x[i];
		for(int i=1;i<=m;i++) b[i]=y[i];
		int kx=0,ky=0;
		cin>>kx>>ky;
		for(int i=1;i<=kx;i++) {
			int px,vx;
			cin>>px>>vx;
			a[px]=vx;
		}
		for(int i=1;i<=ky;i++) {
			int py,vy;
			cin>>py>>vy;
			b[py]=vy;
		}
		ans+=cmp(a,b);
	}
	cout<<ans;
	return 0;
}
