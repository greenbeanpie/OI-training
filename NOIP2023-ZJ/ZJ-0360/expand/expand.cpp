#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10,inf=1e15;
ll read(){
	ll x=0,sgn=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')sgn*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}
	return x*sgn;
}
ll n,m,c,q;
ll a[N],b[N];
ll px,py,vx,vy;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();n=read();m=read();q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int j=1;j<=m;j++)b[j]=read();
	if((a[1]-b[1])*(a[n]-b[m])>0)cout<<"1";
	else cout<<"0";
	for(int i=1;i<=q;i++){
		ll kx=read(),ky=read();
		for(int j=1;j<=kx;j++){
			px=read();vx=read();
			a[px]=vx;
		}
		for(int j=1;j<=ky;j++){
			py=read();vy=read();
			b[py]=vy;
		}
		if((a[1]-b[1])*(a[n]-b[m])>0)cout<<"1";
		else cout<<"0";
	}
	return 0;
}
//T#YMS@4
//1 1
//10 10
//- 9 8
//- 8 6
//- 6 5
//- 5 4
//- 4 3
//+ 3 9
//- 1 2
//+ 2 7
//+ 7 10
//- 10 1
