#include<bits/stdc++.h>
using namespace std;
const int MAXN=500010;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int c,n,m,q;
int a[MAXN],b[MAXN],d[MAXN],e[MAXN],ans[MAXN];
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();n=read();m=read();q=read();
	for(int i=1;i<=n;i++)d[i]=a[i]=read();
	for(int i=1;i<=m;i++)e[i]=b[i]=read();
	int kx,ky,x,y;
	if(n==1&&m==1){
		if(a[1]!=b[1])ans[1]=1;
		for(int i=1;i<=q;i++){
			for(int j=1;j<=n;j++)d[j]=a[j];
			for(int j=1;j<=m;j++)e[j]=b[j];
			kx=read();ky=read();
			for(int j=1;j<=kx;j++){
				x=read();y=read();
				d[x]=y;
			}
			for(int j=1;j<=ky;j++){
				x=read();y=read();
				e[x]=y;
			}
			if(d[1]!=e[1])ans[i+1]=1;
		}
		for(int i=1;i<=q+1;i++)printf("%d",ans[i]);
		return 0;
	}
	else if(n==2&&m==2){
			if(a[1]<b[1]&&a[2]<b[2])ans[1]=1;
			else if(a[1]>b[1]&&a[2]>b[2])ans[1]=1;
			for(int i=1;i<=q;i++){
				for(int j=1;j<=n;j++)d[j]=a[j];
				for(int j=1;j<=m;j++)e[j]=b[j];
				kx=read();ky=read();
				for(int j=1;j<=kx;j++){
					x=read();y=read();
					d[x]=y;
				}
				for(int j=1;j<=ky;j++){
					x=read();y=read();
					e[x]=y;
				}
				if(d[1]<e[1]&&d[2]<e[2])ans[i+1]=1;
				else if(d[1]>e[1]&&d[2]>e[2])ans[i+1]=1;
			}
			for(int i=1;i<=q+1;i++)printf("%d",ans[i]);
			return 0;
		}
	else if(n==1&&m==2){
			if(a[1]<b[1]&&a[1]<b[2])ans[1]=1;
			else if(a[1]>b[1]&&a[1]>b[2])ans[1]=1;
			for(int i=1;i<=q;i++){
				for(int j=1;j<=n;j++)d[j]=a[j];
				for(int j=1;j<=m;j++)e[j]=b[j];
				kx=read();ky=read();
				for(int j=1;j<=kx;j++){
					x=read();y=read();
					d[x]=y;
				}
				for(int j=1;j<=ky;j++){
					x=read();y=read();
					e[x]=y;
				}
				if(d[1]<e[1]&&d[1]<e[2])ans[i+1]=1;
				else if(d[1]>e[1]&&d[1]>e[2])ans[i+1]=1;
			}
			for(int i=1;i<=q+1;i++)printf("%d",ans[i]);
			return 0;
		}
	else if(n==2&&m==1){
			if(a[1]<b[1]&&a[2]<b[1])ans[1]=1;
			else if(a[1]>b[1]&&a[2]>b[1])ans[1]=1;
			for(int i=1;i<=q;i++){
				for(int j=1;j<=n;j++)d[j]=a[j];
				for(int j=1;j<=m;j++)e[j]=b[j];
				kx=read();ky=read();
				for(int j=1;j<=kx;j++){
					x=read();y=read();
					d[x]=y;
				}
				for(int j=1;j<=ky;j++){
					x=read();y=read();
					e[x]=y;
				}
				if(d[1]<e[1]&&d[2]<e[1])ans[i+1]=1;
				else if(d[1]>e[1]&&d[2]>e[1])ans[i+1]=1;
			}
			for(int i=1;i<=q+1;i++)printf("%d",ans[i]);
			return 0;
		}
	else{
		if(a[1]<b[1]&&a[n]<b[m])ans[1]=1;
		else if(a[1]>b[1]&&a[n]>b[m])ans[1]=1;
		for(int i=1;i<=q;i++){
			for(int j=1;j<=n;j++)d[j]=a[j];
			for(int j=1;j<=m;j++)e[j]=b[j];
			kx=read();ky=read();
			for(int j=1;j<=kx;j++){
				x=read();y=read();
				d[x]=y;
			}
			for(int j=1;j<=ky;j++){
				x=read();y=read();
				e[x]=y;
			}
			if(d[1]<e[1]&&d[n]<e[m])ans[i+1]=1;
			else if(d[1]>e[1]&&d[n]>e[m])ans[i+1]=1;
		}
		for(int i=1;i<=q+1;i++)printf("%d",ans[i]);
		return 0;
	}
}