#include<bits/stdc++.h>
using namespace std;
int a[10],b[10];
int a1[10],b1[10];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q,kx,ky;
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=n;i++)a1[i]=a[i];
	for(int i=1;i<=m;i++)b1[i]=b[i];
	if(n==1&&m==1){
		if(a[1]>b[1])cout<<"1";
		else cout<<"0";
	}
	if(n==2&&m==1){
		if(a[1]>b[1]&&a[2]>b[1])cout<<"1";
		else cout<<"0";
	}
	if(n==1&&m==2){
		if(a[1]>b[2]&&a[1]>b[1])cout<<"1";
		else cout<<"0";
	}
	if(n==2&&m==2){
		if(a[1]>b[1]&&a[2]>b[2])cout<<"1";
		else cout<<"0";
	}
	int x,nu;
	for(int i=1;i<=q;i++){
		cin>>kx>>ky;
	for(int i=1;i<=n;i++)a[i]=a1[i];
	for(int i=1;i<=m;i++)b[i]=b1[i];
		for(int j=1;j<=kx;j++){
			cin>>x>>nu;
			a[x]=nu;
		}
		for(int j=1;j<=ky;j++){
			cin>>x>>nu;
			b[x]=nu;
		}
	if(n==1&&m==1){
		if(a[1]>b[1])cout<<"1";
		else cout<<"0";
	}
	if(n==2&&m==1){
		if(a[1]>b[1]&&a[2]>b[1])cout<<"1";
		else cout<<"0";
	}
	if(n==1&&m==2){
		if(a[1]>b[2]&&a[1]>b[1])cout<<"1";
		else cout<<"0";
	}
	if(n==2&&m==2){
		if(a[1]>b[1]&&a[2]>b[2])cout<<"1";
		else cout<<"0";
	}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
