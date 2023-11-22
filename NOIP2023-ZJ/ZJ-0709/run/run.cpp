#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m,k,d;
long long ans=0,f[1010][1010];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	for(int e=1;e<=t;e++){
		cin>>n>>m>>k>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=k;j++) f[i][j]=-18014398505481984;
		}
		f[0][0]=0;
		vector <int> y[1010],z[1010];
		for(int i=1;i<=m;i++){
			int o,p,q;
			cin>>o>>p>>q;
			if (p>k) continue;
			y[o].push_back(p);
			z[o].push_back(q);
		}
		for(int i=1;i<=n;i++){
			f[i][0]=max(f[i][0],f[i-1][0]);
			for(int j=1;j<=min(k,i);j++){
				f[i][0]=max(f[i][0],f[i-1][j]);
				f[i][j]=max(f[i][j],f[i][j-1]-d);
				for(int h=0;h<y[i].size();h++){
					if (j>=y[i][h]) f[i][j]+=z[i][h];
				}
			}
		}
		for(int i=0;i<=n;i++)
			ans=max(ans,f[n][i]);
		cout<<ans<<endl;
	}
}
