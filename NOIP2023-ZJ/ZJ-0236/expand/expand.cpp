#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x7fffffff
const int maxn=5e5+5;
int opt,n,m,q;
int x[maxn],y[maxn];
int a[maxn],b[maxn];
string ans="";
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
    cin.tie(0),cout.tie(0);
	cin>>opt>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		a[i]=x[i];
	}
	for(int i=1;i<=m;i++){
		cin>>y[i];
		b[i]=y[i];
	}
	if(opt==1){
		if(x[1]!=y[1]) ans+='1';
		else ans+='0';
		while(q--){
			int kx,ky,p,v;
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++){
				cin>>p>>v;
				x[p]=v;
			}
			for(int i=1;i<=ky;i++){
				cin>>p>>v;
				y[p]=v;
			}
			if(x[1]!=y[1]) ans+='1';
			else ans+='0';
			for(int i=1;i<=n;i++){
				x[i]=a[i];
			}
			for(int i=1;i<=m;i++){
				y[i]=b[i];
			}
		}
		cout<<ans<<endl;
	}else if(opt==2){
		if(n==1&&m==2){
			if((y[1]-x[1])*(y[2]-x[1])>0) ans+='1';
			else ans+='0';
			while(q--){
				int kx,ky,p,v;
				cin>>kx>>ky;
				for(int i=1;i<=kx;i++){
					cin>>p>>v;
					x[p]=v;
				}
				for(int i=1;i<=ky;i++){
					cin>>p>>v;
					y[p]=v;
				}
				if((y[1]-x[1])*(y[2]-x[1])>0) ans+='1';
				else ans+='0';
				for(int i=1;i<=n;i++){
					x[i]=a[i];
				}
				for(int i=1;i<=m;i++){
					y[i]=b[i];
				}
			}
			cout<<ans<<endl;
		}else if(n==2&&m==1){
			if((y[1]-x[1])*(y[1]-x[2])>0) ans+='1';
			else ans+='0';
			while(q--){
				int kx,ky,p,v;
				cin>>kx>>ky;
				for(int i=1;i<=kx;i++){
					cin>>p>>v;
					x[p]=v;
				}
				for(int i=1;i<=ky;i++){
					cin>>p>>v;
					y[p]=v;
				}
				if((y[1]-x[1])*(y[1]-x[2])>0) ans+='1';
				else ans+='0';
				for(int i=1;i<=n;i++){
					x[i]=a[i];
				}
				for(int i=1;i<=m;i++){
					y[i]=b[i];
				}
			}
			cout<<ans<<endl;
		}else{
			if((y[1]-x[1])*(y[2]-x[2])>0) ans+='1';
			else ans+='0';
			while(q--){
				int kx,ky,p,v;
				cin>>kx>>ky;
				for(int i=1;i<=kx;i++){
					cin>>p>>v;
					x[p]=v;
				}
				for(int i=1;i<=ky;i++){
					cin>>p>>v;
					y[p]=v;
				}
				if((y[1]-x[1])*(y[2]-x[2])>0) ans+='1';
				else ans+='0';
				for(int i=1;i<=n;i++){
					x[i]=a[i];
				}
				for(int i=1;i<=m;i++){
					y[i]=b[i];
				}
			}
			cout<<ans<<endl;
		}
	}
    return 0;
}