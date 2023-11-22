#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005;
int T,n,m,k,d,num[N][N],f[N][N];
inline int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	read(),T=read();
	while(T--){
		n=read(),m=read(),k=read(),d=read();
		memset(num,0,sizeof(num));
		//memset(f,0x80,sizeof(f));
		for(int i=1;i<=m;i++){
			int x=read(),y=read(),z=read();
			if(y>k)continue;
			num[max(1ll,x-k+1)][x]+=z,num[x-y+2][x]-=z;
		}
		for(int i=1;i<=n;i++)
			for(int j=max(1ll,i-k+1);j<=i;j++)
				num[j][i]+=num[j-1][i];
		for(int i=1;i<=n;i++)
			for(int j=i;j<=i+k-1&&j<=n;j++){
				num[i][j]+=num[i][j-1];
			}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++)
//				printf("%d ",num[i][j]);
//			printf("\n");
//		}
		//f[0][0]=f[1][0]=0;
		for(int i=1;i<=n;i++){
			f[i+1][0]=f[i][0];
			for(int j=1;j<=k&&j<=i;j++)
				f[i][j]=f[i-j][0]+num[i-j][j]-j*d,f[i+1][0]=max(f[i+1][0],f[i][j]);
		}
		printf("%lld\n",f[n+1][0]);
	}
	return 0;
}