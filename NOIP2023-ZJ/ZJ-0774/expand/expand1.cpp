#include<bits/stdc++.h>
using namespace std;
const int maxn =5e5+5;
int id,n,m,q,n0,m0;
int a[maxn],b[maxn];
int ans[maxn];
int e[maxn],f[maxn];
int amx[maxn],bmx[maxn],amn[maxn],bmn[maxn];
bool flag=1;
struct _dat{
	int v,x;
	friend bool operator <(_dat x,_dat y){
		return x.v<y.v;
	}
}c[maxn],d[maxn];
inline int read(){
	int res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<3)+(res<<1)+c-'0';
		c=getchar();
	}
	return res*f;
}
int main(){
	freopen("expand2.in","r",stdin);
	freopen("expand.out","w",stdout);
	id=read();
	n=read();m=read();q=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i)b[i]=read();
	if(m<n)for(int i=m+1;i<=n;++i)b[i]=b[m];
	
	if(n<m)for(int i=n+1;i<=m;++i)a[i]=a[n];
	n=max(n,m);
	if(id<=7)
	{
	
	if(a[1]!=b[1]){
		flag=1;
		bmn[m+1]=1e9+7;
		amn[n+1]=1e9+7;
		for(int i=m;i>=1;--i){
			bmn[i]=min(bmn[i+1],b[i]);
			bmx[i]=max(bmx[i+1],b[i]);
		}
		if(a[1]>b[1]&&a[n]>b[m]){
//			for(int j=m;j>=1;--j){
			
			for(int i=n;i>=1;--i){
				amn[i]=min(amn[i+1],a[i]);
				amx[i]=max(amx[i+1],a[i]);
				if(amx[i]<bmx[i]&&amn[i]>bmn[i]){
					flag=0;break;
				}
				if(!flag)break;
			}
			
//			}
		}
		if(a[1]<b[1]&&a[n]<b[m]){
//			for(int j=m;j>=1;--j){
			
			for(int i=n;i>=1;--i){
				amn[i]=min(amn[i+1],a[i]);
				amx[i]=max(amx[i+1],a[i]);
				if(amx[i]>bmx[i]&&amn[i]<bmn[i]){
					flag=0;break;
				}
				if(!flag)break;
			}
			
//			}
			
		}
		ans[0]=flag;
	}
	
	
	for(int scdf=1;scdf<=q;++scdf){
		flag=1;
		for(int i=1;i<=n;++i)amn[i]=amx[i]=0;
		for(int i=1;i<=m;++i)bmn[i]=bmx[i]=0;
		n0=read();m0=read();
		for(int i=1;i<=n;++i)e[i]=a[i];
		for(int i=1;i<=m;++i)f[i]=b[i];
		for(int i=1;i<=n0;++i){
			c[i].v=read();c[i].x=read();
			e[c[i].v]=c[i].x;
		}
		for(int i=1;i<=m0;++i){
			d[i].v=read();d[i].x=read();
			f[d[i].v]=d[i].x;
		}
		flag=1;
		bmn[m+1]=1e9+7;
		amn[n+1]=1e9+7;
		for(int i=m;i>=1;--i){
			bmn[i]=min(bmn[i+1],f[i]);
			bmx[i]=max(bmx[i+1],f[i]);
		}
		if(e[1]>f[1]&&e[n]>f[m]){
//			for(int j=m;j>=1;--j){
			
			for(int i=n;i>=1;--i){
				amn[i]=min(amn[i+1],e[i]);
				amx[i]=max(amx[i+1],e[i]);
				if(amx[i]<bmx[i]&&amn[i]>bmn[i]){
					flag=0;break;
				}
				if(!flag)break;
			}
			
//			}
			ans[scdf]=flag;
		}
		if(e[1]<f[1]&&e[n]<f[m]){
//			for(int j=m;j>=1;--j){
			
			for(int i=n;i>=1;--i){
				amn[i]=min(amn[i+1],e[i]);
				amx[i]=max(amx[i+1],e[i]);
				if(amx[i]>bmx[i]&&amn[i]<bmn[i]){
					flag=0;break;
				}
				if(!flag)break;
			}
			
//			}
			ans[scdf]=flag;
		}
		
	}
	
	for(int i=0;i<=q;++i)printf("%d",ans[i]);
	printf("\n");
	}
	return 0;
}