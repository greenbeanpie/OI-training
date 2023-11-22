#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;int kx,ky;
int c,n,m,q,x[N],y[N],ans[N],modi[N][3];
int xc[N],yc[N],nc,mc,mx,mn,g[N],h[N],tg,th,nxtg[N],nxth[N],ndg[N],ndh[N],totg,toth;
bool ok(){
	if(g[1]>=h[1])return 0;
	int minn=1;
	nxtg[totg=1]=1;
	ndg[totg]=g[1]+1;
	for(int i=2;i<=tg;i++)
		if(g[i]<=g[minn]){
			nxtg[++totg]=i;
			ndg[totg]=g[i]+1;
			minn=i;
		}else ndg[totg]=max(ndg[totg],g[i]+1);
	int maxn=1;
	nxth[toth=1]=1;
	ndh[toth]=h[1]-1;
	for(int i=2;i<=th;i++)
		if(h[i]>=h[maxn]){
			nxth[++toth]=i;
			ndh[toth]=h[i]-1;
			maxn=i;
		}else ndh[toth]=min(ndh[toth],h[i]-1);
	int nx=1,ny=1;
	while(nx<totg||ny<toth){
		if(nx<totg){
			if(h[nxth[ny]]>=ndg[nx]){
				nx++;
				continue;
			}
		}if(ny<toth){
			if(g[nxtg[nx]]<=ndh[ny]){
				ny++;
				continue;
			}
		}return 0;
	}
	return 1;
}
int check(){
	if(x[1]==y[1])return 0;
	if(x[1]<y[1]){
		nc=n;mc=m;
		for(int i=1;i<=n;i++)
			xc[i]=x[i];
		for(int i=1;i<=m;i++)
			yc[i]=y[i];
	}else{
		nc=m;mc=n;
		for(int i=1;i<=m;i++)
			xc[i]=y[i];
		for(int i=1;i<=n;i++)
			yc[i]=x[i];
	}
	mn=1;
	for(int i=1;i<=nc;i++)
		if(xc[i]<xc[mn])mn=i;
	mx=1;
	for(int i=1;i<=mc;i++)
		if(yc[i]>yc[mx])mx=i;
	tg=th=0;
	for(int i=1;i<=mn;i++)
		g[++tg]=xc[i];
	for(int i=1;i<=mx;i++)
		h[++th]=yc[i];
	if(!ok())return 0;
	tg=th=0;
	for(int i=nc;i>=mn;i--)
		g[++tg]=xc[i];
	for(int i=mc;i>=mx;i--)
		h[++th]=yc[i];
	if(!ok())return 0;
	return 1;
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=m;i++)
		cin>>y[i];
	ans[1]=check();
	for(int i=2;i<=q+1;i++){
		cin>>kx>>ky;
		for(int j=1;j<=kx;j++){
			cin>>modi[j][0]>>modi[j][1];
			modi[j][2]=x[modi[j][0]];
			x[modi[j][0]]=modi[j][1];
		}for(int j=kx+1;j<=kx+ky;j++){
			cin>>modi[j][0]>>modi[j][1];
			modi[j][2]=y[modi[j][0]];
			y[modi[j][0]]=modi[j][1];
		}
		ans[i]=check();
		for(int j=1;j<=kx;j++)
			x[modi[j][0]]=modi[j][2];
		for(int j=kx+1;j<=kx+ky;j++)
			y[modi[j][0]]=modi[j][2];
	}
	for(int i=1;i<=q+1;i++)
		cout<<ans[i];
	cout<<"\n";
	return 0;
}