#include<bits/stdc++.h>
using namespace std;
int ans[114];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);

	int c,n,m,q,tag=1;
	cin>>c>>n>>m>>q;
	int nums;
	for(int i=1;i<=n;i++){
		cin>>nums;
	}
	for(int j=1;j<=m;j++){
		cin>>nums;
	}
	ans[tag++]=nums%2;
	while(q--){
		int a,b;
		cin>>a>>b;
		while(a--){
			int m,n;
			cin>>m>>n;
		}
		while(b--){
			int m,n;
			cin>>m>>n;
		}
		ans[tag++]=(m+n)%2;
	}
	for(int i=1;i<tag;i++)cout<<ans[i];
	return 0;
}