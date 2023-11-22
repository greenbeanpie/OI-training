#include<bits/stdc++.h>
using namespace std;
int c,q;
int n[2],opt;
int a[2005][2],A[2005][2];
bool f[2005][2005];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read();n[0]=read();n[1]=read();q=read();
	for(int i=1;i<=n[0];i++)a[i][0]=A[i][0]=read();
	for(int i=1;i<=n[1];i++)a[i][1]=A[i][1]=read();

		if(a[1][1]<a[1][0])opt=0;
		else opt=1;
		f[0][0]=1;
		for(int i=1;i<=n[opt];i++)
			for(int j=1;j<=n[opt^1];j++)
			if((f[i-1][j-1]||f[i-1][j]||f[i][j-1])&&a[j][opt^1]<a[i][opt])f[i][j]=1;
		printf("%d",f[n[opt]][n[opt^1]]);

	while(q--){
		for(int i=1;i<=n[0];i++)a[i][0]=A[i][0];
		for(int i=1;i<=n[1];i++)a[i][1]=A[i][1];
		int x=read(),y=read();
		for(int i=1;i<=x;i++){
			int X=read();
			a[X][0]=read();
		}
		for(int i=1;i<=y;i++){
			int Y=read();
			a[Y][1]=read();
		}
		if(a[1][1]<a[1][0])opt=0;
		else opt=1;
		memset(f,0,sizeof f);
		f[0][0]=1;
		for(int i=1;i<=n[opt];i++)
			for(int j=1;j<=n[opt^1];j++)
			if((f[i-1][j-1]||f[i-1][j]||f[i][j-1])&&a[j][opt^1]<a[i][opt])f[i][j]=1;
		printf("%d",f[n[opt]][n[opt^1]]);
	}
	return 0;
}