#include<bits/stdc++.h>
using namespace std;
int x[2005],y[2005]; 
int t[2005],k[2005];
int ans[2005];
int c,n,m,p;
int main(){
    freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>p;
    for(int i=1;i<=n;i++){
    	cin>>x[i];
    	t[i]=x[i];
	}
	for(int i=1;i<=m;i++){
    	cin>>y[i];
    	k[i]=y[i];
	}
	if(c==1){
		if(x[1]!=y[1])ans[0]=1;
		else ans[0]=0;
		for(int j=1;j<=p;j++){
			int l=x[1];j=y[1];
			int kx,ky;
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++){
				int px,vx;
				cin>>px>>vx;
				x[1]=vx;
			}
			for(int i=1;i<=ky;i++){
				int py,vy;
			    cin>>py>>vy;
				y[1]=vy;
			}
			if(x[1]!=y[1])ans[j]=1;
			else ans[j]=0;
			x[1]=l;y[1]=j;
		}	
	for(int i=0;i<=p;i++)cout<<ans[i];
	}
	if(c>2){
		if(x[1]>y[1]&&x[n]>y[m])ans[0]=1;
		else if(x[1]<y[1]&&x[n]<y[m])ans[0]=1;
		for(int j=1;j<=p;j++){
			int kx,ky;
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++){
				int px,vx;
				cin>>px>>vx;
				x[px]=vx;
			}
			for(int i=1;i<=ky;i++){
				int py,vy;
			    cin>>py>>vy;
				y[py]=vy;
			}
		if(x[1]>y[1]&&x[n]>y[m])ans[j]=1;
		else if(x[1]<y[1]&&x[n]<y[m])ans[j]=1;
	    }
	for(int i=1;i<=n;i++){
    	x[i]=t[i];
	}
	for(int i=1;i<=m;i++){
        y[i]=k[i];
	}
	for(int i=0;i<=p;i++)cout<<ans[i];
	}
	return 0;
}
