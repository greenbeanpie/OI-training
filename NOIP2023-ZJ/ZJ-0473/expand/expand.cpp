#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,T,x[3005],y[3005],lx,ly,a,b,xx[3005],yy[3005],ans;
inline int read(){
	int p=0,flag=1;
	char ch;
	while((ch=getchar())<'0'||ch>'9')
	if(ch=='-')flag=-1;
	p=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
	p=p*10+ch-'0';
	return flag*p;
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%lld%lld%lld%lld",&c,&n,&m,&T);
	for(int i=1;i<=n;i++){
		x[i]=read();
	}
	for(int i=1;i<=m;i++){
		y[i]=read();
	}
		ans=1;
		if(m==1&&n==1){
			if(x[1]<=y[1])ans=0;
		}
		if(m<=2&&n<=2){
			if(x[1]<=y[1]||x[n]<=y[m])ans=0;
		}
		printf("%lld\n",ans);
	while(T--){
		lx=read();
		ly=read();
		for(int i=1;i<=n;i++)xx[i]=x[i];
		for(int i=1;i<=m;i++)yy[i]=y[i];
		for(int i=1;i<=lx;i++){
			a=read();
			b=read();
			xx[a]=b;
		}
		for(int i=1;i<=ly;i++){
			a=read();
			b=read();
			yy[a]=b;
		}
		ans=1;
		if(m==1&&n==1){
			if(xx[1]<=yy[1])ans=0;
		}
		if(m<=2&&n<=2){
			if(xx[1]<=yy[1]||xx[n]<=yy[m])ans=0;
		}
		printf("%lld",ans);
		
	}
	return 0;
}
