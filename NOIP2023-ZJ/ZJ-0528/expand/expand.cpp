#include<bits/stdc++.h>
using namespace std;
int n,m,id,q,a[500001],b[500001],x,y,qx,qy,px,vx,aq[500001],bq[500001],py,vy;

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>id>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	if(id==1){
		if(b[1]-a[1]) cout<<"1";
		else cout<<"0";
		for(int i=1;i<=q;i++){
			for(int i=1;i<=n;i++) aq[i]=a[i];
			for(int i=1;i<=m;i++) bq[i]=b[i];
			cin>>qx>>qy;
			for(int i=1;i<=qx;i++){
				cin>>px>>vx;
				a[px]=vx;
			}
			for(int i=1;i<=qy;i++){
				cin>>py>>vy;
				a[px]=vy;
			}
			if(a[1]-b[1]) cout<<"1";
			else cout<<"0";
		}
		cout<<endl;
		return 0;
	}
	if(id==2){
		if(n==1) a[2]=a[1];
		if(m==1) b[2]=b[1];
		if((a[1]-b[1])*(a[2]-b[2])>0) cout<<"1";
		else cout<<"0";
		for(int i=1;i<=q;i++){
			for(int i=1;i<=n;i++) aq[i]=a[i];
			for(int i=1;i<=m;i++) bq[i]=b[i];
			cin>>qx>>qy;
			for(int i=1;i<=qx;i++){
				cin>>px>>vx;
				a[px]=vx;
			}
			for(int i=1;i<=qy;i++){
				cin>>py>>vy;
				a[px]=vy;
			}
			if((a[1]-b[1])*(a[2]-b[2])>0) cout<<"1";
			else cout<<"0";
		}
		cout<<endl;
		return 0;
	}
	if(id>=3){
		if((a[1]-b[1])*(a[n]-b[m])>0) cout<<"1";
		else cout<<"0";
		for(int i=1;i<=q;i++){
			for(int i=1;i<=n;i++) aq[i]=a[i];
			for(int i=1;i<=m;i++) bq[i]=b[i];
			cin>>qx>>qy;
			for(int i=1;i<=qx;i++){
				cin>>px>>vx;
				a[px]=vx;
			}
			for(int i=1;i<=qy;i++){
				cin>>py>>vy;
				a[px]=vy;
			}
			if((a[1]-b[n])*(a[2]-b[m])>0) cout<<"1";
			else cout<<"0";
		}
		cout<<endl;
		return 0;
	}
	return 0;
}
