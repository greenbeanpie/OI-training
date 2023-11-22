#include<bits/stdc++.h>
using namespace std;
const int N=100005;
char a[N];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t,n,m;
	char opt;
	int id,ans=0,x,y;
	cin>>c>>t;
	// if(c<=2){
	// 	cin>>n>>m;
	// 	for(int i=0;i<=n;i++){
				
	// 	}
	// }
	if(c>=3&&c<=4){
		while(t--){
			ans=0;
			cin>>n>>m;
			for(int i=1;i<=m;i++){
				cin>>opt>>id;
				a[id]=opt;
			}
			for(int i=1;i<=n;i++){
				if(a[i]=='U') ans++;
			}
			cout<<ans<<endl;
		}
	}
	if(c>=5&&c<=6){
		while(t--){
			ans=0;
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				a[i]='T';
			}
			for(int i=1;i<=m;i++){
				cin>>opt;
				if(opt=='+'){
					cin>>x>>y;
					a[x]=a[y];
				}else{
					cin>>id;
					a[id]=opt;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]=='U') ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
