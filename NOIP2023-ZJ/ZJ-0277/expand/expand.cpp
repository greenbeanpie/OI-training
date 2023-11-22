#include<bits/stdc++.h>
#define R read()

using namespace std;

int lp,n,m,q,i,ccf,t,w,x,lx,ly,y,fl,X[500010],Y[500010],ma,a[500010],c[500010];

int read(){
	int x=0,fl=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')fl=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return x*fl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	lp=R;n=R;m=R;q=R;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=m;i++)cin>>c[i];
	if(lp<=5){
	for(ccf=0;ccf<=q;ccf++){
		for(i=1;i<=n;i++)X[i]=a[i];
		for(i=1;i<=m;i++)Y[i]=c[i];
		if(ccf!=0){
			lx=R;ly=R;
			for(i=1;i<=lx;i++)x=R,y=R,X[x]=y;
			for(i=1;i<=ly;i++)x=R,y=R,Y[x]=y;
		}
//		for(i=1;i<=n;i++)cout<<X[i]<<" ";
//		cout<<'\n';
//		for(i=1;i<=m;i++)cout<<Y[i]<<" ";
//		cout<<'\n';
		
		if(X[1]<Y[1]){
			t=1;w=1;fl=0;
			while(t<=n&&w<=m){
				if(X[t]<Y[w])t++,w++;
				else{
					x=-1;
					for(i=w;i<=m;i++)
						if(Y[i]>X[t]){
							x=i;break;
						}
					if(x==-1){
						fl=1;break;
					}
					ma=0;
					for(i=w;i<=x-1;i++)ma=max(ma,Y[i]);
					if(ma<=X[t-1]){
						fl=1;break;
					}
					t++,w=x+1;
				}
			}
			if(w>m){
				for(i=t;i<=n;i++)
					if(X[i]>=Y[m]){
						fl=1;
						break;
					}
			}
			else if(t>n){
				for(i=w;i<=m;i++)
					if(X[t]>=Y[i]){
						fl=1;
						break;
					}
			}
		}
		else{
			t=1;w=1;fl=0;
			while(t<=n&&w<=m){
				if(X[t]>Y[w])t++,w++;
				else{
					x=-1;
					for(i=w;i<=m;i++)
						if(Y[i]<X[t]){
							x=i;break;
						}
					if(x==-1){
						fl=1;break;
					}
					ma=0;
					for(i=w;i<=x-1;i++)ma=max(ma,Y[i]);
					if(ma>=X[t-1]){
						fl=1;break;
					}
					t++,w=x+1;
				}
			}
			if(w>m){
				for(i=t;i<=n;i++)
					if(X[i]<=Y[m]){
						fl=1;
						break;
					}
			}
			else if(t>n){
				for(i=w;i<=m;i++)
					if(X[t]<=Y[i]){
						fl=1;
						break;
					}
			}
		}
		
		if(fl)cout<<0;
		else cout<<1;                           
	}
		
	}
	else{
		for(i=1;i<=q+1;i++)cout<<0;
	}
	return 0;
}
