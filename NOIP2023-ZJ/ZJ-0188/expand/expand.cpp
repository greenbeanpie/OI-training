#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int C,n,m,Q,x[maxn],y[maxn],a[maxn],b[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	C=read();n=read();m=read();Q=read();
	for(int i=1;i<=n;i++)x[i]=a[i]=read();
	for(int i=1;i<=m;i++)y[i]=b[i]=read();
	if(C==1){
		while(Q--){
			for(int i=1;i<=n;i++)x[i]=a[i],y[i]=b[i];
			int kx=read(),ky=read();
			for(int i=1;i<=kx;i++){
				int px=read(),vx=read();
				x[px]=vx;
			}
			for(int i=1;i<=ky;i++){
				int py=read(),vy=read();
				y[py]=vy;
			}
			putchar('1');
		}
		return 0;
	}
	else if(C==2){
		while(Q--){
			for(int i=1;i<=n;i++)x[i]=a[i],y[i]=b[i];
			int kx=read(),ky=read();
			for(int i=1;i<=kx;i++){
				int px=read(),vx=read();
				x[px]=vx;
			}
			for(int i=1;i<=ky;i++){
				int py=read(),vy=read();
				y[py]=vy;
			}
			if(n==2&&m==2){
				if((x[1]-x[2])*(y[1]-y[2])>0)putchar('1');
				else putchar('0');
			}
			else if(n==2){
				if((x[1]-y[1])*(x[2]-y[1])>0)putchar('1');
				else putchar('0');
			}else{
				if((x[1]-y[1])*(x[1]-y[2])>0)putchar('1');
				else putchar('0');
			}
		}
		return 0;
	}
	while(Q--){
		for(int i=1;i<=n;i++)x[i]=a[i],y[i]=b[i];
		int kx=read(),ky=read();
		for(int i=1;i<=kx;i++){
			int px=read(),vx=read();
			x[px]=vx;
		}
		for(int i=1;i<=ky;i++){
			int py=read(),vy=read();
			y[py]=vy;
		}
		int j=1;int now=0;
		if(x[1]-y[1]<0)now=-1;else if(x[1]-y[1]>0)now=1;
		else {putchar('0');continue;}
		for(int i=2;i<=n;i++){
			if(j<=m&&(x[i]-y[j])*now>0)continue;
			
			else {
				j++;
				while((x[i]-y[j])*now<=0&&j<=m)j++;
			}
		}
		if(j>m)putchar('0');else putchar('1');
	}
	return 0;
}