#include<bits/stdc++.h>
using namespace std;
int c,t,n,m;
int a[100050];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
//	if(c==1||c==2){
//		while(t--){
//			char op;
//			int pos1,pos2;
//			int ans=0;
//			int cnt=1;
//			cin>>n>>m;
//			for(int i=1;i<=m;i++){
//			}
//			for(int i=1;i<=n;i++){
//				for(int j=i;j<=n;j++){
//				}
//			}
//		}
//	}
	if(c==3||c==4){
		while(t--){
			char op;
			int pos;
			int ans=0;
			cin>>n>>m;
			for(int i=1;i<=m;i++){
				cin>>op>>pos;
				if(op=='U'){
					a[pos]=3;
				}
				if(op=='T'){
					a[pos]=1;
				}
				if(op=='F'){
					a[pos]=2;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==3){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
