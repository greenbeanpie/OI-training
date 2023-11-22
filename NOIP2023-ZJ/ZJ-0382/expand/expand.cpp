#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int i,C,n,m,q,a[N],b[N],kx,ky,p,x,P[N],PP[N],ta[N<<2],tb[N<<2],c[N],d[N];
inline void b_a(int l,int r,int k){
	if(l==r){
		ta[k]=a[l];
		return ;
	}
	int mid=l+r>>1;
	b_a(l,mid,k<<1);
	b_a(mid+1,r,k<<1|1);
	ta[k]=min(ta[k<<1],ta[k<<1|1]);
}
inline void b_b(int l,int r,int k){
	if(l==r){
		tb[k]=b[l];
		return ;
	}
	int mid=l+r>>1;
	b_b(l,mid,k<<1);
	b_b(mid+1,r,k<<1|1);
	tb[k]=max(tb[k<<1],tb[k<<1|1]);
}
inline void A(int l,int r,int p,int k,int q){
	if(l==r){
		ta[k]=q;
		return ;
	}
	int mid=l+r>>1;
	if(p<=mid)A(l,mid,p,k<<1,q);
	else A(mid+1,r,p,k<<1|1,q);
	ta[k]=min(ta[k<<1],ta[k<<1|1]);
}
inline void B(int l,int r,int p,int k,int q){
	if(l==r){
		tb[k]=q;
		return ;
	}
	int mid=l+r>>1;
	if(p<=mid)B(l,mid,p,k<<1,q);
	else B(mid+1,r,p,k<<1|1,q);
	tb[k]=max(tb[k<<1],tb[k<<1|1]);
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>n>>m>>q;
	for(i=1;i<=n;i++)
	   cin>>a[i];
	for(i=1;i<=m;i++)
		cin>>b[i];
	if(C==1){
		if(a[1]==b[1])cout<<0;
		else cout<<1;
		int o1=a[1],o2=b[1];
		while(q--){
			cin>>kx>>ky;
			while(kx--){
				cin>>p;
				cin>>a[p];
			}
			while(ky--){
				cin>>p;
				cin>>b[p];
			}
		    if(a[1]==b[1])cout<<0;
		    else cout<<1;
		    a[1]=o1;b[1]=o2;
		}
		return 0;
	}
	if(C==2){
		if((a[1]-b[1])*(a[2]-b[2])>0)cout<<1;
		else cout<<0;
		int o1=a[1],o2=a[2],o3=b[1],o4=b[2];
		while(q--){
			cin>>kx>>ky;
			while(kx--){
				cin>>p;
				cin>>a[p];
			}
			while(ky--){
				cin>>p;
				cin>>b[p];
			}
		  	if((a[1]-b[1])*(a[2]-b[2])>0)cout<<1;
		    else cout<<0;
		    a[1]=o1;a[2]=o2;b[1]=o3;b[2]=o4;
		}
		return 0;
	}
	if(C>=8&&C<=14){
	    b_a(2,n,1);
	    b_b(1,m-1,1);
	    for(i=1;i<=n;i++) 
	      c[i]=a[i];
	    for(i=1;i<=m;i++)
	      d[i]=b[i];
	    int amn=1e10,bmx;
	    for(i=2;i<=n;i++)
	     amn=min(amn,a[i]);
	    for(i=1;i<m;i++)
	     bmx=max(bmx,b[i]);
	    if((a[1]-bmx)*(amn-b[m])>0)cout<<1;
	    else cout<<0;
		while(q--){
			cin>>kx>>ky;
 			for(i=1;i<=kx;i++){
 			  cin>>P[i]>>x;
 			  if(P[i]==1){
 			  	a[1]=x;
			  }
 			  else A(2,n,P[i],1,x);
		    }
		    for(i=1;i<=ky;i++){
 			  cin>>PP[i]>>x;
 			  if(PP[i]==m){
 			  	b[m]=x;
			   }
 			  else B(1,m-1,PP[i],1,x);
		    }
		    if((a[1]-tb[1])*(ta[1]-b[m])>0)cout<<1;
		    else cout<<0;
		    a[1]=c[1];b[m]=d[m];
		    for(i=1;i<=kx;i++)
		      A(2,n,P[i],1,c[P[i]]);
		    for(i=1;i<=ky;i++)
		      B(1,m-1,PP[i],1,d[PP[i]]);
		}
		return 0;
	}
	return 0;
}
/*
1 3
3 3
- 2 1
‐ 3 2
+ 1 3
3 3
‐ 2 1
‐ 3 2
‐ 1 3
2 2
T 2
U 2
*/