#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int c,n,m,q;
int x[N],y[N];
void solve1(){//c==1,n=m=1,f1<g1 or f1>g1 --> (zheng)^2 or (fu)^2 >0
	if(x[1]!=y[1])cout<<1;
	else	cout<<0;
}
void solve2(){//c=2,n=m=2
	if(x[1]>y[1]&&x[1]>y[2]&&x[2]>y[1]&&x[2]>y[2])	cout<<1;
	else	cout<<0;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)	scanf("%d",&x[i]);
	for(int i=1;i<=n;i++)	scanf("%d",&y[i]);
	if(c==1)	solve1();
	else	if(c==2)	solve2();
	while(q--){
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		int adx[kx],ady[ky],nex[kx],ney[ky],bex[kx],bey[ky];
		for(int i=1;i<=kx;i++){
			scanf("%d%d",&adx[i],&nex[i]);
			bex[adx[i]]=x[adx[i]];x[adx[i]]=nex[i];
		}
		for(int i=1;i<=ky;i++)	{
			scanf("%d%d",&ady[i],&ney[i]);
			bey[ady[i]]=y[ady[i]];y[ady[i]]=ney[i];
		}
		if(c==1)	solve1();
		else	if(c==2)	solve2();
		for(int i=1;i<=kx;i++)
		x[adx[i]]=bex[adx[i]];
		for(int i=1;i<=ky;i++)	y[ady[i]]=bey[ady[i]];
	}
	return 0;
}
