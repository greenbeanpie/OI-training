#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int a[500010],b[500010],c,n,m,q,maxn[2000010][2],minn[2000010][2];
string ans;
void builda(int l,int r,int k){
	if(l==r){
		maxn[k][0]=a[l];
		minn[k][0]=a[l];
		return;
	}int mid=(l+r)>>1;
	builda(l,mid,k<<1);
	builda(mid+1,r,k<<1|1);
	maxn[k][0]=max(maxn[k<<1][0],maxn[k<<1|1][0]);
	minn[k][0]=min(minn[k<<1][0],minn[k<<1|1][0]);
}
void buildb(int l,int r,int k){
	if(l==r){
		maxn[k][1]=b[l];
		minn[k][1]=b[l];
		return;
	}int mid=(l+r)>>1;
	builda(l,mid,k<<1);
	builda(mid+1,r,k<<1|1);
	maxn[k][1]=max(maxn[k<<1][1],maxn[k<<1|1][1]);
	minn[k][1]=min(minn[k<<1][1],minn[k<<1|1][1]);
}
int mina(int x,int y,int l,int r,int k){
	if(x<=l&&y>=r){
		return minn[k][0];
	}if(x>r||y<l)return 0x3f3f3f3f;
	int mid=(l+r)>>1;
	return min(mina(l,mid,x,y,k<<1),mina(mid+1,r,x,y,k<<1|1));
}
int minb(int x,int y,int l,int r,int k){
	if(x<=l&&y>=r){
		return minn[k][1];
	}if(x>r||y<l)return 0x3f3f3f3f;
	int mid=(l+r)>>1;
	return min(minb(l,mid,x,y,k<<1),minb(mid+1,r,x,y,k<<1|1));
}
int maxa(int x,int y,int l,int r,int k){
	if(x<=l&&y>=r){
		return maxn[k][0];
	}if(x>r||y<l)return 0;
	int mid=(l+r)>>1;
	return max(maxa(l,mid,x,y,k<<1),maxa(mid+1,r,x,y,k<<1|1));
}
int maxb(int x,int y,int l,int r,int k){
	if(x<=l&&y>=r){
		return maxn[k][1];
	}if(x>r||y<l)return 0;
	int mid=(l+r)>>1;
	return max(maxb(l,mid,x,y,k<<1),maxb(mid+1,r,x,y,k<<1|1));
}
void changea(int l,int r,int p,int v,int k){
	if(p>=l&&p<=r){
		maxn[k][0]=max(maxn[k][0],v);
		minn[k][0]=min(minn[k][0],v);
		int mid=(l+r)>>1;
		if(mid>p)changea(l,mid,p,v,k<<1);
		else changea(mid+1,r,p,v,k<<1|1);
	}
}
void changeb(int l,int r,int p,int v,int k){
	if(p>=l&&p<=r){
		maxn[k][1]=max(maxn[k][1],v);
		minn[k][1]=min(minn[k][1],v);
		int mid=(l+r)>>1;
		if(mid>p)changeb(l,mid,p,v,k<<1);
		else changeb(mid+1,r,p,v,k<<1|1);
	}
}
void check(){
	int i=1,j=1;
	if(a[n]>b[m]){
		while(i<=n&&j<=m){
			int j1=j,i1=i;
			while(b[j]<a[i]&&j<=m)j++;
			while(b[j]>a[i]&&i<=n)i++;
			if(i>n&&j!=m){
				ans+="0";
				return;
			}
			if(j<=m){
				if(mina(i1,i,1,n,1)<minb(j1,j,1,m,1)){
					ans+="0";
					return;
				}
			}
			else{
				while(a[i]>b[j1]&&i<=n){
					i++;
				}
				while(b[j1]<a[i]&&j1<=m)
					j1++;
				if(i>n){
					ans+="1";
					return;
				}
				if(j1>m){
					ans+="0";
					return;
				}
				if(maxa(i,n,1,n,1)<maxb(j1,m,1,m,1)){
					ans+="0";
					return;
				}
			}
		}
	}else ans+="0";
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	memset(maxn,0,sizeof(maxn));
	memset(minn,0x3f3f3f3f,sizeof(minn));
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	if(a[1]<b[1]){
		for(int i=1;i<=max(m,n);i++)swap(a[i],b[i]);
	}builda(1,n,1);
	buildb(1,m,1);
	check();
	for(int i=1;i<=q;i++){
		int x,y,ax[100],ay[100],az[100],bx[100],by[100],bz[100];
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			cin>>ax[j]>>ay[j];
			az[j]=a[ax[j]];
			a[ax[j]]=ay[j];
			changea(1,n,ax[j],ay[j],1);
		}for(int j=1;j<=y;j++){
			cin>>bx[j]>>by[j];
			bz[j]=b[bx[j]];
			b[bx[j]]=by[j];
			changeb(1,m,bx[j],by[j],1);
		}check();
		for(int j=1;j<=x;j++){
			a[ax[j]]=az[j];
			changea(1,n,ax[j],az[j],1);
		}for(int j=1;j<=y;j++){
			b[bx[j]]=bz[j];
			changeb(1,m,bx[j],bz[j],1);
		}
	}
	cout<<ans;
}
