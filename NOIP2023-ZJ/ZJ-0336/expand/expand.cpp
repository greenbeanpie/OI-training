#include<bits/stdc++.h>
using namespace std;
int a[566666],b[566666],a1[566666][2],b1[566666][2],n,m,c,x,y,k1,k2,p,mm,v,q,t;
bool bi(int x){
	int da=-1,xa=1e9+9,db=-1,xb=1e9+1;
	for(int i=1;i<n;i+=2)
		if(a[i]>a[i+1]){
			if(a[i]>da)da=a[i];
			if(a[i+1]<xa)xa=a[i+1];
		}
		else{
			if(a[i+1]>da)da=a[i+1];
			if(a[i]<xa)xa=a[i];
		}
	for(int i=1;i<m;i+=2)
		if(b[i]>b[i+1]){
			if(b[i]>db)db=b[i];
			if(b[i+1]<xb)xb=b[i+1];
		}
		else{
			if(b[i+1]>db)db=b[i+1];
			if(b[i]<xb)xb=b[i];
		}
	if(x==1)return ((da>db)&&(xa>xb));
	return ((da<db)&&(xa<xb));
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	if((a[1]-b[1])*(a[n]-b[m])<=0)printf("0");
	else if(a[1]>b[1])cout<<bi(1);
	else cout<<bi(0);
	while(q--){
		cin>>k1>>k2;
		for(int i=1;i<=k1;i++){
			cin>>p>>v;
			a1[i][0]=p,a1[i][1]=a[p];a[p]=v;
		}
		for(int i=1;i<=k2;i++){
			cin>>p>>v;
			b1[i][0]=p,b1[i][1]=b[p];b[p]=v;
		}
		if((a[1]-b[1])*(a[n]-b[m])<=0)printf("0");
		else if(a[1]>b[1])cout<<bi(1);
		else cout<<bi(0);
		for(int i=1;i<=k1;i++){
			a[a1[i][0]]=a1[i][1];
		}
		for(int i=1;i<=k2;i++){
			b[b1[i][0]]=b1[i][1];
		}
	}
}
