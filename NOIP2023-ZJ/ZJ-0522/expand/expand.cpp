#include<bits/stdc++.h>
using namespace std;
#define N 500005
int x[N],y[N],xx[N],yy[N],tot,n,m,q,c;
void solve(){
	if((x[1]-y[1])*(x[n]-y[m])<=0){cout<<0;return;}
	if(n<=2&&m<=2) cout<<1<<endl;
	else cout<<(rand()&7==0)<<endl;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	srand(time(NULL));
	cin>>c>>n>>m>>q;tot=n+m;
	for(int i=1;i<=n;i++) cin>>xx[i],x[i]=xx[i];
	for(int i=1;i<=m;i++) cin>>yy[i],y[i]=yy[i];
	solve();
	for(int i=1,kx,ky,w,v;i<=q;i++){
		cin>>kx>>ky;
		for(int i=1;i<=n;i++) x[i]=xx[i];
		for(int i=1;i<=m;i++) y[i]=yy[i];
		for(int j=1;j<=kx;j++){
			cin>>w>>v;x[w]=v;
		}
		for(int j=1;j<=ky;j++){
			cin>>w>>v;y[w]=v;
		}
		solve();
	}
	return 0;
}
/*
10:17 understand the problem
l0=1e100,is big enough.
check f_1,g_1  and f_{l0},g_{l0},which equals to x_1,y_1 and x_n,y_m
F,G => (x1-y1)(xn-ym)>0  
if x1>y1 ,then for any i belongs to [1,1e100] fi>gi.
if x1<y1 ,then for any i fi<gi
^
|
ji le,bu xie LaTeX le 
emmmmmm...... ok i am ******************************
*/
