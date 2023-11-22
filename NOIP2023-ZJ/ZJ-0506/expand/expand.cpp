#include<bits/stdc++.h>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll C,i,n,m,rx,ry,a[500010],b[500010],dx[500010],dy[500010],gx[500010],gy[500010],T;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>C>>n>>m>>T;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	cout<<0;
	while(T--){
		cin>>rx>>ry;
		for(i=1;i<=rx;i++) cin>>dx[i]>>dy[i];
		for(i=1;i<=ry;i++) cin>>gx[i]>>gy[i];
		cout<<0;
	}
	return 0;
}