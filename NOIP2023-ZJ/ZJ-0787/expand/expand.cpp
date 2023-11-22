#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int read(){
	int f=1,k=0;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){k=k*10+c-'0';c=getchar();}
	return f*k;
}
int c1,n,m,q;
int a[N],b[N],kx[N],ky[N],c[N],d[N];
int ans[N];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c1=read();n=read();m=read();q=read();
	for(int i=1;i<=n;i++) a[i]=read(),c[i]=a[i];
	for(int i=1;i<=m;i++) b[i]=read(),d[i]=a[i];
	if(n==1 && m==1){
		for(int i=0;i<=q;i++) printf("1");
		return 0;
	}
	if(a[1]>b[1]){
		int j=1,i=1;
		if(a[n]<=b[m]) ans[0]=0;
		else{
			while(i<=n && j<=m){
				if(a[i]<=b[j]){
					while(a[i]<=b[j] && i>=1) i--;
					if(i==0){ans[0]=-1;break;}
					else i++,j++;
				}
				else i++,j++;
			}
			if(ans[0]!=-1) ans[0]=1;
			else ans[0]=0;
		}
	}
	else if(a[1]<b[1]){
		int j=1,i=1;
		if(a[n]>=b[m]) ans[0]=0;
		else{
			while(i<=n && j<=m){
				if(a[i]>=b[j]){
					while(a[i]>=b[j] && i>=1) i--;
					if(i==0){ans[0]=-1;break;}
					else i++,j++;
				}
				else i++,j++;
			}
			if(ans[0]!=-1) ans[0]=1;			
			else ans[0]=0;
		}
	}
	else ans[0]=0;
	for(int k=1;k<=q;k++){
		kx[k]=read();ky[k]=read();
		for(int j=1;j<=kx[k];j++){
			int p=read(),v=read();
			a[p]=v;
		}
		for(int j=1;j<=ky[k];j++){
			int p=read(),v=read();
			b[p]=v;
		}
		if(a[1]>b[1]){
			int j=1,i=1;
			if(a[n]<=b[m]) ans[k]=0;
			else{
				while(i<=n && j<=m){
					if(a[i]<=b[j]){
						while(a[i]<=b[j] && i>=1) i--;
						if(i==0){ans[k]=-1;break;}
						else i++,j++;
					}
					else i++,j++;
				}
				if(ans[k]!=-1) ans[k]=1;
				else ans[k]=0;				
			}
		}
		else if(a[1]<b[1]){
			int j=1,i=1;
			if(a[n]>=b[m]) ans[k]=0;
			else{
				while(i<=n && j<=m){
					if(a[i]>=b[j]){
						while(a[i]>=b[j] && i>=1) i--;
						if(i==0){ans[k]=-1;break;}
						else i++,j++;
					}
					else i++,j++;
				}
				if(ans[k]!=-1) ans[k]=1;
				else ans[k]=0;				
			}
		}
		else{ans[k]=0;}
		for(int i=1;i<=n;i++) a[i]=c[i];
		for(int i=1;i<=m;i++) b[i]=d[i];
	}
	for(int i=0;i<=q;i++) printf("%d",ans[i]);
	return 0;
}
