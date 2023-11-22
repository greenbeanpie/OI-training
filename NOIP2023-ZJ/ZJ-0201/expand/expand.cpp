#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,n,m,q,x[N],y[N];
char ans[N];
namespace Subtask1{
	int kx,ky,px[N],vx[N],py[N],vy[N];
	inline bool chk(){
		if(x[1]>y[1]&&x[n]>y[m])
			return 1;
		if(x[1]<y[1]&&x[n]<y[m])
			return 1;
		return 0;
	}
	inline void solve(){
		ans[0]=chk()?'1':'0';
		for(int k=1;k<=q;k++){
			int kx,ky;
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++){
				cin>>px[i]>>vx[i];
				swap(x[px[i]],vx[i]);
			}
			for(int i=1;i<=ky;i++){
				cin>>py[i]>>vy[i];
				swap(y[py[i]],vy[i]);
			}
			ans[k]=chk()?'1':'0';
			for(int i=1;i<=kx;i++)
				swap(x[px[i]],vx[i]);
			for(int i=1;i<=ky;i++)
				swap(y[py[i]],vy[i]);
		}
		cout<<ans;
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=m;i++) cin>>y[i];
	if(c<=7) Subtask1::solve();
	return 0;
}