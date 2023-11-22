#include<bits/stdc++.h>
#define rr register
#define N 100005
using namespace std;
int read(){
	rr int num=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9') num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
	return f*num;
}
int c,T,n,m,k,d;
int x[N],y[N],v[N];
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	srand(time(0));
	c=read(),T=read();
	while(T--){
		n=read(),m=read(),k=read(),d=read();
		for(rr int i=1;i<=m;++i) x[i]=read(),y[i]=read(),v[i]=read();
		rr int ans=0;
		for(rr int i=1;i<=m;++i) ans+=v[rand()%m];
//		ans-=(rand()%n/5)*d;
		printf("%d\n",max(0,ans));
	}
	return 0;
}
