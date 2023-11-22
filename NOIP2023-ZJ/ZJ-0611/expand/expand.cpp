#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1000;
int c,n,m,q;
pair<int,int> x[N],y[N],xx[N],yy[N];
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.first>y.first;
}
bool cmmp(pair<int,int> x,pair<int,int> y){
	return x.first<y.first;
}
bool dmp(pair<int,int> x,pair<int,int> y){
	return x.second<y.second;
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	if(c>=8&&c<=14){
	for(int i=1;i<=n;i++) 
		scanf("%d",&x[i].first),x[i].second=i;
	for(int i=1;i<=m;i ++) 
		scanf("%d",&y[i].first),y[i].second=i;
	sort(x+1,x+1+n,cmp);
	sort(y+1,y+1+m,cmmp);
	sort(x+1,x+1+n,dmp);
	sort(y+1,y+1+m,dmp);
	if(x[1].first<y[1].first) printf("1");
	else printf("0");
	while(q--){
		for(int i=1;i<=n;i++) xx[i]=x[i];
		for(int i=1;i<=m;i++) yy[i]=y[i];		
		int kx,ky,t,tt;
		scanf("%d%d",&kx,&ky);
		for(int j=1;j<=kx;j++){
			scanf("%d%d",&t,&tt);
			xx[t].first=tt;
		}
		for(int j=1;j<=ky;j++){
			scanf("%d%d",&t,&tt);
			yy[t].first=tt;
		}			
		sort(xx+1,xx+1+n,cmp);
		sort(yy+1,yy+1+m,cmmp);
		if(xx[1].first<yy[1].first) printf("1");
		else printf("0");
	}
	}
	else {
		for(int i=0;i<=q;i++) printf("0");
	}
	return 0;
}