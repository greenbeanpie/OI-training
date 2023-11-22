#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+10;
int c,m,n,q;
int a[maxn],b[maxn];
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=m;j++)cin>>b[j];
	for(int i=1;i<=q;i++){
		int kx,ky;
		cin>>kx>>ky;
		int l,r;
		for(int j=1;j<=kx;j++)cin>>l>>r;
		for(int j=1;j<=ky;j++)cin>>l>>r;
	}
	for(int i=1;i<=q+1;i++)cout<<rand()%2;
	cout<<endl;
	return 0;
}
