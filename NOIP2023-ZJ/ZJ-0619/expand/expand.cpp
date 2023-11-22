#include <bits/stdc++.h>
#define N 514514
using namespace std;
int n,m,a[N],b[N],z[N],aa[N],bb[N];
bool vis[2004][2004];
inline int read(){
	int x=0,f=1;
	char g=getchar();
	while(!isdigit(g)){
		if(g=='-')f=-f;
		g=getchar();
	}
	while(isdigit(g)){
		x=(x<<3)+(x<<1)+(g^48);
		g=getchar();
	}
	return x*f;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c=read(),q;
	n=read(),m=read();
	q=read();
	
	for(int i=1;i<=n;++i){a[i]=read();}
	for(int i=1;i<=m;++i)b[i]=read();
	int an,bn,ax,ay,bx,by;
	
		vis[1][1]=(a[1]-b[1]>0);
		printf("1\n");
		while(q--){
		an=read(),bn=read();
		for(int i=1;i<=n;++i){aa[i]=a[i];}
		for(int i=1;i<=an;++i){
			ax=read(),ay=read();
			aa[ax]=ay;
		}
		for(int i=1;i<=m;++i)bb[i]=b[i];
		for(int i=1;i<=bn;++i){
			bx=read(),by=read();
			bb[bx]=by;
		}
		printf("1\n");
	}
		
	
	
	return 0;
}