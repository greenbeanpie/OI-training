#include<bits/stdc++.h>
using namespace std;
int c,t;
char bol[100010];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c==3||c==4){
		while(t--){
			int ans=0;
			int n,m,tmp;
			char v;
			cin>>n>>m;
			for(int i=1;i<=m;i++){
				cin>>v>>tmp;
				bol[tmp]=v;
			}
			for(int i=1;i<=n;i++){
				if(bol[i]=='U') ans++;
			}
			cout<<ans<<endl;
		}
	}
}