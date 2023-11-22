#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+10;
const int M=1e5+10;
int c,T,n,m,k,x[M],y[M];
ll d,v[M],f[M],ans,sum[N][N];
bool flag1,flag2;
int rd(){
	int x=0,w=0;
	char ch=getchar();
	while (!isdigit(ch)){
		if (ch=='-') w=1;
		ch=getchar();
	}
	while (isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return w?-x:x;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=rd(),T=rd();
	while (T--){
		n=rd(),m=rd(),k=rd(),d=rd();
		flag1=flag2=1;
		for (int i=1;i<=m;++i)
			x[i]=rd(),y[i]=rd(),v[i]=rd();
		for (int i=1;i<m;++i)
		if (x[i]>=x[i+1]-y[i+1]+1){
			flag2=0;
			break;
		}
		if (flag2){
			ans=0;
			for (int i=1;i<=m;++i)
			if (y[i]<=k&&v[i]>y[i]*d) ans+=v[i]-y[i]*d;
			printf("%lld\n",ans);
		}
		else{
			for (int i=1;i<=m;++i)
				sum[x[i]][x[i]-y[i]+1]+=v[i];
			for (int i=1;i<=n;++i)
				for (int j=1;j<=n;++j) sum[i][j]=sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			ans=0;
			for (int i=1;i<=n+1;++i)
			{
				f[i]=f[i-1];
				for (int j=1;j<=k&&j<=i-1;++j) f[i]=max(f[i],f[i-1-j]+(sum[i-1][i-1]-sum[i-1-j][i-1]-sum[i-1][i-1-j]+sum[i-1-j][i-1-j])-j*d);
			}
			for (int i=1;i<=n;++i)
				for (int j=1;j<=n;++j) sum[i][j]=0;
			printf("%lld\n",f[n+1]);
		}
	}
	return 0;
}
