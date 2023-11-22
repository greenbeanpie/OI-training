#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();
	int res=0,b=1;
	while(!isdigit(c)){
		if(c=='-') b=-1;
		c=getchar();
	}
	while(isdigit(c)){
		res=res*10+(c^48);
		c=getchar();
	}
	return res*b;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9){
		write(x/10);
		putchar(x%10+'0');
	}
	else {
		putchar(x+'0');
	}
}
inline bool print(int x){
	write(x);
	putchar(' ');
	return 0;
}
inline bool put(int x){
	write(x);
	putchar('\n');
	return 0;
}
namespace sub1{
	int main(){
		int n=read(),m=read(),q=read();
		int x=read(),y=read();
		if(x==y) putchar('0');
		else putchar('1');
		for(int i=1;i<=q;++i){
			int kx=read(),ky=read(),px,vx=x,py,vy=y;
			for(int i=1;i<=kx;++i) px=read(),vx=read();
			for(int i=1;i<=ky;++i) py=read(),vy=read();
			if(vx==vy) putchar('0');
			else putchar('1');
		}	
		return 0;
	}
}
namespace sub2{
	int x[3],y[3],_x[3],_y[3];
	int main(){
		int n=read(),m=read(),q=read();
		for(int i=1;i<=n;++i) x[i]=read();
		for(int i=1;i<=m;++i) y[i]=read();
		if((x[1]-y[1])*(x[n]-y[m])<=0) putchar('0');
		else putchar('1');
		for(int i=1;i<=q;++i){
			for(int j=1;j<=n;++j) _x[j]=x[j];
			for(int j=1;j<=m;++j) _y[j]=y[i];
			int kx=read(),ky=read(),px,vx,py,vy;
			for(int j=1;j<=kx;++j) {
				px=read(),vx=read();
				_x[px]=vx;
			}
			for(int j=1;j<=ky;++j) {
				py=read(),vy=read();
				_y[py]=vy;
			}
			if((_x[1]-_y[1])*(_x[n]-_y[m])<=0) putchar('0');
			else putchar('1');
		}	
		return 0;
	}
}
namespace sub3{
	const int N=5e5+5;
	int x[N],y[N],_x[N],_y[N],mxx,mxy,mnx,mny;
	int main(){
		int n=read(),m=read(),q=read();
		for(int i=1;i<=n;++i) x[i]=read(),mxx=max(x[i],mxx),mnx=min(x[i],mnx);
		for(int i=1;i<=m;++i) y[i]=read(),mxy=max(mxy,y[i]),mny=min(y[i],mny);
		if((x[1]-y[1])*(x[n]-y[m])<=0) putchar('0');
		else {
			if((x[1]-y[1])*(mxx-mxy)<=0) putchar('0');
			else putchar('1');
		}
		for(int i=1;i<=q;++i){
			_x[1]=x[1],_x[n]=x[n],_y[1]=y[1],_y[m]=y[m];
			int _mxx=mxx,_mxy=mxy;
			int kx=read(),ky=read(),px,vx,py,vy;
			for(int i=1;i<=kx;++i) {
				px=read(),vx=read();
				_x[px]=vx;
				_mxx=max(_mxx,vx);
			}
			for(int i=1;i<=ky;++i) {
				py=read(),vy=read();
				_y[py]=vy;
				_mxy=max(_mxy,vy);
			}
			if((_x[1]-_y[1])*(_x[n]-_y[m])<=0) putchar('0');
			else {
				if((_x[1]-_y[1])*(_mxx-_mxy)<=0) putchar('0');
				else putchar('1');
			}
		}	
		return 0;
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c=read();
	if(c==1){
		sub1::main();
	}
	else if(c==2){
		sub2::main();
	}
	else sub3::main();
	return 0;
}