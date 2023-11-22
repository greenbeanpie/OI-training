#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
const int N=5e5+10;
int a[N],b[N],n,m,q,c;
void ck(){
	for(int i=1;i<=n;i++){
		if(a[i]>b[i]) {
			printf("1");
			return;
		}
		else {
			printf("0");
			return;
		}
	}
}
void work1(){
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	ck();
	while(q--){
		int kx=read(),ky=read();
		for(int i=1;i<=kx;i++){
			int p=read(),x=read();
			a[p]=x;
		}
		for(int i=1;i<=ky;i++){
			int p=read(),x=read();
			b[p]=x;
		}
		ck();
	}
}
void ck2(){
	if(n==2&&m==2){
		if((a[1]-b[1])*(a[2]-b[2])>0) printf("1");
		else printf("0");
		return;
	}
	if(n==1&&m==2){
		if((a[1]-b[1])*(a[1]-b[2])>0) printf("1");
		else printf("0");
		return;
	}
	if(n==2&&m==1){
		if((a[1]-b[1])*(a[2]-b[1])>0) printf("1");
		else printf("0");
		return;
	}
}
void work2(){
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	ck2();
	while(q--){
		int kx=read(),ky=read();
		for(int i=1;i<=kx;i++){
			int p=read(),x=read();
			a[p]=x;
		}
		for(int i=1;i<=ky;i++){
			int p=read(),x=read();
			b[p]=x;
		}
		ck2();
	}
}
void work3(){
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	ck2();
	while(q--){
		int kx=read(),ky=read();
		for(int i=1;i<=kx;i++){
			int p=read(),x=read();
			a[p]=x;
		}
		for(int i=1;i<=ky;i++){
			int p=read(),x=read();
			b[p]=x;
		}
		ck2();
	}
}
void ck5(){
	int s=a[1]-b[1];
	if(a[n]>b[m]) printf("0");
	else{
		bool f=1;
		for(int i=2;i<=min(n,m);i++){
			if((a[i]-b[i])*s<=0) {
				f=0;
				break;
				printf("0"); 
			}
		}
		if(f) printf("1");
	}
}
void work(){
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	ck5();
	while(q--){
		int kx=read(),ky=read();
		for(int i=1;i<=kx;i++){
			int p=read(),x=read();
			a[p]=x;
		}
		for(int i=1;i<=ky;i++){
			int p=read(),x=read();
			b[p]=x;
		}
		ck5();
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	if(c==1) work1();
	else if(c==2) work2();
	else if(c==3||c==4) work3();
	else work();
	return 0;
}
