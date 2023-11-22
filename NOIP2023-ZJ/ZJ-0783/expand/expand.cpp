#include<bits/stdc++.h>
using namespace std;
int aa[5];
int bb[5];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q;
	cin>>c>>n>>m>>q;
	if(c==1){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0;
		}
		if(x!=y){
			cout<<1;
		}
		for(int i=1;i<=q;i++){
			int kx,ky;
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++){
				int px;
				cin>>px;
				x=px;
			}
			for(int i=1;i<=ky;i++){
				int py;
				cin>>py;
				y=py;
			}
			if(x==y){
				cout<<0;
			}
			if(x!=y){
				cout<<1;
			}
		}
	}
//	if(c==2){
//		for(int i=1;i<=n;i++){
//			cin>>a[i];
//		}
//		for(int i=1;i<=m;i++){
//			cin>>b[i];
//		}
//		
//	}
	cout<<flush;
	fclose(stdin);
	fclose(stdout);
	return 0;
}