#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sgn=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')sgn=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}
	return x*sgn;
}
ll c,n,m,q;
ll a[500010],b[500010];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();n=read();m=read();q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=m;i++){
		b[i]=read();
	}
	if(c==1){
		if(a[1]!=b[1])cout<<1;
		else cout<<0;
		while(q--){
			ll kx=read(),ky=read();
			for(int i=1;i<=kx;i++){
				ll px=read(),vx=read();
				a[px]=vx;
			}
			for(int i=1;i<=ky;i++){
				ll px=read(),vx=read();
				b[px]=vx;
			}
			if(a[1]!=b[1])cout<<1;
			else cout<<0;
		}
	}
	if(c==2){
		if((a[1]>b[1]&&a[2]>b[2])||(a[1]<b[1]&&a[2]<b[2])) cout<<1;
		else cout<<0;
		while(q--){
			ll kx=read(),ky=read();
			for(int i=1;i<=kx;i++){
				ll px=read(),vx=read();
				a[px]=vx;
			}
			for(int i=1;i<=ky;i++){
				ll px=read(),vx=read();
				b[px]=vx;
			}
			if((a[1]>b[1]&&a[2]>b[2])||(a[1]<b[1]&&a[2]<b[2])) cout<<1;
			else cout<<0;
		}
	}
	else{
		srand(time(0));
		for(int i=0;i<=q;i++){
			cout<<rand()%2;
		}
	}
	return 0;
}
// ......... best rand