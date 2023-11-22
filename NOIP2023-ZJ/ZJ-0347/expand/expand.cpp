#include<iostream>
#include<cstdio>
#define maxn 500005
using namespace std;
int id,n,m,T,in[2][maxn],lx,ly,pos,val,res[2][maxn]; bool f[2005][2005];
bool chk(){
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) f[i][j]=0; f[1][1]=1;
	if(res[0][1]>res[1][1]){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) if(!(i==1&&j==1)){
				for(int k=i;k>=1;k--) if(res[1][j]<res[0][k]) f[i][j]|=f[k-1][j]; else break;
				for(int k=j;k>=1;k--) if(res[0][i]>res[1][k]) f[i][j]|=f[i][k-1]; else break;
			}
		} return f[n][m];
	}else if(res[0][1]<res[1][1]){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) if(!(i==1&&j==1)){
				for(int k=i;k>=1;k--) if(res[1][j]>res[0][k]) f[i][j]|=f[k-1][j]; else break;
				for(int k=j;k>=1;k--) if(res[0][i]<res[1][k]) f[i][j]|=f[i][k-1]; else break;
			}
		} return f[n][m];
	} return 0;
}
int main(){
	freopen("expand.in","r",stdin); freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&id,&n,&m,&T);
	for(int i=1;i<=n;i++) scanf("%d",&in[0][i]),res[0][i]=in[0][i];
	for(int i=1;i<=m;i++) scanf("%d",&in[1][i]),res[1][i]=in[1][i];
	if(chk()) printf("1"); else printf("0");
	while(T--){
		scanf("%d%d",&lx,&ly);
		for(int i=1;i<=n;i++) res[0][i]=in[0][i]; for(int i=1;i<=m;i++) res[1][i]=in[1][i];
		for(int i=1;i<=lx;i++){scanf("%d%d",&pos,&val); res[0][pos]=val;}
		for(int i=1;i<=ly;i++){scanf("%d%d",&pos,&val); res[1][pos]=val;}
		if(chk()) printf("1"); else printf("0");
	}
	return 0;
}
