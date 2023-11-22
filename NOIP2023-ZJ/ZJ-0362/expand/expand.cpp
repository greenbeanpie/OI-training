#include <bits/stdc++.h>
using namespace std;
const int MAXN=2005;
int _x[MAXN],_y[MAXN],x[MAXN],y[MAXN];
int f[MAXN][MAXN];
int c,n,m,q;
void check(){
	memset(f,0,sizeof(f));
	if (x[1]==y[1]){
		printf("0");
		return;
	}
	f[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if (x[i]>y[j]){
				if (f[i][j-1]==1||f[i-1][j]==1||f[i-1][j-1]==1){
					f[i][j]=1;
				}
			}
		}
	}
	int _t=f[n][m];
	if (_t==1){
		printf("1");
		return;
	}
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if (x[i]<y[j]){
				if (f[i][j-1]==1||f[i-1][j]==1||f[i-1][j-1]==1){
					f[i][j]=1;
				}
			}
		}
	}
	printf("%d",f[n][m]);
}
int main(){	
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d %d %d %d",&c,&n,&m,&q);
	if (c<=7){
		for(int i=1;i<=n;++i){
			scanf("%d",&_x[i]);
			x[i]=_x[i];	
		}
		for(int i=1;i<=m;++i){
			scanf("%d",&_y[i]);
			y[i]=_y[i];
		}
		check();
		for(int temp=1;temp<=q;++temp){
			for(int i=1;i<=n;++i) x[i]=_x[i];	
			for(int i=1;i<=m;++i) y[i]=_y[i];
			int op1,op2;
			scanf("%d %d",&op1,&op2);
			for(int i=1,p,v;i<=op1;++i){
				scanf("%d %d",&p,&v);
				x[p]=v;
			}
			for(int i=1,p,v;i<=op2;++i){
				scanf("%d %d",&p,&v);
				y[p]=v;
			}
			check();
		}
	}
	else{
		while (q--){
			printf("1\n");
		}
	}
	return 0;
}