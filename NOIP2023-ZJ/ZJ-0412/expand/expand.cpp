#include<bits/stdc++.h>
using namespace std;
long long c,n,m,q,a[500001],b[500001];
long long aa[500001],bb[500001];
bool flag=0;
void dfs(long long x,long long y,long long fh){
	if((a[x]-b[y])*fh<=0) return;
	if(x==n&&y==m){
		flag=1;
		return;
	}
	if(x<n) dfs(x+1,y,fh);
	if(flag) return;
	if(y<m) dfs(x,y+1,fh);
	if(flag) return;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(long long i=1;i<=n;i++) cin>>a[i],aa[i]=a[i];
	for(long long i=1;i<=m;i++) cin>>b[i],bb[i]=b[i];
//	if(c<=4){
		if((a[1]-b[1])*(a[n]-b[m])<=0)
			cout<<0;
		else{
			flag=0;
			dfs(1,1,a[1]-b[1]);
			if(flag) cout<<1;
			else cout<<0;
		}
		while(q--){
			long long kx,ky,x,y;
			cin>>kx>>ky;
			for(int i=1;i<=n;i++) a[i]=aa[i],b[i]=bb[i];
			for(long long i=1;i<=kx;i++){
				cin>>x>>y;
				a[x]=y;
			}
			for(long long i=1;i<=ky;i++){
				cin>>x>>y;
				b[x]=y;
			}
			if((a[1]-b[1])*(a[n]-b[m])<0){
				cout<<0;
				continue;
			}
			else{
				flag=0;
				dfs(1,1,a[1]-b[1]);
				if(flag) cout<<1;
				else cout<<0;
			}
		}
//	}
	return 0;
}
