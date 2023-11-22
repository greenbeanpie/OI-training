#include<bits/stdc++.h>
using namespace std;
const int N=106;
int c,n,m,q;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	if(n==1&&m==1){
		int x[N],y[N];
		cin>>x[1]>>y[1];
		if(x[1]>y[1])cout<<1;
		else cout<<0;
		while(q--){
			int k1,k2;
			cin>>k1>>k2;
			int a,b;
			for(int i=1;i<=k1;i++){
				cin>>a>>b;
				x[a]=b;
			}
			for(int i=1;i<=k2;i++){
				cin>>a>>b;
				y[a]=b;
			}
			if(x[1]>y[1])cout<<1;
			else cout<<0;
		}
		return 0;
	}
	else if(n==1&&m==2){
		int x[N],y[N];
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int j=1;j<=m;j++)cin>>y[j];
		int flag=1;
		if(x[1]>y[1]&&x[1]>y[2])cout<<1;
		else cout<<0;
		while(q--){
			int k1,k2;
			cin>>k1>>k2;
			int a,b;
			for(int i=1;i<=k1;i++){
				cin>>a>>b;
				x[a]=b;
			}
			for(int i=1;i<=k2;i++){
				cin>>a>>b;
				y[a]=b;
			}
			if(x[1]>y[1]&&x[1]>y[2])cout<<1;
			else cout<<0;
		}
	}
	else if(n==2&&m==1){
		int x[N],y[N];
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int j=1;j<=m;j++)cin>>y[j];
		int flag=1;
		if(x[1]>y[1]&&x[2]>y[1])cout<<1;
		else cout<<0;
		while(q--){
			int k1,k2;
			cin>>k1>>k2;
			int a,b;
			for(int i=1;i<=k1;i++){
				cin>>a>>b;
				x[a]=b;
			}
			for(int i=1;i<=k2;i++){
				cin>>a>>b;
				y[a]=b;
			}
			if(x[1]>y[1]&&x[2]>y[1])cout<<1;
			else cout<<0;
		}
	}
	else if(n==2&&m==2){
		int x[N],y[N];
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int j=1;j<=m;j++)cin>>y[j];
		int flag=1;
		if(x[1]>y[1]&&x[2]>y[2])cout<<1;
		else cout<<0;
		while(q--){
			int k1,k2;
			cin>>k1>>k2;
			int a,b;
			for(int i=1;i<=k1;i++){
				cin>>a>>b;
				x[a]=b;
			}
			for(int i=1;i<=k2;i++){
				cin>>a>>b;
				y[a]=b;
			}
			if(x[1]>y[1]&&x[2]>y[2])cout<<1;
			else cout<<0;
		}
	}
	else{
		int x[N],y[N];
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int j=1;j<=m;j++)cin>>y[j];
		int flag=1;
		if(x[1]>y[1]&&x[2]>y[2])cout<<1;
		else cout<<0;
		while(q--){
			int k1,k2;
			cin>>k1>>k2;
			int a,b;
			for(int i=1;i<=k1;i++){
				cin>>a>>b;
				x[a]=b;
			}
			for(int i=1;i<=k2;i++){
				cin>>a>>b;
				y[a]=b;
			}
			if(x[1]>y[1]&&x[2]>y[2])cout<<1;
			else cout<<0;
		}
	}
	return 0;
}
