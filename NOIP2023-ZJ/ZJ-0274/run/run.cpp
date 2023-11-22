#include<bits/stdc++.h>
using namespace std;
#define int long long
const int o=5e5+5;
int n,m,a[o],T,q,b[o],k,d,l[o],r[o],v[o],ans,t,c[o];
void qwq(int x,int y,int z){
	if (x==n){
		int q=-d*z;
		for (int i=1;i<=m;i++){
			int w=1;
			for (int j=l[i]-r[i]+1;j<=l[i];j++)
				if (!b[j]) {w=0;break;}
			if (w==1) q+=v[i];
		}
		ans=max(ans,q);
		return;
	}
	b[x+1]=0;qwq(x+1,0,z);
	if (y!=k) b[x+1]=1,qwq(x+1,y+1,z+1);
	return; 
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T>>t;
	while (t--){
		cin>>n>>m>>k>>d;
		ans=0;			
		for (int i=1;i<=m;i++)
			cin>>l[i]>>r[i]>>v[i];
		if (T<=2){
			qwq(0,0,0);
			cout<<ans<<"\n";
			continue;
	 	}
	 	int q=0;
	 	for (int i=1;i<=n;i++)
	 		c[i]=0;
	 	for (int i=1;i<=m;i++)
	 		c[l[i]-r[i]+1]++,c[l[i]]--,q+=v[i];
	 	for (int i=1;i<=n;i++){
	 		c[i]+=c[i-1];
	 		if (c[i]>0) q-=d;
	 	}
	 	cout<<q<<"\n";
	}
	return 0;
}