#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,k,a[205],b[205],nx,ny,x,y,ca[205],cb[205];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=m;++i) cin>>b[i];
	if(m==1&&n==1){
		if(a[1]!=b[1])
		{
			if(a[1]==0&&b[1]==0) cout<<0;
			else cout<<1;
		} 
		else cout<<0;
		for(int Q=1;Q<=q;Q++){
			for(int j=1;j<=n;j++) ca[j]=a[j];
			for(int j=1;j<=m;j++) cb[j]=b[j];
			cin>>nx>>ny;
			for(int i=1;i<=nx;i++){
				cin>>x>>y;
				ca[x]=y;
			}
			for(int i=1;i<=ny;i++){
				cin>>x>>y;
				cb[x]=y;
			}
			if(ca[1]!=cb[1]){
				if(a[1]==0&&b[1]==0) cout<<0;
				else cout<<1;
			} 
			else cout<<0;
			
		}
	}
	return 0;
}
