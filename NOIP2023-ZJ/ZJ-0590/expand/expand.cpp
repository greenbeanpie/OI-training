#include<bits/stdc++.h>
int n,m,q,c,x[500005],y[500005];
int kx,ky,p,v,xx[500005],yy[500005];
inline void read(int &x){
	#define cg c=getchar()
	int f=1;x=0;char cg;
	while(c<48||c>57)f-=(c==45)<<1,cg;
	while(c>47&&c<58)x=x*10+(c&15),cg;
	x*=f;return;
}
void pd1(){
	int a=1;
	for(int i=1;i<=n;i++){
		while(1){
			if(xx[i]>=yy[a])a++;
			if((yy[a]<=xx[i-1])||(a>m)){
				printf("0");
				return;
			}
			if(xx[i]<yy[a])break;		
		}
	}
	printf("1");
	return;
}
void pd2(){
	printf("0");
}
signed main(){
	xx[0]=-1;
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	read(c);read(n);read(m);read(q);
	if(c==1){
		read(x[1]);read(y[1]);
		if(x[1]!=y[1])printf("1");
		while(q--){
			xx[1]=x[1];yy[1]=y[1];
			read(kx);read(ky);
			for(int i=1;i<=kx;i++){
				read(p);read(v);
				xx[p]=v;
			}
			for(int i=1;i<=ky;i++){
				read(p);read(v);
				yy[p]=v;
			}
			if(xx[1]!=yy[1])printf("1");
			else printf("0");
		}
		return 0;
	}
	if(c==2){
		read(x[1]);read(x[2]);
		read(y[1]);read(y[2]);
		if((x[1]<y[1]&&x[2]<y[2])||(x[1]>y[1]&&x[2]>y[2]))printf("1");
		else printf("0");
		while(q--){
			xx[1]=x[1];yy[1]=y[1];
			xx[2]=x[2];yy[2]=y[2];
			read(kx);read(ky);
			for(int i=1;i<=kx;i++){
				read(p);read(v);
				xx[p]=v;
			}
			for(int i=1;i<=ky;i++){
				read(p);read(v);
				yy[p]=v;
			}
			if((xx[1]<yy[1]&&xx[2]<yy[2])||(xx[1]>yy[1]&&xx[2]>yy[2]))printf("1");
			else printf("0");
		}
	}
	for(int i=1;i<=n;i++)read(x[i]);
	for(int i=1;i<=m;i++)read(y[i]);
	for(int i=1;i<=n;i++)xx[i]=x[i];
	for(int i=1;i<=m;i++)yy[i]=y[i];
	if(c>=8&&c<=14)pd1();
	else pd2();
	while(q--){
		for(int i=1;i<=n;i++)xx[i]=x[i];
		for(int i=1;i<=m;i++)yy[i]=y[i];
		read(kx);read(ky);
		for(int i=1;i<=kx;i++){
			read(p);read(v);
			xx[p]=v;
		}
		for(int i=1;i<=ky;i++){
			read(p);read(v);
			yy[p]=v;
		}
		if(c>=8&&c<=14)pd1();
		else pd2();
	}
	return 0;
}