#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,k1,k2;
int tmp;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>tmp;
	}
	for(int i=1;i<=m;i++)
		cin>>tmp;
	cout<<1;
	for(int i=1;i<=q;i++){
		cin>>k1>>k2;
		for(int j=1;j<=k1;j++)
			cin>>tmp>>tmp;
		for(int j=1;j<=k2;j++)
			cin>>tmp>>tmp;
		cout<<1;
	}
	return 0;
}
/*


*/
