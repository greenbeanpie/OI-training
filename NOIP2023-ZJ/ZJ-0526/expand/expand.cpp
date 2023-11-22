#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int MAXN=5e5+5,inf=1e9+7;
int c,n,m,q,x[MAXN],y[MAXN],ans[100],kx,ky,rx[MAXN],ry[MAXN];
int minn1[MAXN],minn2[MAXN],maxn1[MAXN],maxn2[MAXN];
int my_min(int x,int y){
	if(abs(x)>abs(y))return y;
	return x;
}
bool solve(){
	int flag=0;
	if(x[1]<y[1])flag=1;
	else if(x[1]>y[1])flag=-1;
	else return 0;
	if(x[n]*flag>=y[m]*flag)return 0;
	int t=n-m;
	for(int i=1;i<=n;i++){
		x[i]*=flag;
	}for(int i=1;i<=m;i++){
		y[i]*=flag;
	}
	for(int i=1,j=1;j<=m&&i<=n;j++,i++){
		while(t<0&&x[i]<y[j]){
			j++;
			t++;
		}
		while(t>0&&x[i]<y[j]){
			i++;
			t--;
		}
		if(x[i]>=y[j]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
		rx[i]=x[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&y[i]);
		ry[i]=y[i];
	}
	ans[0]=solve();
	for(int i=1;i<=q;i++){
		scanf("%d%d",&kx,&ky);
		while(kx--){
			int p,v;
			scanf("%d%d",&p,&v);
			x[p]=v;
		}
		while(ky--){
			int p,v;
			scanf("%d%d",&p,&v);
			y[p]=v;
		}
		ans[i]=solve();
		for(int j=1;j<=n;j++)x[j]=rx[j];
		for(int j=1;j<=m;j++)y[j]=ry[j];
	}
	for(int i=0;i<=q;i++)printf("%d",ans[i]);
	printf("\n");
	return 0;
}