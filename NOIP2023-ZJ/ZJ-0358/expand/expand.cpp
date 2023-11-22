#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int c,n,m,q,a[maxn],b[maxn],a1[maxn],b1[maxn];
inline int read(){
	int f=1,s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return f*s;
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=m;i++){
		b[i]=read();
	}
	if((c==1) || (m==1 && n==1)){
		if(a[1]!=b[1]){
			printf("1");
		}
		else{
			printf("0");
		}
		while(q--){
			int kx,ky,px,vx=a[1],py,vy=b[1];
			kx=read();
			ky=read();
			for(int i=1;i<=kx;i++){
				px=read();
				vx=read();
			}
			for(int i=1;i<=ky;i++){
				py=read();
				vy=read();
			}
			if(vx==vy){
				printf("0");
			}
			else{
				printf("1");
			}
		}
	}
	else if(c==2){
		if(n==2 && m==2){
			int x1=a[1],x2=a[2],y1=b[1],y2=b[2],kx,ky,px,vx,py,vy;
			if((x1>y1 && x2>y2) || (x1<y1 && x2<y2)){
				printf("1");
			}
			else{
				printf("0");
			}
			while(q--){
				x1=a[1];
				x2=a[2];
				y1=b[1];
				y2=b[2];
				kx=read();
				ky=read();
				for(int i=1;i<=kx;i++){
					px=read();
					vx=read();
					if(px==1){
						x1=vx;
					}
					else{
						x2=vx;
					}
				}
				for(int i=1;i<=ky;i++){
					py=read();
					vy=read();
					if(py==1){
						y1=vy;
					}
					else{
						y2=vy;
					}
				}
				if((x1>y1 && x2>y2) || (x1<y1 && x2<y2)){
					printf("1");
				}
				else{
					printf("0");
				}
			}
		}
		else if(n==1){
			int x=a[1],y1=b[1],y2=b[2],kx,ky,px,vx,py,vy;
			if((x<y1 && x<y2) || (x>y1 && x>y2)){
				printf("1");
			}
			else{
				printf("0");
			}
			while(q--){
				x=a[1];
				y1=b[1];
				y2=b[2];
				kx=read();
				ky=read();
				for(int i=1;i<=kx;i++){
					px=read();
					vx=read();
					x=vx;
				}
				for(int i=1;i<=ky;i++){
					py=read();
					vy=read();
					if(py==1){
						y1=vy;
					}
					else{
						y2=vy;
					}
				}
				if((x<y1 && x<y2) || (x>y1 && x>y2)){
					printf("1");
				}
				else{
					printf("0");
				}
			}
		}
		else{
			int x=b[1],y1=a[1],y2=a[2],kx,ky,px,vx,py,vy;
			if((x<y1 && x<y2) || (x>y1 && x>y2)){
				printf("1");
			}
			else{
				printf("0");
			}
			while(q--){
				x=b[1];
				y1=a[1];
				y2=a[2];
				kx=read();
				ky=read();
				for(int i=1;i<=kx;i++){
					py=read();
					vy=read();
					if(py==1){
						y1=vy;
					}
					else{
						y2=vy;
					}
				}
				for(int i=1;i<=ky;i++){
					py=read();
					vy=read();
					x=vy;
				}
				if((x<y1 && x<y2) || (x>y1 && x>y2)){
					printf("1");
				}
				else{
					printf("0");
				}
			}
		}
	}
	else{
		if((a[1]>b[1] && a[n]>b[m]) || (a[1]<b[1] && a[n]<b[m])){
			printf("1");
		}
		else{
			printf("0");
		}
		while(q--){
			int kx,ky,px,py,vx,vy;
			kx=read();
			ky=read();
			for(int i=1;i<=n;i++){
				a1[i]=a[i];
			}
			for(int i=1;i<=m;i++){
				b1[i]=b[i];
			}
			for(int i=1;i<=kx;i++){
				px=read();
				vx=read();
				a1[px]=vx;
			}
			for(int i=1;i<=ky;i++){
				py=read();
				vy=read();
				b1[py]=vy;
			}
			if((a1[1]>b1[1] && a1[n]>b1[m]) || (a1[1]<b1[1] && a1[n]<b1[m])){
				printf("1");
			}
			else{
				printf("0");
			}
		}
	}
	return 0;
}