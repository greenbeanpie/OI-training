#include<bits/stdc++.h>
using namespace std;
int f[2005][2005];
int a[2005],b[2005];
int _a[2005],_b[2005];
int c,n,m,q;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)scanf("%d",&_a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&_b[i]);
	for(int i=1,ka=0,kb=0;i<=q+1;i++){
		if(i!=1)scanf("%d%d",&ka,&kb);
		for(int i=1;i<=n;i++)a[i]=_a[i];
		for(int j=1;j<=m;j++)b[j]=_b[j];
		for(int i=1,p,v;i<=ka;i++){
			scanf("%d%d",&p,&v);
			a[p]=v;
		}
		for(int i=1,p,v;i<=kb;i++){
			scanf("%d%d",&p,&v);
			b[p]=v;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=0;
			}
		}
		f[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i]>b[j]){
					f[i][j]=(f[i-1][j]|f[i][j-1]|f[i-1][j-1]);
				}
			}
		}
		if(f[n][m]){
			printf("1");
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=0;
			}
		}
		f[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i]<b[j]){
					f[i][j]=(f[i-1][j]|f[i][j-1]|f[i-1][j-1]);
				}
			}
		}
		if(f[n][m]){
			printf("1");
			continue;
		}
		printf("0");
	}
	return 0;
}