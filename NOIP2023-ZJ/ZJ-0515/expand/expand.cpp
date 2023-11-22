#include<bits/stdc++.h>
using namespace std;
int c,m,n,q,x[101],y[101],x4[101],y4[101],x3,y3;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if(c==1){
		for(int i=1;i<=q;i++)cout<<1;
		return 0;
	}
	if(c==2){
	    for(int i=1;i<=n;i++)cin>>x[i];
	    for(int i=1;i<=m;i++)cin>>y[i];
		if((x[1]>y[1]&&x[1]>y[2])||(y[1]>x[1]&&y[1]>x[2])||(x[1]<y[1]&&x[1]<y[2]&&x[2]<y[2])||(y[1]<x[1]&&y[1]<x[2]&&y[2]<x[2]))cout<<1;
		else cout<<0;
		while(q--){
			for(int i=1;i<=n;i++)x4[i]=x[i];
	    for(int i=1;i<=m;i++)y4[i]=y[i];
			cin>>x3>>y3;
			for(int i=1;i<=x3;i++){
				int x2,y2;
				cin>>x2>>y2;
				x4[x2]=y2;
			}
			for(int i=1;i<=y3;i++){
				int x2,y2;
				cin>>x2>>y2;
				y4[x2]=y2;
			}
			if((x4[1]>y4[1]&&x4[1]>y4[2])||(y4[1]>x4[1]&&y4[1]>x4[2])||(x4[1]<y4[1]&&x4[1]<y4[2]&&x4[2]<y4[2])||(y4[1]<x4[1]&&y4[1]<x4[2]&&y4[2]<x4[2]))cout<<1;
			else cout<<0;
		}
	}
	return 0;
}
