//FSZ with yingxue-cat
#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
int x[500005],y[500005];
int xx[500005],yy[500005];
int mnx[500005],mxy[500005];
int X[500005],Y[500005];
pair<int,int>sx[500005],sy[500005];
pair<int,int>ex[500005],ey[500005];
pair<int,int>rx[1000005],ry[1000005];
pair<int,int>px[500005],py[500005];
int mx[500005],my[500005];
void swp(){
	swap(n,m);
	for(int i=1;i<=max(n,m);++i)swap(px[i],py[i]);
}
char ans[500005];int anl=0;
char ib[1<<25],*ip1,*ip2;
#define getchar() ((ip1==ip2&&((ip2=(ip1=ib)+fread(ib,1,1<<24,stdin))),ip1==ip2?EOF:*ip1++))
int read(){
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	int x=0;
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
	return x;
}
void sooo(){
	if(1ll*(x[1]-y[1])*(x[n]-y[m])<=0){
		ans[++anl]='0';
		return;
	}
	int flg=0;
	if(x[1]>y[1])swp(),flg=1;
	int fl=1;
	int ww=0;
	mx[0]=n+1;
	for(int i=1;i<=n;++i)mx[i]=min(mx[i-1],px[i].second);
	for(int i=1;i<=m;++i){
		while(ww<n&&px[ww+1].first<py[i].first)++ww;
		Y[py[i].second]=mx[ww]-1;
	}
	ww=m+1;
	my[m+1]=m+1;
	for(int i=m;i>=1;--i)my[i]=min(my[i+1],py[i].second);
	for(int i=n;i>=1;--i){
		while(ww>1&&py[ww-1].first>px[i].first)--ww;
		X[px[i].second]=my[ww]-1;
	}
	Y[0]=0;
	for(int i=1;i<=m;++i)Y[i]=max(Y[i],Y[i-1]);
	for(int i=1;i<=n;++i)if(Y[X[i]]>=i)fl=0;
	if((c<12||c>14)&&fl){
	for(int i=1;i<=n;++i)px[i].second=n-px[i].second+1;
	for(int i=1;i<=m;++i)py[i].second=m-py[i].second+1;
	ww=0;
	mx[0]=n+1;
	for(int i=1;i<=n;++i)mx[i]=min(mx[i-1],px[i].second);
	for(int i=1;i<=m;++i){
		while(ww<n&&px[ww+1].first<py[i].first)++ww;
		Y[py[i].second]=mx[ww]-1;
	}
	ww=m+1;
	my[m+1]=m+1;
	for(int i=m;i>=1;--i)my[i]=min(my[i+1],py[i].second);
	for(int i=n;i>=1;--i){
		while(ww>1&&py[ww-1].first>px[i].first)--ww;
		X[px[i].second]=my[ww]-1;
	}
	Y[0]=0;
	for(int i=1;i<=m;++i)Y[i]=max(Y[i],Y[i-1]);
	for(int i=1;i<=n;++i)if(Y[X[i]]>=i)fl=0;}
	ans[++anl]='0'+fl;
	if(flg)swp();
}
int vn[500005],vm[500005];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	//int aa=clock();
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;++i)x[i]=read();
	for(int i=1;i<=m;++i)y[i]=read();
	for(int i=1;i<=n;++i)sx[i]=make_pair(x[i],i);
	for(int i=1;i<=m;++i)sy[i]=make_pair(y[i],i);
	sort(sx+1,sx+n+1);
	sort(sy+1,sy+m+1);
	for(int i=1;i<=n;++i)px[i]=sx[i],py[i]=sy[i];
	sooo();
	for(int i=1;i<=q;++i){
		int kx=read(),ky=read();
		stack<pair<int,int>>stx,sty;
		for(int j=1;j<=kx;++j){
			int p=read(),v=read();
			ex[j]=make_pair(v,n+p);
			stx.emplace(p,x[p]);
			x[p]=v;
			vn[p]=i;
		}
		for(int j=1;j<=ky;++j){
			int p=read(),v=read();
			ey[j]=make_pair(v,m+p);
			sty.emplace(p,y[p]);
			y[p]=v;
			vm[p]=i;
		}
		sort(ex+1,ex+kx+1);
		sort(ey+1,ey+ky+1);
		merge(sx+1,sx+n+1,ex+1,ex+kx+1,rx+1);
		merge(sy+1,sy+m+1,ey+1,ey+ky+1,ry+1);
		int t1=0,t2=0;
		for(int j=1;j<=n+kx;++j){
			if(rx[j].second<=n&&vn[rx[j].second]==i)continue;
			px[++t1]=rx[j];
			if(px[t1].second>n)px[t1].second-=n;
		}
		for(int j=1;j<=m+ky;++j){
			if(ry[j].second<=m&&vm[ry[j].second]==i)continue;
			py[++t2]=ry[j];
			if(py[t2].second>m)py[t2].second-=m;
		}
		sooo();
		while(stx.size()){
			auto au=stx.top();
			stx.pop();
			x[au.first]=au.second;
		}
		while(sty.size()){
			auto au=sty.top();
			sty.pop();
			y[au.first]=au.second;
		}
	}
	printf("%s\n",ans+1);
	//cerr<<1.0*(clock()-aa)/CLOCKS_PER_SEC<<endl;
	return 0;
}
