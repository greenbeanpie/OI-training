#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,q,x[N],y[N],lstx[N],lsty[N],p1[N],p2[N],v1[N],v2[N];
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();n=read();m=read();q=read();
	for(register int i = 1; i <= n; i++) x[i]=read(),lstx[i]=x[i];
	for(register int i = 1; i <= m; i++) y[i]=read(),lsty[i]=y[i];
	if(n==1 && m==1){
		printf("1");
		while(q--){
			int kx,ky;
			scanf("%d%d", &kx, &ky);
			for(int i = 1; i <= kx; i++){
				scanf("%d%d", &p1[i], &v1[i]);
			}
			for(int i = 1; i <= ky; i++){
				scanf("%d%d", &p2[i], &v2[i]);
			}
			printf("1");
		}
	}else if(n==2 || m==2){
		if(n==m){
			if(x[1]<y[1] && x[2]<y[2] || x[1]>y[1] && x[2]>y[2]) printf("1");
			else printf("0");
		}else if(n==2){
			if(x[1]>y[1] && x[2]>y[1] || x[1]<y[1] && x[2]<y[1]) printf("1");
			else printf("0");
		}else{
			if(x[1]>y[1] && x[1]>y[2] || x[1]<y[1] && x[1]<y[2]) printf("1");
			else printf("0");
		}
		while(q--){
			int kx,ky;
			scanf("%d%d", &kx, &ky);
			for(int i = 1; i <= kx; i++){
				scanf("%d%d", &p1[i], &v1[i]);
				x[p1[i]]=v1[i];
			}
			for(int i = 1; i <= ky; i++){
				scanf("%d%d", &p2[i], &v2[i]);
				y[p2[i]]=v2[i];
			}	
			if(n==m){
				if(x[1]<y[1] && x[2]<y[2] || x[1]>y[1] && x[2]>y[2]) printf("1");
				else printf("0");
			}else if(n==2){
				if(x[1]>y[1] && x[2]>y[1] || x[1]<y[1] && x[2]<y[1]) printf("1");
				else printf("0");
			}else{
				if(x[1]>y[1] && x[1]>y[2] || x[1]<y[1] && x[1]<y[2]) printf("1");
				else printf("0");
			}
			for(int i = 1; i <= kx; i++) x[p1[i]]=lstx[p1[i]];
			for(int i = 1; i <= ky; i++) y[p2[i]]=lsty[p2[i]];
		}
	}else{
	}
	return 0;
}
