#include<bits/stdc++.h>
using namespace std;
long long c,n,m,q,x[500005],y[500005],kx,ky,p,v,xbase[500005],ybase[500005],a,b,sum1,sum2,l1,l2,f;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>xbase[i];
	}
	for(int i=1;i<=m;i++){
		cin>>ybase[i];
	}
	if(n==1){
		sum1=0;
		sum2=0;
		for(int i=1;i<=m;i++){
			if(xbase[1]>ybase[i]){
				sum1++;
			}
			else if(xbase[1]<ybase[i]){
				sum2++;
			}
		}
		if(sum1==m||sum2==m){
			cout<<1;
		}
		else{
			cout<<0;
		}
		while(q--){
			for(int i=1;i<=n;i++){
				x[i]=xbase[i];
			}
			for(int i=1;i<=m;i++){
				y[i]=ybase[i];
			}
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++){
				cin>>p>>v;
				x[p]=v;
			}
			for(int i=1;i<=ky;i++){
				cin>>p>>v;
				y[p]=v;
			}
			sum1=0;
			sum2=0;
			for(int i=1;i<=m;i++){
				if(x[1]>y[i]){
					sum1++;
				}
				else if(x[1]<y[i]){
					sum2++;
				}
			}
			if(sum1==m||sum2==m){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		return 0;
	}
	else if(m==1){
		sum1=0;
		sum2=0;
		for(int i=1;i<=n;i++){
			if(xbase[i]>ybase[1]){
				sum1++;
			}
			else if(xbase[i]<ybase[1]){
				sum2++;
			}
		}
		if(sum1==n||sum2==n){
			cout<<1;
		}
		else{
			cout<<0;
		}
		while(q--){
			for(int i=1;i<=n;i++){
				x[i]=xbase[i];
			}
			for(int i=1;i<=m;i++){
				y[i]=ybase[i];
			}
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++){
				cin>>p>>v;
				x[p]=v;
			}
			for(int i=1;i<=ky;i++){
				cin>>p>>v;
				y[p]=v;
			}
			sum1=0;
			sum2=0;
			for(int i=1;i<=n;i++){
				if(x[i]>y[1]){
					sum1++;
				}
				else if(x[i]<y[1]){
					sum2++;
				}
			}
			if(sum1==n||sum2==n){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		return 0;
	}
	else if(n==2&&m==2){
		if((xbase[1]-ybase[1])*(xbase[2]-ybase[2])>0){
			cout<<1;
		}
		else{
			cout<<0;
		}
		while(q--){
			for(int i=1;i<=n;i++){
				x[i]=xbase[i];
			}
			for(int i=1;i<=m;i++){
				y[i]=ybase[i];
			}
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++){
				cin>>p>>v;
				x[p]=v;
			}
			for(int i=1;i<=ky;i++){
				cin>>p>>v;
				y[p]=v;
			}
			if((x[1]-y[1])*(x[2]-y[2])>0){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			x[i]=xbase[i];
		}
		for(int i=1;i<=m;i++){
			y[i]=ybase[i];
		}
		l1=1;
		l2=1;
		f=1;
		if(x[l1]==y[l2]){
			cout<<0;
		}
		else if(x[l1]>y[l2]){
			while(l1<n&&l2<m){
				if(x[l1]>y[l2]){
					if(x[l1+1]>y[l2+1]){
						l1++;
						l2++;
					}
					else{
						if(x[l1]>y[l2+1]){
							l2++;
						}
						else if(x[l1+1]>y[l2]){
							l1++;
						}
						else{
							f=0;
							break;
						}
					}
				}
			}
			if(f==0){
				cout<<0;
			}
			else{
				while(l1<n){
					if(x[l1+1]>y[l2]){
						l1++;
					}
					else{
						f=0;
						break;
					}
				}
				while(l2<m){
					if(x[l1]>y[l2+1]){
						l2++;
					}
					else{
						f=0;
						break;
					}
				}
				cout<<f;
			}
		}
		else if(x[l1]<y[l2]){
			while(l1<n&&l2<m){
				if(x[l1]<y[l2]){
					if(x[l1+1]<y[l2+1]){
						l1++;
						l2++;
					}
					else{
						if(x[l1]<y[l2+1]){
							l2++;
						}
						else if(x[l1+1]<y[l2]){
							l1++;
						}
						else{
							f=0;
							break;
						}
					}
				}
			}
			if(f==0){
				cout<<0;
			}
			else{
				while(l1<n){
					if(x[l1+1]<y[l2]){
						l1++;
					}
					else{
						f=0;
						break;
					}
				}
				while(l2<m){
					if(x[l1]<y[l2+1]){
						l2++;
					}
					else{
						f=0;
						break;
					}
				}
				cout<<f;
			}
		}
		while(q--){
			for(int i=1;i<=n;i++){
				x[i]=xbase[i];
			}
			for(int i=1;i<=m;i++){
				y[i]=ybase[i];
			}
			cin>>kx>>ky;
			for(int i=1;i<=kx;i++){
				cin>>p>>v;
				x[p]=v;
			}
			for(int i=1;i<=ky;i++){
				cin>>p>>v;
				y[p]=v;
			}
			l1=1;
			l2=1;
			f=1;
			if(x[l1]==y[l2]){
				cout<<0;
			}
			else if(x[l1]>y[l2]){
				while(l1<n&&l2<m){
					if(x[l1]>y[l2]){
						if(x[l1+1]>y[l2+1]){
							l1++;
							l2++;
						}
						else{
							if(x[l1]>y[l2+1]){
								l2++;
							}
							else if(x[l1+1]>y[l2]){
								l1++;
							}
							else{
								f=0;
								break;
							}
						}
					}
				}
				if(f==0){
					cout<<0;
				}
				else{
					while(l1<n){
						if(x[l1+1]>y[l2]){
							l1++;
						}
						else{
							f=0;
							break;
						}
					}
					while(l2<m){
						if(x[l1]>y[l2+1]){
							l2++;
						}
						else{
							f=0;
							break;
							}
				}
					cout<<f;
				}
			}
		else if(x[l1]<y[l2]){
			while(l1<n&&l2<m){
				if(x[l1]<y[l2]){
					if(x[l1+1]<y[l2+1]){
						l1++;
						l2++;
					}
					else{
						if(x[l1]<y[l2+1]){
							l2++;
						}
						else if(x[l1+1]<y[l2]){
							l1++;
						}
						else{
							f=0;
							break;
						}
					}
				}
			}
			if(f==0){
				cout<<0;
			}
			else{
				while(l1<n){
					if(x[l1+1]<y[l2]){
						l1++;
					}
					else{
						f=0;
						break;
					}
				}
				while(l2<m){
					if(x[l1]<y[l2+1]){
						l2++;
					}
					else{
						f=0;
						break;
					}
				}
				cout<<f;
			}
		}
		
		}
		return 0;
	}
}