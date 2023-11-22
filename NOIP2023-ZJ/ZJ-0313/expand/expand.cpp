#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,q;
ll a[500005],b[500005],tmpa[500005],tmpb[500005];
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f==1?x:-x;
}
bool check(){
	if((a[1]-b[1])*(a[n]-b[m])<=0) return false;
	ll Maxa=0,Mina=1000000000,Minb=1000000000,Maxb=0;
	for(int i=1;i<=n;i++){
		Maxa=max(Maxa,a[i]);
		Mina=min(Mina,a[i]);
	}
	for(int i=1;i<=m;i++){
		Maxb=max(Maxb,b[i]);
		Minb=min(Minb,b[i]);
	}
	//cout<<Mina<<' '<<Maxa<<' '<<Minb<<' '<<Maxb<<' '<<endl;
	if((a[1]-b[1])*(Mina-Minb)<=0||(a[1]-b[1])*(Maxa-Maxb)<=0)
		return false;
	return true;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		b[i]=read();
	}
	cout<<check();
	while(q--){
		for(int i=1;i<=n;i++){
			tmpa[i]=a[i];
		}
		for(int i=1;i<=m;i++){
			tmpb[i]=b[i];
		}
		ll kx,ky,vx,vy,px,py;
		kx=read(),ky=read();
		for(int i=1;i<=kx;i++){
			px=read();
			vx=read();
			a[px]=vx;
		}
		for(int i=1;i<=ky;i++){
			py=read();
			vy=read();
			b[py]=vy;
		}
//		for(int i=1;i<=n;i++){
//			cout<<a[i]<<' ';
//		}
//		cout<<endl;
//		for(int i=1;i<=m;i++){
//			cout<<b[i]<<' ';
//		}
//		cout<<endl;
		cout<<check();
		for(int i=1;i<=n;i++){
			a[i]=tmpa[i];
		}
		for(int i=1;i<=m;i++){
			b[i]=tmpb[i];
		}
	}
	cout<<endl;
	return 0;
}