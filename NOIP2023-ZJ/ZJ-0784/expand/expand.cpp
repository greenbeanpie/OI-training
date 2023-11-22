#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	
	int c,n,m,q;
	cin>>c>>n>>m>>q;
	if(c==1){
		long long a[500],b[500];
		int f[68]={0};
		for(int i=0;i<n;i++)scanf("%lld",&a[i]);
		for(int i=0;i<m;i++)scanf("%lld",&b[i]);
		if(a[0]!=b[0])f[0]=1;
		for(int i=1;i<=q;i++){
			int xx,yy;
			cin>>xx>>yy;
			for(int ii=0;ii<xx;ii++){
				int px,vx;
				cin>>px>>vx;
				a[px-1]=vx;
			}
			for(int ii=0;ii<yy;ii++){
				int py,vy;
				cin>>py>>vy;
				b[py-1]=vy;
			}
			if(a[0]!=b[0])f[i]=1;
		}
		for(int i=0;i<=q;i++){
			cout<<f[i];
		}
	}
	else if(c==2){
		long long a[500],b[500];
		int f[68]={0};
		for(int i=0;i<n;i++)scanf("%lld",&a[i]);
		for(int i=0;i<m;i++)scanf("%lld",&b[i]);
		if((a[0]>b[0]&&a[1]>b[1])||(a[0]<b[0]&&a[1]<b[1]))f[0]=1;
		for(int i=1;i<=q;i++){
			int xx,yy;
			cin>>xx>>yy;
			for(int ii=0;ii<xx;ii++){
				int px,vx;
				cin>>px>>vx;
				a[px-1]=vx;
			}
			for(int ii=0;ii<yy;ii++){
				int py,vy;
				cin>>py>>vy;
				b[py-1]=vy;
			}
			if((a[0]>b[0]&&a[1]>b[1])||(a[0]<b[0]&&a[1]<b[1]))f[i]=1;
		}
		for(int i=0;i<=q;i++){
			cout<<f[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
