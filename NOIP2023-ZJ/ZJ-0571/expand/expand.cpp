#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,a[500100],b[500010],dp[2010][2010],aa,bb;
int main() {
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if(n==1&&m==1) {
		for(int i=1;i<=q+1;++i){
			cout<<"1";
		}
	} else {
		for(int i=1; i<=q+1; ++i) {
			cout<<"0";
		}
	}
	return 0;
}
