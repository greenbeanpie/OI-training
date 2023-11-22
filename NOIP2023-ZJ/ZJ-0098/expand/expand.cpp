#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
inline int Read(){
	int c;
	while((c=getchar())<48);
	int R=c^48;
	while((c=getchar())>47)R=(R<<1)+(R<<3)+(c^48);
	return R;
}
typedef long long ll;
int x[500005],y[500005],X[500005],Y[500005];
int mx[25][500005],mn[25][500005];
int Log[500005];
inline int Max(int l,int r){
	int g=Log[r-l+1];
	return max(mx[g][l],mx[g][r-(1<<g)+1]);
}
inline int Min(int l,int r){
	int g=Log[r-l+1];
	return min(mn[g][l],mn[g][r-(1<<g)+1]);
}
int Fax(int L,int sb,int x){
	if(L>sb)return sb;
	if(x<=mx[0][L])return L-1;
	int l=L+1,r=sb,rt=L,md;
	while(l<=r){
		md=(l+r)>>1;
		if(x>Max(L,md)){
			rt=md;
			l=md+1;
		}
		else r=md-1;
	}
	return rt;
}
int Fin(int R,int x){
	if(R<1)return 0;
	if(x<=Min(1,R))return 0;
	if(x>mn[0][R])return R;
	int l=2,r=R,rt=1,md;
	while(l<=r){
		md=(l+r)>>1;
		if(Min(md,R)<x){
			rt=md;
			l=md+1;
		}
		else r=md-1;
	}
	return rt;
}
void sol(int*a,int*b,int sa,int sb){
	int tl=0;
	for(int i=1;i<=sb;i++){
		mx[0][i]=mn[0][i]=b[i];
	}
	for(int i=1;i<=Log[sb];i++){
		for(int j=1;j+(1<<i)-1<=sb;j++){
			mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
			mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
		}
	}
	for(int i=1;i<=sa;i++){
		tl=Fax(tl+1,sb,a[i]);
		tl=Fin(tl,a[i]);
		if(!tl)return printf("0"),void();
	}
	if(tl!=sb)printf("0");
	else printf("1");
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int ccc,n,m,q;
	scanf("%d%d%d%d",&ccc,&n,&m,&q);
	Log[0]=-1;
	for(int i=1;i<=max(n,m);i++)Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;i++){
		x[i]=Read();
	}
	for(int i=1;i<=m;i++){
		y[i]=Read();
	}
	if(x[1]<y[1])sol(y,x,m,n);
	else sol(x,y,n,m);
	while(q--){
		for(int i=1;i<=n;i++){
			X[i]=x[i];
		}
		for(int i=1;i<=m;i++){
			Y[i]=y[i];
		}
		int kx,ky,p,v;
		kx=Read();ky=Read();
		for(int i=1;i<=kx;i++){
			p=Read();
			v=Read();
			X[p]=v;
		}
		for(int i=1;i<=ky;i++){
			p=Read();
			v=Read();
			Y[p]=v;
		}
		if(X[1]<Y[1])sol(Y,X,m,n);
		else sol(X,Y,n,m);		
	}
	return 0;
}