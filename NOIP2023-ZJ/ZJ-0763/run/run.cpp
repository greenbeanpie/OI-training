#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+10;
long long f[N],x[N],y[N],v[N],be=0x3f3f3f3f;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t,n,m,k,d;
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof x);
		memset(y,0,sizeof y);
		memset(v,0,sizeof v);
		memset(f,0,sizeof f);
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++)
			cin>>x[i]>>y[i]>>v[i];
		for(int i=1;i<=n;i++){
			bool flag=1;
			for(int j=1;j<=m;j++){
				if(i>x[j]&&k>=y[j]&&k>=i-be)
					if(f[i]-d*y[j]+v[j]>f[i]){
						f[i]=f[i]-d*y[j]+v[j];
						flag=0;
						be=min(i-y[j],be);
					}
			}
			if(flag){
				f[i]=f[i-1];
				be=0x3f3f3f3f;
			}
		}
		cout<<f[n]<<"\n";
	}
	return 0;
}
