#include<bits/stdc++.h>
using namespace std;
int c,n,m,_,nn,mm;
int x[510000],y[510000];
int xx[510000],yy[510000];
int xxx[510000],yyy[510000];
int mx1[510000],ps1[510000],mx2[510000],mn1[510000],ps2[510000],mn2[510000];
bool solve(){
	mx1[1]=x[1],ps1[1]=1;
	for(int i=2;i<=n;i++){
		mx1[i]=max(mx1[i-1],x[i]);
		if(mx1[i]==mx1[i-1])ps1[i]=ps1[i-1];
		else ps1[i]=i;
	}
	mx2[1]=y[1];
	for(int i=2;i<=m;i++)mx2[i]=max(mx2[i-1],y[i]);
	mn1[1]=x[1];
	for(int i=2;i<=n;i++)mn1[i]=min(mn1[i-1],x[i]);
	mn2[1]=y[1],ps2[1]=1;
	for(int i=2;i<=m;i++){
		mn2[i]=min(mn2[i-1],y[i]);
		if(mn2[i]==mn2[i-1])ps2[i]=ps2[i-1];
		else ps2[i]=i;
	}
	if(mx1[n]<=mx2[m])return 0;
	if(mn1[n]<=mn2[m])return 0;
	int ii=ps1[n],jj=ps2[m],iii=ii,jjj=jj;
	while(ii>1&&jj>1){
		assert(x[ii]>mx2[jj]&&mn1[ii]>y[jj]);
		if(mx1[ii-1]>mx2[jj]){
			ii=ps1[ii-1];
			continue;
		}
		if(mn1[ii]>mn2[jj-1]){
			jj=ps2[jj-1];
			continue;
		}
		return 0;
	}
	mx1[n]=x[n],ps1[n]=n;
	for(int i=n-1;i;i--){
		mx1[i]=max(mx1[i+1],x[i]);
		if(mx1[i]==mx1[i+1])ps1[i]=ps1[i+1];
		else ps1[i]=i;
	}
	mx2[m]=y[m];
	for(int i=m-1;i;i--)mx2[i]=max(mx2[i+1],y[i]);
	mn1[n]=x[n];
	for(int i=n-1;i;i--)mn1[i]=min(mn1[i+1],x[i]);
	mn2[m]=y[m],ps2[m]=m;
	for(int i=m-1;i;i--){
		mn2[i]=min(mn2[i+1],y[i]);
		if(mn2[i]==mn2[i+1])ps2[i]=ps2[i+1];
		else ps2[i]=i;
	}
	while(iii<n&&jjj<m){
		assert(x[iii]>mx2[jjj]&&mn1[iii]>y[jjj]);
		if(mx1[iii+1]>mx2[jjj]){
			iii=ps1[iii+1];
			continue;
		}
		if(mn1[iii]>mn2[jjj+1]){
			jjj=ps2[jjj+1];
			continue;
		}
		return 0;
	}
	return 1;
}
bool solve2(){
	if(xxx[1]==yyy[1])return 0;
	if(xxx[1]>yyy[1]){
		n=nn,m=mm;
	    for(int i=1;i<=nn;i++)x[i]=xxx[i];
	    for(int i=1;i<=mm;i++)y[i]=yyy[i];
		return solve();
	}
	n=mm,m=nn;
	for(int i=1;i<=nn;i++)y[i]=xxx[i];
	for(int i=1;i<=mm;i++)x[i]=yyy[i];
	return solve();
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&nn,&mm,&_);
	for(int i=1;i<=nn;i++)scanf("%d",&xx[i]);
	for(int i=1;i<=mm;i++)scanf("%d",&yy[i]);
	for(int i=1;i<=nn;i++)xxx[i]=xx[i];
	for(int i=1;i<=mm;i++)yyy[i]=yy[i];
	if(solve2())printf("1");
	else printf("0");
	while(_--){
		for(int i=1;i<=nn;i++)xxx[i]=xx[i];
	    for(int i=1;i<=mm;i++)yyy[i]=yy[i];
	    int kx,ky;
	    scanf("%d%d",&kx,&ky);
	    while(kx--){
	    	int px,vx;
	    	scanf("%d%d",&px,&vx);
	    	xxx[px]=vx;
		}
		while(ky--){
	    	int py,vy;
	    	scanf("%d%d",&py,&vy);
	    	yyy[py]=vy;
		}
    	if(solve2())printf("1");
    	else printf("0");
	}
	return 0;
}