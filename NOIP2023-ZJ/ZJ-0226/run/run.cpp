#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
inline int read(){
	int w=1,s=0;
	char c=getchar();
	for(;c<'0'||c>'9';w*=(c=='-')?-1:1,c=getchar());
	for(;c>='0'&&c<='9';s=s*10+c-'0',c=getchar());
	return w*s;
}
int Id,T;
int n,m,k,d;
struct P{
	int x,y,v;
}a[N];
int w[1005][1005];
int f[1005][1005];
int maxn[1005];
//f[i][j] 到第i天连续打卡j天，的最大能量值 

signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	Id=read(),T=read();
	if(Id<=9){	
		while(T--){
			memset(w,0,sizeof w);
			n=read(),m=read(),k=read(),d=read();
			for(int i=1;i<=m;i++){
				a[i].x=read(),a[i].y=read(),a[i].v=read();
				w[a[i].x][a[i].y]+=a[i].v;
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=min(i,k);j++){
					w[i][j]+=w[i][j-1];
				}
			}
			memset(maxn,-0x3f,sizeof maxn);
			memset(f,-0x3f,sizeof f);
			f[0][0]=0;
			maxn[0]=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(i,k);j++){
					if(j==0) f[i][j]=maxn[i-1];
					else f[i][j]=max(f[i][j],f[i-1][j-1]-d+w[i][j]);
					maxn[i]=max(maxn[i],f[i][j]);
				}
			}
			cout<<maxn[n]<<endl;
		}
	}
	return 0;
}

