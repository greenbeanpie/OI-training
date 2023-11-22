#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
int c,n,m,q,x[maxn],y[maxn],lstx[maxn],lsty[maxn];
bool f[maxn][maxn];
int read(){
	int ret=0,y=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') y=-y;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<1)+(ret<<3)+(ch&15),ch=getchar();
	return ret*y;
}
void solve(){
	n=read();m=read();q=read();
	for(int i=1;i<=n;i++) lstx[i]=x[i]=read();
	for(int i=1;i<=m;i++) lsty[i]=y[i]=read();
//	for(int i=1;i<=n;i++) printf("%d ",x[i]);puts("");
//	for(int i=1;i<=m;i++) printf("%d ",y[i]);puts("");
	bool flg=x[1]>y[1];
	if(x[1]==y[1]||x[n]==y[m]||(x[1]>y[1]&&x[n]<=y[m])||(x[1]<y[1]&&x[n]>y[m])){
		printf("0");
	}else{
		memset(f,0,sizeof f);f[1][1]=1;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(flg&&x[i]>y[j]&&(f[i][j-1]||f[i-1][j-1]||f[i-1][j])) f[i][j]=1;
			if(!flg&&x[i]<y[j]&&(f[i][j-1]||f[i-1][j-1]||f[i-1][j])) f[i][j]=1;
		}
		printf("%d",f[n][m]);
	}
	while(q--){
		int X=read(),Y=read();
		for(int i=1;i<=n;i++) x[i]=lstx[i];
		for(int i=1;i<=m;i++) y[i]=lsty[i];
		for(int i=1;i<=X;i++){
			int p=read(),nw=read();
			x[p]=nw;
		}
		for(int i=1;i<=Y;i++){
			int p=read(),nw=read();
			y[p]=nw;
		}
//		for(int i=1;i<=n;i++) printf("%d ",x[i]);puts("");
//		for(int i=1;i<=m;i++) printf("%d ",y[i]);puts("");
		bool flg=x[1]>y[1];
		if(x[1]==y[1]||x[n]==y[m]||(x[1]>y[1]&&x[n]<=y[m])||(x[1]<y[1]&&x[n]>y[m])){
			printf("0");
		}else{
			memset(f,0,sizeof f);f[1][1]=1;
			for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(flg&&x[i]>y[j]&&(f[i][j-1]||f[i-1][j-1]||f[i-1][j])) f[i][j]=1;
				if(!flg&&x[i]<y[j]&&(f[i][j-1]||f[i-1][j-1]||f[i-1][j])) f[i][j]=1;
			}
			printf("%d",f[n][m]);
		}
	}
	return;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();
	if(c<=7) solve();
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/