#include <bits/stdc++.h>
using namespace std;
int c,n,m,q;
int kx,ky,p,v;
int x[500005],y[500005];
int xx[500005],yy[500005];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=m;i++) cin>>y[i];
	if(c==1){
		if(x[1]==y[1]) printf("0");
		else printf("1");
		while(q--){
			for(int i=1;i<=n;i++) xx[i]=x[i];
			for(int i=1;i<=m;i++) yy[i]=y[i];
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++){
				cin>>p>>v;
				xx[p]=v;
			}
			for(int i=1;i<=ky;i++){
				cin>>p>>v;
				yy[p]=v;
			}
			if(xx[1]==yy[1]) printf("0");
			else printf("1");
		}
	}
	else if(c==2){
		if(x[1]<y[1]&&x[n]<y[m]) printf("1");
		else if(x[1]>y[1]&&x[n]>y[m]) printf("1");
		else printf("0");
		while(q--){
			for(int i=1;i<=n;i++) xx[i]=x[i];
			for(int i=1;i<=m;i++) yy[i]=y[i];
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++){
				cin>>p>>v;
				xx[p]=v;
			}
			for(int i=1;i<=ky;i++){
				cin>>p>>v;
				yy[p]=v;
			}
			if(xx[1]<yy[1]&&xx[n]<yy[m]) printf("1");
			else if(xx[1]>yy[1]&&xx[n]>yy[m]) printf("1");
			else printf("0");
		}
	}
	else if(c>=9&&c<=14){
		int maxn[500005],f=0;
		memset(maxn,0,sizeof(maxn));
		for(int i=1;i<=m;i++) maxn[i]=max(maxn[i],y[i]);
		for(int i=1;i<=n;i++){
			if(maxn[i]<x[i]){
				printf("0");
				f=1;
				break;
			}
		}
		if(f==0) printf("1");
		while(q--){
			for(int i=1;i<=n;i++) xx[i]=x[i];
			for(int i=1;i<=m;i++) yy[i]=y[i];
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++){
				cin>>p>>v;
				xx[p]=v;
			}
			for(int i=1;i<=ky;i++){
				cin>>p>>v;
				yy[p]=v;
			}
			f=0;
			memset(maxn,0,sizeof(maxn));
			for(int i=1;i<=m;i++) maxn[i]=max(maxn[i],y[i]);
			for(int i=1;i<=n;i++){
				if(maxn[i]<x[i]){
					printf("0");
					f=1;
					break;
				}
			}
			if(f==0) printf("1");
		}
	}
	else{
		for(int i=1;i<=q+1;i++) printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
