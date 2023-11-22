#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int c,n,m,q,kx,ky,p,v;
long long x[N],y[N],xx[N],yy[N];
string ans;
bool pd(long long x[N],long long y[N],int n,int m){
	long long maxx=x[1],minx=x[1],maxy=x[1],miny=x[1];
	for(int i=2;i<=max(m,n);i++){
		if(i<=n){
			maxx=max(maxx,x[i]);
			minx=min(minx,x[i]);
		}else if(i<=m){
			maxy=max(maxy,x[i]);
			miny=min(miny,x[i]);
		}
	}
	if((x[1]-y[1])*(x[n]-y[m])>0){
		if(minx>maxy||maxx<miny) return false;
		else{
			int an=(x[1]-y[1])/abs((x[1]-y[1])),lo=1,po=m;
			for(int i=1;i<=n;i++){
				for(int j=lo;j<=m;j++){
					if((x[i]-x[j])*an<0){
						lo=j;
						break;
					}
				}
			}
			for(int i=n;i>=1;i--){
				for(int j=lo;j>=1;j--){
					if((x[i]-x[j])*an<0){
						po=j;
						break;
					}
				}
			}
			if(lo<po) return false;
		}
	}else return false;
	return true;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	if(c==8||c==9||c==10||c==11||c==12||c==13||c==14){
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=m;i++) cin>>y[i];
		if(pd(x,y,n,m)) ans+="1";
		else ans+="0";
		for(int i=1;i<=q;i++){
			for(int i=1;i<=n;i++) xx[i]=x[i];
			for(int i=1;i<=m;i++) yy[i]=y[i];
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=kx;i++) scanf("%d%d",&p,&v),xx[p]=v;
			for(int i=1;i<=ky;i++) scanf("%d%d",&p,&v),yy[p]=v;
			if(pd(xx,yy,n,m)) ans+="1";
			else ans+="0";
		}
	}else{
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=m;i++) cin>>y[i];
		if(pd(x,y,n,m)) ans+="1";
		else ans+="0";
		for(int i=1;i<=q;i++){
			for(int i=1;i<=n;i++) xx[i]=x[i];
			for(int i=1;i<=m;i++) yy[i]=y[i];
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=kx;i++) scanf("%d%d",&p,&v),xx[p]=v;
			for(int i=1;i<=ky;i++) scanf("%d%d",&p,&v),yy[p]=v;
			if(pd(xx,yy,n,m)) ans+="1";
			else ans+="0";
		}
	}
	cout<<ans;
	return 0;
}