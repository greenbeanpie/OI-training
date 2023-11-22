#include<bits/stdc++.h>
using namespace std;
const int maxn =5e5+5;
int id,n,m,q,n0,m0;
int a[maxn],b[maxn];
int ans[maxn];
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
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	id=read();
	n=read();m=read();q=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i)b[i]=read();
	
	if(a[1]!=b[1]){
		if(a[1]>b[1]&&a[n]>b[m]){
			int kk=1,ll=1,r1=0,r2=0,amn=a[1],bmn=b[1],amx=a[1],bmx=b[1];
			flag=1;if(n<=2&&m<=2)ans[0]=1;
			else
			while(kk<n+1&&ll<m+1){
				while(a[kk]>b[ll]&&kk<n+1&&ll<m+1){
					++ll;bmn=min(bmn,b[ll]);
					bmx=max(bmx,b[ll]);
					++kk;amn=min(amn,a[kk]);
					amx=max(amx,a[kk]);
				}
				
				while(amn>bmn&&kk<n+1&&ll<m+1&&amx<=bmx){
					++kk;amn=min(amn,a[kk]);
					amx=max(amx,a[kk]);
				}
				while(b[ll]>=a[kk]&&kk<n+1&&ll<m+1&&amx>bmx){
					++ll;amn=min(amn,a[kk]);
					amx=max(amx,a[kk]);
				}
				if(kk==n+1){
					while(ll<m+1){
						++ll;bmn=min(bmn,b[ll]);
						bmx=max(bmx,b[ll]);
						if(b[ll]>a[n]){
							flag=0;
							break;
						}
					}
					if(flag)ans[0]=1;
					break;
				}
				
				
				if(ll==m+1){
					while(kk<n+1){
						++kk;amn=min(amn,a[kk]);
						amx=max(amx,a[kk]);
						if(a[kk]>b[m]){
							flag=0;
							break;
						}
					}
					if(flag)ans[0]=1;
					break;
					
				}
				if(!flag){
					break;
				}
			}
		}
		if(a[1]<b[1]&&a[n]<b[m]){
			int kk=1,ll=1,r1=0,r2=0,amn=a[1],bmn=b[1],amx=a[1],bmx=b[1];
			flag=1;
			while(kk<n+1&&ll<m+1){
				while(b[kk]>a[ll]&&kk<m+1&&ll<n+1){
					++ll;amn=min(amn,a[ll]);
					amx=max(amx,a[ll]);
					++kk;bmn=min(bmn,b[kk]);
					bmx=max(bmx,b[kk]);
				}
				
				while(bmn>amn&&kk<m+1&&ll<n+1&&bmx<=amx){
					++kk;bmn=min(bmn,b[kk]);
					bmx=max(bmx,b[kk]);
				}
				while(a[ll]>=b[kk]&&kk<m+1&&ll<n+1&&bmx>amx){
					++ll;bmn=min(bmn,b[kk]);
					bmx=max(amx,a[kk]);
				}
				if(kk==m+1){
					while(ll<n+1){
						++ll;amn=min(amn,a[ll]);
						amx=max(amx,a[ll]);
						if(a[ll]>b[m]){
							flag=0;
							break;
						}
					}
					if(flag)ans[0]=1;
					break;
				}
				
				
				if(ll==n+1){
					while(kk<m+1){
						++kk;bmn=min(bmn,b[kk]);
						bmx=max(bmx,b[kk]);
						if(b[kk]>a[n]){
							flag=0;
							break;
						}
					}
					if(flag)ans[0]=1;
					break;
					
				}
				if(!flag){
					break;
				}
			}
		}
			
		
	}
	
	
	for(int qq=1;qq<=q;++qq){
		n0=read();m0=read();
		for(int i=1;i<=n0;++i){
			c[i].v=read();c[i].x=read();
		}
		for(int i=1;i<=m0;++i){
			d[i].v=read();d[i].x=read();
		}
		sort(c+1,c+n0+1);
		sort(d+1,d+m0+1);
		for(int i=1;i<=n0;++i)swap(c[i].x,a[c[i].v]);
		for(int i=1;i<=m0;++i)swap(d[i].x,b[d[i].v]);
		if(a[1]!=b[1]){
		if(a[1]>b[1]&&a[n]>b[m]){
			int kk=1,ll=1,r1=0,r2=0,amn=a[1],bmn=b[1],amx=a[1],bmx=b[1];
			flag=1;
			while(kk<n+1&&ll<m+1){
				while(a[kk]>b[ll]&&kk<n+1&&ll<m+1){
					++ll;bmn=min(bmn,b[ll]);
					bmx=max(bmx,b[ll]);
					++kk;amn=min(amn,a[kk]);
					amx=max(amx,a[kk]);
				}
				
				while(amn>bmn&&kk<n+1&&ll<m+1&&amx<=bmx){
					++kk;amn=min(amn,a[kk]);
					amx=max(amx,a[kk]);
				}
				while(b[ll]>=a[kk]&&kk<n+1&&ll<m+1&&amx>bmx){
					++ll;amn=min(amn,a[kk]);
					amx=max(amx,a[kk]);
				}
				if(kk==n+1){
					while(ll<m+1){
						++ll;bmn=min(bmn,b[ll]);
						bmx=max(bmx,b[ll]);
						if(b[ll]>a[n]){
							flag=0;
							break;
						}
					}
					if(flag)ans[qq]=1;
					break;
				}
				
				
				if(ll==m+1){
					while(kk<n+1){
						++kk;amn=min(amn,a[kk]);
						amx=max(amx,a[kk]);
						if(a[kk]>b[m]){
							flag=0;
							break;
						}
					}
					if(flag)ans[qq]=1;
					break;
					
				}
				if(!flag){
					break;
				}
			}
		}
		if(a[1]<b[1]&&a[n]<b[m]){
			int kk=1,ll=1,r1=0,r2=0,amn=a[1],bmn=b[1],amx=a[1],bmx=b[1];
			flag=1;
			while(kk<n+1&&ll<m+1){
				while(b[kk]>a[ll]&&kk<m+1&&ll<n+1){
					++ll;amn=min(amn,a[ll]);
					amx=max(amx,a[ll]);
					++kk;bmn=min(bmn,b[kk]);
					bmx=max(bmx,b[kk]);
				}
				
				while(bmn>amn&&kk<m+1&&ll<n+1&&bmx<=amx){
					++kk;bmn=min(bmn,b[kk]);
					bmx=max(bmx,b[kk]);
				}
				while(a[ll]>=b[kk]&&kk<m+1&&ll<n+1&&bmx>amx){
					++ll;bmn=min(bmn,b[kk]);
					bmx=max(amx,a[kk]);
				}
				if(kk==m+1){
					while(ll<n+1){
						++ll;amn=min(amn,a[ll]);
						amx=max(amx,a[ll]);
						if(a[ll]>b[m]){
							flag=0;
							break;
						}
					}
					if(flag)ans[qq]=1;
					break;
				}
				
				
				if(ll==n+1){
					while(kk<m+1){
						++kk;bmn=min(bmn,b[kk]);
						bmx=max(bmx,b[kk]);
						if(b[kk]>a[n]){
							flag=0;
							break;
						}
					}
					if(flag)ans[qq]=1;
					break;
					
				}
				if(!flag){
					break;
				}
			}
		}
			
		
	}
		
		for(int i=1;i<=n0;++i)swap(c[i].x,a[c[i].v]);
		for(int i=1;i<=m0;++i)swap(d[i].x,b[d[i].v]);
	}
	
	for(int i=0;i<=q;++i)printf("%d",ans[i]);
	printf("\n");
	return 0;
}