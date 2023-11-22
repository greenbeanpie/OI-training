#include<bits/stdc++.h>
using namespace std;
int F[202000],val[202000],vis[202000],sz[202000],isval[202000];
char isc[202000];
set<int> S[202000];
inline int find(int x) {
	if(F[x]==x)return x;
	int fa=find(F[x]);
	val[x]^=val[F[x]];
	return F[x]=fa;
}
int main() {
	int c,t;
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	// T,F,U san ge dian
	// chu zhi dian
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		for(int i=1; i<=2*n; ++i)
			F[i]=i,isc[i]=0,val[i]=vis[i]=sz[i]=isval[i]=0,S[i].clear();
		for(int i=1;i<=n;++i)
			F[i+n]=i;
		for(int i=1; i<=m; ++i) {
			char v;int x,y;
			cin>>v;
			if(v=='T'||v=='F'||v=='U') {
				cin>>x;
				isc[x]=v;
				F[x+n]=x;
			} else if(v=='+') {
				cin>>x>>y;
				if(isc[y]!=0) {
					F[x+n]=x;
					isc[x]=isc[y];
				} else {
					isc[x]=0;
					F[x+n]=find(y+n);
					val[x+n]=val[y+n];
				}
			} else if(v=='-') {
				cin>>x>>y;
				if(isc[y]!=0) {
					F[x+n]=x;
					isc[x]=(isc[y]=='U')?'U':((isc[y]=='T')?'F':'T');
				} else {
					isc[x]=0;
					F[x+n]=find(y+n);
					val[x+n]=val[y+n]^1;
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;++i)
			if(isc[i]=='U')
				isval[find(i)]=isval[find(i+n)]=1;
		for(int i=1;i<=n;++i){
			int x=find(i),y=find(i+n);
		//	cout<<x<<' '<<y<<' '<<val[i]<<' '<<val[i+n]<<endl;
			if(x!=y){
				F[x]=y,val[x]=val[i]^val[i+n];
				isval[y]|=isval[x];
			}else if(val[i]!=val[i+n]){
				isval[find(i)]=1;
			}
		}
		for(int i=1;i<=n;++i)
			sz[find(i)]++;
		for(int i=1;i<=2*n;++i)
			if(find(i)==i&&isval[i])
				sum+=sz[i];
		cout<<sum<<'\n';
	}
}