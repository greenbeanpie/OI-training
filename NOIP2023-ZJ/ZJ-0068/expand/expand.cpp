#include<bits/stdc++.h>
using namespace std;
int const N=5e5+10;
int c,n,m,q,a[N],b[N],aa[N],bb[N],f[20][N],g[20][N],lg[N];
#define qry(l,r) (max(f[lg[(r)-(l)+1]][(l)],f[lg[(r)-(l)+1]][(r)-(1<<lg[(r)-(l)+1])+1]))
#define qryy(l,r) (min(g[lg[(r)-(l)+1]][(l)],g[lg[(r)-(l)+1]][(r)-(1<<lg[(r)-(l)+1])+1]))
void sol(){
	vector<int>vec1,vec2;
	for (int i=1;i<=n;++i)
		if ((i==1) || (a[i]!=a[i-1])) vec1.push_back(a[i]);
	for (int i=1;i<=m;++i)
		if ((i==1) || (b[i]!=b[i-1])) vec2.push_back(b[i]);
	if (vec1[0]>vec2[0]) swap(vec1,vec2);
	if (vec1[0]==vec2[0]) return cout<<"0",void();
	int nn=vec1.size(),mm=vec2.size(),j=-1;
	for (int i=0;i<nn;++i) f[0][i]=vec1[i],g[0][i]=vec1[i];
	for (int j=1;j<20;++j)
		for (int i=0;i+(1<<j)-1<nn;++i)
			f[j][i]=max(f[j-1][i],f[j-1][i+(1<<(j-1))]),
			g[j][i]=min(g[j-1][i],g[j-1][i+(1<<(j-1))]);
	for (int i=0;i<mm;++i){
//		while (j+1<nn && vec2[i]>vec1[j+1]) ++j;
//		while (j>=0 && vec2[i]<=vec1[j]) --j;
		if (j+1<nn && vec2[i]>vec1[j+1]){
			int l=j+1,r=nn-1,ans=j;
			while (l<=r){
				int mid=(l+r)>>1;
				if (qry(j+1,mid)<vec2[i]) l=(ans=mid)+1;
				else r=mid-1;
			}
			j=ans;
		}
		if (j>=0 && vec2[i]<=vec1[j]){
			int l=0,r=j,ans=-1;
			while (l<=r){
				int mid=(l+r)>>1;
				if (qryy(mid,j)<vec2[i]) l=(ans=mid)+1;
				else r=mid-1;
			}
			j=ans;
		}
		if (j==-1) return cout<<"0",void();
	}
	if (j+1==nn) cout<<"1";else cout<<"0";
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	for (int i=2;i<N;++i) lg[i]=lg[i>>1]+1;
	cin>>c>>n>>m>>q;
	for (int i=1;i<=n;++i) cin>>a[i],aa[i]=a[i];
	for (int i=1;i<=m;++i) cin>>b[i],bb[i]=b[i];
	sol();
	while (q--){
		int kx,ky;cin>>kx>>ky;
		for (int i=1;i<=n;++i) a[i]=aa[i];
		for (int i=1;i<=m;++i) b[i]=bb[i];
		while (kx--){
			int x,y;cin>>x>>y;
			a[x]=y;
		}
		while (ky--){
			int x,y;cin>>x>>y;
			b[x]=y;
		}
		sol();
	}
	cout<<'\n';
	return 0;
}