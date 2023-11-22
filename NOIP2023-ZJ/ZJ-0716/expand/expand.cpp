#include<bits/stdc++.h>
using namespace std;
#define rt register int 
int c,n,m,q,p1,p2,flag;
int x[500005],y[500005],ans[500005];
int xx[500005],yy[500005];
int p,v,kx,ky;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>q;
	if(c==1){
		cin>>x[1];
		cin>>y[1];
		if(x[1]==y[1])ans[1]=0;
		else ans[1]=1;
		q=q+1;
		for(rt cnt=2;cnt<=q;++cnt)
		{
			xx[1]=x[1];yy[1]=y[1];
			cin>>kx>>ky;
			for(rt i=1;i<=kx;++i)
			{
				cin>>p>>v;
				xx[p]=v;
			}
			for(rt i=1;i<=ky;++i)
			{
				cin>>p>>v;
				yy[p]=v;
			}
			if(xx[1]==yy[1])ans[cnt]=0;
			else ans[cnt]=1;
		}
		for(rt i=1;i<=q;++i)
			cout<<ans[i];
		return 0;
	}
	for(rt i=1;i<=n;++i)
		cin>>x[i];
	for(rt i=1;i<=m;++i)
		cin>>y[i];
	p1=p2=1;flag=1;
	while(p1<=n and p2<=m){
		if(x[p1]>y[p2]){
			p1+=1;p2+=1;
		}else{
			if(p1>1 and x[p1-1]>y[p2]){
				p2+=1;
			}else{
				flag=0;
				break;
			}	
		}
	}
	if(p1<=n and p2>m){
		for(rt i=p1;i<=n;++i)
			if(x[i]<=y[m]){
				flag=0;	break;
			}
	}
	ans[1]=flag;
	p1=p2=1;flag=1;
	while(p1<=n and p2<=m){
		if(x[p1]<y[p2]){
			p1+=1;p2+=1;
		}else{
			if(p1>1 and x[p1-1]<y[p2]){
				p2+=1;
			}else{
				flag=0;
				break;
			}	
		}
	}
	if(p1<=n and p2>m){
		for(rt i=p1;i<=n;++i)
			if(x[i]>y[m]){
				flag=0;	break;
			}
	}
	if(ans[1]==0 and flag)ans[1]=1;
	/*
	if(p2<=m and p1>n){
		for(rt i=p2;i<=m;++i)
			if(x[n]<=y[i]){
				flag=0;break;
			}
	}
	*/
	q=q+1;
	for(rt cnt=2;cnt<=q;++cnt){
		cin>>kx>>ky;
		for(rt i=1;i<=n;++i)xx[i]=x[i];
		for(rt j=1;j<=m;++j)yy[j]=y[j];
		for(rt i=1;i<=kx;++i){
			cin>>p>>v;
			xx[p]=v;
		}
		for(rt i=1;i<=ky;++i){
			cin>>p>>v;
			yy[p]=v;
		}
		p1=p2=1;flag=1;
		while(p1<=n and p2<=m){
			if(xx[p1]>yy[p2]){
				p1+=1;p2+=1;
			}else{
				if(p1>1 and xx[p1-1]>yy[p2]){
					p2+=1;
				}else{
					flag=0;
					break;
				}	
			}
		}
		if(p1<=n and p2>m){
			for(rt i=p1;i<=n;++i)
				if(xx[i]<=yy[m]){
					flag=0;	break;
				}
		}
		ans[cnt]=flag;
		p1=p2=1;flag=1;
		while(p1<=n and p2<=m){
			if(xx[p1]<yy[p2]){
				p1+=1;p2+=1;
			}else{
				if(p1>1 and xx[p1-1]<yy[p2]){
					p2+=1;
				}else{
					flag=0;
					break;
				}	
			}
		}
		if(p1<=n and p2>m){
			for(rt i=p1;i<=n;++i)
				if(xx[i]>yy[m]){
					flag=0;	break;
				}
		}
		if(ans[cnt]==0 and flag)ans[cnt]=1;
	}
	
	for(rt i=1;i<=q;++i)
		cout<<ans[i];

	return 0;
}
