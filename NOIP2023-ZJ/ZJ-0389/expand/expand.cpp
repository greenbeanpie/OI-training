#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[100005],y[100005],a[10005],b[10005];
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int C,n,m,T;
	cin>>C>>n>>m>>T;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=m;i++)cin>>y[i];
	if(C==1){
		if(x[1]!=y[1])cout<<1;
		else cout<<0;
		while(T--){
			for(int i=1;i<=n;i++)a[i]=x[i];
			for(int i=1;i<=m;i++)b[i]=y[i];
			int k1,k2;
			cin>>k1>>k2;
			while(k1--){
				int p,q;
				cin>>p>>q;
				a[p]=q;
			}
			while(k2--){
				int p,q;
				cin>>p>>q;
				b[p]=q;
			}
			if(a[1]!=b[1])cout<<1;
			else cout<<0;
		}
		
	}
	else if(C==2){
		if(x[1]>y[1]&&x[2]>y[2]||x[1]<y[1]&&x[2]<y[2])cout<<1;
		else cout<<0;
		while(T--){
			for(int i=1;i<=n;i++)a[i]=x[i];
			for(int i=1;i<=m;i++)b[i]=y[i];
			int k1,k2;
			cin>>k1>>k2;
			while(k1--){
				int p,q;
				cin>>p>>q;
				a[p]=q;
			}
			while(k2--){
				int p,q;
				cin>>p>>q;
				b[p]=q;
			}
			if(a[1]>b[1]&&a[2]>b[2]||a[1]<b[1]&&a[2]<b[2])cout<<1;
			else cout<<0;
		}
		
	}
	else{
		for(int i=0;i<=T;i++)cout<<1;
	}
	return 0;
}