#include<bits/stdc++.h>
using namespace std;
#define il inline
#define re(i,a,b) for(int i=(a);i<=(b);i++)
il int read(){
	char c=getchar();
	int ret=0;
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret;
}
int c,n,m,q,x[500005],y[500005];
namespace algo1{
	int cx[500005],cy[500005];
	bool f[7005][7005];
	il void p0(){putchar('0');}
	il void p1(){putchar('1');}
	il bool gre(int a,int b){return a>b;}
	il bool les(int a,int b){return a<b;}
	bool(*cmp)(int,int);
	il void solve(){
		if(cx[1]>cy[1]&&cx[n]>cy[m]){
			cmp=gre;
		}
		else if(cx[1]<cy[1]&&cx[n]<cy[m]){
			cmp=les;
		}
		else{
			p0();
			return;
		}
		memset(f,0,sizeof(f));
//		re(i,1,n){
//			f[i][0]=true;
//		}
//		re(j,1,m){
//			f[0][j]=true;
//		}
		re(j,1,m){
			if(cmp(cx[1],cy[j]))f[1][j]=true;
			else break;
		}
		re(i,1,n){
			if(cmp(cx[i],cy[1]))f[i][1]=true;
			else break;
		}
		re(i,2,n){
			re(j,1,m){
				if(cmp(cx[i],cy[j]))f[i][j]=f[i-1][j-1]|f[i-1][j]|f[i][j-1];
			}
		}
		if(f[n][m])p1();
		else p0();
	}
	il void run(){
		memcpy(cx,x,sizeof(int)*(n+5));
		memcpy(cy,y,sizeof(int)*(m+5));
		solve();
		re(i,1,q){
			memcpy(cx,x,sizeof(int)*(n+5));
			memcpy(cy,y,sizeof(int)*(m+5));
			int kx=read(),ky=read();
			re(j,1,kx){
				int p=read(),v=read();
				cx[p]=v;
			}
			re(j,1,ky){
				int p=read(),v=read();
				cy[p]=v;
			}
//			re(d,1,n){
//				printf("%d ",cx[d]);
//			}
//			putchar('\n');
//			re(d,1,m){
//				printf("%d ",cy[d]);
//			}
			solve();
		}
		putchar('\n');
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	re(i,1,n){
		x[i]=read();
	}
	re(i,1,m){
		y[i]=read();
	}
	algo1::run();
	return 0;
}
