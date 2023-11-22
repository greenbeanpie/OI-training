#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N],n,m,q,kx,ky,c[N],d[N],e[N],mn[N][20],mx[N][20],sum[N],Mn[N];
int Min(int x,int y){return b[x]<b[y]?x:y;}
int Max(int x,int y){return b[x]>b[y]?x:y;}
int askmin(int l,int r){
	if(l>r)return -1;
	int t=__lg(r-l+1);
	return Min(mn[l][t],mn[r-(1<<t)+1][t]);
}
int askmax(int l,int r){
	if(l>r)return -1;
	int t=__lg(r-l+1);
	return Max(mx[l][t],mx[r-(1<<t)+1][t]);
}
void make(){sum[n+1]=0;
	for(int i=n;i>=1;i--)sum[i]=max(sum[i+1],a[i]);
	Mn[n+1]=-1;
	for(int i=n;i>=1;i--)
		if(i==n)Mn[i]=n;
		else if(a[Mn[i+1]]<a[i])Mn[i]=Mn[i+1];
		else Mn[i]=i;
	for(int i=1;i<=m;i++)mn[i][0]=mx[i][0]=i;
	for(int j=1;j<=19;j++)
		for(int i=1;i+(1<<j)-1<=m;i++){
			mn[i][j]=Min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
			mx[i][j]=Max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
		}	
}
int ask(int x,int y){
	if(a[x]<=b[y])return 0;
	if(x==n){while(y<=m&&a[x]>b[y])y++;return y>m;}
	if(y==m){while(x<=n&&a[x]>b[y])x++;return x>n;}
	if(a[x]>=sum[x]){
		int p=y-1,mn=Mn[x];
		while(1){
			int w=askmin(p+1,m);
			if(w!=-1&&b[w]<a[mn])p=w;
			else break;
		}p=max(p,y);
		if(b[p]>=a[mn])return 0;
		if(b[askmax(y,p)]>=a[x])return 0;
		return ask(mn,p);
	}int p=x+1,mn=x;
	while(p<=n&&a[p]<=a[x]){
		if(a[p]<=a[mn])mn=p;
		p++;
	}while(y<=m&&a[x]>b[y]&&b[y]>=a[mn])y++;
	if(y>m||a[x]<=b[y])return 0;
	return ask(p,y);
}
bool chk(){
	if(a[1]<=b[1])return 0;
	int mx1=0,mx2=0;
	for(int i=1;i<=n;i++)mx1=max(mx1,a[i]);
	for(int i=1;i<=m;i++)mx2=max(mx2,b[i]);
	return mx1>mx2;
}
bool solve(){
	if(chk()){make();if(ask(1,1))return 1;}
	for(int i=1;i<=n;i++)e[i]=a[i];
	for(int i=1;i<=m;i++)a[i]=b[i];
	for(int i=1;i<=n;i++)b[i]=e[i];swap(n,m);
	bool flag=0;if(chk()){make();flag=ask(1,1);}
	for(int i=1;i<=n;i++)e[i]=a[i];
	for(int i=1;i<=m;i++)a[i]=b[i];
	for(int i=1;i<=n;i++)b[i]=e[i];
	swap(n,m);return flag;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%*d%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),c[i]=a[i];
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),d[i]=b[i];
	printf("%d",solve());
	while(q--){
		scanf("%d%d",&kx,&ky);
		for(int i=1,p,w;i<=kx;i++){scanf("%d%d",&p,&w);a[p]=w;}
		for(int i=1,p,w;i<=ky;i++){scanf("%d%d",&p,&w);b[p]=w;}
		printf("%d",solve());
		for(int i=1;i<=n;i++)a[i]=c[i];
		for(int i=1;i<=m;i++)b[i]=d[i];
	}
}
