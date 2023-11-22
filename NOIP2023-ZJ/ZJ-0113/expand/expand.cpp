#include<bits/stdc++.h>
using namespace std;
int read(){
	char ch=getchar();
	int x=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
const int N=5e5+10;
const int N7=2e3+10;
int c,n,m,q;
int x[N],y[N],orix[N],oriy[N];
int f[N7][N7];
bool calc(){
	if(c==1)return x[1]!=y[1];
	else if(c==2){
		if(x[1]==y[1]||x[2]==y[2])return 0;
		return (x[1]>y[1])==(x[2]>y[2]);
	}
	else if(c<=7){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)f[i][j]=0;
		if(x[1]>y[1])f[1][1]=1;
		for(int i=2;i<=n;i++)
			if(x[i]>y[1])f[i][1]=1;
			else break;
		for(int i=2;i<=m;i++)
			if(x[1]>y[i])f[1][i]=1;
			else break;
		for(int i=2;i<=n;i++){
			for(int j=2;j<=m;j++){
				if(x[i]<=y[j])continue;
				if(f[i-1][j-1]||f[i-1][j]||f[i][j-1])
					f[i][j]=1;
			}
		}
		if(f[n][m]&&f[1][1])return 1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)f[i][j]=0;
		if(x[1]<y[1])f[1][1]=1;
		else return 0;
		for(int i=2;i<=n;i++)
			if(x[i]<y[1])f[i][1]=1;
			else break;
		for(int i=2;i<=m;i++)
			if(x[1]<y[i])f[1][i]=1;
			else break;
		for(int i=2;i<=n;i++){
			for(int j=2;j<=m;j++){
				if(x[i]>=y[j])continue;
				if(f[i-1][j-1]||f[i-1][j]||f[i][j-1])
					f[i][j]=1;
			}
		}
		return f[n][m];
	}
	return 1;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)orix[i]=x[i]=read();
	for(int i=1;i<=m;i++)oriy[i]=y[i]=read();
	cout<<calc();
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++)x[j]=orix[j];
		for(int j=1;j<=m;j++)y[j]=oriy[j];
		int kx=read(),ky=read();
		for(int j=1;j<=kx;j++){
			int p=read(),v=read();
			x[p]=v;
		}
		for(int j=1;j<=ky;j++){
			int p=read(),v=read();
			y[p]=v;
		}
		cout<<calc();
	}
	return 0;
}
