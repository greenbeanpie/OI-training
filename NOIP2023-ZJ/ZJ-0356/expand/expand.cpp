#include <bits/stdc++.h>
using namespace std;
#define maxn 500005
int c,n,m,q;
int a[maxn],b[maxn];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if(n==1 && m==1){
		cin>>a[1];cin>>b[1];
		if(a[1]!=b[1])cout<<1;
		else cout<<0;
		for(int i=1;i<=q;i++){
			int u,v;
			cin>>u>>v;
			for(int j=1;j<=u;j++){
				int x,y;
				cin>>x>>y;
				a[x]=y;
			}
			for(int j=1;j<=v;j++){
				int x,y;
				cin>>x>>y;
				b[x]=y;
			}
			if(a[1]!=b[1])cout<<1;
			else cout<<0;
		}
	}
	if(n==2 && m==2){
		cin>>a[1]>>a[2];cin>>b[1]>>b[2];
		if((a[1]>b[1] && a[2]>b[2]) ||(a[1]<b[1] && a[2]<b[2]))cout<<1;
		else cout<<0;
		for(int i=1;i<=q;i++){
			int u,v;
			cin>>u>>v;
			for(int j=1;j<=u;j++){
				int x,y;
				cin>>x>>y;
				a[x]=y;
			}
			for(int j=1;j<=v;j++){
				int x,y;
				cin>>x>>y;
				b[x]=y;
			}
			if((a[1]>b[1] && a[2]>b[2]) ||(a[1]<b[1] && a[2]<b[2]))cout<<1;
			else cout<<0;
		}
	}
	if(n==1 && m==2){
		cin>>a[1];cin>>b[1]>>b[2];
		if((a[1]>b[1] && a[1]>b[2]) ||(a[1]<b[1] && a[1]<b[2]))cout<<1;
		else cout<<0;
		for(int i=1;i<=q;i++){
			int u,v;
			cin>>u>>v;
			for(int j=1;j<=u;j++){
				int x,y;
				cin>>x>>y;
				a[x]=y;
			}
			for(int j=1;j<=v;j++){
				int x,y;
				cin>>x>>y;
				b[x]=y;
			}
			if((a[1]>b[1] && a[1]>b[2]) ||(a[1]<b[1] && a[1]<b[2]))cout<<1;
			else cout<<0;
		}
	}
	if(n==2 && m==1){
		cin>>a[1]>>a[2];cin>>b[1];
		if((a[1]>b[1] && a[2]>b[1]) ||(a[1]<b[1] && a[2]<b[1]))cout<<1;
		else cout<<0;
		for(int i=1;i<=q;i++){
			int u,v;
			cin>>u>>v;
			for(int j=1;j<=u;j++){
				int x,y;
				cin>>x>>y;
				a[x]=y;
			}
			for(int j=1;j<=v;j++){
				int x,y;
				cin>>x>>y;
				b[x]=y;
			}
			if((a[1]>b[1] && a[2]>b[1]) ||(a[1]<b[1] && a[2]<b[1]))cout<<1;
			else cout<<0;
		}
	}
}

